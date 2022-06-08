#include "fila_prioridade_heap.h"

#include <string.h>

#define TAM_INICIAL 5

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/
bool fila_ehValida(FilaPrioridade* f) { return (f != NULL ? true : false); }

void verifica_aumenta(FilaPrioridade* f) {
    if (f->qtdeElementos < f->tamVetor) return;

    int novoTamanho = f->tamVetor * 2;
    TipoElemento* vetorAuxiliar =
        (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for (i = 0; i < f->qtdeElementos; i++) vetorAuxiliar[i] = f->vetor[i];
    free(f->vetor);
    f->vetor = vetorAuxiliar;
    f->tamVetor = novoTamanho;
}

void verifica_diminui(FilaPrioridade* f) {
    if (f->qtdeElementos > f->tamVetor / 4) return;

    int novoTamanho = f->tamVetor / 2;
    TipoElemento* vetorAuxiliar =
        (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for (i = 0; i < f->qtdeElementos; i++) vetorAuxiliar[i] = f->vetor[i];
    free(f->vetor);
    f->vetor = vetorAuxiliar;
    f->tamVetor = novoTamanho;
}

int pai(int i) { return (i - 1) / 2; }

int filhoEsquerda(int i) { return 2 * i + 1; }

int filhoDireita(int i) { return 2 * i + 2; }

void troca(TipoElemento* a, TipoElemento* b) {
    TipoElemento tmp = *a;
    *a = *b;
    *b = tmp;
}

void sobe_ajustando(FilaPrioridade* f, int k) {
    while (k > 0 && f->vetor[k].id > f->vetor[pai(k)].id) {
        troca(&f->vetor[k], &f->vetor[pai(k)]);
        k = pai(k);
    }
}

bool tem_filho_esquerda(FilaPrioridade* f, int k) {
    return (filhoEsquerda(k) < f->qtdeElementos);
}

bool tem_filho_direita(FilaPrioridade* f, int k) {
    return (filhoDireita(k) < f->qtdeElementos);
}

int devolveMaiorFilho(FilaPrioridade* f, int k, int* maior) {
    *maior = -1;
    if (!tem_filho_esquerda(f, k)) return false;

    // Encontra a posicao do maior dos filhos
    int posMaiorFilho = filhoEsquerda(k);
    if (tem_filho_direita(f, k)) {
        if (f->vetor[filhoDireita(k)].id > f->vetor[filhoEsquerda(k)].id)
            posMaiorFilho = filhoDireita(k);
    }

    // Verifica se o maior dos filhos eh maior que o pai
    if (f->vetor[posMaiorFilho].id > f->vetor[k].id) {
        *maior = posMaiorFilho;
    }
    return (*maior != -1);
}

void desce_ajustando(FilaPrioridade* f, int k) {
    int maior;

    while (devolveMaiorFilho(f, k, &maior)) {
        troca(&f->vetor[k], &f->vetor[maior]);
        k = maior;
    }
}

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/

FilaPrioridade* filaP_criar_heap() {
    FilaPrioridade* f = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    f->vetor = (TipoElemento*)calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tamVetor = TAM_INICIAL;
    f->qtdeElementos = 0;
    return f;
}

void filaP_destruir_heap(FilaPrioridade** enderecoFila) {
    if (enderecoFila == NULL) return;
    if (!fila_ehValida(*enderecoFila)) return;

    FilaPrioridade* f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool filaP_inserir_heap(FilaPrioridade* f, TipoElemento elemento) {
    if (!fila_ehValida(f)) return false;
    verifica_aumenta(f);

    f->vetor[f->qtdeElementos++] = elemento;

    sobe_ajustando(f, f->qtdeElementos - 1);
    return true;
}

bool filaP_remover_heap(FilaPrioridade* f, TipoElemento* saida) {
    if (!fila_ehValida(f)) return false;
    if (filaP_vazia_heap(f)) return false;

    *saida = f->vetor[0];

    troca(&f->vetor[0], &f->vetor[f->qtdeElementos - 1]);
    f->qtdeElementos--;
    desce_ajustando(f, 0);

    verifica_diminui(f);
    return true;
}

bool filaP_primeiro_heap(FilaPrioridade* f,
                         TipoElemento* saida) {  // estratégia do scanf
    if (!fila_ehValida(f)) return false;
    if (filaP_vazia_heap(f)) return false;

    *saida = f->vetor[0];
    return true;
}

bool filaP_vazia_heap(FilaPrioridade* f) {
    if (!fila_ehValida(f)) return false;

    return (f->qtdeElementos == 0 ? true : false);
}
int filaP_tamanho_heap(FilaPrioridade* f) {
    if (!fila_ehValida(f)) return -1;

    return f->qtdeElementos;
}

FilaPrioridade* filaP_clone_heap(FilaPrioridade* f) {
    if (!fila_ehValida(f)) return NULL;

    FilaPrioridade* novo = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    novo->vetor = (TipoElemento*)calloc(f->tamVetor, sizeof(TipoElemento));
    memcpy(novo->vetor, f->vetor, f->qtdeElementos * sizeof(TipoElemento));
    novo->tamVetor = f->tamVetor;
    novo->qtdeElementos = f->qtdeElementos;
    return novo;
}

bool filaP_inserirTodos_heap(FilaPrioridade* f, TipoElemento* vetor,
                             int tamVetor) {
    if (!fila_ehValida(f)) return false;

    int i;
    for (i = 0; i < tamVetor; i++) {
        filaP_inserir_heap(f, vetor[i]);
    }
    return true;
}

bool filaP_toString_heap(FilaPrioridade* f, char* str) {
    if (!fila_ehValida(f)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    int i;
    for (i = 0; i < f->qtdeElementos; i++) {
        sprintf(elemento, "%d", f->vetor[i].id);
        strcat(str, elemento);
        if (i < f->qtdeElementos - 1) strcat(str, ",");
    }
    strcat(str, "]");
    return true;
}
