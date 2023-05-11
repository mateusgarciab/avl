#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

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

    //inserir(&raiz, 4);
    //inserir(&raiz, 2);
    //inserir(&raiz, 7);

    inserir(&raiz, 3);

    inserir(&raiz, 1);
           imprimirEmLargura(raiz);
    inserir(&raiz, 2);
 
    //inserir(&raiz, 8);


    printf("\n");

    imprimirEmLargura(raiz);

   
    destroiArvore(raiz);
	return 0;
}
