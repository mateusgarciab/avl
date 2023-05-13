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
    struct nodo *raiz = NULL, *retorno2;
    char op;
    int chave, retorno;
    imprimirDadosAlunos();
    scanf("%c %d", &op, &chave);
    while(op != 'f'){
        switch(op){
            case 'i':
                retorno2 = inserir(&raiz, chave);
                if(retorno2 == NULL)
                    printf("Falha ao inserir.\n");
            break;
            case 'r':
                retorno = excluir(&raiz, chave);
                if(retorno == 0)
                    printf("Falha ao remover %d.\n", chave);
            break;
            case 'b':
                retorno2 = buscar(raiz, chave);
                if(retorno2 == NULL)
                    printf("Nao encontrado %d.\n", chave);
                else
                    printf("Encontrado %d.\n", retorno2->chave);
            break;
            case 'e':
                imprimirEmOrdem(raiz);
            break;
            case 'l':
                imprimirEmLargura(raiz);
            break;
        }
        scanf("%c %d", &op, &chave);
    }
    destroiArvore(raiz);
	return 0;
}
