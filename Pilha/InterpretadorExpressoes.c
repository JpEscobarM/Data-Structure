#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no
{

    int num;
    char c;
    struct no *prox;

} No;

typedef struct
{

    No *operandos;//1
    No *operadores;//2

    int countOrdem;
    int ordem[100];

} Header;

//CRIAR EXPRESSAO DESEMPILHAR QUE PERCORRE A PILHA ATE O FINAL E DROPA O ULTIMO VERIFICANDO AUX->PROX != NULL

int interpretaExpressao(char x[],Header *header)
{
    int valorFinal = 0, valores[2];
    int i = 0; //PERCORRE O VETOR DE STRING X
    char c;
    while(x[i] != '\0')
    {
        if(isdigit(x[i])) // E UM OPERANDO OU SEJA 1
        {

            No *novo = malloc(sizeof(No));

            novo->prox = NULL;
            novo->num = x[i] -'0';

            if(header->operandos == NULL) //SE FOR O PRIMEIRO
            {
                header->operandos = novo;
            }
            else//SE JA TIVER OPERANDOS NA PILHA
            {
                novo->prox = header->operandos;
                header->operandos = novo;
            }
        header->ordem[header->countOrdem++] = 1;
        }
        else if ( x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/' || x[i] =='(' || x[i] == ')')// OPERADORES OU SEJA 2
        {
        No *novo = malloc(sizeof(No));

        novo->c = x[i];
        novo->prox = NULL;

        if(header->operadores ==NULL)
        {
            header->operadores = novo;
        }
        else
        {
            novo->prox = header->operadores;
            header->operadores = novo;
        }

        header->ordem[header->countOrdem++] = 2;

        }
    i++;
    }

    i=0;
    int posi=0;
    while(i<header->countOrdem)
    {

    if(header->ordem[i]==1) //OPERANDOS
    {



    }
    else if(header->ordem[i]==2)//OPERADORES
    {

    }

    i++;
    }


    return 0;
}

void imprimirOperadores(Header *header){
    No *aux = header->operadores;

    printf("\nOPERADORES\n");
    while(aux != NULL){
        printf("%c ",aux->c);
        aux = aux->prox;
    }
    printf("\nFIM\n");
}

void imprimirOperandos(Header *header){
    No *aux = header->operandos;

    printf("\nOPERANDOS\n");
    while(aux != NULL){
        printf("%d ",aux->num);
        aux = aux->prox;
    }
    printf("\nFIM\n");
}


int main()
{

    Header header;
    header.operadores = NULL;
    header.operandos = NULL;
    header.countOrdem = 0;

    char expressao[100]= {"(3*(4+5))"};
    printf("%s\n",expressao);
    interpretaExpressao(expressao,&header);

    imprimirOperadores(&header);
    imprimirOperandos(&header);

}
