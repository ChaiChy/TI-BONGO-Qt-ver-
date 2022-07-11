#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Configuration.h"
#include "Console.h"
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QKeyEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "Aufgabe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMediaPlayer *music = new QMediaPlayer();
    QAudioOutput *output = new QAudioOutput();
    music->setSource(QUrl("qrc:/image/BongoImages/bilder/take_on_me.mp3"));
    music->setAudioOutput(output);
    music->play();


    //timer
    QTimer *clock = new QTimer(this);
    int initial_time = std::time(NULL); //keep track of starting time

    connect (clock, &QTimer::timeout, [=] ()mutable {
        ui->lcdNumber_zeit->display(static_cast<int>(5 - (std::time(NULL) - initial_time)));
        if (ui->lcdNumber_zeit->intValue() < 0)
        {
            ui->pushButton_naechste->click();
            initial_time = std::time(NULL);
        }

        else if (ui->pushButton_naechste->isDown())
        {
            initial_time = std::time(NULL);
        }
        else if (ui->pushButton_reset->isDown())
        {
            initial_time = std::time(NULL);
        }

    });
    clock->start(5); //start clock in one second after program starts

    //--------------------------------------------------------------------------
    // Setzt das Hintergrundbild des MainWindow
    //--------------------------------------------------------------------------
    this->setAutoFillBackground(true); //In einigen Qt-Versionen notwendig
    QPalette qpalette;
    QPixmap pixmap = QPixmap(":/images/BongoImages/bilder/hintergrund.png");
    pixmap.scaled(CONFIGURATION::SPIELFELD_DIMENSION_X*CONFIGURATION::CONSOLE_FAKTOR_GUI,
                  CONFIGURATION::SPIELFELD_DIMENSION_Y*CONFIGURATION::CONSOLE_FAKTOR_GUI);
    qpalette.setBrush( backgroundRole(), pixmap);
    this->setPalette (qpalette); // Bild wird gekachelt, falls es keliner als das Widget ist

    //--------------------------------------------------------------------------
    // Setzt das Layout der QPushButton
    //--------------------------------------------------------------------------
    QColor col = QColor(Qt::gray);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_bewegen_hoch->setStyleSheet(qss);
       ui->pushButton_bewegen_runter->setStyleSheet(qss);
       ui->pushButton_bewegen_rechts->setStyleSheet(qss);
       ui->pushButton_bewegen_links->setStyleSheet(qss);
       ui->pushButton_drehen_rechts->setStyleSheet(qss);
       ui->pushButton_drehen_links->setStyleSheet(qss);
       ui->pushButton_flip->setStyleSheet(qss);
    }


    //--------------------------------------------------------------------------
    // Tibongo Logo als Text oder Bild
    //--------------------------------------------------------------------------
    QLabel* label_logo = ui->label_logo;
    label_logo->setText("Tibongo");
    label_logo->setStyleSheet("font: Chiller; font-size: 200; font-weight: bold; color: gray");//; color: red");
    //Optional - Bild überdeckt den Text
    label_logo->setText(QString(""));
    label_logo->setPixmap(QPixmap(":/images/BongoImages/bilder/Logo1_oH.png"));
    label_logo->setScaledContents(true);

    //--------------------------------------------------------------------------
    // Setzen der Spieler QLabel
    //--------------------------------------------------------------------------
    QLabel* label_punkte = ui->label_punkte;
    label_punkte->setText("Punkte");
    QLabel* label_eingaben = ui->label_eingaben;
    label_eingaben->setText("Eingaben");
    QLabel* label_zeit = ui->label_zeit;
    label_zeit->setText("Restzeit");

    //-------------------------------------------------------------------------------------------------------
    //Spielfläche initialisieren - Zeichnen über blocks [CONFIGURATION::SPIELFELD_DIMENSION_X] [CONFIGURATION::SPIELFELD_DIMENSION_Y]
    //-------------------------------------------------------------------------------------------------------
    QGraphicsScene* qgs_spielfeld = new QGraphicsScene(0,0,CONFIGURATION::SPIELFELD_DIMENSION_X*CONFIGURATION::CONSOLE_FAKTOR_GUI,
                                             CONFIGURATION::SPIELFELD_DIMENSION_Y*CONFIGURATION::CONSOLE_FAKTOR_GUI, ui->graphicsView_Spielfeld);
    qgs_spielfeld->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    QGraphicsRectItem* blocks [CONFIGURATION::SPIELFELD_DIMENSION_X] [CONFIGURATION::SPIELFELD_DIMENSION_Y] ;
    for (int x = 0; x < CONFIGURATION::SPIELFELD_DIMENSION_X; x++)
        for (int y = 0; y < CONFIGURATION::SPIELFELD_DIMENSION_Y; y++)
        {
            blocks [x] [y] = new QGraphicsRectItem (x*CONFIGURATION::CONSOLE_FAKTOR_GUI, y*CONFIGURATION::CONSOLE_FAKTOR_GUI,
                                                    CONFIGURATION::CONSOLE_FAKTOR_GUI, CONFIGURATION::CONSOLE_FAKTOR_GUI);
            blocks [x] [y]->setBrush(Qt::white);
            blocks [x] [y]->setPen(QPen(Qt::black));
            qgs_spielfeld->addItem(blocks[x][y]);
        }
    ui->graphicsView_Spielfeld->setScene(qgs_spielfeld);

    //-------------------------------------------------------------------------------------------------------
    //Stein Legende - Vorbereitung - Zeichnen über legende_blocks [16] [4]
    //-------------------------------------------------------------------------------------------------------
    QGraphicsScene* qgs_steine = new QGraphicsScene(0,0,4*3*CONFIGURATION::CONSOLE_FAKTOR_GUI-20,
                                             4*CONFIGURATION::CONSOLE_FAKTOR_GUI, ui->graphicsView_Spielsteine);
    qgs_steine->setBackgroundBrush(QBrush(Qt::lightGray, Qt::SolidPattern));
    QGraphicsRectItem* legende_blocks [16] [4] ;
    for (int x = 0; x < 16; x++)
        for (int y = 0; y < 4; y++)
        {
            legende_blocks [x] [y] = new QGraphicsRectItem (x*(CONFIGURATION::CONSOLE_FAKTOR_GUI-10), y*(CONFIGURATION::CONSOLE_FAKTOR_GUI-10),
                                                    CONFIGURATION::CONSOLE_FAKTOR_GUI-10, CONFIGURATION::CONSOLE_FAKTOR_GUI-10);
            legende_blocks [x] [y]->setBrush(Qt::white);
            legende_blocks [x] [y]->setPen(QPen(Qt::black));
            qgs_steine->addItem(legende_blocks[x][y]);
        }
    ui->graphicsView_Spielsteine->setScene(qgs_steine);

    //-------------------------------------------------------------------------------------------------------
    //Initialisieren der Aufgabe
    //-------------------------------------------------------------------------------------------------------
    Aufgabe* aufgabe = new Aufgabe();
    aufgabe->initSchwer();

    //Verstecke Button 4 falls nicht benötigt.
    if (aufgabe->steine.size() <= CONFIGURATION::SPIELSTEIN_4_INDEX)
        ui->radioButton_stein4->hide();
    ui->radioButton_stein1->setChecked(true);
    //-------------------------------------------------------------------------------------------------------
    //Zeichne-Funktionen für die Stein-Legende - Zeichnet über legende_blocks - Jeder Stein 4x4 Felder
    // Anmerkung: Die Legende verwendet stets die Ausgangsposition, also die Positionen aus felder [0][0]
    //-------------------------------------------------------------------------------------------------------
    //Aufgabe 6c)
    auto zeichneLegende = [=] (bool visible)
    {
        int offset_X = 0;  //print block at next position, starting at 0, 0 each stein gets 4x4 square
        for (auto spielstein : aufgabe->steine)
        {
            std::string color = visible ? spielstein->getFarbe() : HINTERGRUND_WEISS;
            for (auto pos : spielstein->felder[0][0])
            {
               legende_blocks[offset_X + pos.getX()][pos.getY()]->setBrush(Cursor::QtFarbwandler(color));
            }
            offset_X += 4; //next block
        }
    };
    //-------------------------------------------------------------------------------------------------------
    //Zeichne-Funktionen für Steine in die Spielfläche - Zeichnet über blocks
    //Anmerkung: Ist visible false wird der Stein in weiß gezeichnet, sonst in original Farbe
    //-------------------------------------------------------------------------------------------------------
    //Aufgabe 6d)
    auto zeichneStein = [=] (Spielstein* stein_ptr, bool visible)
    {
        std::string color = visible? stein_ptr->getFarbe() : HINTERGRUND_WEISS;
        for (auto pos : *(stein_ptr->getPositionen()))
        {
           blocks[pos.getX() + stein_ptr->position.getX()][pos.getY() + stein_ptr->position.getY()]->setBrush(Cursor::QtFarbwandler(color));
        }
    };
    //-------------------------------------------------------------------------------------------------------
    //Zeichne-Funktionen der Aufgabe in die Spielfläche - Zeichnet über Funktion zeichneStein
    //Anmerkung 1: Es wird mit dem Lösungstein begonnen, danach werden alle anderen Steine gezeichnet,
    //             wobei der aktive Stein als letztes gezeichnet wird damit er "oben" liegt.
    //Anmerkung: Ist visible false werden alle Steine in weiß gezeichnet == gelöscht, sonst in original Farbe
    //-------------------------------------------------------------------------------------------------------
    //Aufgabe 6e)
    auto zeichneAufgabe = [=] (bool visible)
    {
        zeichneStein(aufgabe->loesung_ptr, visible); //draws loesung stein
        for (auto stein : aufgabe->steine)
        {
            zeichneStein(stein, visible); //draws pieces
        }
    };

    //-------------------------------------------------------------------------------------------------------
    // Prüft, ob die Aufgabe gelöst ist. Falls ja, dann ...
    // Funktion:: Zeichnet die aktuelle-Aufgbe und Legende weiß, erstellt eine neue Aufgabe,
    //            zeichnet die neue Aufgae (Legende und Spielsteine). Abschließend wird noch Stein 1 angewählt.
    //-------------------------------------------------------------------------------------------------------
    //Aufgabe 6f)
    auto geloest = [=] ()
    {
        if (aufgabe->geloest())
        {
            zeichneLegende(false);
            zeichneAufgabe(false);
            for (auto stein: aufgabe->steine) //free allocated memory
            {
                delete stein;
            }
            aufgabe->steine.clear();
            aufgabe->initSchwer(); //new puzzle
            zeichneLegende(true);
            zeichneAufgabe(true);
            ui->radioButton_stein1->setChecked(true);
        }
    };
    //____________________ AB HIER SPIEL UND INDIVIDUELLES SETUP

    //-------------------------------------------------------------------------------------------------------
    // Zeichnet die Aufgabe weiß, versetzt den Spielstein, zeichnet die Aufgabe neu und prüft anschließend,
    // ob die Aufgabe geloest ist.
    //-------------------------------------------------------------------------------------------------------
    //Aufgabe 6g)
    auto bewegen = [=] (int richtung)
    {
          zeichneAufgabe(false); //delete aufgabe
          aufgabe->steine[aufgabe->aktiverSpielstein]->bewegen(richtung);
          zeichneAufgabe(true);
          counter++;
          ui->lcdNumber_eingaben->display(counter);
          geloest();
    };

    zeichneLegende(true);
    zeichneAufgabe(true);

    //-------------------------------------------------------------------------------------------------------
    // Verbinden der interaktiven grafischen Elemente zur Steinmanipulation
    //-------------------------------------------------------------------------------------------------------
    connect (ui->pushButton_bewegen_hoch, &QPushButton::clicked, [=] ()
    {
        bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_HOCH);
    });
    connect (ui->pushButton_bewegen_runter, &QPushButton::clicked, [=] ()
    {
        bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_RUNTER);
    });
    connect (ui->pushButton_bewegen_links, &QPushButton::clicked, [=] ()
    {
        bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_LINKS);
    });
    connect (ui->pushButton_bewegen_rechts, &QPushButton::clicked, [=] ()
    {
        bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_RECHTS);
    });
    connect (ui->pushButton_drehen_rechts, &QPushButton::clicked, [=] ()
    {
        zeichneAufgabe(false);
        aufgabe->steine[aufgabe->aktiverSpielstein]->rotation_rechts();
        zeichneAufgabe(true);
        counter++;
        ui->lcdNumber_eingaben->display(counter);
    });
    connect (ui->pushButton_drehen_links, &QPushButton::clicked, [=] ()
    {
        zeichneAufgabe(false);
        aufgabe->steine[aufgabe->aktiverSpielstein]->rotation_links();
        zeichneAufgabe(true);
        counter++;
        ui->lcdNumber_eingaben->display(counter);
    });
    connect (ui->pushButton_flip, &QPushButton::clicked, [=] ()
    {
        zeichneAufgabe(false);
        aufgabe->steine[aufgabe->aktiverSpielstein]->flip();
        zeichneAufgabe(true);
        counter++;
        ui->lcdNumber_eingaben->display(counter);
    });
    connect (ui->pushButton_reset, &QPushButton::clicked, [=] ()
    {
        zeichneAufgabe(false);
        for (auto stein : aufgabe->steine)
        {
            stein->setOrientierung(0);
            stein->setSeite(0);
        }
        aufgabe->steine[0]->setX(CONFIGURATION::SPIELFELD_STEIN1_X);
        aufgabe->steine[0]->setY(CONFIGURATION::SPIELFELD_STEIN1_Y);

        aufgabe->steine[1]->setX(CONFIGURATION::SPIELFELD_STEIN2_X);
        aufgabe->steine[1]->setY(CONFIGURATION::SPIELFELD_STEIN2_Y);

        aufgabe->steine[2]->setX(CONFIGURATION::SPIELFELD_STEIN3_X);
        aufgabe->steine[2]->setY(CONFIGURATION::SPIELFELD_STEIN3_Y);

        aufgabe->steine[3]->setX(CONFIGURATION::SPIELFELD_STEIN4_X);
        aufgabe->steine[3]->setY(CONFIGURATION::SPIELFELD_STEIN4_Y);

        zeichneAufgabe(true);
        counter = 0;
        ui->lcdNumber_eingaben->display(counter);
        //initial_time = std::time(NULL);   //update initial_time to reset the clock
    });
    connect (ui->pushButton_naechste, &QPushButton::clicked, [=] ()
    {
        zeichneLegende(false);
        zeichneAufgabe(false);
        std::for_each(aufgabe->steine.begin(), aufgabe->steine.end(), std::default_delete<Spielstein>()); // this works too
        aufgabe->steine.clear();
        aufgabe->initSchwer(); //new puzzle
        zeichneLegende(true);
        zeichneAufgabe(true);
        ui->radioButton_stein1->setChecked(true);
        counter = 0;
        ui->lcdNumber_eingaben->display(counter);
        //initial_time = std::time(NULL);   //update initial_time to reset the clock
    });
    //-------------------------------------------------------------------------------------------------------
    // Verbinden der QRadioButtons zur Steinauswahl
    //-------------------------------------------------------------------------------------------------------
    connect (ui->radioButton_stein1, &QRadioButton::clicked, [=] ()
    {
        aufgabe->aktiverSpielstein = 0;
    });
    connect (ui->radioButton_stein2, &QRadioButton::clicked, [=] ()
    {
        aufgabe->aktiverSpielstein = 1;
    });
    connect (ui->radioButton_stein3, &QRadioButton::clicked, [=] ()
    {
        aufgabe->aktiverSpielstein = 2;
    });
    connect (ui->radioButton_stein4, &QRadioButton::clicked, [=] ()
    {
        aufgabe->aktiverSpielstein = 3;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
