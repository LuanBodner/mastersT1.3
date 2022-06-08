#ifndef _FILA_PRIORIDADE_H_HEAP_
#define _FILA_PRIORIDADE_H_HEAP_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[255];
} TipoElemento;

typedef struct _filaPrioridade {
    TipoElemento* vetor;
    int tamVetor;
    int qtdeElementos;
} FilaPrioridade;

FilaPrioridade* filaP_criar_heap();
void filaP_destruir_heap(FilaPrioridade** enderecoFila);
bool filaP_inserir_heap(FilaPrioridade* f, TipoElemento elemento);
bool filaP_remover_heap(FilaPrioridade* f, TipoElemento* saida);
bool filaP_primeiro_heap(FilaPrioridade* f, TipoElemento* saida);
bool filaP_vazia_heap(FilaPrioridade* f);
int filaP_tamanho_heap(FilaPrioridade* f);
FilaPrioridade* filaP_clone_heap(FilaPrioridade* f);
bool filaP_inserirTodos_heap(FilaPrioridade* f, TipoElemento* vetor,
                             int tamVetor);
bool filaP_toString_heap(FilaPrioridade* f, char* str);

#endif
