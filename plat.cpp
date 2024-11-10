#include "plat.h"
#include <QDebug>

//plat::plat(QObject *parent)
//    : QObject{parent}
//{

     short oblicza_kon( int wychyl_lotki, int kont_natarcia ){

         if (wychyl_lotki > 0)
             {
                kont_natarcia = kont_natarcia + wychyl_lotki;
             }
         else if(wychyl_lotki < 0)
                 {
                 kont_natarcia = kont_natarcia - wychyl_lotki;
                 }
         else if(wychyl_lotki == 0)
             {
                kont_natarcia = kont_natarcia - wychyl_lotki;
             }
        return kont_natarcia;
    }


    //return 0;
//}
