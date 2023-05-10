#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

struct nodo *destroiNodo(struct nodo *nodo){
    free(nodo);
    nodo = NULL;
    return nodo;
}

int main(){
    struct nodo *raiz = NULL;
	imprimirDadosAlunos();
    inserir(&raiz, 1);
    destroiNodo(raiz);
	return 0;
}
