#ifndef _FILA_PRIORIDADE_H_ENCADEADA_
#define _FILA_PRIORIDADE_H_ENCADEADA_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[255];
} TipoElemento;

typedef struct no {
    TipoElemento dado;
    struct no* prox;
} No;

struct _filaPrioridade {
    No* inicio;
    No* fim;
    int qtde;
};

typedef struct _filaPrioridade FilaPrioridade;

FilaPrioridade* filaP_criar_encadeada();
void filaP_destruir_encadeada(FilaPrioridade** enderecoFila);
bool filaP_inserir_encadeada(FilaPrioridade* f, TipoElemento elemento);
bool filaP_remover_encadeada(FilaPrioridade* f, TipoElemento* saida); // estratégia do scanf
bool filaP_primeiro_encadeada(FilaPrioridade* f, TipoElemento* saida); // estratégia do scanf
bool filaP_vazia_encadeada(FilaPrioridade* f);
int filaP_tamanho_encadeada(FilaPrioridade* f);
FilaPrioridade* filaP_clone_encadeada(FilaPrioridade* f);
bool filaP_inserirTodos_encadeada(FilaPrioridade* f, TipoElemento* vetor, int tamVetor);
bool filaP_toString_encadeada(FilaPrioridade* f, char* str);




#endif
