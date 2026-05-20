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

int main() {
	Masina m = initializare(1, 1000.5, "Astra");
	Masina m2 = initializare(5, 2000, "Audi");
	Masina m3 = initializare(15, 3000, "Opel");

	Nod* radacina = NULL;
	radacina = insereaza(radacina, m);
	radacina = insereaza(radacina, m2);
	radacina = insereaza(radacina, m3);

	Nod* rezultat = cauta(radacina, 5);

	if (rezultat != NULL) {
		printf("Gasit: %s\n", rezultat->info.model);
	}
	else {
		printf("Nu exista!\n");
	}


	return 0;
}
