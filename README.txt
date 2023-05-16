Trabalho de Gabriel Shigueo Ushiwa Kaguimoto Rodrigues
Login Dinf gsukr22
GRR 20221261

...E... 

Trabalho de Mateus Garcia Baiak
Login Dinf mgb22
GRR 20224378

A biblioteca avl contém as seguintes funções 

criaNodo: Aloca espaço para a struct nodo que representa um nodo da árvore.

destroiNodo: Libera espaço alocado para um nodo da árvore.

rotacaoDireita/Esquerda: Rotaciona o nodo apontado para a direita as propriedades vistas no estudo de árvores avl e alterando os respectivos valores. O filho esquerdo do nodo aponta para o pai do nodo e vice versa, o nodo se torna o filho direito de seu filho esquerdo e o filho direito do filho esquerdo do nodo se torna o filho esquerdo do nodo. Enquanto isso na rotação a esquerda a mesma idéia foi utilizada apenas trocando o lado da rotação(espelhado).

rebalancear: Responsável por rebalancear um nodo caso tenha sido, identifica qual dos quatro casos está lidando e efetua as rotações com base nisso. Se um novo nodo foi adicionado a esquerda do filho direito ou removido a direita do filho direito vai efetuar uma rotação a Direita do filho direito e uma rotação a esquerda no nodo logo em seguida, caso tenha sido adicionado a direita do filho direito ou removido a esquerda do filho direito sera efetuada apenas uma rotação a esquerda, nos outros dois casos a lógica segue identica porém espelhada.

atualizarBalanco: Atualiza o balanço dos nodos acima a partir do nodo que foi inserido.

inserir: Encontra o local em que o nodo deve ser inserido e insere e chama a função que atualiza o balanço.

buscar: Busca um nodo com a chave a ser encontrada, anda pelos nodos usando a propriedade da árvore até encontrar um nodo nulo, se a chave for encontrada retorna ela, caso contrário retorna NULL.

antecessor: Verifica se o nodo tem filho esquerdo se não tiver retorna NULL se tiver anda para o filho esquerdo do nodo até encontrar NULL, retorna o nodo antecessor.

reduzirBalanco: Rerduz o balanço a parir do nodo passado, utilizado na função transplantar.

transplantar: transplanta um nodo para efetuar a exclusão
Se não houver nodo antecessor nem sucessor. Verifica se é a raiz se for retorna se não apenas altera o balanço a partir do pai do nodo atual e retorna.
Se nodo novo for filho esquerdo do nodo atual o nodo novo apenas aponta para o pai do nodo atual. Caso haja um nodo pai ele aponta para o nodo novo e altera o balanço a partir do pai do nodo atual e retorna.
Se for antecessor verifica se tem filho esquerdo, se tiver o pai do novo nodo aponta para o filho esquerdo do novo nodo e vice versa, nodo novo aponta para o pai do nodo atual e se houver um nodo pai de atual diferente de NULL ele aponta de volta, nodo novo filho direito aponta para o nodo atual filho direito e vice versa, nodo novo filho esquerdo aponta para nodo atual filho esquerdo e vice versa, altera balanço a partir do pai do nodo novo e retorna.
Se for sucessor nodo novo aponta para nodo atual pai e vice versa se houver nodo pai, altera balanço a partir de nodo atual pai.

excluir: Tenta excluir um determinado valor.
Se não houver este valor na arvore retorna zero.
Chama função antecessor, se não houver pega o sucessor.
Chama a função transplantar e por fim exclui o nodo.

imprimirEmOrdem: Imprime em ordem, ou seja do menor para o maior valor.

imprimirEmLargura: Imprime em largura, ou seja imprime um nivel de cada vez sendo eles separados por linha, ainda imprime o nivel no inicio de cada linha e o balanço dos nodos;
Essa função utiliza as funções da biblioteca fila:
    A biblioteca fila implementa uma fila a partir de uma lista ligada e possui as seguintes funções:

    cria_fila: Inicializa a lista e retorna um ponteiro para a mesma.

    destroi_fila: Destroi a fila, desaloca a memoria dessa fila.

    vazia_fila: Verifica se a fila esta vazia,retorna 1 caso positivo e 0 caso contrario.

    insere_fila: Insere na fila o ponteiro passado.

    retira_fila: Retira da fila o elemento mais antigo, Retorna o nodo se a operacao foi bem sucedida e NULL caso contrario