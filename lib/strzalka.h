#ifndef STRZALKA_H
#define STRZALKA_H

#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class strzalka;
}
QT_END_NAMESPACE

struct Punkt1{
    int x{}, y{};
};

class strzalka : public QObject
{
    Q_OBJECT
public:

    strzalka();
    QTimer *timer;
    const int speed = 50; // ms

    void PolorzenieStrz(int kierunek_wiatru);
    void setKierunekStrzalki(int x, int y);
    void narysuj_strz();
    void odwrocenieTablicy();
    Punkt1 getCostam();

    Punkt1 wyliczPolo_strzalki() ;
    Punkt1 wyliczPolo_strzalki_1();
    void wsp_tangens(int kont, int bok_a);
    int wsp_cosinus(int kont, int bok);

    // int tab_pol[360];

    static const int tab_size{359};
    Punkt1 tab_pol[tab_size];
    typedef std::vector<int>vec_tab;
    vec_tab v_tab;
    vec_tab k1{};
    vec_tab k2;


    QGraphicsItemGroup *getGroup() {
        return m_grupa_linii;
    }
    //void rysStrz(int x, int y);
    void SetPozycja(int x, int y);

private:
    QGraphicsScene *scene{nullptr};
    QGraphicsItemGroup *m_grupa_linii{nullptr};
    QGraphicsLineItem *line{nullptr};

public slots:
    void rysStrz(int x, int y);
};
#endif // STRZALKA_H
