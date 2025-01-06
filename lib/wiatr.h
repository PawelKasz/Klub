#ifndef WIATR_H
#define WIATR_H

#include <QObject>

#include "strzalka.h"

class Wiatr : public QObject
{
    Q_OBJECT
public:
    int kierunek_wiatru{270};
    int otrzymany_kier_wiatr{};

    int obliczKier_wiatru(int);
    int getDane_Dialog();

    Wiatr() {
        m_strzalka = new strzalka();
    }

    Wiatr(int kierunek_wiatru, int otrzymany_kierunek_wiatru, Wiatr *p );

    virtual ~Wiatr() {
        delete m_strzalka;
    }

    strzalka *GetStrzalka() const;

private:
    strzalka* m_strzalka{nullptr};

public slots:
    int ustawWartosc_wiatr();
    void UstawKierunek(int kierunek);

signals:
    void wiatrSignal();
};

#endif // WIATR_H
