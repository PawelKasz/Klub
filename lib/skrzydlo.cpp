#include "skrzydlo.h"
#include <QDebug>
#include <math.h>

skrzydlo::skrzydlo(Punkt srodek, int dlugosc, float kat):m_srodek(srodek), m_dlugosc(dlugosc), m_kat(kat)
{
    double radians=1.04720, degres;
    double stopni = qRadiansToDegrees(radians);
    qDebug() << "Stopni " <<stopni;

    Punkt x;

    int a =0;
    qDebug() << a;
    a = srodek.x + srodek.y;
    qDebug() << a;
    qDebug() << srodek.x;
    qDebug() << srodek.y;
}

Punkt skrzydlo::GetPoczatek() const
{


    return{-1, -1};
}

Punkt skrzydlo::GetKoniec() const
{

}
skrzydlo::skrzydlo(): num_plata(2), sila_nosna(5)
{


}

short skrzydlo::oblicza_kont( int wychyl_lotki, int kont_natarcia ){

    if (wychyl_lotki > 0)
    {
        kont_natarcia += wychyl_lotki;
        qDebug() << "Wypis z oblicza_kon";
    }
    else if(wychyl_lotki < 0)
    {
        kont_natarcia -= wychyl_lotki;
    }
    //else if(wychyl_lotki == 0)
    //{
    //}
    return kont_natarcia;
}
void skrzydlo::rysujLotke(){
    qDebug() << "Wypis z rysujLotke ";
}

void skrzydlo::rysujPlat(int srodekPlata[]){
    for (int i=0; i<2;i++){
        int xy1 = srodekPlata[i];
        int xy2 = srodekPlata[i+1];
        //poczPlata[i] = xy1 - 15;
        //konePlata[i] = xy2 + 25;

        qDebug() << "= skonePlata[i]";

    }
}

Punkt skrzydlo::srodek() const
{
    return m_srodek;
}

void skrzydlo::slotLot(){
    qDebug() << "Wypis z slotLot ";

}
