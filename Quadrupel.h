#ifndef QUADRUPEL
#define QUADRUPEL

#include "Spielstein.h"
class Quadrupel
{
public:
    Quadrupel();
    Quadrupel(int stein_1, int stein_2, int stein_3, int stein_4);
    Quadrupel(const Quadrupel& other);

    int stein_1;
    int stein_2;
    int stein_3;
    int stein_4;
};

#endif
