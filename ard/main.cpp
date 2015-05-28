#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char **argv){
/*    int clientR = 0;
    int socketServer = 0;

    std::cout << "Inicializando o servidor..." << std::endl;


    struct sockaddr_in serverAddr;

    socketServer = socket(AF_INET, SOCK_STREAM, 0);


    bzero ( &serverAddr, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
    serverAddr.sin_port = htons(8080);

    bind(socketServer, (struct sockaddr*) &serverAddr, sizeof(serverAddr));

    std::cout << "Aguardando Conexoes..." << std::endl;

    listen(socketServer, 3);

    clientR = accept(socketServer, (struct sockaddr*) NULL, NULL);

    std::cout << "Cliente Conectado" << std::endl;
*/
    /* CODIGO DO TRENS.INO*/
    int tremCount = 0;   // selecionar o trem
    int sendState = 0;         // enviar
    int stopState = 0;         //parar
    int lastStopState = 0;
    int lastSendState = 0;
    int tremState = 0;
    int lastTremState = 0;
    int velocidade = 0;       //velocidade do trem
    bool stop = false;

    /*portDirection(sendButton, PORT_IN);
    portDirection(stopButton, PORT_IN);
    portDirection(tremButton, PORT_IN);
    portDirection(ledPin1, PORT_OUT);
    portDirection(ledPin2, PORT_OUT);
    portDirection(ledPin3, PORT_OUT);*/

    velocidade = 40;
    tremCount = 3;
    stop = true;

    while ( true ) {
     /*   memset(serverBuffer, 0x0, 50);

        read(clientR, serverBuffer, 50);

        serverHandle(serverBuffer);*/

        /*tremState = digitalRead(tremButton);
        stopState = digitalRead(stopButton);
        velocidade = analogRead(sensorPin);
        sendState = digitalRead(sendButton);

        //SELEÇÃO DO TREM
        if(tremState != lastTremState){
            if (tremState == 0) {
                tremCount = (tremCount%6)+1;
                std::cout << "trem selecionado:  " << tremCount << std::endl;
                selectTrem(tremCount);
            }
        }

        //TESTA BOTÃO STOP -- NÃO ALTERA SE MANTIVER PRESSIONADO
        if (stopState != lastStopState && stopState == 0)
            stop = !stop;*/

        //TESTA SE O SEND FOI APERTADO
        //if(sendState != lastSendState){
        if(true){
            if(sendState == 0){
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
                if (connect (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 ){
                    perror("Error connect()\n");
                    exit(1);
                }
                printf ("Cliente: me conectei ao servidor\n");


                //Enviando um A para o servidor
                if (send (socketId, &tremCount, 16, 0) == -1 ){
                    perror ("Error send\n");
                    exit(1);
                }
                printf("Cliente: enviei o id: %i para o servidor\n", tremCount);

                //Enviando um A para o servidor
                if (send (socketId, &velocidade, 16, 0) == -1 ){
                    perror ("Error send\n");
                    exit(1);
                }
                printf("Cliente: enviei a velocidade: %i para o servidor\n", velocidade);

                //Enviando um A para o servidor
                if (send (socketId, &stop, 1, 0) == -1 ){
                    perror ("Error send\n");
                    exit(1);
                }
                printf("Cliente: enviei o bool: %i para o servidor\n", stop);

                //Fechar o socket cliente
                close(socketId);
            }
        }
        break;
        lastSendState = sendState;
        lastStopState = stopState;
        lastTremState = tremState;
    }

    return 0;
}

