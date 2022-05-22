#include <iostream>
#include "Console.h"
#include "Cursor.h"


//Leere Bildschirm, verstecke Cursor, Position 0,0
void Console::init()
{
    leeren();
    verstecken();
}
//Leere Terminal
void Console::leeren()
{
    std::cout << "\33[2J";
}
//Verstecke Cursor
void Console::verstecken()
{
    std::cout << "\33[?25l";
}
//Zeigt den Cursor
void Console::zeigen()
{
    std::cout << "\33[?25h";
}

//Gebe Zeichen c an Position x, y aus.
void Console::zeichne_punkt(int x, int y, char c)
{
    //printf("\33[%d;%dH%c", y, x, c);
    Cursor::bewegen(x, y);
    std::cout << c;
}
//Zeichnet eine Linie aus Zeichen c von Position x1, y1 nach Position x2, y2
void Console::zeichne_linie(int x1, int y1, int x2, int y2, char c)
{
    int diff_x = abs(x1 - x2);
    int diff_y = abs(y1 - y2);

    double schritte = diff_x > diff_y ? diff_x : diff_y;
    schritte = schritte - 1.0;
    double delta_x = diff_x / schritte;
    double delta_y = diff_y / schritte;
    double x_faktor = x1 > x2 ? -1 : 1;
    double y_faktor = y1 > y2 ? -1 : 1;
    double x = x1;
    double y = y1;

    for (int i = 0; i <= schritte; i++)
    {
        Console::zeichne_punkt((int)ceil(x), (int)ceil(y), c);
        x = x + x_faktor * delta_x;
        y = y + y_faktor * delta_y;
    }
}
