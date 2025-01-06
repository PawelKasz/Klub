#include "mainwindow.h"
#include <memory.h>
#include <QApplication>
#include "../lib/plat.h"
#include "../lib/skrzydlo.h"
#include "../lib/dialog.h"
#include "../lib/wiatr.h"
#include "../lib/strzalka.h"
#include <qtextedit.h>

int main(int argc, char* argv[])
{
    QApplication program(argc, argv);

    Punkt srodek{0, 0};
    skrzydlo skrz1(srodek, 100, 45);        //stworzenie objektu strz1

    Wiatr wiatr;     //stworzenie obiektu Wiatr i ustawienie na niego wskaznika
    wiatr.ustawWartosc_wiatr();      //wywolanie metody dla objektu Wiatr przez wskaznik

    Dialog w(&skrz1, &wiatr);
    w.show();







    // Wiatr *wsk_wiatr_1 = new Wiatr();
    // wsk_wiatr_1->ustawWartosc_wiatr();
    // wsk_wiatr_1->obliczKier_wiatru();
    // wsk_wiatr_1->kierunek_wiatru = 100;
    // wsk_wiatr_1->otrzymany_kier_wiatr = 200;
    // wsk_wiatr_1->obliczKier_wiatru();

    //skrzydlo skrz2(Punkt{3, 4}, 300, 45);
    //skrzydlo skrz3({5, 6}, 300, 45);

    //Punkt resultPoczatek = skrz1.GetPoczatek2Ver();
    //Punkt resultKoniec = skrz1.GetKoniec();

    //Punkt sr{10, 15};
    //skrzydlo skrzydloMK(sr);




           //w.test();

           //connect(w<-horizontalSlider_2, SIGNAL(slidermoved) this, SLOT(Lcdnumber_2));


    //MainWindow window;
    // window.move(250,150);
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
