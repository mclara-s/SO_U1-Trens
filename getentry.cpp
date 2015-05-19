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
    int socketId;
    struct sockaddr_in endereco;
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    int conexaoClienteId;
    int id_final;
    int id;
    int velocidade;
    bool stop;
    int bytesLidos;
    struct sockaddr_in enderecoCliente;

    socklen_t enderecoClienteTam;


    if (socketId == -1)    {
       perror("Error socket()\n");
       exit(1);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(4325);
    endereco.sin_addr.s_addr = INADDR_ANY;
    bzero( &( endereco.sin_zero ), 8);

    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )    {
       perror("Error bind()\n");
       exit(1);
    }

    if ( listen( socketId, 4 ) == -1)    {
       perror("Error listen()\n");
       exit(1);
    }

    while (true)    {
      printf("Servidor: esperando conexões clientes\n");
      //Fica bloqueado esperando uma conexão do cliente
      conexaoClienteId = accept( socketId,
                                 (struct sockaddr *) &enderecoCliente,
                                 &enderecoClienteTam );
      printf("Servidor: recebeu conexão de %s\n", inet_ntoa( enderecoCliente.sin_addr ));

      if ( conexaoClienteId == -1)
      {
        perror("Error accept");
        exit(1);
      }

      if ( (bytesLidos = recv (conexaoClienteId, &id, 16, 0)) == -1 )
      {
        perror ("Error recv\n");
        exit(1);
      }
      printf("id recebido do cliente: %i\n", id);
      id_final = id;//SOLUÇÃO <<<<<

      if ( (bytesLidos = recv (conexaoClienteId, &velocidade, 16, 0)) == -1 )
      {
        perror ("Error recv\n");
        exit(1);
      }
      printf("velocidade recebida do cliente: %i\n", velocidade);


      if ( (bytesLidos = recv (conexaoClienteId, &stop, 1, 0)) == -1 )
      {
        perror ("Error recv\n");
        exit(1);
      }

      printf("stop recebido do cliente: %i\n", stop);

      //Fechar a conexão cliente criada em accept
      close(conexaoClienteId);

      emit entry(id_final, velocidade, stop);
    }
}
