#include "mainwindow.h"
#include <memory.h>
#include <QApplication>
#include "../lib/plat.h"
#include "../lib/skrzydlo.h"
#include "../lib/dialog.h"
#include "../lib/wiatr.h"

int main(int argc, char* argv[])
{
    QApplication program(argc, argv);
    //int *poz;
    plat plat1;  //Tworzy obiekt klasy plat

    Punkt srodek{0, 0};
    skrzydlo skrz1(srodek, 100, 45);
    Wiatr *wsk_wiatr = new Wiatr();
    wsk_wiatr->ustawWartosc();

    std::vector<std::unique_ptr<skrzydlo>> SkrzydlataPolska;
    SkrzydlataPolska.emplace_back(std::make_unique<skrzydlo>(Punkt{0, 0}, 100, 45));
    SkrzydlataPolska.emplace_back(std::make_unique<skrzydlo>(Punkt{50, 50}, 150, 65));
//     Dialog w(SkrzydlataPolska);

    //skrzydlo skrz2(Punkt{3, 4}, 300, 45);
    //skrzydlo skrz3({5, 6}, 300, 45);

    //Punkt resultPoczatek = skrz1.GetPoczatek2Ver();
    //Punkt resultKoniec = skrz1.GetKoniec();

    //Punkt sr{10, 15};
    //skrzydlo skrzydloMK(sr);

    Dialog w(/*&plat1,*/ &skrz1);

    w.show();



           //w.test();

           //connect(w<-horizontalSlider_2, SIGNAL(slidermoved) this, SLOT(Lcdnumber_2));

    //qDebug() << "Hello" ;
    //MainWindow window;
    //window.move(250,150);
    //window.show();

           //QTextEdit textedit;
           //textedit.show();
           //textedit.move(100,200);

           //short wynik = plat1.oblicza_kon(2,5);
           //cout << wynik << endl;

           //plat1.rysujPlat();

           //std::string st = std::to_string(wynik);
           //char const *wsk_string = st.c_str();

           //QString wynik_str(wsk_string);
           //textedit.setPlainText(wynik_str);


    /*Moje_dane rezultat = plat1.Funkcja();

     cout << "Rezultat to: " << rezultat.wynik1 << ";  " << rezultat.wynik2 << ", "
          << rezultat.wynik_txt << endl;
     */

    /*  window.setGeometry(100, 100, 500, 400);
      window.setWindowTitle("Okno Główne");

     QPushButton button("Zamknij", &window);
     button.setGeometry(200, 350, 100, 40);

      QLabel label("Tekst etykiety :)", &window);
      label.setGeometry(200, 150, 400, 50);

     QObject::connect(&button, SIGNAL(clicked()), &program, SLOT(quit()));
 */

           //window.show();

    return program.exec();


}
