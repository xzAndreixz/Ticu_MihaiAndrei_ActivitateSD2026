#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
}Masina;


Masina citireMasinaFisier(FILE* file) {
	Masina m;
	char buffer[100];
	char* token;
	char delimitatori[] = ",\n";

	fgets(buffer, 100, file);
	token = strtok(buffer, delimitatori);
	m.id = atoi(token);
	
	token = strtok(NULL, delimitatori);
	m.nrUsi = atoi(token);

	token = strtok(NULL, delimitatori);
	m.pret = atof(token);

	token = strtok(NULL, delimitatori);
	m.model = (char*)malloc(strlen(token) + 1);
	strcpy(m.model, token);

	token = strtok(NULL, delimitatori);
	m.numeSofer = (char*)malloc(strlen(token) + 1);
	strcpy(m.numeSofer, token);

	token = strtok(NULL, delimitatori);
	m.serie = token[0];

	return m;
}

void afisareMasina(Masina m) {
	printf("\nId: %d", m.id);
	printf("\nNr usi: %d", m.nrUsi);
	printf("\nPret: %.2f", m.pret);
	printf("\nModel: %s", m.model);
	printf("\nNume sofer: %s", m.numeSofer);
	printf("Serie: %c", m.serie);
}
void adaugaMasiniInVector(Masina** masini, int* nrMasini, Masina m) {
	Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
	for (int i = 0; i < (*nrMasini); i++) {
		aux[i] = (*masini)[i];
	}
	aux[(*nrMasini)] = m;
	free((*masini));
	(*masini) = aux;
	(*nrMasini)++;

}

void afisareVectorMasini(Masina* masini, int nrMasini) {
	for (int i = 0; i < nrMasini; i++) {
		afisareMasina(masini[i]);
	}
}

void dezalocareVectorMasini(Masina** masini, int* nm) {
	for (int i = 0; i < (*nm); i++) {
		free((*masini)[i].model);
		free((*masini)[i].numeSofer);
	}
	free((*masini)); masini = NULL;
	(*nm) = 0;
}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrm) {
	Masina* masini = NULL;
	FILE* f = fopen(numeFisier, "r");
	if (f != NULL) {
		while (!feof(f)) {
			Masina m = citireMasinaFisier(f);
			adaugaMasiniInVector(&masini, nrm, m);
		}
		fclose(f);
	}
	return masini;
}

int main() {

	Masina* masini = NULL;
	int nrMasini = 0;
	masini = citireVectorMasiniFisier("masini.txt", &nrMasini);

	afisareVectorMasini(masini, nrMasini);
	dezalocareVectorMasini(&masini, &nrMasini);

	printf("Numar masini dupa dezalocare: %d", nrMasini);


	return 0;
}