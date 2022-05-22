#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //create instance of QAplication
    MainWindow w;               // create instance of MainWindow
    w.show();                   //display application
    return a.exec();            //loop
}
