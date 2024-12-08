#ifndef PLAT_H
#define PLAT_H

#include <QObject>

struct Moje_dane    //przykladowa struktura
{
    int wynik1;
    int wynik2;
    std::string wynik_txt;
};

class plat : public QObject //deklaracja klasy plat
{
    Q_OBJECT
public:     //skladniki klasy plat
    //explicit plat(QObject *parent = nullptr);
    //plat();     //Deklaracja konstruktora


    // int num_plata;  //To zastąpi nazwę
    // int kont_natarcia; //Tymczasowe wpisanie wartosci
    // int sila_nosna;
    // int wychyl_lotki;
    // int srodekPlata[2]={0,0};
    // int poczPlata[2];
    // int konePlata[2];
    // char str;
            //metody klasy plat
    short oblicza_kon(int wychyl_lotki, int kont_natarcia);       //Oblicza kont natarcia plata
    Moje_dane Funkcja();
    void rysujLotke();
    void rysujPlat(int srodekPlata[]);




signals:
    void mySignals();

private slots:
    //void on_pushButon();
    void mojSlot();

/*
plat(int, int wychyl_lotki, int sila_nosna)
{
    //num_plata = 1;
    wychyl_lotki = 0;
}
*/
};
#endif // PLAT_H
