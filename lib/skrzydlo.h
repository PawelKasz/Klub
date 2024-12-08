#ifndef SKRZYDLO_H
#define SKRZYDLO_H

#include <QObject>


struct Punkt
{
    int x{};
    int y{};
};

class skrzydlo: public QObject {
    Q_OBJECT
public:
     int num_plata;  //To zastąpi nazwę
     int kont_natarcia; //Tymczasowe wpisanie wartosci
     int sila_nosna;
     int wychyl_lotki;
     int srodekSkrzy[2]={0,0};
     int poczPlata[2];
     int koniePlata[2];
     char str;

     skrzydlo();
     skrzydlo(Punkt srodek, int dlugosc = 10, float kat = 0);

     Punkt GetPoczatek() const;
     Punkt GetKoniec() const;

    virtual  ~skrzydlo(){};

     short oblicza_kont(int wychyl_lotki, int kont_natarcia);       //Oblicza kont natarcia plata
     void rysujLotke();
     void rysujPlat(int srodekSkrzy[]);

 private:
     Punkt          m_srodek;
     int const      m_dlugosc{};
     float          m_kat{};

 signals:

 private slots:
     void slotLot();
};

#endif // SKRZYDLO_H
