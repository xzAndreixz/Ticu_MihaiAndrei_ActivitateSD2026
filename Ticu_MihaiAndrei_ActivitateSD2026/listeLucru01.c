#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Nod {
	int nr;
	struct Nod* urm;
}Nod;

void inserareLista(Nod** prim, int x) {
	Nod* q = (Nod*)malloc(sizeof(Nod));
	q->nr = x;
	q->urm = NULL;
	if ((*prim) == NULL) {
		(*prim) = q;
	}
	else {
		Nod* pas = (*prim);
		while (pas->urm != NULL) {
			pas = pas->urm;
		}
		pas->urm = q;
	}
}
void afisareLista(Nod* p) {
	if (p == NULL) {
		printf("Lista este goala!\n");
	}
	else {
		Nod* pas = p;
		while (pas != NULL) {
			printf("Valoare: %d\n", pas->nr);
			pas = pas->urm;
		}
	}
}

void adaugaInceput(Nod** prim, int x) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->nr = x;
	nou->urm = (*prim);
	(*prim) = nou;
	
}

int n = 5, i, a;
int main() {


	Nod* p = NULL;
	for (i = 0; i < n; i++) {
		printf("Intorduceti in lista: ");
		scanf_s("%d", &a);
		//inserareLista(&p, a);
		adaugaInceput(&p, a);
	}

	afisareLista(p);

	return 0;
}