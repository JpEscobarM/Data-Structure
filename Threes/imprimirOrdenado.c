#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;

}No;


//INSERÇÔES ->
No* inserir(No **raiz, int num)
{

    No *novo = malloc(sizeof(No));
    novo->dado = num;
    novo->esq = NULL;
    novo->dir = NULL;


    if(*raiz == NULL)
    {

        return novo;
    }
    else
    {

        if (num < (*raiz)->dado)
        {
            (*raiz)->esq = inserir(&(*raiz)->esq,num);


        }
        else
        {
            (*raiz)->dir = inserir (&(*raiz)->dir,num);

        }

        return *raiz;

    }


}

void inserir2(No **raiz,int num)
{
    if(*raiz == NULL)
    {


    }
    else
    {

    }

}


///////////////
//IMPRIMIR ->
void imprimirVersao1(No **raiz)
{
    if(*raiz == NULL)
    {

    }
    else{

        printf("%d ", (*raiz)->dado);
        imprimirVersao1(&(*raiz)->esq);
        imprimirVersao1(&(*raiz)->dir);
    }

}

void imprimirVersao2Ordenado(No **raiz)
{
    if(*raiz == NULL)
    {

    }
    else{


        imprimirVersao2Ordenado(&(*raiz)->esq);
        printf("%d ", (*raiz)->dado);
        imprimirVersao2Ordenado(&(*raiz)->dir);
    }

}

int main(){

    No *raiz = NULL;
    int valor;
    int menu = 1;

    while(menu != 0)
    {
        printf("\n1- inserir");
        printf("\n2- imprimir\n");

        scanf("%d", &menu);

        switch(menu)
        {
    default:
            printf("\nopcao invalida");
        break;
    case 1:
        printf("\nDigite o valor: ");
        scanf("%d", &valor);

       raiz = inserir(&raiz, valor);

        break;

    case 2:
        imprimirVersao2Ordenado(&raiz);

        break;
    case 0:
        menu = 0;
    break;


        }

    }



return 0;
}
