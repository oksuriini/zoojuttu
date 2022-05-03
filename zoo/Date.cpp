#pragma once
#include "Date.h"

//Date toiminnassa, testattu hiukan.

Date::Date(int d, int m, int y)
{    
    if (!setValues(d, m, y)) {
        setValues(1, 1, 2022);
    }
}

bool Date::checkValues(int d, int m, int y)
{
    bool isLeap;
    if (((y % 4 == 0) &&
            (y % 100 != 0)) ||
        (y % 400 == 0)) {
        isLeap = true;
        }
    else { isLeap = false;}
    
    

    /*
    Tarkastetaan eka onko hyppyvuosi:
    Jaetaan vuosi 4:llä  -> Jos on jakojäännöstä = ei ole hyppyvuosi.
    Muuten -> Jaetaan vuosi 100 -> jos jakojäännöstä = on hyppyvuosi.
    Muuten -> Jaetaan vuosi 400 -> jos jakojäännöstä = ei ole hyppyvuosi.
    Muuten -> On hyppyvuosi.
    Jos on hyppyvuosi, niin asetetaan muuttuja leapyear = true

    Tarkistetaan onko validi vuosi:
    Onko vuosi välillä 1970 - 2038:
    Jos on = on validi.
    Jos ei = ei ole validi.
    */

    const int max_vuosi = 2038;
    const int min_vuosi = 1970;

    if (y > max_vuosi || y < min_vuosi)
        return false;

    /*
    Tarkastetaan onko validi kuukausi:
    Onko välillä 1 - 12:
    Jos on = on validi.
    Muuten -> ei ole
    */
    // tarkastetaan onko kuukausi välillä 1 - 12
    const int max_kk = 12;
    const int min_kk = 1;
    if (m < min_kk || m > max_kk) {
        return false;
    }


    /*
    Muistio:
  kk         päivien lukumäärä
   1 Tammi,  31pv
   2 Helmi,  28pv   hyppy: 29pv
   3 Maali,  31pv
   4 Huhti,  30pv
   5 Touko,  31pv
   6 Kesä,   30pv
   7 Heinä,  31pv
   8 Elo,    31pv
   9 Syys,   30pv
  10 Loka,   31pv
  11 Marras, 30pv
  12 Joulu   31pv
    Tarkastetaan onko validi päivä:
    Onko päivä välillä 1 - 31, jos ei ole = ei ole validi.
    Muuten -> tarkastetaan mitä kuukausi on -> tarkastetaan ylittääkö päivä kuukauden maksimi arvon
    jos ylittää = ei ole validi, muuten on validi. Helmikuun yhteydessä tarkastetaan myös hyppyvuosi.
    */
    
    if (d < 1 || d > 31) {
        return false;
    }
    else {
        //Tarkastetaan onko päivä validi kyseisenä kuukautena
        switch (m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return true;
        case 4:
        case 6:
        case 9:
        case 11:
            if (d < 31) {
                return true;
            }
            else {
                return false;
            }
        case 2:
            if (d < 29) {
                return true;
            }
            else if (d < 30 && isLeap) {
                return true;
            }
            else{
                return false;
            }
        default:
            break;
        }
    }
    return false;
}

bool Date::setValues(int d, int m, int y)
{
    if (!checkValues(d, m, y)) {
        return false;
    }
    this->d = d;
    this->m = m;
    this->y = y;
    return true;
}
