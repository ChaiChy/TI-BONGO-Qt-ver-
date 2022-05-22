#include "Spielstein.h"

void Spielstein::init() {
    switch (typ)
    {
        case SPIELSTEIN_Z2:
        {
            name = "Z2";
            farbe = HINTERGRUND_GELB;
            felder[0][0].push_back(Position(2, 0));//__#_
            felder[0][0].push_back(Position(1, 1));//_##_
            felder[0][0].push_back(Position(2, 1));//_#__
            felder[0][0].push_back(Position(1, 2));//____

            felder[0][1].push_back(Position(1, 1));//____
            felder[0][1].push_back(Position(2, 1));//_##_
            felder[0][1].push_back(Position(2, 2));//__##
            felder[0][1].push_back(Position(3, 2));//____

            felder[0][2].push_back(Position(2, 0));//__#_
            felder[0][2].push_back(Position(1, 1));//_##_
            felder[0][2].push_back(Position(2, 1));//_#__
            felder[0][2].push_back(Position(1, 2));//____

            felder[0][3].push_back(Position(1, 1));//____
            felder[0][3].push_back(Position(2, 1));//_##_
            felder[0][3].push_back(Position(2, 2));//__##
            felder[0][3].push_back(Position(3, 2));//____

            felder[1][0].push_back(Position(1, 0));//_#__
            felder[1][0].push_back(Position(1, 1));//_##_
            felder[1][0].push_back(Position(2, 1));//__#_
            felder[1][0].push_back(Position(2, 2));//____

            felder[1][1].push_back(Position(2, 1));//____
            felder[1][1].push_back(Position(3, 1));//__##
            felder[1][1].push_back(Position(1, 2));//_##_
            felder[1][1].push_back(Position(2, 2));//____

            felder[1][2].push_back(Position(1, 0));//_#__
            felder[1][2].push_back(Position(1, 1));//_##_
            felder[1][2].push_back(Position(2, 1));//__#_
            felder[1][2].push_back(Position(2, 2));//____

            felder[1][3].push_back(Position(2, 1));//____
            felder[1][3].push_back(Position(3, 1));//__##
            felder[1][3].push_back(Position(1, 2));//_##_
            felder[1][3].push_back(Position(2, 2));//____

            break;
        }
        case SPIELSTEIN_Z3:
        {
            name = "Z3";
            farbe = HINTERGRUND_HELL_BLAU;
            felder[0][0].push_back(Position(2, 0));//___#
            felder[0][0].push_back(Position(0, 1));//_###
            felder[0][0].push_back(Position(1, 1));//_#__
            felder[0][0].push_back(Position(2, 1));//____
            felder[0][0].push_back(Position(0, 2));

            felder[0][1].push_back(Position(0, 0));//_##_
            felder[0][1].push_back(Position(1, 0));//__#_
            felder[0][1].push_back(Position(1, 1));//__##
            felder[0][1].push_back(Position(1, 2));//____
            felder[0][1].push_back(Position(2, 2));

            felder[0][2].push_back(Position(2, 0));//___#
            felder[0][2].push_back(Position(2, 1));//_###
            felder[0][2].push_back(Position(1, 1));//_#__
            felder[0][2].push_back(Position(0, 1));//____
            felder[0][2].push_back(Position(0, 2));

            felder[0][3].push_back(Position(0, 0));//_##_
            felder[0][3].push_back(Position(1, 0));//__#_
            felder[0][3].push_back(Position(1, 1));//__##
            felder[0][3].push_back(Position(1, 2));//____
            felder[0][3].push_back(Position(2, 2));

            felder[1][0].push_back(Position(0, 0));//_#__
            felder[1][0].push_back(Position(0, 1));//_###
            felder[1][0].push_back(Position(1, 1));//___#
            felder[1][0].push_back(Position(2, 1));//____
            felder[1][0].push_back(Position(2, 2));

            felder[1][1].push_back(Position(2, 0));//__##
            felder[1][1].push_back(Position(1, 0));//__#_
            felder[1][1].push_back(Position(1, 1));//_##_
            felder[1][1].push_back(Position(1, 2));//____
            felder[1][1].push_back(Position(0, 2));

            felder[1][2].push_back(Position(0, 0));//_#__
            felder[1][2].push_back(Position(0, 1));//_###
            felder[1][2].push_back(Position(1, 1));//___#
            felder[1][2].push_back(Position(2, 1));//____
            felder[1][2].push_back(Position(2, 2));

            felder[1][3].push_back(Position(2, 0));//__##
            felder[1][3].push_back(Position(1, 0));//__#_
            felder[1][3].push_back(Position(1, 1));//_##_
            felder[1][3].push_back(Position(1, 2));//____
            felder[1][3].push_back(Position(0, 2));

            break;
        }
        case SPIELSTEIN_L2:
        {
            name = "L2";
            farbe = HINTERGRUND_LILA;
            felder[0][0].push_back(Position(1, 0));//_#__
            felder[0][0].push_back(Position(1, 1));//_##_
            felder[0][0].push_back(Position(2, 1));//____
                                                   //____

            felder[0][1].push_back(Position(2, 0));//__#_
            felder[0][1].push_back(Position(1, 1));//_##_
            felder[0][1].push_back(Position(2, 1));//____
                                                   //____

            felder[0][2].push_back(Position(1, 0));//_##_
            felder[0][2].push_back(Position(2, 0));//__#_
            felder[0][2].push_back(Position(2, 1));//____
                                                   //____

            felder[0][3].push_back(Position(1, 0));//_##_
            felder[0][3].push_back(Position(2, 0));//_#__
            felder[0][3].push_back(Position(1, 1));//____
                                                   //____

            felder[1][0].push_back(Position(2, 0));//__#_
            felder[1][0].push_back(Position(1, 1));//_##_
            felder[1][0].push_back(Position(2, 1));//____
                                                   //____

            felder[1][1].push_back(Position(1, 0));//_##_
            felder[1][1].push_back(Position(2, 0));//__#_
            felder[1][1].push_back(Position(2, 1));//____
                                                   //____

            felder[1][2].push_back(Position(1, 0));//_##_
            felder[1][2].push_back(Position(2, 1));//_#__
            felder[1][2].push_back(Position(1, 1));//____
                                                   //____

            felder[1][3].push_back(Position(1, 0));//_#__
            felder[1][3].push_back(Position(1, 1));//_##_
            felder[1][3].push_back(Position(2, 1));//____
                                                   //____

            break;
        }
        case SPIELSTEIN_L3:
        {
            name = "L3";
            farbe = HINTERGRUND_HELL_ROT;
            felder[0][0].push_back(Position(1, 0));//_#__
            felder[0][0].push_back(Position(1, 1));//_#__
            felder[0][0].push_back(Position(1, 2));//_##_
            felder[0][0].push_back(Position(2, 2));//____

            felder[0][1].push_back(Position(3, 1));//____
            felder[0][1].push_back(Position(1, 2));//___#
            felder[0][1].push_back(Position(2, 2));//_###
            felder[0][1].push_back(Position(3, 2));//____

            felder[0][2].push_back(Position(1, 0));//_##_
            felder[0][2].push_back(Position(2, 0));//__#_
            felder[0][2].push_back(Position(2, 1));//__#_
            felder[0][2].push_back(Position(2, 2));//____

            felder[0][3].push_back(Position(1, 1));//____
            felder[0][3].push_back(Position(2, 1));//_###
            felder[0][3].push_back(Position(3, 1));//_#__
            felder[0][3].push_back(Position(1, 2));//____

            felder[1][0].push_back(Position(2, 0));//__#_
            felder[1][0].push_back(Position(2, 1));//__#_
            felder[1][0].push_back(Position(1, 2));//_##_
            felder[1][0].push_back(Position(2, 2));//____

            felder[1][1].push_back(Position(1, 1));//____
            felder[1][1].push_back(Position(2, 1));//_###
            felder[1][1].push_back(Position(3, 1));//___#
            felder[1][1].push_back(Position(3, 2));//____

            felder[1][2].push_back(Position(1, 0));//_##_
            felder[1][2].push_back(Position(2, 0));//_#__
            felder[1][2].push_back(Position(1, 1));//_#__
            felder[1][2].push_back(Position(1, 2));//____

            felder[1][3].push_back(Position(1, 1));//____
            felder[1][3].push_back(Position(1, 2));//_#__
            felder[1][3].push_back(Position(2, 2));//_###
            felder[1][3].push_back(Position(3, 2));//____

            break;
        }
        case SPIELSTEIN_L4:
        {
            name = "L4";
            farbe = HINTERGRUND_HELL_GELB;
            felder[0][0].push_back(Position(1, 0));//_#__
            felder[0][0].push_back(Position(1, 1));//_#__
            felder[0][0].push_back(Position(1, 2));//_#__
            felder[0][0].push_back(Position(1, 3));//_##_
            felder[0][0].push_back(Position(2, 3));

            felder[0][1].push_back(Position(3, 1));//____
            felder[0][1].push_back(Position(0, 2));//___#
            felder[0][1].push_back(Position(1, 2));//####
            felder[0][1].push_back(Position(2, 2));//____
            felder[0][1].push_back(Position(3, 2));

            felder[0][2].push_back(Position(1, 0));//_##_
            felder[0][2].push_back(Position(2, 0));//__#_
            felder[0][2].push_back(Position(2, 1));//__#_
            felder[0][2].push_back(Position(2, 2));//__#_
            felder[0][2].push_back(Position(2, 3));

            felder[0][3].push_back(Position(0, 1));//____
            felder[0][3].push_back(Position(1, 1));//####
            felder[0][3].push_back(Position(2, 1));//#___
            felder[0][3].push_back(Position(3, 1));//____
            felder[0][3].push_back(Position(0, 2));


            felder[1][0].push_back(Position(2, 0));//__#_
            felder[1][0].push_back(Position(2, 1));//__#_
            felder[1][0].push_back(Position(2, 2));//__#_
            felder[1][0].push_back(Position(1, 3));//_##_
            felder[1][0].push_back(Position(2, 3));

            felder[1][1].push_back(Position(0, 1));//____
            felder[1][1].push_back(Position(1, 1));//####
            felder[1][1].push_back(Position(2, 1));//___#
            felder[1][1].push_back(Position(3, 1));//____
            felder[1][1].push_back(Position(3, 2));

            felder[1][2].push_back(Position(1, 0));//_##_
            felder[1][2].push_back(Position(2, 0));//_#__
            felder[1][2].push_back(Position(1, 1));//_#__
            felder[1][2].push_back(Position(1, 2));//_#__
            felder[1][2].push_back(Position(1, 3));

            felder[1][3].push_back(Position(0, 1));//____
            felder[1][3].push_back(Position(0, 2));//#___
            felder[1][3].push_back(Position(1, 2));//####
            felder[1][3].push_back(Position(2, 2));//____
            felder[1][3].push_back(Position(3, 2));

            break;
        }
        case SPIELSTEIN_I2:
        {
            name = "I2";
            farbe = HINTERGRUND_HELL_LILA;
            felder[0][0].push_back(Position(1, 1));//____
            felder[0][0].push_back(Position(1, 2));//_#__
                                                   //_#__
                                                   //____

            felder[0][1].push_back(Position(1, 1));//____
            felder[0][1].push_back(Position(2, 1));//_##_
                                                   //____
                                                   //____

            felder[0][2].push_back(Position(1, 1));//____
            felder[0][2].push_back(Position(1, 2));//_#__
                                                   //_#__
                                                   //____

            felder[0][3].push_back(Position(1, 1));//____
            felder[0][3].push_back(Position(2, 1));//_##_
                                                   //____
                                                   //____

            break;
        }
        case SPIELSTEIN_I3:
        {
            name = "I3";
            farbe = HINTERGRUND_HELL_GELB;
            felder[0][0].push_back(Position(1, 0));//_#__
            felder[0][0].push_back(Position(1, 1));//_#__
            felder[0][0].push_back(Position(1, 2));//_#__
                                                   //____

            felder[0][1].push_back(Position(1, 1));//____
            felder[0][1].push_back(Position(2, 1));//###_
            felder[0][1].push_back(Position(3, 1));//____
                                                   //____

            felder[0][2].push_back(Position(1, 0));//_#__
            felder[0][2].push_back(Position(1, 1));//_#__
            felder[0][2].push_back(Position(1, 2));//_#__
                                                   //____

            felder[0][3].push_back(Position(1, 1));//____
            felder[0][3].push_back(Position(2, 1));//###_
            felder[0][3].push_back(Position(3, 1));//____
                                                   //____

            break;
        }
        case SPIELSTEIN_I4:
        {
            name = "I4";
            farbe = HINTERGRUND_BLAU;
            felder[0][0].push_back(Position(1, 0));//_#__
            felder[0][0].push_back(Position(1, 1));//_#__
            felder[0][0].push_back(Position(1, 2));//_#__
            felder[0][0].push_back(Position(1, 3));//_#__

            felder[0][1].push_back(Position(0, 1));//____
            felder[0][1].push_back(Position(1, 1));//####
            felder[0][1].push_back(Position(2, 1));//____
            felder[0][1].push_back(Position(3, 1));//____

            felder[0][2].push_back(Position(1, 0));//_#__
            felder[0][2].push_back(Position(1, 1));//_#__
            felder[0][2].push_back(Position(1, 2));//_#__
            felder[0][2].push_back(Position(1, 3));//_#__

            felder[0][3].push_back(Position(0, 1));//____
            felder[0][3].push_back(Position(1, 1));//####
            felder[0][3].push_back(Position(2, 1));//____
            felder[0][3].push_back(Position(3, 1));//____

            break;
        }
        case SPIELSTEIN_Q:
        {
            name = "Q";
            farbe = HINTERGRUND_HELL_ROT;
            felder[0][0].push_back(Position(1, 1));//##__
            felder[0][0].push_back(Position(2, 1));//##__
            felder[0][0].push_back(Position(1, 2));
            felder[0][0].push_back(Position(2, 2));

            felder[0][1].push_back(Position(0, 0));//##__
            felder[0][1].push_back(Position(1, 0));//##__
            felder[0][1].push_back(Position(0, 1));
            felder[0][1].push_back(Position(1, 1));

            felder[0][2].push_back(Position(0, 0));//##__
            felder[0][2].push_back(Position(1, 0));//##__
            felder[0][2].push_back(Position(0, 1));
            felder[0][2].push_back(Position(1, 1));

            felder[0][3].push_back(Position(0, 0));//##__
            felder[0][3].push_back(Position(1, 0));//##__
            felder[0][3].push_back(Position(0, 1));
            felder[0][3].push_back(Position(1, 1));

            felder[0][3].push_back(Position(0, 0));//##__
            felder[0][3].push_back(Position(1, 0));//##__
            felder[0][3].push_back(Position(0, 1));
            felder[0][3].push_back(Position(1, 1));

            break;
        }
        case SPIELSTEIN_QPLUS: //GECHECKT
        {
            name = "QPLUS";
            farbe = HINTERGRUND_HELL_GELB;
            felder[0][0].push_back(Position(1, 0));//#_
            felder[0][0].push_back(Position(1, 1));//##__
            felder[0][0].push_back(Position(2, 1));//##__
            felder[0][0].push_back(Position(1, 2));
            felder[0][0].push_back(Position(2, 2));

            felder[0][1].push_back(Position(1, 0));//###_
            felder[0][1].push_back(Position(2, 0));//##__
            felder[0][1].push_back(Position(3, 0));
            felder[0][1].push_back(Position(1, 1));
            felder[0][1].push_back(Position(2, 1));

            felder[0][2].push_back(Position(1, 0));//##__
            felder[0][2].push_back(Position(2, 0));//##__
            felder[0][2].push_back(Position(1, 1));//#_
            felder[0][2].push_back(Position(2, 1));
            felder[0][2].push_back(Position(2, 2));

            felder[0][3].push_back(Position(2, 0));//##_
            felder[0][3].push_back(Position(3, 0));//###__
            felder[0][3].push_back(Position(1, 1));
            felder[0][3].push_back(Position(2, 1));
            felder[0][3].push_back(Position(3, 1));

            felder[1][0].push_back(Position(2, 0));//#_
            felder[1][0].push_back(Position(1, 1));//##__
            felder[1][0].push_back(Position(2, 1));//##__
            felder[1][0].push_back(Position(1, 2));
            felder[1][0].push_back(Position(2, 2));

            felder[1][1].push_back(Position(1, 0));//##__
            felder[1][1].push_back(Position(2, 0));//###_
            felder[1][1].push_back(Position(1, 1));
            felder[1][1].push_back(Position(2, 1));
            felder[1][1].push_back(Position(3, 1));

            felder[1][2].push_back(Position(1, 0));//##__
            felder[1][2].push_back(Position(2, 0));//##__
            felder[1][2].push_back(Position(1, 1));//#_
            felder[1][2].push_back(Position(2, 1));
            felder[1][2].push_back(Position(2, 2));

            felder[1][3].push_back(Position(1, 0));//###__
            felder[1][3].push_back(Position(2, 0));//##_
            felder[1][3].push_back(Position(3, 0));
            felder[1][3].push_back(Position(2, 1));
            felder[1][3].push_back(Position(3, 1));

            break;
        }
        case SPIELSTEIN_T:
        {
            name = "T";
            farbe = HINTERGRUND_HELL_BLAU;
            felder[0][0].push_back(Position(1, 0));//_#__
            felder[0][0].push_back(Position(1, 1));//_##_
            felder[0][0].push_back(Position(2, 1));//_#__
            felder[0][0].push_back(Position(1, 2));//____

            felder[0][1].push_back(Position(0, 1));
            felder[0][1].push_back(Position(1, 1));
            felder[0][1].push_back(Position(1, 0));
            felder[0][1].push_back(Position(2, 1));

            felder[0][2].push_back(Position(1, 2));
            felder[0][2].push_back(Position(1, 1));
            felder[0][2].push_back(Position(0, 1));
            felder[0][2].push_back(Position(1, 0));

            felder[0][3].push_back(Position(2, 0));
            felder[0][3].push_back(Position(1, 0));
            felder[0][3].push_back(Position(1, 1));
            felder[0][3].push_back(Position(0, 0));

            felder[1][0].push_back(Position(1, 0));
            felder[1][0].push_back(Position(1, 1));
            felder[1][0].push_back(Position(0, 1));
            felder[1][0].push_back(Position(1, 2));

            felder[1][1].push_back(Position(0, 0));
            felder[1][1].push_back(Position(1, 0));
            felder[1][1].push_back(Position(1, 1));
            felder[1][1].push_back(Position(2, 0));

            felder[1][2].push_back(Position(0, 2));
            felder[1][2].push_back(Position(0, 1));
            felder[1][2].push_back(Position(1, 1));
            felder[1][2].push_back(Position(0, 0));

            felder[1][3].push_back(Position(2, 1));
            felder[1][3].push_back(Position(1, 1));
            felder[1][3].push_back(Position(1, 0));
            felder[1][3].push_back(Position(0, 1));

            break;
        }
        case SPIELSTEIN_TPLUS:
        {
            name = "TPLUS";
            farbe = HINTERGRUND_ROT;
            felder[0][0].push_back(Position(1, 0));//_#__
            felder[0][0].push_back(Position(1, 1));//_##_
            felder[0][0].push_back(Position(2, 1));//_#__
            felder[0][0].push_back(Position(1, 2));//_#__
            felder[0][0].push_back(Position(1, 3));

            felder[0][1].push_back(Position(0, 1));
            felder[0][1].push_back(Position(1, 1));
            felder[0][1].push_back(Position(1, 0));
            felder[0][1].push_back(Position(2, 1));
            felder[0][1].push_back(Position(3, 1));

            felder[0][2].push_back(Position(1, 3));
            felder[0][2].push_back(Position(1, 2));
            felder[0][2].push_back(Position(0, 2));
            felder[0][2].push_back(Position(1, 1));
            felder[0][2].push_back(Position(1, 0));

            felder[0][3].push_back(Position(3, 0));
            felder[0][3].push_back(Position(2, 0));
            felder[0][3].push_back(Position(2, 1));
            felder[0][3].push_back(Position(1, 0));
            felder[0][3].push_back(Position(0, 0));

            felder[1][0].push_back(Position(1, 0));
            felder[1][0].push_back(Position(1, 1));
            felder[1][0].push_back(Position(0, 1));
            felder[1][0].push_back(Position(1, 2));
            felder[1][0].push_back(Position(1, 3));

            felder[1][1].push_back(Position(0, 0));
            felder[1][1].push_back(Position(1, 0));
            felder[1][1].push_back(Position(1, 1));
            felder[1][1].push_back(Position(2, 0));
            felder[1][1].push_back(Position(3, 0));

            felder[1][2].push_back(Position(0, 3));
            felder[1][2].push_back(Position(0, 2));
            felder[1][2].push_back(Position(1, 2));
            felder[1][2].push_back(Position(0, 1));
            felder[1][2].push_back(Position(0, 0));

            felder[1][3].push_back(Position(3, 1));
            felder[1][3].push_back(Position(2, 1));
            felder[1][3].push_back(Position(2, 0));
            felder[1][3].push_back(Position(1, 1));
            felder[1][3].push_back(Position(0, 1));

            break;
        }
        case SPIELSTEIN_FREI:
        {
            name = "FREI";
            farbe = HINTERGRUND_HELL_GRAU;
            break;
        }
        case SPIELSTEIN_LOESUNG:
        {
            name = "LOESUNG";
            farbe = HINTERGRUND_HELL_WEISS;
            felder[0][0].push_back(Position(2, 0)); //__##_
            felder[0][0].push_back(Position(3, 0));	//__###
            felder[0][0].push_back(Position(2, 1)); //__###
            felder[0][0].push_back(Position(3, 1)); //#####
            felder[0][0].push_back(Position(4, 1)); //_####
            felder[0][0].push_back(Position(2, 2));
            felder[0][0].push_back(Position(3, 2));
            felder[0][0].push_back(Position(4, 2));
            felder[0][0].push_back(Position(0, 3));
            felder[0][0].push_back(Position(1, 3));
            felder[0][0].push_back(Position(2, 3));
            felder[0][0].push_back(Position(3, 3));
            felder[0][0].push_back(Position(4, 3));
            felder[0][0].push_back(Position(1, 4));
            felder[0][0].push_back(Position(2, 4));
            felder[0][0].push_back(Position(3, 4));
            felder[0][0].push_back(Position(4, 4));


            break;
        }
        default:
            break;
        }
}
void Spielstein::zeichne()
{
    Cursor::setze_Farbe(farbe);
    for (auto k : *getPositionen())
    {
        Console::zeichne_punkt(position.getX() + 1 + k.getX(),position.getY() + k.getY() + 1, ' ');
    }
    Cursor::setze_Farbe(HINTERGRUND_SCHWARZ);
}
void Spielstein::loesche()
{
    Cursor::setze_Farbe(HINTERGRUND_SCHWARZ);
    for (auto k : *getPositionen())
    {
        Console::zeichne_punkt(position.getX() + k.getX() + 1, position.getY() + k.getY() + 1, ' ');
    }
}


