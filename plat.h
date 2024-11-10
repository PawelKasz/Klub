#ifndef PLAT_H
#define PLAT_H

#include <QObject>

class plat : public QObject
{
    Q_OBJECT

public:
    //explicit plat(QObject *parent = nullptr);

    int num_plata;  //To zastąpi nazwę
    int kont_natarcia = 2; //Tymczasowe wpisanie wartosci
    int sila_nosna;
    int wychyl_lotki = 5;

    short oblicza_kon(int wychyl_lotki, int kont_natarcia);       //Oblicza kont natarcia plata


signals:


};

#endif // PLAT_H
