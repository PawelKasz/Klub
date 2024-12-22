#ifndef WIATR_H
#define WIATR_H

#include <QObject>

class Wiatr : public QObject
{
    Q_OBJECT
public:
    int kierunek_wiatru{270};
    int otrzymany_kier_wiatr{};

    int obliczKier_wiatru();
    void rysuj_strzalke();

    Wiatr() {}
    Wiatr(int kierunek_wiatru, int otrzymany_kierunek_wiatru, Wiatr *p );
    virtual ~Wiatr() {}

private:

public slots:
    void ustawWartosc();

signals:
    void wiatrSignal();

};

#endif // WIATR_H
