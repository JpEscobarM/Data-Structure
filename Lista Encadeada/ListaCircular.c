#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int valor;
    struct no *proximo;
}No;

typedef struct
{
    No *inicio;
    No *corrente;
    No *fim;

    int tam;

}Header;

void inserirNoInicioCircular(Header *header, int valorInserido)
{

    No *novo = malloc(sizeof(No));
    novo->proximo = NULL;
    novo->valor = valorInserido;

    if(header->inicio == NULL)
    {
        header->inicio = novo;
        header->corrente = novo;
        header->fim = novo;
    }
    else
    {
     novo->proximo = header->inicio;
     header->inicio = novo;
     header->fim->proximo = novo;
    }
    header->tam++;
}

void inserirNoFimCircular(Header *header, int valorInserido)
{
    No *novo = malloc(sizeof(No));
    novo->proximo = NULL;
    novo->valor = valorInserido;

    if(header->inicio == NULL)
    {

        header->inicio = novo;
        header->corrente = novo;
        header->fim = novo;

    }
    else
    {

    novo->proximo = header->inicio;
    header->fim->proximo = novo;
    header->fim = novo;

    }
    header->tam++;
}

void imprimirListaCircular(Header *header)
{
    if(header->inicio == NULL){
        printf("\nLISTA VAZIA\n");
    }
    else{
        printf("\nLISTA:\n");
        header->corrente = header->inicio;


        do {
            printf("%d ", header->corrente->valor);
            header->corrente = header->corrente->proximo;  // Move para o próximo nó
        } while (header->corrente != header->inicio);  // Continua até voltar ao início

        printf("\nFIM\n");
    }
}

int main()
{

    Header header;
    header.inicio = NULL;
    header.corrente = NULL;
    header.fim = NULL;

    inserirNoFimCircular(&header, 10);
    inserirNoFimCircular(&header, 20);
    inserirNoFimCircular(&header, 30);

    imprimirListaCircular(&header);

    return 0;

return 0;
}
