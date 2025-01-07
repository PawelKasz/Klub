#include "wiatr.h"
// #include "skrzydlo.h"
// #include "dialog.h"
#include <QDebug>
//     #include <QMainWindow>

Wiatr::Wiatr(int kierunek_wiatru,int otrzmany_kierunek_wiatru, Wiatr *p){

    connect(this, SIGNAL(wiatrSignal()), p, SLOT(obliczKier_wiatru()));
}

strzalka *Wiatr::GetStrzalka() const
{
    return m_strzalka;
}

// void Wiatr::wiatrSignal(int){       //sygnal
//     qDebug() << "klokol";
//}
int Wiatr::ustawWartosc_wiatr(){    //wywolywane teraz w main.cpp wyk1

    int a = 5;
    qDebug() << "klokoloooo";
   // emit wiatrSignal();
    return a;
}

void Wiatr::UstawKierunek(int kierunek) //slot. wywolywane przez slider
{
    qDebug() << "Wiatr ma ustawiony kierunek = " << kierunek;
    // Tutaj mozemy przekazc wartość kąta ze slidera do strzalki.
    // ...
    //strzalka::narysuj_strz();
    kierunek_wiatru = kierunek;
    qDebug() << "kierunek_wiatru - " << kierunek_wiatru;
    m_strzalka->SetPozycja(-150, 150);
    //m_strzalka->rysStrz(100, 100);

    for(int i=0 ; i<50 ; i=i+10){
    m_strzalka->narysuj_strz();
    m_strzalka->SetPozycja(i+10, i+20);

    }
    qDebug() << " KI " << kierunek_wiatru;
    //obliczKier_wiatru(kierunek_wiatru);
}

int Wiatr::obliczKier_wiatru(int kier){
    qDebug() << "wyp z obliczKier_wiatru";
    otrzymany_kier_wiatr = kier;
    return otrzymany_kier_wiatr;
}

