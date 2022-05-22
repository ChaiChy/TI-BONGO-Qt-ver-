#include "SimpleInput.h"
#include "Configuration.h"
#include <windows.h>
#include <iostream>
//Microsoft Codetabelle
//https://msdn.microsoft.com/de-de/library/windows/desktop/dd375731(v=vs.85).aspx

SimpleInput::SimpleInput()
{
}

SimpleInput::~SimpleInput()
{
}

char SimpleInput::getSteuerung(long interval)
{
    Sleep(interval);
    const int KEY_UP = 0x1;
    if ((GetAsyncKeyState(0x57) & KEY_UP) == KEY_UP) // 'w';
        return CONFIGURATION::SPIELSTEIN_BEWEGEN_HOCH;
    else if ((GetAsyncKeyState(0x41) & KEY_UP) == KEY_UP) // 'a';
        return CONFIGURATION::SPIELSTEIN_BEWEGEN_LINKS;
    else if ((GetAsyncKeyState(0x53) & KEY_UP) == KEY_UP) // 's';
        return CONFIGURATION::SPIELSTEIN_BEWEGEN_RUNTER;
    else if ((GetAsyncKeyState(0x44) & KEY_UP) == KEY_UP) // 'd';
        return CONFIGURATION::SPIELSTEIN_BEWEGEN_RECHTS;
    else if ((GetAsyncKeyState(0x51) & KEY_UP) == KEY_UP) // 'q';
        return CONFIGURATION::SPIELSTEIN_ROTIEREN_LINKS;
    else if ((GetAsyncKeyState(0x45) & KEY_UP) == KEY_UP) // 'e';
        return CONFIGURATION::SPIELSTEIN_ROTIEREN_RECHTS;
    else if ((GetAsyncKeyState(0x46) & KEY_UP) == KEY_UP) // 'f';
        return CONFIGURATION::SPIELSTEIN_FLIP;
    else if ((GetAsyncKeyState(0x31) & KEY_UP) == KEY_UP) // '1'
        return CONFIGURATION::SPIELSTEIN_1_INDEX;
    else if ((GetAsyncKeyState(0x32) & KEY_UP) == KEY_UP) // '2'
        return CONFIGURATION::SPIELSTEIN_2_INDEX;
    else if ((GetAsyncKeyState(0x33) & KEY_UP) == KEY_UP) // '3'
        return CONFIGURATION::SPIELSTEIN_3_INDEX;
    else if ((GetAsyncKeyState(0x34) & KEY_UP) == KEY_UP) // '4'
        return CONFIGURATION::SPIELSTEIN_4_INDEX;
    else
        return CONFIGURATION::EINGABE_UNGUELTIG;
}
