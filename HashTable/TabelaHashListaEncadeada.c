#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//2*15 =30 primo mais prox 31 tam = 31
#define tam 31

typedef struct no
{
    int chave;
    struct no *prox;

}No;

typedef struct
{

    No *inicio;

    int tamanho;

}Lista;

void inicializaLista(Lista *lista)
{
        lista->inicio = NULL;
        lista->tamanho = 0;
}

void inserirNaLista(Lista *lista, int valor)
{
    No *novo = malloc(sizeof(No));

    novo->chave = valor;

     novo->prox = lista->inicio;
     lista->inicio = novo;

}

void buscarNaLista(Lista *lista, int chave)
{

}

void inicializaTabelaHash(int *v)
{
        for(int i =0 ; i < tam; i++)
        {
            v[i] = -1;
        }
}

int funcaoHash(int valor)
{
    return valor%31;
}

void inserir(int num, int *v)
{
    int posicao = funcaoHash(num);

    while(v[posicao] != -1)
    {
        posicao = funcaoHash(posicao+1);
    }

    v[posicao] = num;

}

int busca(int *v, int chave)
{
    int posicao = funcaoHash(chave);

    while(v[posicao] != -1)
    {
        if(v[posicao] == chave)
        {
            return v[posicao];
        }
        else
        {
            posicao = funcaoHash(posicao+1);
        }
    }
return -1;
}

void imprimir(int *v)
{
    for(int i =0  ; i < tam; i ++){
        printf("%d:%d \n",i, v[i]);
    }
}


int main()
{


        int tabela[tam];
         int valor;
    inicializaTabelaHash(tabela);

    for(int i =0 ; i < tam; i++)
        {
            printf("%d", tabela[i]);
        }

    int menu = 1;

    while(menu != 0)
    {
        printf("\n1- inserir ");
        printf("\n2- buscar");
        printf("\n3- imprimir\n");
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:

        scanf("%d",&valor);
           inserir(valor,tabela);


        break;

        case 2:

           scanf("%d",&valor);
            int num = busca(tabela,valor);

            printf("%d", num);

        break;

        case 3:

            imprimir(tabela);

        break;
        }


    }
}
