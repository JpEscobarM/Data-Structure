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

void inserir2(No **raiz,int num) // INSERCAO SEM RETORNO
{
    No *novo = malloc(sizeof(No));

    novo->dado = num;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
    {

        *raiz = novo;

    }
    else
    {

        if(num < (*raiz)->dado)
        {
            inserir2(&(*raiz)->esq,num);
        }
        else
        {
            inserir2(&(*raiz)->dir,num);
        }

    }

}



void inserir3(No **raiz, int num)
{
    No *aux = *raiz;

    while(aux != NULL)
    {

        if(num < aux->dado)
        {
            raiz =  &aux->esq;
        }
        else
        {
            raiz = &aux->dir;

        }
        aux = *raiz;

    }
    aux = malloc(sizeof(No));
    aux->dado = num;
    aux->dir = NULL;
    aux->esq = NULL;

    *raiz = aux;

}


//BUSCAR
No* buscar1(No **raiz, int num)
{

    if(*raiz != NULL) //
    {
        if(num == (*raiz)->dado) // SE É O VALOR BUSCADO
        {

            return *raiz;
        }
        else if (num < (*raiz)->dado) //SE FOR MENOR VAI PRA ESQUERDA
        {

          return  buscar1(&(*raiz)->esq,num);

        }
        else
        {
           return  buscar1(&(*raiz)->dir,num);
        }
    }


return NULL;
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
    No *busca = NULL;
    int valor;
    int menu = 1;

    while(menu != 0)
    {
        printf("\n\t1- inserir");
        printf("\n\t2- imprimir");
        printf("\n\t3- buscar\n");

        scanf("%d", &menu);

        switch(menu)
        {
    default:
            printf("\nopcao invalida");
        break;
    case 1:
        printf("\nDigite o valor: ");
        scanf("%d", &valor);

      // raiz = inserir(&raiz, valor);
         inserir2(&raiz,valor);

        break;

    case 2:
        printf("\nVERSAO 1:");
        imprimirVersao1(&raiz);

          printf("\nVERSAO 2:");
        imprimirVersao2Ordenado(&raiz);

        break;

        case 3:
                printf("\n\tDigite o valor que deseja buscar: ");
                scanf("%d", &valor);

                busca = buscar1(&raiz,valor);

                if(busca != NULL)
                {
                    printf("\nValor %d encontrado",busca->dado);

                }
                else
                {
                    printf("\nValor nao encontrado");
                }
        break;


    case 0:
        menu = 0;
    break;


        }

    }



return 0;
}
