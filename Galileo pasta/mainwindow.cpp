#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> //bzero
//Bibliotecas socket
#include <sys/types.h>  //AF_INET
#include <sys/socket.h> //socket
#include <netinet/in.h> //htons
#include <arpa/inet.h> //inet_addr
#include <unistd.h>  //close

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    id = 1;
    velocidade = 40;
    stop = false;

    ui->dial->setRange(0, 4095);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::send(){
    //Identificador do socket
    int socketId;

    //Struct de endereco
    struct sockaddr_in endereco;

    //Criando o socket (internet, TCP, IP)
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    //Verificar erros
    if (socketId == -1){
        perror("Error socket()\n");
        exit(1);
    }
    //tipo do protocolo
    endereco.sin_family = AF_INET;
    //porta
    endereco.sin_port = htons(4325);
    //o endereco do servidor
    endereco.sin_addr.s_addr = inet_addr("127.0.0.1");
    //inserir zeros
    bzero( &( endereco.sin_zero ), 8);

    //Ligando o cliente a um servidor
    if (::connect (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 ){
        perror("Error connect()\n");
        exit(1);
    }
    printf ("Cliente: me conectei ao servidor\n");


    //Enviando um A para o servidor
    if ( ::send (socketId, &id, 16, 0) == -1 ){
        perror ("Error send\n");
        exit(1);
    }
    printf("Cliente: enviei o id: %i para o servidor\n", id);

    //Enviando um A para o servidor
    if ( ::send (socketId, &velocidade, 16, 0) == -1 ){
        perror ("Error send\n");
        exit(1);
    }
    printf("Cliente: enviei a velocidade: %i para o servidor\n", velocidade);

    //Enviando um A para o servidor
    if ( ::send (socketId, &stop, 1, 0) == -1 ){
        perror ("Error send\n");
        exit(1);
    }
    printf("Cliente: enviei o bool: %i para o servidor\n", stop);

    //Fechar o socket cliente
    ::close (socketId);
}

void MainWindow::on_pushButton_4_pressed()
{
    //send
    send();
    stop = false;
}

void MainWindow::on_pushButton_2_pressed()
{
    //id
    id = ((id)%6)+1;
    ui->lcdNumber->display(id);
}

void MainWindow::on_dial_valueChanged(int value)
{

    value /= 37;
    //value /= 7;
    velocidade = (value+40);
    ui->lcdNumber_2->display(10000/velocidade);
}

void MainWindow::on_pushButton_pressed()
{
    stop = !stop;
}