void Spielstein::bewegen(int richtung)
{
    switch (richtung)
    {
        case CONFIGURATION::SPIELSTEIN_BEWEGEN_HOCH:
        {
            if (position.getY() != 0)
            {
                position.setY(position.getY() - 1);
                break;
            }
        }
        case CONFIGURATION::SPIELSTEIN_BEWEGEN_RUNTER:
        {
            if (position.getY() != 0)
            {
                position.setY(position.getY() + 1);
                break;
            }
        }
        case CONFIGURATION::SPIELSTEIN_BEWEGEN_LINKS:
        {
            if (position.getX() != 0)
            {
                position.setX(position.getX() - 1);
                break;
            }
        }
        case CONFIGURATION::SPIELSTEIN_BEWEGEN_RECHTS:
            if (position.getX() != 0)
            {
                position.setX(position.getX() + 1);
                break;
            }
    }
}
//Inkrementiert das Attribut orientierung um 1, wobei stets Werte zwischen 0 und 3 angenommen werden.
void Spielstein::rotation_rechts() //Decrease
{
    orientierung--;
    if (orientierung < 0)
    {
        orientierung = 3;
    }
}
//Dekrementiert das Attribut orientierung um 1, wobei stets Werte zwischen 0 und 3 angenommen werden.
void Spielstein::rotation_links() //Increase
{
    orientierung++;
    if (orientierung >= 4)
    {
        orientierung = 0;
    }
}
//Inkrementiert das Attribut seite um 1, wobei stets Werte zwischen 0 und 1 angenommen werden.
void Spielstein::flip()
{
    if (seite == 0)
    {
        seite = 1;
    }
    else if (seite == 1)
    {
        seite = 0;
    }
}

