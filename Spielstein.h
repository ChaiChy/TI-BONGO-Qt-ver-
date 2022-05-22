#ifndef SPIELSTEIN
#define SPIELSTEIN

#define SPIELSTEIN_Z2 0
#define SPIELSTEIN_Z3 1
#define SPIELSTEIN_L2 2
#define SPIELSTEIN_L3 3
#define SPIELSTEIN_L4 4
#define SPIELSTEIN_I2 5
#define SPIELSTEIN_I3 6
#define SPIELSTEIN_Q 7
#define SPIELSTEIN_QPLUS 8
#define SPIELSTEIN_T 9
#define SPIELSTEIN_TPLUS 10
#define SPIELSTEIN_LOESUNG 11
#define SPIELSTEIN_I4 12
#define SPIELSTEIN_FREI 13


#include "Position.h"
#include <string>
#include <vector>
#include "Console.h"
#include "Cursor.h"
#include "Configuration.h"

class Spielstein
{

protected:

    int typ = SPIELSTEIN_FREI;
    std::string name;
    char orientierung = 0;
    char seite = 0;
    std::string farbe = CURSOR_WEISS;

public:
    std::vector<Position> felder[2][4];
    Position position;

    void setPosition(Position position);
    void setX(int x);
    void setY(int y);
    void setSeite(int seite);
    void setOrientierung(int orientierung);
    Position getPosition();
    std::string getFarbe();

    void init();
    void zeichne();
    void loesche();

    void bewegen(int richtung);
    void rotation_rechts();
    void rotation_links();
    void flip();

    std::vector<Position>* getPositionen();
    bool innerhalb(Position pos); //const removed

    bool ueberlapp(Spielstein& sp);

    Spielstein(int typ) : typ(typ)
    {
        init();
    }
    virtual ~Spielstein() {};

    Spielstein operator+ (Spielstein& rhs); //const removed
};



#endif
