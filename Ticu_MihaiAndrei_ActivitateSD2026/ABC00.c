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

	return nou;
}

Nod* insereaza(Nod* radacina, Masina m) {
	if (radacina == NULL)
		return creeazaNod(m);

	if (m.id < radacina->info.id) {
		radacina->stanga = insereaza(radacina->stanga, m);
	}
	else if (m.id > radacina->info.id) {
		radacina->stanga = insereaza(radacina->stanga, m);
	}

	return radacina;

}

int main() {
	Masina m = initializare(1, 1000.5, "Astra");
	Nod* radacina = NULL;
	insereaza(radacina, m);



	return 0;
}
