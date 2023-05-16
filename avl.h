#ifndef AVL_H_
#define AVL_H_

struct nodo {
    int chave;
    struct nodo *pai;
    struct nodo *fe;
    struct nodo *fd;
    short int balance;
    //coloque demais itens aqui
};

struct aluno{
    char* nome;//nome completo
    char* nomeDinf;//nome de usuário nas servidoras do dinf
    unsigned int grr;
};

struct aluno* getAluno1();

//retorne NULL se o aluno2 não existir
struct aluno* getAluno2();

void imprimirDadosAlunos();

struct nodo *destroiNodo(struct nodo *nodo);

//retorna NULL se não foi possível inserir
struct nodo* inserir(struct nodo** raiz, int chave);

//retorna 1 caso removido, ou 0 caso não seja possível remover
int excluir(struct nodo** raiz, int chave);

//retorna NULL se não existe
struct nodo* buscar(struct nodo* nodo, int chave);

void imprimirEmOrdem(struct nodo* nodo);

void imprimirEmLargura(struct nodo* raiz);

#endif // AVL_H_
