#include "../../includes/hash_table/hashtable.h"

void init_table(int table[]) {
    int i;
	for (i = 0; i < M; i++) {
        table[i] = EMPTY;
    }
}

int hash1(int key) {
    return key % M;
}

int hash2(int key) {
    return 1 + (key % (M - 1));
}

void insert(int table[], int key) {
    int h1 = hash1(key);
    int h2 = hash2(key);
    int index;
	int i;
    for (i = 0; i < M; i++) {
        index = (h1 + i * h2) % M;
        if (table[index] == EMPTY) {
            table[index] = key;
            printf("Chave inserida com sucesso!");
            return;
        }
    }

    printf("Erro: tabela cheia, nao foi possivel inserir a chave %d\n", key);
}

int search(int table[], int key) {
    int h1 = hash1(key);
    int h2 = hash2(key);
    int index;
	int i;
    for (i = 0; i < M; i++) {
        index = (h1 + i * h2) % M;
        if (table[index] == key)
            return index;
        if (table[index] == EMPTY)
            return -1;
    }

    return -1;
}

void print_table(int table[]) {
    int i;
	for (i = 0; i < M; i++) {
        if (table[i] != EMPTY)
            printf("Posicao %d: %d\n", i, table[i]);
        else
            printf("Posicao %d: [NULL]\n", i);
    }
}
