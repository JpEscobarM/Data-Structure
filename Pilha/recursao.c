#include <stdio.h>
#include <stdlib.h>


typedef struct no{

    int valor;

    struct no *proximo;

}No;


No* empilhar(No *pilha, int num){

    No *novo = malloc(sizeof(No));

    novo->valor=num;
    novo->proximo;
    novo->proximo = pilha;
    return novo;
}


No* desempilhar(No **pilha){

    No *remover = NULL;

    if(*pilha){

        remover = *pilha;
        *pilha = remover->proximo;

    }else{
        printf("pilha vazia");
        return remover;
    }

}


void imprimirPilha(No  *pilha){


printf("\nPILHA\n");

    while(pilha){

        printf("\t%d\n", pilha->valor);
        pilha = pilha->proximo;
    }

printf("\nFim da PILHA");


}


int fatorial(int num){


    No *remover, *pilha = NULL;

    while(num > 1){
        pilha = empilhar(pilha, num);
        num--;
    }

    imprimirPilha(pilha);

    while(pilha){
         remover = desempilhar(&pilha);
        num = num * remover->valor;
        free(remover);
    }

    return num;
}

int main(){

    printf("digite um numero:");

    int numero;

    scanf("%d", &numero);

    printf("\tFatorial de %d: %d\n", numero, fatorial(numero));



return 0;
}
