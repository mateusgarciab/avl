#include "avl.h"
#include "fila.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nodo *destroiNodo(struct nodo *nodo){ /* Lembrar q tem ver isso depois, se nois vamo deixar aq ou no main*/
    free(nodo);
    nodo = NULL;
    return nodo;
}

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

//Dados do aluno garcia
struct aluno* getAluno2(){
    struct aluno* retorno = malloc(sizeof(struct aluno));
    if(!retorno)
        exit(1);
    retorno->nome = malloc(sizeof("Mateus Garcia Baiak"));//sizeof conta o \0
	if(!retorno->nome)
		exit(1);
    retorno->nomeDinf = malloc(sizeof("mgb22"));
    if(!retorno->nomeDinf)
        exit(1);
    
	strcpy(retorno->nome, "Mateus Garcia Baiak");
    strcpy(retorno->nomeDinf, "mgb22");
    retorno->grr = 20224378;

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

void rotacaoDireita(struct nodo **raiz){
    struct nodo *p = *raiz;
    struct nodo *q = p->fe;
    short int pBalance = p->balance;
    
    if(q->balance >= 0)
        p->balance++;
    else
        p->balance = p->balance + 2;

    if(q->balance == -1 && pBalance == -1)
        q->balance = q->balance + 2;
    else 
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

void rotacaoEsquerda(struct nodo **raiz){
    struct nodo *p = *raiz;
    struct nodo *q = p->fd;
    short int pBalance = p->balance;
    if(q->balance <= 0)
        p->balance--;
    else
     p->balance = p->balance - 2;
    if(q->balance == 1 && pBalance == 1)
        q->balance = q->balance - 2;
    else 
        q->balance--;


    if(p->pai == NULL){
        q->pai = NULL;
    } else {
        if(p == p->pai->fd)
            p->pai->fd = q;
        else
            p->pai->fe = q;
        q->pai = p->pai;
    }
    p->pai = q;
    p->fd = q->fe;
    if(q->fe != NULL)
        q->fe->pai = p;
    q->fe = p;
    *raiz = q;
}

void rebalacear(struct nodo** nodo)
{
    if(((*nodo)->balance == 2) && ((*nodo)->fd->balance == -1)){
        imprimirEmLargura((*nodo)->fd);
        printf("\n");
        rotacaoDireita(&(*nodo)->fd);
        imprimirEmLargura((*nodo)->fd);
        printf("\n");
        rotacaoEsquerda(nodo);
        return;
    }
    if(((*nodo)->balance == -2) && ((*nodo)->fe->balance == 1)){
        imprimirEmLargura((*nodo)->fe);
        printf("\n");

        rotacaoEsquerda(&(*nodo)->fe);
        imprimirEmLargura((*nodo)->fe);
        printf("\n");

        rotacaoDireita(nodo);
        return;
    }
    if((*nodo)->balance == 2)
        rotacaoEsquerda(nodo);
    else
        rotacaoDireita(nodo);
    return;
}

void atualizarBalanco(struct nodo** nodo, struct nodo** raiz)
{
	struct nodo* p = (*nodo)->pai;
	if (*nodo == p->fe)  /* q é filho esquerdo de p */
		p->balance--;
	else
		p->balance++;
	while ((p->pai != NULL) && (p->balance != -2) && (p->balance != 2)) {  /* enquanto p não é raiz e p.balanco ≠ ± 2 */
		*nodo = p;
		p = p->pai;
		if ((*nodo)->balance == 0)
			return;
		if (*nodo == p->fe) /* q é um filho esquerdo de p */
			p->balance--;
		else
			p->balance++;
	}
    if ((p->balance == 2) || (p->balance == -2)){
        if(p == *raiz){
            rebalacear(&p);
            *raiz = p;
        }
        else
            rebalacear(&p);
    }
	return;
}

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
    atualizarBalanco(&novo,raiz);
    return *raiz;
}

struct nodo* buscar(struct nodo* nodo, int chave){
	struct nodo *pai = NULL;
    while(nodo != NULL){
        if(nodo->chave == chave)
            return nodo;
        pai = nodo;
        if(nodo->chave > chave)
            nodo = nodo->fe;
        else
            nodo = nodo->fd;
    }
    return NULL;
}

/* Procura e retorna o antecessor de um nodo
 * retorna NULL caso não exista             */
struct nodo* antecessor(struct nodo* nodo){
    struct nodo *pai;
    pai = nodo;
    nodo = nodo->fe;
    if(!nodo)
        return NULL;
    while(nodo != NULL){
        pai = nodo;
        nodo=nodo->fd;
    }
    return pai;
}

void reduzirBalanco(struct nodo** nodo)
{
	struct nodo* p = (*nodo)->pai;
    if (((*nodo)->balance == 2) || ((*nodo)->balance == -2)){
        rebalacear(nodo);
        return;
    }
    if(p == NULL)
        return;
	if (*nodo == p->fe)  /* q é filho esquerdo de p */
		p->balance++;
	else
		p->balance--;
	while ((p->pai != NULL) && (p->balance != -2) && (p->balance != 2)) {  /* enquanto p não é raiz e p.balanco ≠ ± 2 */
		*nodo = p;
		p = p->pai;
		if (((*nodo)->balance == -1) || ((*nodo)->balance == 1))
			return;
		if (*nodo == p->fe) /* q é um filho esquerdo de p */
			p->balance++;
		else
			p->balance--;
	}
    if ((p->balance == 2) || (p->balance == -2))
        rebalacear(&p);
	return;
}

void transplantar(struct nodo **atual, struct nodo **novo, struct nodo **raiz){
    struct nodo *q;
    if((*novo) == NULL){
        if((*atual)->pai == NULL)
            return;
        q = (*atual)->pai;
        if(*atual == q->fe)
            q->balance++;
        else
            q->balance--;
    }
    else{



        if(*novo == (*atual)->fe){
            (*novo)->balance = (*atual)->balance + 1;
            q = (*atual)->pai;
            if(q != NULL){
                if(*atual == q->fe)
                    q->balance++;
                else
                    q->balance--;
            }
            (*novo)->fd = (*atual)->fd;
        }
        else if(*novo != (*atual)->fd){
            q = (*novo)->pai;
            (*novo)->balance = (*atual)->balance;
            if(q != NULL){
                if(*novo == q->fe)
                    q->balance++;
                else
                    q->balance--;
            }
            if((*novo)->fe != NULL){
                (*novo)->pai->fd = (*novo)->fe;
                (*novo)->fe->pai = (*novo)->pai;
                (*novo)->fe = NULL;
            }
            else
                (*novo)->pai->fd = NULL;

            (*novo)->fd = (*atual)->fd;
            (*atual)->fd->pai = *novo;
            (*novo)->fe = (*atual)->fe;
            (*atual)->fe->pai = *novo;
        }
        else {
            q = (*atual)->pai;
            if(q != NULL){
                if(*atual == q->fe)
                    q->balance++;
                else
                    q->balance--;
            }
        }
        (*novo)->pai = (*atual)->pai;
    }

    if((*atual)->pai != NULL && *atual == (*atual)->pai->fe)
        (*atual)->pai->fe = *novo;
    else if((*atual)->pai != NULL && *atual == (*atual)->pai->fd)
        (*atual)->pai->fd = *novo;

    if (*novo != NULL && (*novo)->pai == NULL)
        *raiz = *novo;
    if(q != NULL){
        reduzirBalanco(&q);
        if(q->pai == NULL)
            *raiz = q;
    }
    return;
}

/* exclui o nodo correspondete a chave
 * retorna 1 em caso de sucesso e 0 se falhar   */
int excluir(struct nodo** raiz, int chave){
    struct nodo* atual;
    struct nodo* novo;

    if(*raiz == NULL)
        return 0;

    atual = buscar(*raiz, chave);
    if(!atual)
        return 0;

    novo = antecessor(atual);
    if(!novo)
        novo = atual->fd;

    transplantar(&atual, &novo, raiz);

    free(atual);
    return 1;
}

void imprimirEmOrdem(struct nodo* raiz){
    if (raiz !=NULL){
        imprimirEmOrdem(raiz->fe);
        printf("%d ", raiz->chave);
        imprimirEmOrdem(raiz->fd);
    }
}

void imprimirEmLargura(struct nodo* raiz) {
    struct fila* fila = cria_fila();
    size_t tam = 1, tamP = 0;
    struct nodo* n;
    unsigned int nivel = 0;

    printf("[%d]", nivel);
    insere_fila(&fila, raiz);

    while (!vazia_fila(fila)) {
        n = retira_fila(&fila);
        printf(" %d(%d)", n->chave, n->balance);
        if (n->fe != NULL){
            insere_fila(&fila, n->fe);
            tamP++;
        }
        if (n->fd != NULL){
            insere_fila(&fila, n->fd);
            tamP++;
        }
        tam--;
        if(tam == 0) {
            printf("\n");
            tam = tamP;
            nivel++;
            if (tamP != 0)
                printf("[%d]", nivel);
            tamP = 0;
        }
    }
    destroi_fila(fila);
    return;
}
