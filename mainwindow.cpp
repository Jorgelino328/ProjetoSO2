#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSemaphore>
#include <iostream>
#include <stdlib.h>

QSemaphore sem;
QSemaphore sem2;
QSemaphore sem3;
QSemaphore sem4;
QSemaphore sem5;
QSemaphore sem6;
QSemaphore sem7;
QSemaphore sem8;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,340,40);
    trem2 = new Trem(2,640,140);
    trem3 = new Trem(3,140,330);
    trem4 = new Trem(4,440,440);
    trem5 = new Trem(5,740,340);

    //Inicia trens
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));


}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        if(x == 440)
            sem4.release();
        if((sem.tryAcquire() && x >= 410 && y == 40) || ((sem6.tryAcquire() || sem2.tryAcquire()) && x == 440 && y >= 210))
            trem1->run_or_stop(0);
        else
            trem1->run_or_stop(1);
        ui->label_trem1->setGeometry(x,y,21,21);
        trem1->setSpeed(ui->horizontalSlider->value());
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        if(x == 440)
            sem.release();
        if(y == 240 && x >= 540)
            sem5.release();
        if((sem7.tryAcquire() || sem4.tryAcquire()) && x <= 570 && y == 240)
            trem2->run_or_stop(0);
        else
            trem2->run_or_stop(1);
        ui->label_trem2->setGeometry(x,y,21,21);
        trem2->setSpeed(ui->horizontalSlider_2->value());
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        if(y == 240)
            sem2.release();
        if(sem3.tryAcquire() && x >= 310 && y == 240)
            trem3->run_or_stop(0);
        else
            trem3->run_or_stop(1);
        ui->label_trem3->setGeometry(x,y,21,21);
        trem3->setSpeed(ui->horizontalSlider_3->value());
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        if(x == 540 && y <= 350)
            sem8.release();
        if(y == 240 && x <= 400)
            sem6.release();
        if(y == 240 && x <= 410)
            sem7.release();
        if(y <= 410 && x <= 340)
            sem3.release();
        ui->label_trem4->setGeometry(x,y,21,21);
        trem4->setSpeed(ui->horizontalSlider_4->value());
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        if((sem5.tryAcquire() || sem8.tryAcquire()) && x <= 570 && y == 440)
            trem5->run_or_stop(0);
        else
            trem5->run_or_stop(1);
        ui->label_trem5->setGeometry(x,y,21,21);
        trem5->setSpeed(ui->horizontalSlider_5->value());
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
