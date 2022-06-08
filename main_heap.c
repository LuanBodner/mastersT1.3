#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila_prioridade_heap.h"

int controlado() {
    // TipoElemento elemento;
    // char str[100];

    // FilaPrioridade* f = filaP_criar_heap();
    // filaP_inserir_heap(f, {id : 15});
    // filaP_inserir_heap(f, {id : 10});
    // filaP_inserir_heap(f, {id : 4});
    // filaP_inserir_heap(f, {id : 7});
    // filaP_inserir_heap(f, {id : 13});
    // filaP_inserir_heap(f, {id : 3});
    // filaP_inserir_heap(f, {id : 2});
    // filaP_inserir_heap(f, {id : 6});
    // filaP_inserir_heap(f, {id : 1});
    // filaP_inserir_heap(f, {id : 5});
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_remover_heap(f, &elemento);
    // filaP_toString_heap(f, str);
    // printf("%s\n", str);

    // filaP_destruir_heap(&f);
    // return 0;
}

void teste_heap_10k() {
    FilaPrioridade* f = filaP_criar_heap();
    TipoElemento newElement[10000];
    TipoElemento oldElement;
    for (int i = 0; i < 10000; i++) {
        newElement[i].id = i;
        filaP_inserir_heap(f, newElement[i]);
    }

    for (int i = 0; i < 10000; i++) filaP_remover_heap(f, &oldElement);
    filaP_destruir_heap(&f);
}

void teste_heap_25k() {
    FilaPrioridade* f = filaP_criar_heap();
    TipoElemento newElement[25000];
    TipoElemento oldElement;
    for (int i = 0; i < 25000; i++) {
        newElement[i].id = i;
        filaP_inserir_heap(f, newElement[i]);
    }

    for (int i = 0; i < 25000; i++) filaP_remover_heap(f, &oldElement);
    filaP_destruir_heap(&f);
}

int main() {
    teste_heap_25k();
    return 0;
}