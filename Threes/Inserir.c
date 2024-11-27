#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;

}No;



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

int main(){

    No *raiz  = NULL;

    raiz = inserir(&raiz,12);


     raiz = inserir(&raiz,50);


     raiz = inserir(&raiz,150);

     raiz = inserir(&raiz,250);

     imprimirVersao1(&raiz);

return 0;
}
