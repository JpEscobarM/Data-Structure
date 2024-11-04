#include <stdio.h>
#include <stdlib.h>



typedef struct no{

    int valor;

    struct no *proximo;

}No;

//INSERIR NO INICIIO

void inserirNoInicio(No **lista, int numeroInserido){

    No *novo = malloc( sizeof(No));

    if(novo){

        novo->valor = numeroInserido;
        novo->proximo = lista;
        *lista = novo;
    }
    else{
        printf("\nErro ao Alocar Memoria no inicio da lista.\n");
    }




}


int main(){


    No *lista = malloc(sizeof(No));


    for(int i = 0; i < 5; i++){

        inserirNoInicio(&lista,i);
    }

return 0;
}
