#include <stdio.h>
#include <stdlib.h>

typedef struct no
{

    int info;
    struct no *proximo;

} No;

void inserirNoInicio(No **lista, int numero )
{

    No *novo = malloc (sizeof(No));

    if(novo)
    {

        novo->info = numero;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("Erro ao alocar memoria");
    }

}

void inserirNoFim(No **lista, int numero)
{

    No *aux,*novo = malloc(sizeof(No));

    if(novo)
    {

        novo->info = numero;
        novo->proximo = NULL;

        if(*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            aux= *lista;

            while(aux->proximo!= NULL)
            {
                aux = aux->proximo;
            }
            aux->proximo =novo;
        }

    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}
    void inserirNoMeio(No **lista, int num, int ante)
    {

        No *aux,*novo = malloc(sizeof(No));

        if(novo)
        {
            novo->info = num;

            if(*lista == NULL)
            {
                novo->proximo = NULL;
                *lista = novo;

            }
            else
            {
                aux = *lista;
                while(aux->info != ante && aux->proximo)
                {
                    aux = aux->proximo;
                }
                novo->proximo = aux->proximo;
                aux->proximo = novo;

            }
        }

    }


    void imprimirLista(No *listaImprimir)
    {


        printf("LISTA: \n");

        while(listaImprimir){
            printf("%d ", listaImprimir->info);
            listaImprimir= listaImprimir->proximo;
        }
    printf("\n\n");

    }

    int main()
    {

        No *lista = NULL;
        int numero, anterior;
        int op = 1;

        while(op != 0 )
        {

            printf("\t0 - SAIR\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t3 - Inserir no meio\n\t4 - Imprimir\n");

            scanf("%d",&op);
            switch(op){
        case 0:

            op=0;
            break;
        case 1:


            printf("DIGITE O VALOR: \n");
            scanf("%d",&numero);
            inserirNoInicio(&lista ,numero);

            break;

        case 2:
             printf("DIGITE O VALOR: \n");
            scanf("%d",&numero);
            inserirNoFim(&lista ,numero);
            break;
        case 3:

            printf("DIGITE O VALOR: \n");
            printf("DIGITE O VALOR DE REFERENCIA: \n");
            scanf("%d",&numero);
            inserirNoMeio(&lista ,numero);


            break;
        case 4:
            imprimirLista(lista);
            break;
        default:

            break;
            }
        }


        return 0;

   }
