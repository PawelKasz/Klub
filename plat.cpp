#include <QDebug>

#include "plat.h"

short plat::oblicza_kon( int wychyl_lotki, int kont_natarcia ){

    if (wychyl_lotki > 0)
    {
        kont_natarcia += wychyl_lotki;
    }
    else if(wychyl_lotki < 0)
    {
        kont_natarcia -= wychyl_lotki;
    }
    else if(wychyl_lotki == 0)
    {
            }
    return kont_natarcia;
}
/*
Moje_dane plat::Funkcja()
{
    Moje_dane rezultat;

    rezultat.wynik1 = 123;
    rezultat.wynik2 = 998;
    rezultat.wynik_txt = "Ala ma kota";

    return rezultat;
}
*/
