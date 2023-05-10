#include "avl.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Dados do shigueo
struct aluno* getAluno1(){
    struct aluno* retorno = malloc(sizeof(struct aluno));
    if(!retorno)
        exit(1);
    retorno->nome = malloc(sizeof("Gabriel Shigueo Ushiwa Kaguimoto Rodrigues"));//sizeof conta o \0
	if(!retorno->nome)
		exit(1);
    retorno->nomeDinf = malloc(sizeof("gsukr22"));
    if(!retorno->nomeDinf)
        exit(1);
    
	strcpy(retorno->nome, "Gabriel Shigueo Ushiwa Kaguimoto Rodrigues");
    strcpy(retorno->nomeDinf, "gsukr22");
    retorno->grr = 20221261;

	return retorno;
}

//Dados do garcia
struct aluno* getAluno2(){
    struct aluno* retorno = malloc(sizeof(struct aluno));
    if(!retorno)
        exit(1);
    retorno->nome = malloc(sizeof("Garcia"));//sizeof conta o \0
	if(!retorno->nome)
		exit(1);
    retorno->nomeDinf = malloc(sizeof("mg22"));
    if(!retorno->nomeDinf)
        exit(1);
    
	strcpy(retorno->nome, "Garcia");
    strcpy(retorno->nomeDinf, "mg22");
    retorno->grr = 69696969;

	return retorno;
}

//Imprime dados de ambos os alunos
void imprimirDadosAlunos(){
    struct aluno* aluno = getAluno1();
    
    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);

    aluno = getAluno2();
    if(!aluno)
        return;
    
    printf("...E... \n\n");
    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);
}

/* Cria e retorna um nodo avl
 * retorna NULL em caso de falha    */
struct nodo *criaNodo(int chave){
    struct nodo *nodo;
    nodo = malloc(sizeof(struct nodo));
    if(!nodo)
        return NULL;
    nodo->chave = chave;
    nodo->pai = NULL;
    nodo->fe = NULL;
    nodo->fd = NULL;
    nodo->balance = 0;
    return nodo;
}
/*
* Cria e retorna um nodo avl
 * retorna NULL em caso de falha    *
struct nodo *destroiNodo(struct nodo *nodo){
    free(nodo);
    nodo = NULL;
    return nodo;
}*/

/*
struct nodo* rotacaoEsquerda(struct nodo** raiz, int chave, int chave2){
    return NULL;
}

struct nodo* rotacaoDireita(){
    return NULL;
}
*/

struct nodo* inserir(struct nodo** raiz, int chave){
	struct nodo *novo;
    struct nodo *atual = *raiz;
    struct nodo *pai = NULL;
    if(atual == NULL){
        novo = criaNodo(chave);
        if(!novo)
            return NULL;
        *raiz = novo;
        return *raiz;
    }
    while(atual != NULL){
        if(atual->chave == chave)
            return NULL;
        pai = atual;
        if(atual->chave > chave)
            atual = atual->fe;
        else
            atual = atual->fd;
    }
    novo = criaNodo(chave);
    if(!novo)
        return NULL;
    novo->pai = pai;
    if(novo->chave < pai->chave)
        pai->fe = novo;
    else
        pai->fd = novo;
    return *raiz;
}

struct nodo* buscar(struct nodo* nodo, int chave){
	return NULL;
}

int excluir(struct nodo** raiz, int chave){
	return -99;
}

void imprimirEmOrdem(struct nodo* raiz){
	printf("Imprimindo em ordem\n");
}

void imprimirEmLargura(struct nodo* raiz){
	printf("Imprimindo em largura\n");
}
