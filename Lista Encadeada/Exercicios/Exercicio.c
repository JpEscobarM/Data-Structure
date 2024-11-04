#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int informacao;

    struct no *proximo;


}No;


void inserirNoInicio(No **lista,int valor){

    No *novo;
    novo = malloc(sizeof (No));
    novo->informacao = valor;
    novo-> proximo = NULL;


    if(*lista == NULL){

     *lista = novo;

    }
    else{
        novo->proximo = *lista;
        *lista = novo;
    }


}

void imprimirLista(No **lista){

    No *aux = *lista;

    printf("\n========LISTA========\n");

    while(aux!=NULL){
        printf("[%d]-->",aux->informacao);
        aux = aux->proximo;
    }
    printf("\n========FIM========\n");

}

void inserirNoFinal(No **lista,int valor){
    No *novo = malloc(sizeof(No));
    No *aux;
    aux = *lista;
    if(novo){

    novo->informacao = valor;
    novo->proximo = NULL;


       if(*lista == NULL){
        *lista = novo;
       }
       else{

        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
       }


    }
    else{
        printf("\nErro ao alocar memoria\n");
    }

}

void insereNoMeio(No **lista, int valor){

    No *novo = malloc(sizeof(No));

    No *aux = *lista, *anterior = *lista;

    novo->informacao = valor;
    novo->proximo = NULL;

    while(aux != NULL && aux->informacao < novo->informacao){
        anterior = aux;

        aux = aux->proximo;

    }
    anterior->proximo = novo;
    novo->proximo = aux;


}

void removerPorValor(No **lista, int valor){

    No *aux = *lista, *anterior = *lista;

    while(aux!= NULL && aux->informacao != valor){
        anterior= aux;
        aux= aux->proximo;
    }
    if(aux != NULL){
        anterior->proximo = aux->proximo;
        free(aux);
    }


}

void insereOrdenado(No **lista, int valor){
    No *aux, *novo = malloc(sizeof(No));

    novo->informacao = valor;
    novo->proximo= NULL;
    if(*lista == NULL){
        *lista = novo;
    }
    else if( novo->informacao < (*lista)->informacao){

        novo->proximo = *lista;
        *lista = novo;

    }
    else{
        aux = *lista;

        while(aux->proximo != NULL && aux->proximo->informacao < novo->informacao){
            aux = aux->proximo;

        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;

    }


}


void inverterLista(No **lista){

    No *inv, *aux;

    aux = NULL;
    inv = NULL;

    while(*lista != NULL){

       //ARMAZENA A LISTA PARA NAO SE "PERDER"
         aux = (*lista)->proximo;


      //APONTA PARA A LISTA "INVERTIDA"
        (*lista)->proximo = inv;

      //MOVE OS PONTEIROS
        inv = *lista;
        *lista = aux;
    }
    *lista = inv;

}

int main(){

    No *lista = NULL;

    int menu  =  1, valor = 0;

    while (menu != 0 ){
        int op;
        printf("\nEscolha uma opcao");
        printf("\n0- sair");
        printf("\n1- adicionar no inicio");
        printf("\n2- adicionar no fim");
        printf("\n3- inserir no meio");
        printf("\n4- inserir ordenado");
        printf("\n5- imprimir");
        printf("\n6- remover por valor");
        printf("\n7- inverter lista");
        printf("\n");

        scanf("%d",&op);

        switch(op){
    case 0:
        menu = 0;
        printf("Saindo...");
    break;

    case 1:
     printf("\nDigite o valor para inserir no inicio: ");
        scanf("%d", &valor);
        inserirNoInicio(&lista,valor);

    break;

    case 2:
        printf("\nDigite o valor para inserir no final: ");
        scanf("%d", &valor);
        inserirNoFinal(&lista,valor);
    break;

    case 3:
        printf("\nDigite o valor para inserir no meio: ");
        scanf("%d", &valor);
        insereNoMeio(&lista,valor);
    break;

    case 4:

        printf("\nDigite o valor para inserir ordenado: ");
        scanf("%d", &valor);
        insereOrdenado(&lista,valor);

    break;
    case 5:
        imprimirLista(&lista);

    break;

    case 6:
         printf("\nDigite o valor para remover da lista: ");
        scanf("%d", &valor);
        removerPorValor(&lista,valor);

    break;
    case 7:
        inverterLista(&lista);
    break;

    default:
        printf("opcao invalida");
    break;
        }

    }
}
