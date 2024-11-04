#include <stdio.h>
#include <stdlib.h>



typedef struct
{

    int dia;
    int mes;
    int ano;

} Data;

typedef struct
{

    char cpf[50];
    char nome[50];
    Data data;
} Pessoa;

typedef struct no
{

    Pessoa p;

    struct no *proximo;

} No;

Pessoa lerPessoa()
{

    Pessoa p;

    printf("\nDigite o CFP: ");
    fgets(p.cpf,sizeof(p.cpf),stdin);

    printf("\nDigite o NOME: ");
    fgets(p.nome,sizeof(p.nome),stdin);

    printf("\nDigite a DATA de NASCIMENTO dd/mm/aaaa:\n");
    scanf("%d",&p.data.dia);
    scanf("%d",&p.data.mes);
    scanf("%d",&p.data.ano);


    return p;
}

void imprimirPessoa(Pessoa p)
{

    printf("\n--INFO's--\nCPF:%s\nNome:%s\nDataNascimento:%d/%.2d/%d", p.cpf, p.nome, p.data.dia, p.data.mes, p.data.ano);

}


No* push(No *topo){

    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = lerPessoa();
        novo->proximo = topo;

        return novo;
    }
    else{
        printf("erro de alocação de memoria");
    }
return NULL;
}

int main()
{



    No *topo = NULL;
    int op=10;

    while(op!=0)
    {
        printf("---ESCOLHA---\nSair - 0\nEmpilhar - 1\nDesempilhar - 2\nImprimir - 3\n");
        scanf("%d",&op);
        getchar();

        switch(op)
        {
        case 1:

            topo = push(topo);

            break;

        case 2:

            break;
        case 0:

            break;
        default:
            printf("opção invalida!");
            break;
        }



    }



    return 0;
}
