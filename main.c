#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

void rotacaoDireita(struct nodo **raiz){
    struct nodo *p = *raiz;
    struct nodo *q = p->fe;
    if(q->balance >= 0)
        p->balance++;
    else
        p->balance = p->balance + 2;
    q->balance++;
    if(p->pai == NULL){
        q->pai = NULL;
    }
    else{
        if(p == p->pai->fe)
            p->pai->fe = q;
        else
            p->pai->fd = q;
        q->pai = p->pai;
    }
    p->pai = q;
    p->fe = q->fd;
    if(q->fd != NULL)
        q->fd->pai = p;
    q->fd = p;
    *raiz = q;
}

struct nodo *destruirNodo(struct nodo *nodo){
    free(nodo);
    nodo = NULL;
    return nodo;
}

void destroiArvore(struct nodo* nodo){
	if(nodo == NULL)
		return;

	destroiArvore(nodo->fe);
	destroiArvore(nodo->fd);
	destruirNodo(nodo);
	return;
}

int main(){
    struct nodo *raiz = NULL;
    
    imprimirDadosAlunos();

    inserir(&raiz, 4);
    inserir(&raiz, 2);
    //inserir(&raiz, 7);
    inserir(&raiz, 1);
    //inserir(&raiz, 3);
    //inserir(&raiz, 6);
    //inserir(&raiz, 8);

    imprimirEmLargura(raiz);
    printf("\n");
    rotacaoDireita(&raiz);
    imprimirEmLargura(raiz);

   
    destroiArvore(raiz);
	return 0;
}
