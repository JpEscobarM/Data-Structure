#include <stdio.h>
#include <stdlib.h>


typedef struct no
{

    int numero;
    struct no *prox;

}No;


int lerNumero()
{
    int n;
    printf("\nDigite o numero: ");
    scanf("%d", &n);

    return n;
}

void empilhar(No **topo, int num)
{

    No *novo = malloc(sizeof(No));
    novo->numero = num;
    novo->prox = NULL;

    if(*topo == NULL) // SE A PILHA ESTA VAZIA
    {
        *topo = novo;

    }
    else // SE TEM NUMERO
    {

        novo->prox = *topo;
        *topo = novo;

    }

}

void imprimirPilha( No **topo)
{

    No *aux = NULL;
    aux = *topo;

    if(*topo == NULL)
    {
        printf("\nPilha vazia");
    }
    else
    {

        while(aux->prox != NULL )
        {

            printf("\n%d ", aux->numero);
            aux = aux->prox;

        }
    }
}

void desempilhar(No **pilha)
{

    No *aux;


    if (*pilha == NULL)
    {
        printf("\nPilha vazia");
    }
    else
    {
        printf("\nDesempilhou: %d", (*pilha)->numero);
        aux = *pilha;
       *pilha = (*pilha)->prox;

    }
}

int main()
{

    int menu = 1;
    No *pilha;
    pilha->numero = NULL;
    pilha->prox = NULL;

     int numero;

    while (menu != 0 )
    {
        printf("\n1 Empilhar");
        printf("\n2 Imprimir");
        printf("\n3 desempilhar");
        printf("\nDigite um numero: ");
        scanf("%d", &menu);
        switch(menu)
        {

        case 1:


            numero = lerNumero();
            empilhar(&pilha,numero);

        break;
        case 2:

                printf("\nPilha: ");
                imprimirPilha(&pilha);

        break;
        case 3:

                desempilhar(&pilha);

        break;

        }

    }


    return 0;
}
