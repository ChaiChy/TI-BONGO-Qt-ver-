#ifndef CONSOLE
#define CONSOLE 

//https://ansi.gabebanks.net/
//https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit
#include <string>
#include "mainwindow.h"


namespace Console
{
    void init();				//Leere Terminal, verstecke Cursor, Position 0,0
	void leeren();				//Leere Terminal

	void verstecken();			//Verstecke Cursor 	
	void zeigen();				//Zeige Cursor 

	void zeichne_punkt(int x, int y, char c); //Zeichne Zeichen c an Position x, y
	//Zeichnet eine Linie aus Zeichen c von Position x1, y1 nach Position x2, y2
	void zeichne_linie(int x1, int y1, int x2, int y2, char c);

};
#endif
