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

//SERVIDOR DE HISTORIA

struct livros{
    int ano;
    int tipo;
    int isbn;
    char nome[30];
    char autor[30];

};

typedef int bool;

struct livros historia[QUANTIDADE];

void cadastraLivros(){

    strcpy(historia[0].nome, "Era dos externos");
    strcpy(historia[0].autor, "Eric Hobsbawm");
    historia[0].ano = 1994;
    historia[0].tipo = 3;
    historia[0].isbn = 6;

    strcpy(historia[1].nome, "Guerra e Paz");
    strcpy(historia[1].autor, "Liev Tolstoi");
    historia[1].ano = 1867;
    historia[1].tipo = 3;
    historia[1].isbn = 7;

    strcpy(historia[2].nome, "O Povo Brasileiro");
    strcpy(historia[2].autor, "Darcy Ribeiro");
    historia[2].ano = 1995;
    historia[2].tipo = 3;
    historia[2].isbn = 8;

}

int main(int c, char** v)
{
    cadastraLivros();
    serve_forever("12915");
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
            if (historia[i].isbn == isbn){
                found = true;
                printf("HTTP/1.1 200 OK\r\n\r\n");
                printf("Nome: "); puts(historia[i].nome);
                printf("Autor: "); puts(historia[i].autor);
                printf("Ano: "); printf("%d\n", historia[i].ano);
                printf("Sessao: "); printf("%d\n", historia[i].tipo);
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