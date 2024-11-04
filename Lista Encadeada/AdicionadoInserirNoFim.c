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

//Inserindo no fim

void inserirNoFim(No **lista,int numeroInserido){

    No *aux, *novo = malloc(sizeof(No));

    if(novo){

        novo->valor = numeroInserido;
        novo->proximo= NULL;
        //é o primeiro?
        if(*lista == NULL){
            *lista = novo;
        }
        else{

            aux = *lista;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }



    }
    else{
        printf("Nao foi possivel alocar memoria\n");
    }

}

int main(){


    No *lista = malloc(sizeof(No));


    for(int i = 0; i < 1; i++){

        inserirNoInicio(&lista,i);
    }

    for(int i = 99 ; i<102 ; i++){
        inserirNoFim(&lista,i);

    }


return 0;
}
