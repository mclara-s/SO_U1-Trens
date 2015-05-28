#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*
typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

char serverBuffer[50];
*/
//Definições de algumas GPIO que são Digitais, fica mais fácil para manipular as portas
//se você quiser saber a lista completa, basta olhar no esquemático que tem no slide !
/*
enum DIGITAL_PORT {
        DIGITAL_0 = 33,
        DIGITAL_1 = 29,
        DIGITAL_2 = 35,
        DIGITAL_3 = 17,
        DIGITAL_4 = 37,
        DIGITAL_5 = 19,
        DIGITAL_6 = 21,
        DIGITAL_7 = 39,
        DIGITAL_8 = 41,
        DIGITAL_9 = 23,
        DIGITAL_10 = 27,
        DIGITAL_11 = 25,
        DIGITAL_12 = 43,
        DIGITAL_13 = 31
};

//Definições de algumas GPIO que são Analógicas, fica mais fácil para manipular as portas
//se você quiser sabera  lista completa, basta olhar no esquemático que tem no slide !
enum ANALOG_PORT {
        ANALOG_A0 = 0,
        ANALOG_A1 = 1,
        ANALOG_A2 = 2,
        ANALOG_A3 = 3,
        ANALOG_A4 = 4,
        ANALOG_A5 = 5
};

enum PORT_DIRECTION {
        PORT_IN = 1,
        PORT_OUT = 0
};


const int sendButton = DIGITAL_2;    // the pin that the pushbutton is attached to
const int stopButton = DIGITAL_3;
const int tremButton = DIGITAL_4;
const int ledPin1 = DIGITAL_10;       // the pin that the LED is attached to
const int ledPin2 = DIGITAL_11;
const int ledPin3 = DIGITAL_12;
const int sensorPin = ANALOG_A0;
*/
/* Utilizado para saber se a porta que vamos manipular é entrada ou saída
Obs: Utilizar apenas com DIGITAL ! */
/*
void portDirection(int PORT_NUM, int DIRECTION) {
        FILE *gpio = NULL;
        char file_buffer[40];

        //Limpa o buffer
        memset(file_buffer, 40, 0x0);

        //Utilizado para escrever o número da porta que queremos utilizar
        sprintf(file_buffer, "/sys/class/gpio/gpio%d/direction", PORT_NUM);

        //Abre o arquivo que queremos manipular
        gpio = fopen(file_buffer, "wb");

        //Verifica se o arquivo foi aberto, caso contrário ele continua NULL
        if (gpio == NULL) {
                printf("Nao foi possivel acessar o %s \n", file_buffer);
                exit(0);
        }

        //no arquivo se é IN = entrada ou OUT = Saída//
        if (DIRECTION == PORT_IN) {
                fputs("in", gpio);
        } else {
                fputs("out", gpio);
        }

        fclose(gpio);
}*/


// Export the GPIO to be used in your code.
/*
void exportGPIO(u8 gpio_f) {
        FILE *gpio = NULL;
        char file_buffer[40];

        // Clear fileBuffer
        memset(file_buffer, 40, 0x0);

        // write in file buffer the path of export
        sprintf(file_buffer, "/sys/class/gpio/export");

        // open the file
        gpio = fopen(file_buffer, "wb");

        // verify if was possible open the file.
        if (gpio == NULL) {
                printf("Nao foi possivel acessar o %s \n", file_buffer);
                exit(0);
        }

        // with fprintf we will write the gpio which we want to export.
        fprintf(gpio, "%d", gpio_f);

        // close the gpio
        fclose(gpio);
}*/


// Unexport the GPIO which was probably used.
/*
void unexportGPIO(u8 gpio_f) {
        FILE *gpio = NULL;
        char file_buffer[40];

        // Clear fileBuffer
        memset(file_buffer, 40, 0x0);

        // write in file buffer the path of unexport
        sprintf(file_buffer, "/sys/class/gpio/unexport");

        // open the file
        gpio = fopen(file_buffer, "wb");

        // verify if was possible open the file.
        if (gpio == NULL) {
                printf("wasn't possible find the file:  %s \n", file_buffer);
                exit(0);
        }

        // with fprintf we will write the gpio which we want to unexport.
        fprintf(gpio, "%d", gpio_f);

        // close the gpio
        fclose(gpio);

}*/

