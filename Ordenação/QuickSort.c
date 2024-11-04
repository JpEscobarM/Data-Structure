#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct no
{
    int numero;
    struct no *prox;
    struct no *ant;

}No;

typedef struct
{

    No *inicio;
    No *fim;

    int tamanho;

}Header;

//FUNCOES QUICKSORT


int procuraPivo( Header *header)
{
    int inicio;
    inicio = header->inicio->numero;
    int fim;
    fim = header->fim->numero;

    int meioPosicao = header->tamanho/2;
    int meioValor;

    int count= 0;

    No *aux = header->inicio;

    while(count < meioPosicao)
    {
        count++;
        aux = aux->prox;
    }
    meioValor = aux->numero;

    int pivo = (inicio+fim+meioValor)/3;

    return pivo;
}



No* particiona(Header *header, No *inicio, No *fim, int pivo) {
    No *esquerda = inicio;
    No *direita = fim;

    while (esquerda != NULL && direita != NULL && esquerda != direita && esquerda->ant != direita) {

        while (esquerda != NULL && esquerda->numero < pivo) {
            esquerda = esquerda->prox;
        }

        while (direita != NULL && direita->numero > pivo) {
            direita = direita->ant;
        }


        if (esquerda != NULL && direita != NULL && esquerda != direita && esquerda->ant != direita) {
            int temp = esquerda->numero;
            esquerda->numero = direita->numero;
            direita->numero = temp;

            esquerda = esquerda->prox;
            direita = direita->ant;
        }
    }
    return esquerda; // Retorna a nova posição do pivô
}

void quickSortRecursivo(Header *header, No *inicio, No *fim)
{
      if (inicio != NULL && fim != NULL && inicio != fim && inicio != fim->prox)
    {
        int pivo = procuraPivo(header);
        No *pivoFinal = particiona(header, inicio, fim, pivo);

        // Ordena as sub-listas recursivamente
        quickSortRecursivo(header, inicio, pivoFinal->ant);
        quickSortRecursivo(header, pivoFinal->prox, fim);
    }

}

void quickSortLista(Header *header)
{

    quickSortRecursivo(header, header->inicio, header->fim);

}

void inserirLista(Header *header,int num)
{

    No *aux,*novo;
    novo = malloc(sizeof(No));
    novo->prox = NULL;
    novo->numero = num;
    novo->ant = NULL;

    aux = header->inicio;

    if(header->inicio == NULL)
    {

        header->inicio = novo;
        header->fim  = novo;
        header->tamanho++;

    }
    else if(header->inicio == header->fim)
    {
        header->inicio->prox = novo;
        novo->ant = header->inicio;
        header->fim = novo;
           header->tamanho++;

    }
    else
    {
        while(aux->prox != NULL)
        {
            aux = aux->prox;

        }
        aux->prox = novo;
        novo->ant = aux;
        header->tamanho++;

    }
}

void imprimirLista(Header *header)
{

    No *aux = header->inicio;
    printf("\nLista: %d\n", header->tamanho);
    while(aux != NULL)
    {

        printf("%d ", aux->numero);
        aux = aux->prox;

    }

}

int main()
{

    Header header;
    header.inicio = NULL;
    header.fim = NULL;
    header.tamanho = 0;

    for(int i = 0 ; i < 10 ; i++)
    {
        inserirLista(&header, rand()%100);
    }

    imprimirLista(&header);
    quickSortLista(&header);
    imprimirLista(&header);

    return 0;
}
