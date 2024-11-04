#include <stdio.h>
#include <stdlib.h>

int bubbleLista, bubbleVetor;

typedef struct no
{

    int numero;
    struct no *prox;

}No;

void insereValor(No **lista, int valor)
{
    No  *novo = malloc(sizeof(No));
    No *aux;
    aux = *lista;
    novo->numero = valor;
    novo->prox = NULL;

    if(*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void bubbleSortLista(No **lista)
{
    int trocou = 1;
    No *aux;
    int auxValor;




    while(trocou)
    {
        trocou = 0;
        aux = *lista;
        while(aux->prox != NULL)
        {
            if(aux->numero > aux->prox->numero)
            {
                auxValor = aux->prox->numero;
                aux->prox->numero = aux->numero;
                aux->numero = auxValor;
                trocou = 1;
                bubbleLista++;
            }
            aux = aux->prox;
        }
    }
}

void bubbleSortVetor(int vetor[])
{
    int auxV;
    for(int i=0; i<1000; i ++)
    {
        for(int j =1; j< 1000; j++)
        {
            if(vetor[j] < vetor[i])
            {
            auxV = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = auxV;
            bubbleVetor++;
            }

        }
    }
}

void imprimirLista(No **lista) {

    No *aux;
    aux = *lista;
    while(aux!=NULL)
    {

        printf("%d ", aux->numero);
        aux = aux->prox;
    }
    printf("\n");
}

int main()
{
    bubbleLista = 0;
    printf("\nBubbleSort lista no inicio: %d", bubbleLista);
    bubbleVetor = 0;
    bubbleLista = 0;
    printf("\nBubbleSort vetor no inicio: %d\n", bubbleVetor);
    No *lista;
    lista = NULL;

    int randomVet[1000];
    for (int i = 0 ; i < 1000 ; i++)
    {
        randomVet[i] = rand();
        insereValor(&lista,randomVet[i]);
    }

    bubbleSortLista(&lista);
    printf("\nBubbleSort lista no fim: %d\n", bubbleLista);

    bubbleSortVetor(randomVet);
    printf("BubbleSort vetor no fim: %d\n", bubbleVetor);

return 0;
}
