#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct Masina {

	int id;
	float pret;
	char* model;

}Masina;

typedef struct Nod {
	Masina info;
	struct Nod* stanga;
	struct Nod* dreapta;

}Nod;

Masina initializare(int id, float pret, const char* model) {
	Masina m;
	m.id = id;
	m.pret = pret;
	m.model = (char*)malloc(strlen(model) + 1);
	strcpy(m.model, model);

	return m;
}


Nod* creeazaNod(Masina m) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = m;
	nou->info.model = (char*)malloc(strlen(m.model) + 1);
	strcpy(nou->info.model, m.model);
	nou->stanga = NULL;
	nou->dreapta = NULL;

	return nou;
}

Nod* insereaza(Nod* radacina, Masina m) {
	if (radacina == NULL)
		return creeazaNod(m);

	if (m.id < radacina->info.id) {
		radacina->stanga = insereaza(radacina->stanga, m);
	}
	else if (m.id > radacina->info.id) {
		radacina->dreapta = insereaza(radacina->dreapta, m);
	}

	return radacina;

}

Nod* cauta(Nod* r, int id) {
	if (r == NULL || r->info.id == id)
		return r;
	if (id < r->info.id)
		return cauta(r->stanga, id);
	return cauta(r->dreapta, id);
}

void parcurgereInOrdine(Nod* r) {
	if (r == NULL) return;
	parcurgereInOrdine(r->stanga);
	printf("  ");
	parcurgereInOrdine(r->dreapta);
}

void adaugaMasiniaV(Masina** masini, Masina m, int* dim) {
		Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*dim) + 1));
	for (int i = 0; i < (*dim); i++) {
		aux[i] = (*masini)[i];
	}

	aux[*dim].id = m.id;
	aux[*dim].pret = m.pret;
	aux[*dim].model = (char*)malloc(strlen(m.model) + 1);
	strcpy(aux[*dim].model, m.model);

	free((*masini));
	(*masini) = aux;
	(*dim)++;
}

void afisareInOrdine(Nod* r) {
	if (r == NULL) return;
	afisareInOrdine(r->stanga);
	printf("Id: %d ", r->info.id);
	afisareInOrdine(r->dreapta);
}

void VectorInOrdine(Nod* r, Masina** m, int* dim) {
	if (r == NULL) return;
	VectorInOrdine(r->stanga,m,dim);
	adaugaMasiniaV(m,r->info,dim);
	VectorInOrdine(r->dreapta, m, dim);
}

int main() {
	Masina m = initializare(1, 1000.5, "Astra");
	Masina m2 = initializare(5, 2000, "Audi");
	Masina m3 = initializare(15, 3000, "Opel");
	
	Masina* masini = NULL;

	Nod* radacina = NULL;
	radacina = insereaza(radacina, m);
	radacina = insereaza(radacina, m2);
	radacina = insereaza(radacina, m3);

	int dim = 0;
	//afisareInOrdine(radacina);
	VectorInOrdine(radacina, &masini, &dim);

	for (int i = 0; i < dim; i++) {
		printf("Id: %d   ", masini[i].id);
	}

	return 0;
}
