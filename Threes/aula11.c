#include <stdio.h>
#include <stdlib.h>

typedef struct no

{
    char info;
    struct no *esq;
    struct no *dir;

}No;


No* adicionaNo(char c)
{
    No *novo;
    novo = malloc(sizeof(No));

    novo->info = c;
    novo->esq = NULL;
    novo->dir = NULL;

return novo;
}


void dfs(No *n)
{

    if( n != NULL)
    {
        printf("%c", n->info);
        dfs(n->esq);
        dfs(n->dir);
    }


}

int main()
{

    No *arvore = NULL;

    arvore = adicionaNo('a');

    arvore->dir = adicionaNo('b');
    arvore->esq = adicionaNo('c');

return 0;
}
