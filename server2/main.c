#include "httpd.h"
#include <string.h>
#include <stdlib.h>
#define QUANTIDADE 3
#define true 1
#define false 0
/*tipo:
    1. Matematica
    2.Ciencias
    3.Historia
 */


//SERVIDOR DE CIENCIAS

struct livros{
    int ano;
    int tipo;
    int isbn;
    char nome[30];
    char autor[30];

};

typedef int bool;

struct livros ciencias[QUANTIDADE];

void cadastraLivros(){

    strcpy(ciencias[0].nome, "A horigem das Espécie");
    strcpy(ciencias[0].autor, "Charles Darwin");
    ciencias[0].ano = 1859;
    ciencias[0].tipo = 2;
    ciencias[0].isbn = 3;

    strcpy(ciencias[1].nome, "O Gene egoista");
    strcpy(ciencias[1].autor, "Richard Dawkins");
    ciencias[1].ano = 1976;
    ciencias[1].tipo = 2;
    ciencias[1].isbn = 4;

    strcpy(ciencias[2].nome, "Cosmos");
    strcpy(ciencias[2].autor, "Carl Sagan");
    ciencias[2].ano = 1980;
    ciencias[2].tipo = 2;
    ciencias[2].isbn = 5;

}

int main(int c, char** v)
{
    cadastraLivros();
    serve_forever("12914");
    return 0;
}

void route(char *qs)
{
    int i, isbn;
    char *token = NULL;
    ROUTE_START()


    ROUTE_GET("/livros")
    {
        bool found = false;
        //printf("HTTP/1.1 200 OK\r\n\r\n");
        //printf("Hello! You are using %s\n", request_header("User-Agent"));
        //printf("%s\n", qs);

        token = strtok(qs, "=");
        token = strtok(NULL, "=");

        //printf("numero: %s\n", token);      //teste to tokinezer

        isbn = atoi(token);                    //converte para inteiro e salva em isbn

        //printf("%d", isbn);


        for (i = 0; i < QUANTIDADE; i++){
            if (ciencias[i].isbn == isbn){
                found = true;
                printf("HTTP/1.1 200 OK\r\n\r\n");
                printf("Nome: "); puts(ciencias[i].nome);
                printf("Autor: "); puts(ciencias[i].autor);
                printf("Ano: "); printf("%d\n", ciencias[i].ano);
                printf("Sessao: "); printf("%d\n", ciencias[i].tipo);
            }
        }

        if (!found) {
            printf("HTTP/1.1 404 Not Found\r\n\r\n");
        }
    }

    ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
        printf("Fetch the data using `payload` variable.");
    }
  
    ROUTE_END()
}