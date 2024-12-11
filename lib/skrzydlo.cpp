#include "skrzydlo.h"
#include <QDebug>
#include <math.h>

skrzydlo::skrzydlo(Punkt srodek, int dlugosc, float kat):m_srodek(srodek), m_dlugosc(dlugosc), m_kat(kat)
{
    /*
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
    */
    float bok_a = 0;
    float bok_b = 0;
    int zap_sr_x = srodek.x;
    int zap_sr_y = srodek.y;
    int pocz_s_x;
    int pocz_s_y;

    srodek.x = 0;
    srodek.y = 0;
    kat = 5;   //tymczasowo dla testów
    if (kat==0){
     int poczPlata = srodek.x - dlugosc;
        qDebug( )<< "PoczPlata" << poczPlata;
    }
    else if(kat!=0){
        if (kat >0 && kat <=90){
            //bok = qDegreesToRadians(kat);
            bok_a = dlugosc * sin(qDegreesToRadians(kat));
        qDebug()<< "X- " << bok_a ;
        bok_b = (dlugosc * dlugosc) - pow(bok_a,2) /* (bok_a * bok_a)*/;
        bok_b = sqrt(bok_b);
        bok_b = roundevenf(bok_b);
        qDebug() << "Y- " << bok_b ;

        pocz_s_x = bok_a;
        pocz_s_y = bok_b;
        }
        else if(kat <90 && kat <=180){

        }
    }


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
