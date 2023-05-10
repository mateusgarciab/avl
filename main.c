#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

struct nodo *destroiNodo(struct nodo *nodo){
    free(nodo);
    nodo = NULL;
    return nodo;
}

void destroiArvore(struct nodo* nodo){
	if(nodo == NULL)
		return;

	destroiArvore(nodo->fe);
	destroiArvore(nodo->fd);
	destroiNodo(nodo);
	return;
}

int main(){
    struct nodo *raiz = NULL;
	imprimirDadosAlunos();
    inserir(&raiz, 1);
	inserir(&raiz, 5);
	inserir(&raiz, 3);
	inserir(&raiz, 2);
	inserir(&raiz, 4);

	imprimirEmOrdem(raiz);
    destroiArvore(raiz);
	return 0;
}
