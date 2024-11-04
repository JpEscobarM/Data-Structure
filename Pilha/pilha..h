#ifndef PILHA__H_INCLUDED
#define PILHA__H_INCLUDED

typedef struct no{

    int valor;

    struct no proximo;

}No;

No* empilhar(No *pilha, int num);

No* desempilhar(No **pilha);

void imprimir_pilha(No *topo);

#endif // PILHA__H_INCLUDED
