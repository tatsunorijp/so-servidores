#include "httpd.h"
#include <string.h>
#include <stdlib.h>
#define QUANTIDADE 3
/*tipo:
    1. Matematica
    2.Ciencias
    3.Historia
 */

//SERVIDOR DE MATEMATICA

struct livros{
    int ano;
    int tipo;
    int isbn;
    char nome[30];
    char autor[30];

};


struct livros matematica[QUANTIDADE];
struct livros ciencias[QUANTIDADE];
struct livros historia[QUANTIDADE];

void cadastraLivros(){
    strcpy(matematica[0].nome, "Os Elementos");
    strcpy(matematica[0].autor, "Euclides");
    matematica[0].ano = 1756;
    matematica[0].tipo = 1;
    matematica[0].isbn = 0;

    strcpy(matematica[1].nome, "Matematicando");
    strcpy(matematica[1].autor, "Jõao Paulo Paiva");
    matematica[1].ano = 2002;
    matematica[1].tipo = 1;
    matematica[1].isbn = 1;


    strcpy(matematica[2].nome, "50 ideias matematicas");
    strcpy(matematica[2].autor, "Tony Crilly");
    matematica[2].ano = 2007;
    matematica[2].tipo = 1;
    matematica[2].isbn = 2;

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
    serve_forever("12913");
    return 0;
}

void route(char *qs)
{
    int i, isbn;
    char *token = NULL;
    ROUTE_START()


    ROUTE_GET("/livros")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Hello! You are using %s\n", request_header("User-Agent"));
        printf("Livros\n");
        //printf("%s\n", qs);

        token = strtok(qs, "=");
        token = strtok(NULL, "=");

        //printf("numero: %s\n", token);      //teste to tokinezer

        isbn = atoi(token);                    //converte para inteiro e salva em isbn

        //printf("%d", isbn);


        for (i = 0; i < QUANTIDADE; i++){
            if (matematica[i].isbn == isbn){
                printf("Nome: "); puts(matematica[i].nome);
                printf("Autor: "); puts(matematica[i].autor);
                printf("Ano: "); printf("%d\n", matematica[i].ano);
                printf("Sessao: "); printf("%d\n", matematica[i].tipo);
            }
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