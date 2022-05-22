#include "Console.h"
#ifndef CONFIG
#define CONFIG 
class CONFIGURATION
{
public:
	//SPIELFELD - DIMENSION
    static const int SPIELFELD_DIMENSION_X = 14;
    static const int SPIELFELD_DIMENSION_Y = 14;
    static const int SPIELFELD_INNERER_ABSTAND = 2;
    static const int SPIELFELD_OFFSET_X = 0;
    static const int SPIELFELD_OFFSET_Y = 0;

    static const int CONSOLE_FAKTOR_GUI = 34;

	//SPIELFELD - GRAFIK
	static const int SPIELFELD_BEGRENZUNG_BREITE = 1;
	static const char SPIELFELD_HINTERGRUND_SYMBOL = ' ';
	static const char SPIELFELD_BEGRENZUNG = '#';

	//SPIELSTEIN - Initialpositionen
    static const int SPIELFELD_STEIN1_X = 2;
    static const int SPIELFELD_STEIN1_Y = 2;
    static const int SPIELFELD_STEIN2_X = 2;
    static const int SPIELFELD_STEIN2_Y = SPIELFELD_DIMENSION_Y - 5;
    static const int SPIELFELD_STEIN3_X = SPIELFELD_DIMENSION_X - 5;
    static const int SPIELFELD_STEIN3_Y = 2;
    static const int SPIELFELD_STEIN4_X = SPIELFELD_DIMENSION_X - 5;
    static const int SPIELFELD_STEIN4_Y = SPIELFELD_DIMENSION_Y - 5;
    static const int SPIELFELD_LOESUNG_X = (SPIELFELD_DIMENSION_X + SPIELFELD_OFFSET_X ) / 2 - 2;
    static const int SPIELFELD_LOESUNG_Y = (SPIELFELD_DIMENSION_Y + SPIELFELD_OFFSET_Y) / 2 - 2;
	
	//SPIEL - SPIELSTEIN - INDEX
	static const int SPIELSTEIN_1_INDEX = 0;
	static const int SPIELSTEIN_2_INDEX = 1;
	static const int SPIELSTEIN_3_INDEX = 2;
	static const int SPIELSTEIN_4_INDEX = 3;

	//SPIELSTEIN - TRANSLATION / ROTATION / FLIP
	static const int SPIELSTEIN_BEWEGEN_HOCH	= 4;
	static const int SPIELSTEIN_BEWEGEN_RUNTER	= 5;
	static const int SPIELSTEIN_BEWEGEN_RECHTS	= 6;
	static const int SPIELSTEIN_BEWEGEN_LINKS	= 7;

	static const int SPIELSTEIN_ROTIEREN_RECHTS	= 8;
	static const int SPIELSTEIN_ROTIEREN_LINKS	= 9;

	static const int SPIELSTEIN_FLIP			= 10;
	static const int EINGABE_UNGUELTIG			= 11;

	//GAMEPLAY
	static const int ANZAHL_STEINE = 4;
	static const int ANZAHL_RUNDEN = 3;
	static const int ANZAHL_BEWEGUNGEN = 100;
	static const int LOESUNGSZEIT_IN_SEKUNDEN = 30;
	
	//Abtastdauer Tastatur in Millisekungen
	static const int INTERVALL = 300;

	//SPIELER - WERTE
	static const int SPIELER_ANZAHL_LEBEN = 2;
};
#endif
