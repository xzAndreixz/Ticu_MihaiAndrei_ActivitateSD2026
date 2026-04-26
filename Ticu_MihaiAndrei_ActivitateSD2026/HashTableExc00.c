#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Laptop {
	char* model;
	float pret;
}Laptop;

Laptop initializare(const char* model, float pret) {
	Laptop r;
	r.model = (char*)malloc(sizeof(char) * (1 + strlen(model)));
	strcpy_s(r.model, 1 + strlen(model), model);
	r.pret = pret;
	return r;
}

void afisareLaptop(Laptop l) {
	printf("Model: %s\n", l.model);
	printf("Pret: %.2f\n", l.pret);

}

void dezalocareLaptop(Laptop* l) {
	if (l->model != NULL) {
		free(l->model);
		l->model = NULL;
	}
	l->pret = 0;
}

Laptop copiazaLaptop(Laptop l) {
	Laptop c;
	c.model = (char*)malloc(sizeof(char) * (strlen(l.model) + 1));
	strcpy_s(c.model, 1 + strlen(l.model), l.model);
	c.pret = l.pret;

	return c;
}

typedef struct Nod {
	Laptop info;
	struct Nod* next;
}Nod;


void adaugaLaptopInLista(Nod** lista, Laptop laptopNou) {
	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
	nodNou->info = copiazaLaptop(laptopNou);
	nodNou->next = NULL;

	if (*lista == NULL) {
		*lista = nodNou;  //folosesti ** pentru cazul in care lista ar fi goala si trebuie sa poti initializa inceputul listei :)!
	}
	else {
		Nod* pas = *lista;

		while (pas->next != NULL) {
			pas = pas->next;
		}
		pas->next = nodNou;

	}

}
void afisareLista(Nod* lista) {
	while (lista != NULL) {
		afisareLaptop(lista->info);
		lista = lista->next;
	}
}

typedef struct HashTable {
	int dim;
	Nod** vector;
}HashTable;


HashTable initializareHashTable(int dim) {
	HashTable h;
	h.dim = dim;
	h.vector = (Nod**)malloc(sizeof(Nod*) * dim);
	for (int i = 0; i < dim; i++) {
		h.vector[i] = NULL;
	}

	return h;
}


int calculeazaHash(const char* model, int dim) {
	return strlen(model) % dim;
}



int main() {
	
	Laptop l1 = initializare("ASUS", 3499.99);
	afisareLaptop(l1);
	Laptop l2 = copiazaLaptop(l1);
	l2.pret = 5000.0f;
	free(l2.model);
	l2.model = (char*)malloc(sizeof(char) * (1 + strlen("LENOVO")));
	strcpy_s(l2.model, 1 + strlen("LENOVO"), "LENOVO");


	Nod* lista=NULL;  //daca nu initializez cu NULL la functia de adaugare in lista intra pe else si da eroare!
	adaugaLaptopInLista(&lista, l1);
	adaugaLaptopInLista(&lista, l2);
	afisareLista(lista);

	int dim = 4;
	HashTable h;
	h = initializareHashTable(dim);

	int index = calculeazaHash(l1.model, dim);
	printf("Index: %d", index);


	return 0;
}