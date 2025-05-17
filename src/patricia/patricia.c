#include "../../includes/patricia/PATRICIA.h"


// Retorna o bit mais significativo a left
int pegaBit(int key, int pos) 
{
    if (pos < 0 || pos >= sizeof(int) * 8) return 0;  //evita valores negativos
    return (key >> pos) & 1;
}

// Cria um novo no folha
node* novoNo(int key, int index) 
{
    node* no = (node*) malloc(sizeof(node));
    no->key = key;
    no->index = index;
    no->left = NULL;
    no->right = NULL;
    return no;
}

//Inserir nos na arvore 

node* Inserir(node* root, int key) {
    int i;

    if (root == NULL)
        return novoNo(key, -1);

    // Caso especial: root é uma folha
    if (root->left == root && root->right == root) {
        if (root->key == key) {
            printf("Chave ja existente: %d\n", key);
            return root;
        }

        // Encontrar primeiro bit onde divergem
        for (i = 0; i < 32; i++) {
            if (pegaBit(key, i) != pegaBit(root->key, i))
                break;
        }
        
        printf("Chave %d e key %d diferem no bit de posicao %d\n", key, root->key, i);

        node* novo = novoNo(key, -1);
        node* interno = (node*)malloc(sizeof(node));
        interno->index = i;
        interno->key = 0;

        if (pegaBit(key, i) == 0) {
            interno->left = novo;
            interno->right = root;
        } else {
            interno->left = root;
            interno->right = novo;
        }

        return interno;
    }

    // Procurar folha mais próxima
    node* y = root;
    node* x = pegaBit(key, root->index) ? root->right : root->left;

    while (y->index < x->index){
        y = x;
        x = pegaBit(key, x->index) ? x->right : x->left;
    }

    // Encontrar primeiro bit onde divergem
    for (i = 0; i < 32; i++) {
        if (pegaBit(key, i) != pegaBit(x->key, i))
            break;
    }

	printf("Chave %d e key %d diferem no bit de posicao %d\n", key, x->key, i);


    node* novo = novoNo(key, -1);
    node* interno = (node*)malloc(sizeof(node));
    interno->index = i;
    interno->key = 0;

    if (pegaBit(key, i) == 0) {
        interno->left = novo;
        interno->right = x;
    } else {
        interno->left = x;
        interno->right = novo;
    }

    // Se o novo índice de desvio é menor que o da root, inserir acima da root
    if (i < root->index) {
        if (pegaBit(key, i) == 0) {
            interno->left = novo;
            interno->right = root;
        } else {
            interno->left = root;
            interno->right = novo;
        }
        return interno;
    }

    // Caso contrário, inserir no ponto certo abaixo
    node* h = root;
    node* k = pegaBit(key, root->index) ? root->right : root->left;

    while (h->index < k->index && k->index < i) {
        h = k;
        k = pegaBit(key, k->index) ? k->right : k->left;
    }

    if (pegaBit(key, i) == 0) {
        interno->left = novo;
        interno->right = k;
    } else {
        interno->left = k;
        interno->right = novo;
    }

    if (pegaBit(key, h->index) == 0)
        h->left = interno;
    else
        h->right = interno;

    return root;
}


//pesquisar um no na arvore
int Pesquisar(node* root, int key) 
{
    if (root == NULL) return 0;

    if (root->left == root && root->right == root)
        return root->key == key;

    node* y = root;
    node* x = pegaBit(key, root->index) ? root->right : root->left;

    while (y->index < x->index) 
	{
        y = x;
        x = pegaBit(key, x->index) ? x->right : x->left;
    }

    return x->key == key;
}


//remover um nó da árvore
node *removerNo(node *root, int key)
{
	if (root == NULL)
	{
    	puts("nodeore vazia!!!");
		return root;	
	} 
	
	node *pai;
	node *avo;
	node *noaremover;
	
	//verifica se a root é folha
	if(root->right == root && root->left == root)
{
		if(root->key == key)
		{
			free(root);
			puts("Chave removida com sucesso!");
			return NULL;
		}
		else
		{
			puts("Chave nao encontrada!");
			return root;
		}	
	}
	
	//Localizar o nó a ser removido e os seus pais
	pai = root;
	noaremover = pegaBit(key, root->index) ? root->right : root->left;
	
	while(pai->index < noaremover->index){
			avo = pai;
			pai = noaremover;
			noaremover = pegaBit(key, noaremover->index) ? noaremover->right : noaremover->left;
	}
	
	 // Verifica se a key realmente existe
    if (noaremover->key != key) {
        printf("Chave nao encontrada.\n");
        return root;
    }
    
     // Se p == root e p->left/right for folha, caso especial
     if(pai == root && (pai->left->left == pai->left && pai->right->right == pai->right)){
	 
		node* outro = (pai->left == noaremover) ? pai->right : pai->left;
        free(noaremover);
		free(pai);
		puts("Chave removida com sucesso!");
        return outro;
    }
        
    // Se x é filho esquerdo ou direito de p
    node* outroFilho = (pai->left == noaremover) ? pai->right : pai->left;
    
    if (avo == NULL) 
	{
        // Removendo diretamente da root
        free(noaremover);
        free(pai);
        puts("Chave removida com sucesso!");
        return outroFilho;
    }
    
    if (avo->left == pai)
        avo->left = outroFilho;
    else
        avo->right = outroFilho;
	
	free(noaremover);
    free(pai);
	puts("Chave removida com sucesso!");  
    return root;
}

//Imprimir arvore em ordem(red)
void Imprimir(node* no)
{
    if (no == NULL) return;	 

    if (no->left == no && no->right == no) 
	{
        printf("Chave: %d \n", no->key);
        return;
    }
    
    	printf("Desvio: %d\n", no->index);

    Imprimir(no->left);
    Imprimir(no->right);
}