// Write value on a DigitalIO, it can be :
// 0 or 1(5V)
/*
void writeDigital(u8 digitalNum, u8 value) {
        FILE *gpio = NULL;
        char file_buffer[40];


        // Clear fileBuffer
        memset(file_buffer, 40, 0x0);

        // write in file buffer the path of gpio value
        sprintf(file_buffer, "/sys/class/gpio/gpio%d/value", digitalNum);

        // open the file
        gpio = fopen(file_buffer, "wb");

        // Verify if was possible acess the gpio
        if (gpio == NULL) {
                printf("wasn't possible find the folder: %s \n", file_buffer);
                exit(0);
        }

        // write the value in our digitalIO
        fprintf(gpio, "%d", value);

        // close our gpio
        fclose(gpio);

}*/

//  ADC value read
/*
u32 analogRead(u8 analogNum) {
        FILE *gpio = NULL;
        char file_buffer[40];
        int analogValue = 0;

         Limpa o buffer
        memset(file_buffer, 40, 0x0);

         Utilizado para escrever o número da porta que queremos utilizar
        sprintf(file_buffer, "/sys/bus/iio/devices/iio\:device0/in_voltage%d_raw", analogNum);

         Abre o arquivo que queremos manipular
        gpio = fopen(file_buffer, "rb");

         Verifica se o arquivo foi aberto, caso contrário ele continua NULL
        if (gpio == NULL) {
                printf("Nao foi possivel acessar o %s \n", file_buffer);
                exit(0);
        }

         Ler o valor Digital com fscanf !
        fscanf(gpio, "%d", &analogValue);

        fclose (gpio);

        return analogValue;
}*/

// digital pin read value
/*
u8  digitalRead(u8 digitalNum) {
        FILE *gpio = NULL;
        char file_buffer[40];
        int digitalValue = 0;


        // Clear fileBuffer
        memset(file_buffer, 40, 0x0);

        // write in file buffer the path of gpio value
        sprintf(file_buffer, "/sys/class/gpio/gpio%d/value", digitalNum);

        // open the file
        gpio = fopen(file_buffer, "rb");

        // Verify if was possible acess the gpio
        if (gpio == NULL) {
                printf("wasn't possible find the folder: %s \n", file_buffer);
                exit(0);
        }

        // write the value in our digitalIO
        fscanf(gpio, "%d", &digitalValue);

        // close our gpio
        fclose(gpio);

        return digitalValue;
}*/



//void serverHandle(char *p) {
   /*     switch (p[0]) {
                case 0:
                        std::cout << "Pedido de atualização de dados !" << std::endl;
                        memset(serverBuffer, 0x0, 50);

                        /** serverBuffer[0] = HEADER_PACOTE
                         ** serverBuffer[1] = Dados
                         ** ...
                         ** serverBuffer[n] = Dados
                         **


                serverBuffer[0] = 0xA;
                serverBuffer[1] = tremSelect;
                serverBuffer[2] = (analogRead(1));
                serverBuffer[3] = tremState;

                break;

                case 2:
                    tremState = serverBuffer[1];
                break;

                default:
                        printf("Pacote errado: %x\n", p[0]);
                break;
        }*/
//}
/*
void selectTrem(int tremCount){
            switch(tremCount){
                case 1:
                writeDigital(ledPin1, 1);  //LIGADO = 1 , DESLIGADO = 0 ?
                writeDigital(ledPin2, 0);
                writeDigital(ledPin3, 0);
                break;

                case 2:
                writeDigital(ledPin1, 0);  //LIGADO = 1 , DESLIGADO = 0 ?
                writeDigital(ledPin2, 1);
                writeDigital(ledPin3, 0);
                break;

                case 3:
                writeDigital(ledPin1, 1);  //LIGADO = 1 , DESLIGADO = 0 ?
                writeDigital(ledPin2, 1);
                writeDigital(ledPin3, 0);
                break;

                case 4:
                writeDigital(ledPin1, 0);  //LIGADO = 1 , DESLIGADO = 0 ?
                writeDigital(ledPin2, 0);
                writeDigital(ledPin3, 1);
                break;

                case 5:
                writeDigital(ledPin1, 1);  //LIGADO = 1 , DESLIGADO = 0 ?
                writeDigital(ledPin2, 0);
                writeDigital(ledPin3, 1);
                break;

                case 6:
                writeDigital(ledPin1, 0);  //LIGADO = 1 , DESLIGADO = 0 ?
                writeDigital(ledPin2, 1);
                writeDigital(ledPin3, 1);
                break;

                default:
                writeDigital(ledPin1, 0);  //LIGADO = 1 , DESLIGADO = 0 ?
                writeDigital(ledPin2, 0);
                writeDigital(ledPin3, 0);
                break;
                }
}
*/

int main(int argc, char **argv){
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

