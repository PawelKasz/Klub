#ifndef PLAT_H
#define PLAT_H

#include <QObject>

class plat : public QObject
{
    Q_OBJECT

public:
    explicit plat(QObject *parent = nullptr);

    int num_plata;  //To zastąpi nazwę
    int kont_natarcia;
    int sila_nosna;
    int wychyl_lotki;

    short oblicza_kon();       //Oblicza kont natarcia plata


signals:


};

#endif // PLAT_H
