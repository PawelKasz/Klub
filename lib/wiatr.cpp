#include "wiatr.h"
// #include "skrzydlo.h"
// #include "dialog.h"
#include <QDebug>
//     #include <QMainWindow>

Wiatr::Wiatr(int kierunek_wiatru,int otrzmany_kierunek_wiatru, Wiatr *p){

    connect(this, SIGNAL(wiatrSignal()), p, SLOT(ustawWartosc()));
}

// void Wiatr::wiatrSignal(int){       //sygnal
//     qDebug() << "klokol";
// }
void Wiatr::ustawWartosc(){     //slot
qDebug() << "klokoloooo";
    emit wiatrSignal();
}

int Wiatr::obliczKier_wiatru(){


    return otrzymany_kier_wiatr;
}

void Wiatr::rysuj_strzalke(){


}
