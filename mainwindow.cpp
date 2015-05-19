#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1, 160, 200, 100);
    trem2 = new Trem(2, 320, 80, 40);
    trem3 = new Trem(3, 550, 80, 150);
    trem4 = new Trem(4, 280, 320, 70);
    trem5 = new Trem(5, 640, 220, 90);
    trem6 = new Trem(6, 530, 340, 40);

    /*trem1 = new Trem(1, 90, 80, 200);
    trem2 = new Trem(2, 320, 80, 40);
    trem3 = new Trem(3, 550, 80, 150);
    trem4 = new Trem(4, 200, 200, 70);
    trem5 = new Trem(5, 430, 200, 90);
    trem6 = new Trem(6, 320, 320, 20);*/

    connect(trem1, SIGNAL(updateGUI(int,int,int, int)), SLOT(updateInterface(int, int, int, int)));
    connect(trem2, SIGNAL(updateGUI(int,int,int, int)), SLOT(updateInterface(int, int, int, int)));
    connect(trem3, SIGNAL(updateGUI(int,int,int, int)), SLOT(updateInterface(int, int, int, int)));
    connect(trem4, SIGNAL(updateGUI(int,int,int, int)), SLOT(updateInterface(int, int, int, int)));
    connect(trem5, SIGNAL(updateGUI(int,int,int, int)), SLOT(updateInterface(int, int, int, int)));
    connect(trem6, SIGNAL(updateGUI(int,int,int, int)), SLOT(updateInterface(int, int, int, int)));

    receberEntrada = new getEntry();
    connect(receberEntrada, SIGNAL(entry(int, int, bool)), SLOT(updateTrem(int, int, bool)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();
    receberEntrada->start();

}

void MainWindow::updateTrem(int id, int speed, bool stop){
    //std::cout<<std::endl<<"ENTROU updateTrem. id: "<<id<<"  |  velocidade: "<<speed<<"  |  stop: "<<stop<<std::endl;;
    switch(id){
    case 1:
        if(stop){
            trem1->parar_retomar();
        }
        else{
            trem1->changeSpeed(speed);
        }
        break;
    case 2:
        if(stop){
            trem2->parar_retomar();
        }
        else{
            trem2->changeSpeed(speed);
        }
        break;
    case 3:
        if(stop){
            trem3->parar_retomar();
        }
        else{
            trem3->changeSpeed(speed);
        }
        break;
    case 4:
        if(stop){
            trem4->parar_retomar();
        }
        else{
            trem4->changeSpeed(speed);
        }
        break;
    case 5:
        if(stop){
            trem5->parar_retomar();
        }
        else{
            trem5->changeSpeed(speed);
        }
        break;
    case 6:
        if(stop){
            trem6->parar_retomar();
        }
        else{
            trem6->changeSpeed(speed);
        }
        break;
    }
}

void MainWindow::updateInterface(int id, int x, int y, int vel){
    switch (id){
    case 1:
        ui->label_Trem1->setGeometry(x, y, 21, 21);
        ui->lcdNumber->display(10000/vel);
        break;
    case 2:
        ui->label_Trem2->setGeometry(x, y, 21, 21);
        ui->lcdNumber_2->display(10000/vel);
        break;
    case 3:
        ui->label_Trem3->setGeometry(x, y, 21, 21);
        ui->lcdNumber_3->display(10000/vel);
        break;
    case 4:
        ui->label_Trem4->setGeometry(x, y, 21, 21);
        ui->lcdNumber_4->display(10000/vel);
        break;
    case 5:
        ui->label_Trem5->setGeometry(x, y, 21, 21);
        ui->lcdNumber_5->display(10000/vel);
        break;
    case 6:
        ui->label_Trem6->setGeometry(x, y, 21, 21);
        ui->lcdNumber_6->display(10000/vel);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    trem1->parar_retomar();
    trem2->parar_retomar();
    trem3->parar_retomar();
    trem4->parar_retomar();
    trem5->parar_retomar();
    trem6->parar_retomar();
}
