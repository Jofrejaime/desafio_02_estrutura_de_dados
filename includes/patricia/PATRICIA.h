#ifndef PATRICIA_H
#define PATRICIA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

typedef struct Node 
{
    int index, key;
    struct Node* left;
    struct Node* right;

}node;

void menu();
void main_patricia();
node* Inserir(node* root, int key);
node* noFolha(int key);
//node* noDesvio(int index, node*left, node*right);
node* Remover(node* root, int key);
int Pesquisar(node* root, int key);
node *removerNo(node *root, int key);
void coletarChaves(node* no, int* keys, int* tamanho);
void Imprimir(node* no);

#endif