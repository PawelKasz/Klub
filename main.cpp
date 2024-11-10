#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QDebug>




int main(int argc, char *argv[])
{
    QApplication program(argc, argv);

    qDebug() << "Hello" ;
    MainWindow window;
    QTextEdit textedit;
    textedit.show();

    /*window.setGeometry(100, 100, 500, 400);
    window.setWindowTitle("Okno Główne");

    QPushButton button("Zamknij", &window);
    button.setGeometry(200, 350, 100, 40);

    QLabel label("Tekst etykiety :)", &window);
    label.setGeometry(200, 150, 400, 50);

    QObject::connect(&button, SIGNAL(clicked()), &program, SLOT(quit()));
    */
    window.show();

    return program.exec();
}
