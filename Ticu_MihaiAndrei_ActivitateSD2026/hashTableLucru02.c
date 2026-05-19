#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod {
	int valoare;
	struct Nod* next;
}Nod;

void insereazaLaSfarsit(Nod** cap, int val) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->valoare = val;
	nou->next = NULL;

	if ((*cap) == NULL) (*cap) = nou;
	else {
		Nod* curent = (*cap);
		while (curent->next != NULL) {
			curent = curent->next;
		}
		curent->next = nou;
	}

}


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

int calculeazaHash(int val, int dim) {
	return val % dim;
}


void inserareHash(HashTable h, int val) {
	int index = calculeazaHash(val, h.dim);
	insereazaLaSfarsit(&h.liste[index], val);

}


void afisareHash(HashTable h) {
	for (int i = 0; i < h.dim; i++) {
		if (h.liste[i] != NULL) {
			Nod* curent = h.liste[i];
			printf("Index: %d -> ", i);
			while (curent != NULL) {
				printf("%d   ", curent->valoare);
				curent = curent->next;
			}printf("\n");
		}
		else {
			printf("Index: %d -> NULL\n", i);
		}
	}
}




int main() {

	HashTable h1;
	h1 = initializare(10);
	inserareHash(h1, 25);
	inserareHash(h1, 35);
	inserareHash(h1, 45);
	inserareHash(h1, 28);
	inserareHash(h1, 38);
	inserareHash(h1, 41);

	afisareHash(h1);


	return 0;
}