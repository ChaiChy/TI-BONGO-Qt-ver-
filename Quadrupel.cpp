#include "Quadrupel.h"

Quadrupel::Quadrupel()
    :stein_1(SPIELSTEIN_FREI), stein_2(SPIELSTEIN_FREI), stein_3(SPIELSTEIN_FREI), stein_4(SPIELSTEIN_FREI) {};

Quadrupel::Quadrupel(int stein_1, int stein_2, int stein_3, int stein_4)
{
    this->stein_1 = stein_1;
    this->stein_2 = stein_2;
    this->stein_3 = stein_3;
    this->stein_4 = stein_4;
}

Quadrupel::Quadrupel(const Quadrupel& other)
{
    this->stein_1 = other.stein_1;
    this->stein_2 = other.stein_2;
    this->stein_3 = other.stein_3;
    this->stein_4 = other.stein_4;
}


