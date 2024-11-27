#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;

} No;


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
    else
    {

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
    else
    {


        imprimirVersao2Ordenado(&(*raiz)->esq);
        printf("%d ", (*raiz)->dado);
        imprimirVersao2Ordenado(&(*raiz)->dir);
    }

}

//ALTURA

int altura (No **raiz)
{

    if(*raiz == NULL)
    {

        return -1;
    }
    else
    {
        int esq = altura(&(*raiz)->esq);
        int dir = altura(&(*raiz)->dir);

        if(esq > dir)
        {

            return esq+1;
        }
        else
        {
            return dir+1;
        }

    }

}


//CONTAR A QUANTIDADE DE NÓS

int qtdNosArvore(No **raiz)
{

    if(*raiz != NULL)
    {

        return 1 + qtdNosArvore(&(*raiz)->esq) + qtdNosArvore(&(*raiz)->dir);
    }
    else
    {
        return 0;
    }

}

//QUANTIDADE DE FOLHAS
int qtdFolhas(No **raiz)
{

        if(*raiz == NULL)
        {
            return 0;
        }
        else if( (*raiz)->esq == NULL && (*raiz)->dir == NULL)
        {

        return 1;
        }
        else
        {

        return qtdFolhas(&(*raiz)->esq) + qtdFolhas(&(*raiz)->dir);
        }

}

//REMOVENDO NÓ FOLHA DE UMA ARVORE BINARIA
No* removerNoArvore(No **raiz, int chave) //CHAVE E O VALOR A SER REMOVIDO
{

    if(*raiz != NULL) //SE A RAIZ TEM ALGUM VALOR
    {
        if( (*raiz)->dado == chave)//SE É O ELEMENTO PROCURADO
        {
            if((*raiz)->esq == NULL && (*raiz)->dir == NULL) //REMOVE SE NAO TEM FILHOS
            {

                printf("\nElemento folha removido: %d", (*raiz)->dado);
                free(*raiz);
                return NULL;
            }
            else//SE TIVER 1 OU 2 FILHOS
            {



            }

        }
        else//SE NAO FOR O ELEMENTO PROCURADO
        {
            if( chave < (*raiz)->dado)
            {
                (*raiz)->esq = removerNoArvore((*raiz)->esq,chave);
            }
            else
            {
                (*raiz)->dir = removerNoArvore((*raiz)->dir,chave);
            }

        return *raiz;
        }


    }
    else
    {
        printf("\nValor nao encontrado!.");
        return NULL;
    }

}



int main()
{

    No *raiz = NULL;
    No *busca = NULL;
    int valor;
    int menu = 1;

    while(menu != 0)
    {
        printf("\n\t1- inserir");
        printf("\n\t2- imprimir");
        printf("\n\t3- buscar");
        printf("\n\t4 - altura da arvore");
        printf("\n\t5 - quantidade de nos");
        printf("\n\t6 - quantidade de folhas");
        printf("\n");

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

        case 4:
            printf("\nA altura da arvore atual é: %d", altura(&raiz));


            break;
        case 5:
            printf("\nA quantidade de nos e: %d", qtdNosArvore(&raiz));
            break;

          case 6:
            printf("\nA quantidade de folhas e: %d", qtdFolhas(&raiz));
            break;

        case 0:
            menu = 0;
            break;


        }

    }



    return 0;
}
