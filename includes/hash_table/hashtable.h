#ifndef HASHTABLE_H
#define HASHTABLE_H

# include <stdio.h>

#define M 11
#define EMPTY -1
void main_hash();
void init_table(int table[]);
int hash1(int key);
int hash2(int key);
void insert(int table[], int key);
int search(int table[], int key);
void print_table(int table[]);

#endif
