#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod {
	int valoare;
	struct Nod* next;
}Nod;

typedef struct HashTable {
	int dim;
	Nod** liste;
}HashTable;

HashTable initializare(int dim) {
	HashTable h;
	h.dim = dim;
	h.liste = (Nod**)malloc(sizeof(Nod*) * dim);
	for (int i = 0; i < dim; i++)
		h.liste[i] = NULL;
	return h;
}

int main() {

	HashTable h1;
	h1 = initializare(10);


	return 0;
}