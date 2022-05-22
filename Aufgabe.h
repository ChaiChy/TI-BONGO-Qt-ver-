#ifndef AUFGABE
#define AUFGABE

#include "Spielstein.h"
#include "Position.h"
#include "Quadrupel.h"

class Aufgabe
{
private:
	std::vector<Spielstein*> steine;
public:
	friend class Spiel;
    friend class MainWindow;
	Spielstein* loesung_ptr = NULL;
    int aktiverSpielstein = 0;

	Spielstein* getSpielstein(size_t index);
	bool geloest(); //solved
	void zeichne();
	void loesche();
    void initSchwer();

	Aufgabe();
	Aufgabe(Spielstein* stein1_ptr, Spielstein* stein2_ptr, Spielstein* stein3_ptr, Spielstein* loesung_ptr);
};

#endif
