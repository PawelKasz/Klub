#ifndef SKRZYDLO_H
#define SKRZYDLO_H

#include <QObject>

struct Punkt
{
    int x{};
    int y{};
};

struct cieciwa
{
    Punkt poczatek{};
    Punkt koniec{};
};


class skrzydlo: public QObject {
    Q_OBJECT
public:
     int num_plata;  //To zastąpi nazwę
     int kont_natarcia{0}; //Tymczasowe wpisanie wartosci
     int sila_nosna;
     int wychyl_lotki;
     int srodekSkrzy[2]={100,100};
     int poczPlata[2];
     int koniePlata[2];
     char str;

     skrzydlo(){};                                                            //Konstruktor
     skrzydlo(Punkt srodek, int dlugosc = 300, float kat = 0);                //Konstruktor


     [[deprecated ("Uzywamy innej funkcji")]]
     //Punkt GetPoczatek() const;
     Punkt srodek() const;              //Uzywane w testach
     Punkt GetKoniec() const;
     Punkt GetPoczatek2Ver() const;
     cieciwa GetCieciwa() const;

    virtual  ~skrzydlo(){};                                                   //Destruktor

     short oblicza_kont(int wychyl_lotki, int kont_natarcia);       //Oblicza kont natarcia plata
     //void rysujLotke();
     //void rysujPlat(int srodekSkrzy[]);

     //float kat() const;
     void setKat(float newKat);             //Uzywane w testach
     void setSrodek(const Punkt &newSrodek);

 private:
     Punkt          m_srodek;
     int const      m_dlugosc{}; // Dlugosc odcinka skrzydła od środka do "Poczatku".
     float          m_kat{};
     float const m_proporcja{1.6}; // Proporcja czesci koncowej częsci skrzydla (60% dlugosci calkowitej)


 signals:
     void valueChanged(Punkt);

 public slots:
     void slotLot();
     void ustawWartosc();
};

#endif // SKRZYDLO_H
