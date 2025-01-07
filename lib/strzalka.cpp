#include "strzalka.h"
#include "qgraphicsitem.h"
#include <QDialog>
#include "wiatr.h"
#include "skrzydlo.h"

QGraphicsLineItem* createLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    QPen blackPen(Qt::GlobalColor::black);
    blackPen.setWidth(3);

    auto linia = new QGraphicsLineItem(x1, y1, x2, y2);
    linia->setPen(blackPen);
    return linia;
}

strzalka::strzalka()
{
    std::vector<QGraphicsLineItem*> zestaw_linii;

    zestaw_linii.push_back(createLine(0,10,50,10));
    zestaw_linii.push_back(createLine(50,10,50,20));
    zestaw_linii.push_back(createLine(50,20,70,0));
    zestaw_linii.push_back(createLine(50,-20,70,0));
    zestaw_linii.push_back(createLine(50,-10,50,-20));
    zestaw_linii.push_back(createLine(0,-10,50,-10));
    zestaw_linii.push_back(createLine(0,-10,0,10));
    // ...
    m_grupa_linii = new QGraphicsItemGroup;

    for(auto &i: zestaw_linii){
        m_grupa_linii->addToGroup(i);
    }

    m_grupa_linii->setX(-210);
    m_grupa_linii->setFlag(QGraphicsItem::ItemIsMovable);
    int raz = 0;
    if(raz==0){
    Punkt1 polo = wyliczPolo_strzalki();
        raz = 1;
    }
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &strzalka::narysuj_strz);
    // connect(timer, &QTimer::timeout, this, SLOT(updatePosition()));
    timer->start(speed);

}

void strzalka::narysuj_strz(){
    qDebug() << "lko_nar_strzalka";

    static int counter{0};
    if(counter>185) counter =0;

    //m_grupa_linii->setX(-200);
   // int *wsk_ta_po = 0;
    // wsk_ta_po = tab_pol;
    // for(int i=0; i<8; i++){
    //             int b, c;
    //     b = *wsk_ta_po;


    //     strzalka::rysStrz(wsk_ta_po, 10);
    //     // wsk_ta_po +1;
    //     wsk_ta_po++;
    // }


    // for(int i=0; i<8; i++){

    //     strzalka::rysStrz(tab_pol[i].x, tab_pol[i].y);

    // }

    strzalka::rysStrz(tab_pol[counter].x, tab_pol[counter].y);
    counter++;
}

void strzalka::SetPozycja(int x, int y)
{
    m_grupa_linii->setX(x);
    m_grupa_linii->setY(y);
    m_grupa_linii->setTransformOriginPoint(0, 0);
    m_grupa_linii->setRotation(45);
    //qDebug() << m_grupa_linii;
}

void strzalka::PolorzenieStrz(int kierunek_wiatru){
    auto wynik = 0;
}

Punkt1 strzalka::wyliczPolo_strzalki() {
    int pol_szer = 220;
    int pol_wys = 220;
    int polo_x{};
    int polo_y{};

    // constexpr int tab_size{185};
    // Punkt1 tab_pol[tab_size];

    // std::array<int, 2> tablica;

    for(int i=0;i<tab_size;i=i+1){
        int g = i;
        if(i<45 || i==45){
        polo_x = pol_wys * tan(qDegreesToRadians(g));
            tab_pol[i].x = polo_x;
            tab_pol[i].y = pol_wys - 1 ;
        qDebug() << i << "I";
        }
        if((i>45 && i<90) || i==90){
        polo_y = pol_szer * cos(qDegreesToRadians(g));
        tab_pol[i].y = polo_y;
        tab_pol[i].x = pol_wys - 1 ;
        qDebug() << i << "II";
        }
        if((i>90 && i<135) || i==135){
            polo_y = pol_szer * tan(qDegreesToRadians(g-90));
            tab_pol[(i)].y = -polo_y;
            tab_pol[i].x = pol_wys - 1 ;
            qDebug() << i << "III";
        }
        if((i>135 && i<180) || i==180){
            polo_x = pol_wys * tan(qDegreesToRadians(g-180));

            tab_pol[i].x = -polo_x;
            tab_pol[i].y = -pol_szer;
            qDebug() << i << "IV";
        }

        qDebug() << i << "X " << polo_x << "TabX " << tab_pol[i].x;
        qDebug() << i << "Y " << polo_y << "TabY " << tab_pol[i].y;

        int n = 180;
        int start = 0;
        int end = n-1;
        //while (start<end) {
            Punkt1 pierw = tab_pol[start];
            Punkt1 ostat = tab_pol[end];

        //}

        }
return {};
}





    //polo_x = 2;
    //polo_y = 6;

    //return {polo_x, polo_y};



void strzalka::rysStrz(int x, int y){

    qDebug() << "x = " << x << " y = " << y;

    //m_grupa_linii->setX(x);
    //m_grupa_linii->setY(y);
    m_grupa_linii->setPos(x, y);
}
