#include <stdio.h>
#include <stdlib.h>
#include <string.h>>
#include <ctype.h>

typedef struct no
{
    char nome[100];
    int telefone;

    struct no *prox;
    struct no *ant;
} No;

typedef struct
{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct voo
{
    char codigoVoo[30];
    char codigoAeroporto[30];

    Data data;

    char horario[6]; // HH:MM\0


    No *inicioFila;// NO PARA INICIO DA FILA
    No *fimFila; //NO PARA O ULTIMO DA FILA

    struct voo *proximoVoo; //PARA LISTA DE VOOS

    int tamanhoFila;

} Voo;

void stringUppercase(char *string) // TRANSFORA OS CODIGOS DE AEROPORTO E VOO EM UPPERCASE PARA COMPARAR POSTERIORMENTE
{
    int i;
    for( i = 0  ; i < strlen(string); i ++)
    {
        string[i] = toupper(string[i]);
    }

}

Voo lerVoo()
{
    Voo novoVoo;

    printf("\n--DIGITE AS INFORMACOES A SEGUIR--\n");
    printf("\nCODIGO DO VOO: ");
    scanf(" %[^\n]", &novoVoo.codigoVoo);
    getchar();
    stringUppercase(novoVoo.codigoVoo);


    printf("\nCODIGO DO AEROPORTO: ");
    scanf(" %[^\n]", &novoVoo.codigoAeroporto);
    getchar();
    stringUppercase(novoVoo.codigoAeroporto);

    printf("\n--DATA DO VOO--\n");
    printf("\nDia: ");
    scanf("%d", &novoVoo.data.dia);

    printf("\nMes: ");
    scanf("%d", &novoVoo.data.mes);

    printf("\nAno: ");
    scanf("%d", &novoVoo.data.ano);

    printf("\nHorario(HH:MM): ");
    scanf(" %[^\n]", &novoVoo.horario);
    getchar();

    novoVoo.inicioFila = NULL;
    novoVoo.fimFila = NULL;
    novoVoo.tamanhoFila = 0;
    novoVoo.proximoVoo = NULL;

    return novoVoo;
}


int adicionarVoo(Voo **listaVoo) //ADICIONA UM VOO E RETORA UM INTEIRO PARA CONFIRMAR SE FOI ADICIONADO
{


    Voo *novo = malloc (sizeof(Voo));
    *novo = lerVoo();



    if(novo == NULL)
    {
        printf("\nErro de alocacao de memoria\n");
        return 0;
    }


    if(*listaVoo == NULL)
    {
        *listaVoo = novo;
        return 1;
    }

    else if(strcmp(novo->codigoVoo,(*listaVoo)->codigoVoo) < 0)  //INSERE ORDENADO STRCMP ( x, y)  SE strcmp = -1
    {
        // SE CODIGO DO VOO NOVO < INICIO

        novo->proximoVoo = *listaVoo;
        *listaVoo = novo;
        return 1;
    }
    else //SE PRECISAR INSERIR NO " MEIO" OU FIM
    {

        Voo *aux = *listaVoo;

        while(aux->proximoVoo != NULL && strcmp(novo->codigoVoo,aux->proximoVoo->codigoVoo) > 0)
        {
            aux = aux ->proximoVoo;

        }
        novo->proximoVoo = aux->proximoVoo;

        aux->proximoVoo = novo;
        return 1;
    }



    return 0;
}


void removerFilaVoo(No **inicioFila)
{
    No *auxFila = *inicioFila;
    No *antFila = NULL;

    if(auxFila != NULL)
    {

        while(auxFila !=NULL)
        {
            antFila = auxFila;
            auxFila = auxFila->ant;
            free(antFila);
        }

    }
    free(auxFila);
}

int removerVoo(Voo **listaVoo, char *codVoo)
{

    if(*listaVoo != NULL)
    {


        Voo *aux,*ant;
        aux = *listaVoo;
        ant = NULL;

        while(aux != NULL && strcmp(codVoo,aux->codigoVoo) != 0)
        {
            ant = aux;
            aux = aux->proximoVoo;
        }
        if( aux != NULL) //PERCORREU A LISTA E ACHOU O VOO
        {

            if( aux == *listaVoo)//SE E O PRIMEIRO
            {
                removerFilaVoo(&(*listaVoo)->inicioFila);
                *listaVoo = (*listaVoo)->proximoVoo;
                free(aux);

                return 1;
            }
            else
            {
                ant->proximoVoo = aux->proximoVoo;
                removerFilaVoo(&aux->inicioFila);
                free(aux);
                return 1;
            }

        }
        else
        {
            *listaVoo= NULL;
        }
    }
    else
    {
        return 2;
    }

    return 0;
}

No lerPassageiro()
{

    No passageiro;
    printf("\nDIGITE O NOME DO PASSAGEIRO: ");
    scanf("%[^\n]", &passageiro.nome);
    getchar();
    stringUppercase(passageiro.nome);

    printf("\nDIGITE O NUMERO DO PASSAGEIRO: ");
    scanf("%d",&passageiro.telefone);


    return passageiro;
}

int adicionaNaFila(Voo **vooSelecionado) // RECEBE UM VOO E UM PASSAGEIRO  E ADICIONA NA FILA
{

    No *novo = malloc(sizeof(No));

    *novo = lerPassageiro();
    novo->prox = NULL;
    novo->ant = NULL;
    if((*vooSelecionado)->inicioFila == NULL)
    {
        (*vooSelecionado)->inicioFila = novo;
        (*vooSelecionado)->tamanhoFila++;
        (*vooSelecionado)->fimFila = novo;
        return 1;
    }
    else
    {

        (*vooSelecionado)->fimFila->prox = novo;
        novo->ant = (*vooSelecionado)->fimFila;
        (*vooSelecionado)->fimFila = novo;
        (*vooSelecionado)->tamanhoFila++;

        return 1;
    }
    return 0;
}

void enfileirarPassageiro(Voo **listaVoo) //SELECIONA UM VOO
{

    if(*listaVoo != NULL)
    {
        Voo *aux;
        aux = *listaVoo;
        int i=1;

        while(aux != NULL )
        {
            printf("\n[%d] - %s", i, aux->codigoVoo);
            aux = aux->proximoVoo;
            i++;
        }
        printf("\nDIGITE O CODIGO DO VOO: ");
        char codVoo[30];

        fgets(codVoo, sizeof(codVoo), stdin);
        codVoo[strcspn(codVoo, "\n")] = '\0';

        stringUppercase(codVoo);

        aux = *listaVoo;
        while(aux != NULL && strcmp(aux->codigoVoo,codVoo) != 0)
        {
            aux = aux->proximoVoo;
        }
        if( aux != NULL)
        {

            if(adicionaNaFila(&aux))
            {
                printf("\nPassageiro adicionado na fila de espera do voo %s\n", aux->codigoVoo);

            }
            else
            {

            }

        }
        else
        {
            printf("\nVoo não encontrado.\n");

        }

    }
    else
    {
        printf("\nLista de voos vazia.\n");

    }
}

int desenfileirarPassageiro(Voo **vooSelecionado)
{

    No *aux = NULL;

    if( (*vooSelecionado)->inicioFila == NULL) // SE A FILA ESTA VAZIA
    {
        printf("\nA fila do voo esta vazia\n");
        return 0;
    }
    else
    {
        aux = (*vooSelecionado)->inicioFila;

        if((*vooSelecionado)->inicioFila == (*vooSelecionado)->fimFila) // SE SO TIVER 1 PASSAGEIRO
        {
            (*vooSelecionado)->inicioFila = NULL;
            (*vooSelecionado)->fimFila = NULL;
        }
        else
        {

            (*vooSelecionado)->inicioFila = (*vooSelecionado)->inicioFila->prox;
            (*vooSelecionado)->inicioFila->ant = NULL;

        }

        free(aux);
        (*vooSelecionado)->tamanhoFila--;

        return 1;
    }


    return 0;
}

void selecionaVooDesenfileirar(Voo **listaVoo)
{

    if(*listaVoo != NULL)
    {

        Voo *aux = *listaVoo;

        int i = 1;

        while(aux != NULL)
        {
            printf("\n[%d] - %s", i, aux->codigoVoo);
            aux = aux->proximoVoo;
            i++;
        }
        printf("\nDIGITE O CODIGO DO VOO: ");
        char codVoo[30];
        fgets(codVoo, sizeof(codVoo), stdin);
        codVoo[strcspn(codVoo, "\n")] = '\0';

        stringUppercase(codVoo);

        aux = *listaVoo;

        while( aux != NULL &&  strcmp(codVoo,aux->codigoVoo) != 0)
        {
            aux = aux->proximoVoo;

        }


        if(aux!= NULL)
        {
            if(desenfileirarPassageiro( &aux))
            {
                printf("\nPassageiro desenfileirado com sucesso.");

            }

        }
        else
        {

            printf("\nVoo nao encontrado.");


        }

    }

}
void maiorFilaVoo(Voo **listaVoo)
{
    Voo *aux = NULL;

    if(*listaVoo == NULL)
    {
        printf("\nLista de voos vazia.");
    }
    else
    {
        int maior = 0;
        aux = *listaVoo;

        while(aux != NULL)
        {

          if(maior < aux->tamanhoFila)
          {
              maior = aux->tamanhoFila;
          }

        aux = aux->proximoVoo;
        }

        if(maior > 0){
        printf("\nA maior fila encontrada e: %d\n", maior);

        aux = *listaVoo;
        while(aux != NULL)
        {
            if(aux->tamanhoFila == maior)
            {
                printf("\nVOO: %s", aux->codigoVoo);
                printf("\nAEROPORTO: %s", aux->codigoAeroporto);
                printf("\nTamanho da fila: %d", aux->tamanhoFila);
            }
            aux= aux->proximoVoo;
        }
        }
        else
        {
        printf("\nFilas vazias.");
        }
    }

}
void imprimirListaVoo(Voo **listaVoo)
{
    Voo *aux = *listaVoo;

    if(*listaVoo == NULL)
    {
        printf("\nNao a voos na lista.\n");
        return;
    }
    printf("\n\t===[LISTA DE VOOS]===\n");
    while(aux != NULL)
    {
        printf("\nVOO: %s", aux->codigoVoo);
        printf("\nAEROPORTO: %s", aux->codigoAeroporto);
        printf("\nHORARIO: %s", aux->horario);
        printf("\nDATA: %02d/%02d/%04d",aux->data.dia, aux->data.mes,aux->data.ano);
        printf("\nFILA DE ESPERA: %d ",aux->tamanhoFila);
        aux = aux->proximoVoo;

    }
    printf("\n\t===[FIM DA LISTA]===\n");

}

//FUNCOES ALISSON:




void maiorfila(Voo **Lista)
{
    Voo *nova = malloc (sizeof(Voo));
    Voo *listmaior,*aux = *Lista;
    int  maior= 0;

    if(aux == NULL)
    {
        printf("Não existe Voos registrados!!\n");
    }
    else
    {
        while(aux)
        {
            int cont = 0;
            No *list = aux -> inicioFila;
            if(list == NULL)
            {
                aux = aux -> proximoVoo;
                free(list);
            }
            else
            {
                while(list)
                {
                    cont++;
                    list = list -> prox;
                }
                if(maior < cont)
                {
                    maior = cont;
                    listmaior = aux;
                    free(nova);
                    nova = listmaior;
                }
                else if(maior == cont)
                {
                    if(nova==NULL)
                    {
                        nova = listmaior;
                    }
                    else
                    {
                        nova -> proximoVoo = listmaior;
                        listmaior = nova;
                    }
                }
                aux = aux -> proximoVoo;
                free(list);
            }
        }

    }
    while(nova != NULL)
    {
        printf("\nVOO: %s", nova->codigoVoo);
        printf("\nAEROPORTO: %s", nova->codigoAeroporto);
        printf("\nHORARIO: %s", nova->horario);
        printf("\nDATA: %02d/%02d/%04d",nova->data.dia, nova->data.mes, nova->data.ano);
        printf("\nFILA DE ESPERA: %d ",nova->tamanhoFila);

        nova = nova -> proximoVoo;
    }
    return;
}

void semFila(Voo **Lista)
{
    Voo *aux = *Lista;

    if(aux == NULL)
    {
        printf("Não existe Voos registrados!!\n");
    }
    else
    {
        while(aux)
        {
            No *list = aux -> inicioFila;
            printf("Voos sem passageiros:\n");
            if(list == NULL)
            {
                printf("\nVOO: %s", aux->codigoVoo);
                printf("\nAEROPORTO: %s", aux->codigoAeroporto);
                printf("\nHORARIO: %s", aux->horario);
                printf("\nDATA: %02d/%02d/%04d",aux->data.dia, aux->data.mes,aux->data.ano);
            }

            aux = aux -> proximoVoo;
            free(list);
        }
    }
    return;
}

void consultarFilaVoo(Voo **Lista, char *codVoo)
{
    Voo *aux = *Lista;


    if(aux == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }
    else
    {
        while(aux != NULL && strcmp(aux->codigoVoo,codVoo) != 0)
        {
            aux = aux -> proximoVoo;
        }

        if(aux != NULL)
        { // SE ACHOU O CODIGO DO VOO


            No *list = aux -> inicioFila;

            if(list == NULL)
            {
                printf("\nfila vazia!!\n");

            }
            else
            {
                printf("\nFila do voo:%s\n", aux -> codigoVoo);
                while(list != NULL)
                {
                    printf("\npassageiro: %s", list -> nome);
                    list = list -> prox;
                }

            }

        }
          else
        {
            printf("Voo não localizado!\n");

        }

    }
}

void consultarVoo(Voo **ListaVoo, char *cvoo)
{
    Voo *aux = *ListaVoo;
    if(*ListaVoo == NULL)
    {
        printf("\nNao a voos na lista.\n");
        return;
    }
    else
    {
        while( aux->proximoVoo != NULL && strcmp(aux->codigoVoo,cvoo) != 0  )
        {
            aux = aux->proximoVoo;
        }
        if(strcmp (aux -> codigoVoo, cvoo) == 0)
        {
            printf("\nVOO: %s", aux->codigoVoo);
            printf("\nAEROPORTO: %s", aux->codigoAeroporto);
            printf("\nHORARIO: %s", aux->horario);
            printf("\nDATA: %02d/%02d/%04d",aux->data.dia, aux->data.mes,aux->data.ano);
            printf("\nFILA DE ESPERA: %d ",aux->tamanhoFila);
        }
        else
        {
            printf("\nVoo não existe!\n");
            return;
        }

    }

}

int inverterFila(Voo **vooSelecionado)
{

    No *inv, *aux;
    inv = NULL;
    aux = NULL;

    if( (*vooSelecionado)->inicioFila == NULL)
    {
        printf("\nNao existem passageiros na fila.");
        return 0;
    }
    else
    {

        (*vooSelecionado)->fimFila = (*vooSelecionado)->inicioFila;

        while((*vooSelecionado)->inicioFila != NULL)
        {

            aux = (*vooSelecionado)->inicioFila->prox;

            (*vooSelecionado)->inicioFila->prox = inv;

            if(inv != NULL)
            {
                inv->ant = (*vooSelecionado)->inicioFila;
            }

            inv = (*vooSelecionado)->inicioFila;

            (*vooSelecionado)->inicioFila = aux;

        }

        (*vooSelecionado)->inicioFila = inv;

        return 1;
    }
}

void selecionaVooInverter(Voo **listaVoo)
{

    if(*listaVoo != NULL)
    {

        Voo *aux = *listaVoo;

        int i = 1;

        while(aux != NULL)
        {
            printf("\n[%d] - %s", i, aux->codigoVoo);
            aux = aux->proximoVoo;
            i++;
        }
        printf("\nDIGITE O CODIGO DO VOO: ");
        char codVoo[30];
        fgets(codVoo, sizeof(codVoo), stdin);
        codVoo[strcspn(codVoo, "\n")] = '\0';

        stringUppercase(codVoo);

        aux = *listaVoo;
        while( aux != NULL &&  strcmp(codVoo,aux->codigoVoo) != 0)
        {
            aux = aux->proximoVoo;

        }

        if(aux != NULL)
        {


            if(inverterFila(&aux))
            {

                printf("\nFila invertida com sucesso.");

            }


        }
        else
        {
            printf("\nVoo nao encontrado.");
        }

    }
    else
    {
        printf("\nLista de voos vazia.");
    }

}

int main()
{


    Voo *listaVoo = NULL;

    char searchCod[30];

    int menu = 1;


    while(menu != 0)
    {
        printf("\n========== MENU ==========");
        printf("\n[0] - SAIR");
        printf("\n[1] - INCLUIR VOO");
        printf("\n[2] - REMOVER VOO");
        printf("\n[3] - CONSULTAR VOOS");
        printf("\n[4] - ENFILEIRAR PASSAGEIRO");
        printf("\n[5] - DESENFILEIRAR PASSAGEIRO");
        printf("\n[6] - CONSULTAR FILA DE ESPERA");
        printf("\n[7] - MAIOR FILA DE ESPERA");
        printf("\n[8] - SEM FILA DE ESPERA");
        printf("\n[9] - CONSULTAR UM VOO");
        printf("\n[10] - INVERTER FILA DE UM VOO");
        printf("\nOPCAO: ");
        scanf("%d", &menu);
        getchar();

        switch (menu)
        {
        case 0:
            printf("\nSaindo...");
            break;

        case 1:
            if(adicionarVoo(&listaVoo))
            {
                printf("\nVoo adicionado com sucesso\n");

            }
            else
            {
                printf("\nNao foi possivel adicionar o voo\n");

            }
            scanf("%c");

            break;

        case 2:
            printf("\nDigite o codigo do Voo: ");
            fgets(searchCod, sizeof(searchCod),stdin);
            searchCod[strcspn(searchCod, "\n")] = '\0';

            stringUppercase(searchCod);
            int retorno = removerVoo(&listaVoo,searchCod);
            if( retorno == 0)
            {
                printf("\nVoo não econtrado");
            }
            else if(retorno == 1)
            {
                printf("\nVoo removido com sucesso");
            }
            else if(retorno == 2)
            {
                printf("\nLista de voos vazia");
            }

            scanf("%c");
            break;

        case 3:
            imprimirListaVoo(&listaVoo);
            scanf("%c");

            break;

        case 4:

            enfileirarPassageiro(&listaVoo);

            break;

        case 5:
            selecionaVooDesenfileirar(&listaVoo);
            break;

        case 6:
            printf("\nDigite o codigo do Voo: ");
            fgets(searchCod, sizeof(searchCod),stdin);
            searchCod[strcspn(searchCod, "\n")] = '\0';
            stringUppercase(searchCod);
            consultarFilaVoo(&listaVoo,searchCod);

            break;

        case 7:
            maiorFilaVoo(&listaVoo);
            break;

        case 8:
            semFila(&listaVoo);
            break;

        case 9:
            printf("\nDigite o codigo do Voo: ");
            fgets(searchCod, sizeof(searchCod),stdin);
            searchCod[strcspn(searchCod, "\n")] = '\0';
            stringUppercase(searchCod);
            consultarVoo(&listaVoo,searchCod);
            break;

        case 10:

            selecionaVooInverter(&listaVoo);

        break;

        default:
            printf("\nOpcao invalida");
            break;
        }


    }


    return 0;
}
