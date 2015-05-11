#include "getentry.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> //bzero
//Bibliotecas socket
#include <sys/types.h>  //AF_INET
#include <sys/socket.h> //socket
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_ntoa
#include <unistd.h>  //close

getEntry::getEntry()
{

}

getEntry::~getEntry()
{

}

void getEntry::run(){
    //Identificador do socket
    int socketId;
    //Struct de endereco
    struct sockaddr_in endereco;
    //Criando o socket (internet, TCP, IP)
    socketId = socket(AF_INET, SOCK_STREAM, 0);
    //Verificar erros
    if (socketId == -1)    {
       perror("Error socket()\n");
       exit(1);
    }

    //tipo do protocolo
    endereco.sin_family = AF_INET;
    //porta
    endereco.sin_port = htons(4325);
    //o endereco será qualquer interface de rede do computador
    endereco.sin_addr.s_addr = INADDR_ANY;
    //inserir zeros
    bzero( &( endereco.sin_zero ), 8);

    //Ligando o socket a uma porta do servidor
    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )    {
       perror("Error bind()\n");
       exit(1);
    }

    //Habilitando o servidor a receber conexoes do cliente
    if ( listen( socketId, 4 ) == -1)    {
       perror("Error listen()\n");
       exit(1);
    }

    while (true)    {
      //Variaveis auxiliares para obter informações das conexões

      //Identificador de uma conexao cliente
      int conexaoClienteId;

      //Caracter lido do cliente
      int id;
      int velocidade;
      bool stop;

      //Bytes lidos do cliente
      int bytesLidos;

      //Endereço de uma conexão cliente
      struct sockaddr_in enderecoCliente;

      //Tamanho do endereço do cliente
      socklen_t enderecoClienteTam;

      printf("Servidor: esperando conexões clientes\n");
      //Fica bloqueado esperando uma conexão do cliente
      conexaoClienteId = accept( socketId,
                                 (struct sockaddr *) &enderecoCliente,
                                 &enderecoClienteTam );
      printf("Servidor: recebeu conexão de %s\n", inet_ntoa( enderecoCliente.sin_addr ));

      //Verificando erros
      if ( conexaoClienteId == -1)
      {
        perror("Error accept");
        exit(1);
      }

      //Recebendo o id do trem do cliente
      if ( (bytesLidos = recv (conexaoClienteId, &id, 1, 0)) == -1 )
      {
        perror ("Error recv\n");
        exit(1);
      }
      printf("Servidor: dado recebido do cliente - %i\n", id);

      //Recebendo a velocidade do trem do cliente
      if ( (bytesLidos = recv (conexaoClienteId, &velocidade, 1, 0)) == -1 )
      {
        perror ("Error recv\n");
        exit(1);
      }
      printf("Servidor: dado recebido do cliente - %i\n", velocidade);


      //Recebendo o stop do trem do cliente
      if ( (bytesLidos = recv (conexaoClienteId, &stop, 1, 0)) == -1 )
      {
        perror ("Error recv\n");
        exit(1);
      }
      printf("Servidor: dado recebido do cliente - %i\n", stop);

      //Fechar a conexão cliente criada em accept
      close(conexaoClienteId);
    }
    //while(true){
        //cin >> id;
        //cin >> speed;
        //cin >> stop; // true or false
        //emit entry(id, speed, stop);
    //}
}
