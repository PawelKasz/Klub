#include "mainwindow.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePosition);
    // connect(timer, &QTimer::timeout, this, SLOT(updatePosition()));
    timer->start(speed);

}

void MainWindow::updatePosition(){

    qDebug() << "uplynelo 5 sek.";


}

MainWindow::~MainWindow()
{
    delete ui;
}

