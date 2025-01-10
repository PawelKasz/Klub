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
    //Punkt1 polo = wyliczPolo_strzalki();
        strzalka::wyliczPolo_strzalki_1();
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
    if(counter>359) counter =0;
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
            polo_y = pol_szer * tan(qDegreesToRadians(g+45));
            tab_pol[i].y = -(polo_y);
            qDebug() << -(polo_y);
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
Punkt1 strzalka::wyliczPolo_strzalki_1(){
    int bok_a =220;
    int bok_b{};
    int kont {0};

    for(int i=0;i<46;i++){      //pierwsze wypelnienie tablicy vec_tab
    strzalka::wsp_tangens(kont,bok_a); //to bedzie os X 0->+
        kont++;
    }

    for(int i=0;i<359;i++){

        if(i<=45){
        //bok_b = strzalka::wsp_tangens(kont,bok_a); //to bedzie os X 0->+
            tab_pol[i].x = v_tab[i];
        tab_pol[i].y = 219;
        //qDebug() << kont << " bok_b 0->+  = " << bok_b;
        }

        if((i>45) && (i<=90)){
            if(i==46) odwrocenieTablicy();
            tab_pol[i].y = v_tab[i-45];
        tab_pol[i].x = 219;
        //bok_b = wsp_tangens(-(kont-45),bok_a);  //to bedzie os Y +->0
        //qDebug() << kont << " bok_b +->0 = " << bok_b;
        }

        if((i>90 && i<135) || i==135){
            if(i==91) odwrocenieTablicy();
            tab_pol[i].y = -(v_tab[i-90]);
        tab_pol[i].x = 219;
        //bok_b = strzalka::wsp_tangens((kont-90),bok_a); //to bedzie os Y 0->-
        //qDebug() << kont << " bok_b  = " << -bok_b;
        }

        if((i>135 && i<180) || i==180){
            if(i==136) odwrocenieTablicy();
            tab_pol[i].x = v_tab[i-135];
        tab_pol[i].y = -219;
            //bok_b = strzalka::wsp_tangens((kont-90),bok_a); //to bedzie os Y 0->-
            //qDebug() << kont << " bok_b  = " << -bok_b;
        }

        if((i>180 && i<225) || i==225){
            if(i==181) odwrocenieTablicy();
            tab_pol[i].x = -(v_tab[i-180]);
        tab_pol[i].y = -219;
            //bok_b = strzalka::wsp_tangens((kont-90),bok_a); //to bedzie os Y 0->-
            //qDebug() << kont << " bok_b  = " << -bok_b;
        }

        if((i>225 && i<270) || i==270){
            if(i==226) odwrocenieTablicy();
            tab_pol[i].y = -(v_tab[i-225]);
            tab_pol[i].x = -219;
                //bok_b = strzalka::wsp_tangens((kont-90),bok_a); //to bedzie os Y 0->-
                //qDebug() << kont << " bok_b  = " << -bok_b;
        }

        if((i>270 && i<315) || i==315){
            if(i==271) odwrocenieTablicy();
            tab_pol[i].y = v_tab[i-270];
            tab_pol[i].x = -219;
                //bok_b = strzalka::wsp_tangens((kont-90),bok_a); //to bedzie os Y 0->-
                //qDebug() << kont << " bok_b  = " << -bok_b;
        }

        if((i>315 && i<359) || i==359){
            if(i==316) odwrocenieTablicy();
            tab_pol[i].x = -(v_tab[i-315]);
            tab_pol[i].y = 219;
                //bok_b = strzalka::wsp_tangens((kont-90),bok_a); //to bedzie os Y 0->-
                //qDebug() << kont << " bok_b  = " << -bok_b;
        }
    }

    return {};
}

void strzalka::wsp_tangens(int kont,int bok_a){
    int bok_b{};
    //if(kont<46){
    bok_b = bok_a * tan(qDegreesToRadians(kont));
    qDebug() << kont << " bok_b = " << bok_b;
    v_tab.push_back(bok_b);
   // kont++;
    //}
    //return bok_b;
}

int strzalka::wsp_cosinus(int kont, int bok){
    int bok_a{};
    kont = kont-90;
    if(kont<46){
    bok_a = bok * tan(qDegreesToRadians(kont));
    }
    return bok_a;
}

void strzalka::rysStrz(int x, int y){

    qDebug() << "x = " << x << " y = " << y;

    //m_grupa_linii->setX(x);
    //m_grupa_linii->setY(y);
    m_grupa_linii->setPos(x, y);
}

void strzalka::odwrocenieTablicy(){
    for (int i = 0; i < v_tab.size()/2; ++i)
        std::swap(v_tab[i], v_tab[v_tab.size()-1-i]);

    /*
    for( int i = 1; i < 10; i++ )
        k1.push_back( i );

    for( int i = 100; i < 103; i++ )
        k2.push_back( i );

        k1.swap( k2 );
*/
}
