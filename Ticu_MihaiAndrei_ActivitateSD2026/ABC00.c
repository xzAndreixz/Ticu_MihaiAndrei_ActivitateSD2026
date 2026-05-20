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


Nod* creeazaNod(Masina m) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = m;
	nou->info.model = (char*)malloc(strlen(m.model) + 1);
	strcpy(nou->info.model, m.model);

	return nou;
}

Nod* insereaza(Nod* radacina, Masina m) {
	if (radacina == NULL)
		creeazaNod(m);

	if (m.id < radacina->info.id) {
		insereaza(radacina->stanga, m);
	}
	else if (m.id > radacina->info.id) {
		insereaza(radacina->stanga, m);
	}

	return radacina;

}

int main() {

	



	return 0;
}
