#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QDebug>

#include "mainwindow.h"
#include "plat.h"
#include "dialog.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication program(argc, argv);
    int *poz;
    Dialog w;
    w.show();

    connect(horizontalSlider_2, SIGNAL(slidermoved) this, SLOT(Lcdnumber_2));

    qDebug() << "Hello" ;
    MainWindow window;
    window.move(250,150);
    //window.show();


    QTextEdit textedit;
    //textedit.show();
    textedit.move(100,200);

    plat plat1;  //Tworzy obiekt klasy plat

    short wynik = plat1.oblicza_kon(2,5);
    cout << wynik << endl;

    std::string st = std::to_string(wynik);
    char const *wsk_string = st.c_str();

    QString wynik_str(wsk_string);
    textedit.setPlainText(wynik_str);


    /*Moje_dane rezultat = plat1.Funkcja();

    cout << "Rezultat to: " << rezultat.wynik1 << ";  " << rezultat.wynik2 << ", "
         << rezultat.wynik_txt << endl;
    */

    /*window.setGeometry(100, 100, 500, 400);
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
