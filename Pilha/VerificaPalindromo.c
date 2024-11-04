#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char letra;
    struct no *prox;

}No;

void nova(No **pilha){

    *pilha = NULL;

}

void push(No **pilha, char c)
{
    No *novo = malloc(sizeof(No));

    novo->letra = c;
    novo->prox = NULL;

    if(*pilha == NULL)
    {
        *pilha = novo;
    }
    else
    {
        novo->prox = *pilha;
        *pilha = novo;
    }
}

void pop(No **pilha)
{
    if(*pilha == NULL)
    {
        printf("\nPilha vazia");

    }
    else
    {
        No *aux = *pilha;
        *pilha = (*pilha)->prox;

       free(aux);
    }
}

char top(No **pilha)
{
    if(*pilha == NULL)
    {

    }
    else
    {
        return (*pilha)->letra;
    }
return NULL;
}

int isEmpty(No **pilha)
{
    if (*pilha == NULL)
    {
    return 1;
    }
    else
    {
        return 0;
    }
}

int verificaPalindromo(char *string)
{

       No *pilha;
       nova(&pilha);

      int tamanho = strlen(string);

      for(int i = 0 ; i < tamanho/2; i++)
      {
          push(&pilha,string[i]);
      }

      for(int i = (tamanho+1)/2 ; i <tamanho; i ++)
      {

        if(string[i] != top(&pilha))
        {

        return 0;
        }
        pop(&pilha);

        if(isEmpty(&pilha))
        {
            break;
        }
      }
return 1;
}
int main()
{

    int n = verificaPalindromo("AAaCASD");
    printf("%d", n);
}
