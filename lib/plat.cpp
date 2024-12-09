#include "plat.h"
#include <QDebug>

//plat::plat(QObject *parent)
//    : QObject{parent}
//{

void plat::mojSlot()
{
    qDebug() << "Wypis z mojSlot";

}



short plat::oblicza_kon( int wychyl_lotki, int kont_natarcia ){

    if (wychyl_lotki > 0)
    {
        kont_natarcia += wychyl_lotki;
        qDebug() << "Wypis z oblicza_kon";

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

void plat::rysujLotke(){

}

void plat::rysujPlat(int srodekPlata[]){
    for (int i=0; i<2;i++){
        int xy1 = srodekPlata[i];
        int xy2 = srodekPlata[i+1];
        //poczPlata[i] = xy1 - 15;
        //konePlata[i] = xy2 + 25;

        qDebug() << "= skonePlata[i]";

    }
}

Moje_dane plat::Funkcja()
{

}

//return 0;
//}
