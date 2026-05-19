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

void dezalocareNod(Nod** cap) {
	Nod* curent = *cap;
	while (curent != NULL) {
		Nod* temp = curent;
		curent = curent->next;
		free(temp);
	}
	*cap = NULL;
}

void dezalocareHashTable(HashTable* h) {
	for (int i = 0; i < h->dim; i++) {
		dezalocareNod(&h->liste[i]);
	}
	free(h->liste);
	h->liste = NULL;
}


int cautare(HashTable h, int val) {
	int index = calculeazaHash(val, h.dim);
	Nod* curent = h.liste[index];
	while (curent != NULL) {
		if (curent->valoare == val)
			return 1;
		curent = curent->next;

	}
	return 0;
}

float* calculValMediePerCluster(HashTable h) {
	int lungimeV = 0;
	float* v;
	for (int i = 0; i < h.dim; i++) {
		if (h.liste[i] != NULL)
			lungimeV++;
	}

	if (lungimeV)
	{
		v = (int*)malloc(sizeof(int) * lungimeV);
		int j = 0;
		for (int i = 0; i < h.dim; i++) {
			Nod* curent = h.liste[i];
			if (curent != NULL) {
				float s = 0; int k = 0;
				while (curent != NULL) {
					s = s + (float)curent->valoare;
					k++;
					curent = curent->next;
				}
				s = s / (float)k;
				v[j++] = s;
			}

		}
		return v;
	}
	else {
		return NULL;
	}


}
int calucleazaLungime(HashTable h) {
	int lungimeV = 0;
	int* v;
	for (int i = 0; i < h.dim; i++) {
		if (h.liste[i] != NULL)
			lungimeV++;
	}
	return lungimeV;
}

int main() {

	float* v = NULL;
	HashTable h1;
	h1 = initializare(10);
	inserareHash(h1, 25);
	inserareHash(h1, 35);
	inserareHash(h1, 45);
	inserareHash(h1, 28);
	inserareHash(h1, 38);
	inserareHash(h1, 41);

	afisareHash(h1);


	if (cautare(h1, 49)) {
		printf("Este in hash!");
	}
	else {
		printf("Nu este in hash!");
	}


	
	int n = calucleazaLungime(h1);
	v = calculValMediePerCluster(h1);
	for (int i = 0; i < n; i++) {
		printf("\nVal. med. cluster %d este: %.2f\n", i, v[i]);
	}
	return 0;
}