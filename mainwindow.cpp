#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1, 90, 80);
    trem2 = new Trem(2, 320, 80);
    trem3 = new Trem(3, 550, 80);
    trem4 = new Trem(4, 200, 200);
    trem5 = new Trem(5, 430, 200);
    trem6 = new Trem(6, 320, 320);

    connect(trem1, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int, int, int)));
    connect(trem2, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int, int, int)));
    connect(trem3, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int, int, int)));
    connect(trem4, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int, int, int)));
    connect(trem5, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int, int, int)));
    connect(trem6, SIGNAL(updateGUI(int,int,int)), SLOT(updateInterface(int, int, int)));

}

void MainWindow::updateInterface(int id, int x, int y){
    switch (id){
    case 1:
        ui->label_Trem1->setGeometry(x, y, 21, 21);
        break;
    case 2:
        ui->label_Trem2->setGeometry(x, y, 21, 21);
        break;
    case 3:
        ui->label_Trem3->setGeometry(x, y, 21, 21);
        break;
    case 4:
        ui->label_Trem4->setGeometry(x, y, 21, 21);
        break;
    case 5:
        ui->label_Trem5->setGeometry(x, y, 21, 21);
        break;
    case 6:
        ui->label_Trem6->setGeometry(x, y, 21, 21);
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
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();
}
