#include "skrzydlo.h"
#include <QDebug>

skrzydlo::skrzydlo(Punkt srodek, int dlugosc, float kat):m_srodek(srodek), m_dlugosc(dlugosc), m_kat(kat)
{
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

void skrzydlo::slotLot(){
    qDebug() << "Wypis z slotLot ";

}