//Gibt den felder Vektor der aktuellen Lage des Spielsteins zur�ck.
std::vector<Position>* Spielstein::getPositionen()
{
    return felder[seite] + orientierung;
}

//Durchl�uft den felder Vektor des Spielsteins in aktueller Lage.
//Gibt true zur�ck, falls die �bergebene Position innerhalb des Spielsteines liegt.
//Ansonsten wird false zur�ckgegeben.
bool Spielstein::innerhalb(Position pos)
{
    // check if pos is within bounds of this
    for (Position i : *getPositionen()) //removed const as it led to problems
    {
        if (pos == i + position)
        {
            return true;
        }
    }
    return false;
}

//Gibt war zur�ck, falls sich der aufrufende und der �bergebene Spielstein sich in mindestens einer Position �berlappen.
bool Spielstein::ueberlapp(Spielstein& sp)
{
    for (Position i : *getPositionen())
    {
        for (Position j : *(sp.getPositionen()))
        {
            if (i == j)
            {
                return true;
            }
        }
    }
    return false;
}

//Addiert zwei Spielsteine in ihrer aktuellen Lage und gibt die Summe als neuen Spielstein zur�ck.
Spielstein Spielstein::operator+ (Spielstein& rhs) //const removed
{
    Spielstein summe(SPIELSTEIN_FREI);

    for (auto i : *getPositionen())
    {
        summe.felder[0][0].push_back(i);
    }
    for (auto j : *rhs.getPositionen())
    {
        summe.felder[0][0].push_back(j);
    }
    return summe;
} //overlapping issue needs to be solved

void Spielstein::setX(int x)
{
    position.setX(x);
}

void Spielstein::setY(int y)
{
    position.setY(y);
}


void Spielstein::setPosition(Position position) //no idea why we need this
{
    this->position = position;
}

Position Spielstein::getPosition() //this too lmao
{
    return position;
}

std::string Spielstein::getFarbe()
{
    return farbe;
}

void Spielstein::setOrientierung(int orientierung)
{
    this->orientierung = orientierung;
}

void Spielstein::setSeite(int seite)
{
    this->seite = seite;
}
