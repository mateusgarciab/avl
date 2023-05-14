#ifndef __FILA__
#define __FILA__

struct nodo_fila {
    struct nodo *nodo;
    struct nodo_fila *prox;
};

struct fila {
    struct nodo_fila *inicio;
    struct nodo_fila *fim;
};

/* Cria uma fila vazia e a retorna, se falhar retorna NULL */
struct fila *cria_fila ();

/* Remove todos os elementos da fila, libera espaco e devolve NULL */
struct fila *destroi_fila (struct fila *f);

/* retorna 1 caso a fila esteja vazia e 0 caso contrario */
int vazia_fila (struct fila *f);

/* Insere o elemento no final da fila
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario */
int insere_fila (struct fila **f, struct nodo* nodo);

/* Remove o elemento do inicio da fila e o retorna
 * no parametro *elemento. Retorna 1 se a operacao foi bem sucedida
  e 0 caso contrario */
struct nodo* retira_fila (struct fila **f);

#endif
