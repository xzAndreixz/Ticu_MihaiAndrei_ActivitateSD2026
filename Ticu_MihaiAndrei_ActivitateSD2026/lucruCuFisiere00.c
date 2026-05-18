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

int main() {

		


	return 0;
}