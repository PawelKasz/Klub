#ifndef PLAT_H
#define PLAT_H

#include <QObject>

struct Moje_dane
{
    int wynik1;
    int wynik2;
    std::string wynik_txt;
};

class plat : public QObject
{
    Q_OBJECT

public:
    //explicit plat(QObject *parent = nullptr);

    int num_plata;  //To zastąpi nazwę
    int kont_natarcia; //Tymczasowe wpisanie wartosci
    int sila_nosna;
    int wychyl_lotki;

    short oblicza_kon(int wychyl_lotki, int kont_natarcia);       //Oblicza kont natarcia plata

    Moje_dane Funkcja();

signals:


};

#endif // PLAT_H
