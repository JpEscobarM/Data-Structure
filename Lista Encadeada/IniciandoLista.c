
#include <stdio.h>

#include <stdlib.h>


typedef struct no{

    int valor;

    struct no proximo;

}No;


//inserir no inicio

void inserir_no_inicio(No **lista, int num){

    No *novo = malloc(sizeof(No));



    if (novo){

    novo->valor=num;

    novo->proximo = *lista;

    *lista= novo;

    }
    else{
        printf("erro de alocacao de memoria no n�");
    }
}


int main(){



return 0;
}
