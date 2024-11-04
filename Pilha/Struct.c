#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nome[100];
    int idade;

}Pessoa;

typedef struct no{

    Pessoa p;

    struct no *proximo;

}No;

typedef struct{

    No*topo


}Pilha;

int main(){



return 0;
}
