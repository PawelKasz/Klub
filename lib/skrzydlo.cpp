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
}

Punkt skrzydlo::GetPoczatek() const
{
    float bok_a = 0;
    float bok_b = 0;
    //int zap_sr_x = m_srodek.x;
    //int zap_sr_y = m_srodek.y;
    int pocz_s_x;
    int pocz_s_y;

    //Punkt tmp_srodek = m_srodek;

    if (m_kat==0){
        int poczPlata = m_srodek.x - m_dlugosc;
        qDebug( )<< "PoczPlata" << poczPlata;
        return {poczPlata, 0};
    }
    else if(m_kat!=0){
        if (m_kat >0 && m_kat <=90){
            //bok = qDegreesToRadians(kat);
            bok_a = m_dlugosc * cos(qDegreesToRadians(m_kat));
            qDebug()<< "X- " << bok_a ;
            bok_b = (m_dlugosc * m_dlugosc) - pow(bok_a,2) /* (bok_a * bok_a)*/;
            bok_b = roundevenf(bok_b);
            bok_b = sqrt(bok_b);
            qDebug() << "Y- " << bok_b ;

            pocz_s_x = bok_a;
            pocz_s_y = bok_b;
            return {pocz_s_x, pocz_s_y};
        }
        else if(m_kat > 90 && m_kat <= 180){

            bok_a = m_dlugosc * cos(qDegreesToRadians(m_kat));

            //qDebug()<< "X- " << bok_a ;
            bok_b = (m_dlugosc * m_dlugosc) - pow(bok_a,2);
            bok_b = roundevenf(bok_b);
            bok_b = sqrt(bok_b);

            bok_b = bok_b -(bok_b+bok_b)+1;
            qDebug() << "Y- " << bok_b ;

            pocz_s_x = bok_a;
            pocz_s_y = bok_b;
            return {pocz_s_x, pocz_s_y};
        }
        else if(m_kat > 180 && m_kat <=270){
            bok_a = m_dlugosc * cos(qDegreesToRadians(m_kat));

            //qDebug()<< "X- " << bok_a ;
            bok_b = (m_dlugosc * m_dlugosc) - pow(bok_a,2);
            bok_b = roundevenf(bok_b);
            bok_b = sqrt(bok_b);
            bok_b = bok_b -(bok_b+bok_b);
            qDebug() << "Y- " << bok_b ;

            pocz_s_x = bok_a;
            pocz_s_y = bok_b;
            return {pocz_s_x, pocz_s_y};
        }
    }

    return {};
}

Punkt skrzydlo::GetPoczatek2Ver() const
{
    int pocz_s_x;
    int pocz_s_y;

    //Punkt tmp_srodek = m_srodek;

    if (m_kat==0){
        int poczPlata = m_srodek.x - m_dlugosc;
        qDebug( )<< "PoczPlata" << poczPlata;
        return {poczPlata, 0};
    }
    else {
        pocz_s_x = m_dlugosc * sin(qDegreesToRadians(m_kat));
        pocz_s_y = m_dlugosc * cos(qDegreesToRadians(m_kat));

        qDebug() << "Test ";

        return {pocz_s_x, pocz_s_y};
    }

}

Punkt skrzydlo::GetKoniec() const
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

//void skrzydlo::rysujPlat(int srodekPlata[]){
    //for (int i=0; i<2;i++){
        //int xy1 = srodekPlata[i];
        //int xy2 = srodekPlata[i+1];
        //poczPlata[i] = xy1 - 15;
        //konePlata[i] = xy2 + 25;

        //qDebug() << "= skonePlata[i]";
//    }
//}

Punkt skrzydlo::srodek() const
{
    return m_srodek;
}

void skrzydlo::slotLot(){
    qDebug() << "Wypis z slotLot ";

}
