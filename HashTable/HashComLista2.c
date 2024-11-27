
#include <stdio.h>
#include <stdlib.h>
#define tam 31




void inicializarTabela(int t[])
{
    for(int i=0; i < tam ;i++)
    {

        t[i] = -1;
    }

}

int funcaoHash(int chave)
{

        return chave%tam;
}

void inserir(int t[],int valor)
{
    int id = funcaoHash(valor);
    while(t[id] != -1)
    {

        id = funcaoHash(id+1);

    }
    t[id] = valor;
}

int busca(int t[],int chave)
{
    int id = funcaoHash(chave);

    while(t[id] != -1)
    {
        if(t[id] == chave)
        {
            return t[id];
        }
        else
        {
        id = funcaoHash(id+1);
        }



    }
    return -1;
}

void imprimir(int t[])
{

    for (int i =0; i <tam ; i++)
    {

        printf("\n\tINDICE:%d = %d", i, t[i]);

    }

}

int main()
{

    int tabela[tam];
    int valor;
    inicializarTabela(tabela);
    int retorno;
    int menu = 1 ;

    while(menu != 0)
    {

        printf("\n0 - sair");

        printf("\n1 - inserir");

        printf("\n2 - buscar");

        printf("\n3 - imprimir\n");

        scanf("%d",&menu);
        switch(menu)
        {
        case 0:
                menu =0;
            break;

        case 1:

              printf("\n\tdigite o valor: ");
              scanf("%d", &valor);
              inserir(tabela,valor);

            break;

        case 2:
                printf("\n\tdigite o valor: ");
              scanf("%d", &valor);
             retorno = busca(tabela,valor);


                switch(retorno)
                {
                case -1:
                        printf("\nValor nao encontrado");
                    break;

                default:
                        printf("\nValor buscado: %d", retorno);
                    break;

                }

            break;

        case 3:
                imprimir(tabela);
            break;
        }

    }

    return 0;
}
