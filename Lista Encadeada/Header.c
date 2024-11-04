#include<stdio.h>
#include <stdlib.h>

typedef struct no{
    char letra;
    struct no *prox,*ant;
}No;

typedef struct{
    No *inicio;
    No *corrente;
    No *fim;


}Header;

Header header;

void inserirNoInicio(char c){

    No *novo = malloc(sizeof(No));
    novo->letra = c;
    novo->prox = NULL;
    novo->ant = NULL;

    if(header.inicio == NULL){
        header.inicio = novo;
        header.fim = novo;
        header.corrente = novo;
    }
    else{
        novo->prox = header.inicio;
        header.inicio->ant = novo;
        header.inicio = novo;
    }


}

void inserirNoFim(char c){

    No *novo = malloc(sizeof(No));
    novo->letra = c;
    novo->prox = NULL;
    novo->ant = NULL;

    if(header.fim == NULL){
        header.fim = novo;
    }
    else{
        header.fim->prox = novo;
        novo->ant = header.fim;
        header.fim = novo;
    }

}

void imprimirListaHeader(){

    header.corrente = header.inicio;

    printf("\n");
    while(header.corrente != NULL){
        printf("%c", header.corrente->letra);
        header.corrente = header.corrente->prox;
    }
    printf("\n");
}


int main(){

    header.inicio =NULL;
    header.fim = NULL;
    header.corrente = NULL;

    int menu = 1;

    inserirNoInicio('a');
    inserirNoInicio('b');
    inserirNoInicio('c');
    imprimirListaHeader();

    inserirNoFim('a');
    inserirNoFim('a');
    inserirNoFim('a');
    inserirNoFim('a');

    imprimirListaHeader();

return 0;
}

