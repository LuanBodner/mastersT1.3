#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila_prioridade_encadeada.h"

void teste_encadeada_10k() {
    FilaPrioridade* f = filaP_criar_encadeada();
    TipoElemento newElement[10000];
    TipoElemento oldElement;
    for (int i = 0; i < 10000; i++) {
        newElement[i].id = i;
        filaP_inserir_encadeada(f, newElement[i]);
    }

    for (int i = 0; i < 10000; i++) filaP_remover_encadeada(f, &oldElement);
    filaP_destruir_encadeada(&f);
}

void teste_encadeada_25k() {
    FilaPrioridade* f = filaP_criar_encadeada();
    TipoElemento newElement[25000];
    TipoElemento oldElement;
    for (int i = 0; i < 25000; i++) {
        newElement[i].id = i;
        filaP_inserir_encadeada(f, newElement[i]);
    }

    for (int i = 0; i < 25000; i++) filaP_remover_encadeada(f, &oldElement);
    filaP_destruir_encadeada(&f);
}

int main() {
    teste_encadeada_25k();
    return 0;
}