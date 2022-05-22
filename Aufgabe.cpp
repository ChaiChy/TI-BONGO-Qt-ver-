#include "Aufgabe.h"

Spielstein* Aufgabe::getSpielstein(size_t index)
{
    return steine[index];
}

bool Aufgabe::geloest()
{

    for (int i = 0; i < loesung_ptr->felder[0][0].size(); i++)
    {
        for (int j = 0; j < steine.size(); j++)
        {
            if (!steine[j]->innerhalb(loesung_ptr->getPosition() + loesung_ptr->felder[0][0].at(i)))
            {
                return false;
            }
        }
    }
    return true;
}

void Aufgabe::zeichne() //first draw the "Lösungstein", then the rest of the Spielsteine.
{
    loesung_ptr->zeichne();
    for (int i = 0; i < steine.size(); i++)
    {
        getSpielstein(i)->zeichne();
    }
}

void Aufgabe::loesche()
{
    loesung_ptr->loesche();
    for (int i = 0; i < steine.size(); i++)
    {
        getSpielstein(i)->loesche();
    }
}

Aufgabe::Aufgabe() {}; //default empty constructor

Aufgabe::Aufgabe(Spielstein* stein1_ptr, Spielstein* stein2_ptr, Spielstein* stein3_ptr, Spielstein* loesung_ptr)
{
    steine.push_back(stein1_ptr);
    steine.push_back(stein2_ptr);
    steine.push_back(stein3_ptr);
    this->loesung_ptr = loesung_ptr;
}

void Aufgabe::initSchwer()
{
    Quadrupel q1(SPIELSTEIN_QPLUS, SPIELSTEIN_T, SPIELSTEIN_Z2, SPIELSTEIN_L3);
    Quadrupel q2(SPIELSTEIN_Z2, SPIELSTEIN_Q, SPIELSTEIN_QPLUS, SPIELSTEIN_I4);
    Quadrupel q3(SPIELSTEIN_Z2, SPIELSTEIN_L3, SPIELSTEIN_L4, SPIELSTEIN_T);
    Quadrupel q4(SPIELSTEIN_I4, SPIELSTEIN_QPLUS, SPIELSTEIN_Z2, SPIELSTEIN_Z2);
    Quadrupel q5(SPIELSTEIN_Z2, SPIELSTEIN_Z3, SPIELSTEIN_L3, SPIELSTEIN_L3);
    Quadrupel q6(SPIELSTEIN_L3, SPIELSTEIN_QPLUS, SPIELSTEIN_QPLUS, SPIELSTEIN_T);

    Quadrupel arrayQ[] = {q1, q2, q3, q4, q5, q6};
    std::srand(std::time(NULL));
    Quadrupel chosen_q = arrayQ[std::rand() % 6];

    //couldn't use unique_ptr ):
    Spielstein *stein_1 = new Spielstein(chosen_q.stein_1);
    Spielstein *stein_2 = new Spielstein(chosen_q.stein_2);
    Spielstein *stein_3 = new Spielstein(chosen_q.stein_3);
    Spielstein *stein_4 = new Spielstein(chosen_q.stein_4);

    stein_1->position.setX(CONFIGURATION::SPIELFELD_STEIN1_X);
    stein_1->position.setY(CONFIGURATION::SPIELFELD_STEIN1_Y);
    stein_2->position.setX(CONFIGURATION::SPIELFELD_STEIN2_X);
    stein_2->position.setY(CONFIGURATION::SPIELFELD_STEIN2_Y);
    stein_3->position.setX(CONFIGURATION::SPIELFELD_STEIN3_X);
    stein_3->position.setY(CONFIGURATION::SPIELFELD_STEIN3_Y);
    stein_4->position.setX(CONFIGURATION::SPIELFELD_STEIN4_X);
    stein_4->position.setY(CONFIGURATION::SPIELFELD_STEIN4_Y);

    steine.push_back(stein_1);
    steine.push_back(stein_2);
    steine.push_back(stein_3);
    steine.push_back(stein_4);

    loesung_ptr = new Spielstein(SPIELSTEIN_LOESUNG);
    loesung_ptr->position.setX(CONFIGURATION::SPIELFELD_LOESUNG_X);
    loesung_ptr->position.setY(CONFIGURATION::SPIELFELD_LOESUNG_Y);

    aktiverSpielstein = 0;
}
