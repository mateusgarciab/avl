#include <stdio.h>
#include <stdlib.h>

#include "fila.h"


struct fila* cria_fila (){
    struct fila *fila;

    if (!(fila = malloc(sizeof(struct fila))))
        return NULL;

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

int vazia_fila (struct fila *f){
    if(f->inicio == NULL)
        return 1;
    return 0;
}


/*
 * Remove todos os elementos da fila, libera espaco e devolve NULL.pont = malloc(sizeof(fila))
 */
struct fila* destroi_fila (struct fila *f){
    struct nodo_fila* pont;

    if (vazia_fila(f)){
        free(f);
        return NULL;
    }

    pont = f->inicio;
    while (pont->prox != NULL){
        pont = pont->prox;
        free(f->inicio);
        f->inicio = pont;
    }
    free(f->fim);
    free(f);

    return NULL;
}

/*
 * Insere o elemento no final da fila (politica FIFO).
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
int insere_fila (struct fila **f, struct nodo* nodo){
    struct nodo_fila *novo;

    novo = malloc(sizeof(struct nodo_fila));
    if (!novo)
        return 0;
    novo->nodo = nodo;
    novo->prox = NULL;

    if (vazia_fila(*f)){
        (*f)->inicio = novo;
        (*f)->fim = novo;
        return 1;
    }

    (*f)->fim->prox = novo;
    (*f)->fim = novo;
    return 1;

}

/*
 * Remove o elemento do iniciocio da fila e o retorna.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 */
struct nodo* retira_fila (struct fila **f){
    struct nodo_fila* pont;
    struct nodo* nodo;

    if (vazia_fila(*f))
        return 0;

    nodo = (*f)->inicio->nodo;
    pont = (*f)->inicio->prox;
    free((*f)->inicio);
    (*f)->inicio = pont;
    return nodo;
}
