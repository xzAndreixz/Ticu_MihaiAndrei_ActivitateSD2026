#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
}Masina;

void afisareMasina(Masina m) {
	printf("Id: %d\n", m.id);
	printf("Nr. usi: %d\n", m.nrUsi);
	printf("Pret %.2f\n", m.pret);
	printf("Model: %s\n", m.model);
	printf("Sofer: %s\n", m.numeSofer);
	printf("Serie: %c\n", m.serie);
}

void afisareVectorMasini(Masina* m, int dim) {
	for (int i = 0; i < dim; i++) {
		afisareMasina(m[i]);
	}
}


void adaugareVectorMasini(Masina** m, int* nrMasini, Masina masinaNoua) {

	Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
	for (int i = 0; i < (*nrMasini); i++) {
		aux[i] = (*m)[i];
	}
	aux[(*nrMasini)] = masinaNoua;  //shallow copy

	free((*m));
	(*m) = aux;
	(*nrMasini)++;

}

Masina citireMasinaFisier(FILE* file) {
	Masina m;
	char buffer[150];
	char sep[4] = ",;\n";

	fgets(buffer, 150, file);
	m.id=atoi(strtok(buffer, sep));  // imi returneaza un char pointer
	m.nrUsi = atoi(strtok(NULL, sep));  //ii dai NULL ca sa se uite de unde a ramas. Daca ii dai buffer va pleca tot de la inceput!
	m.pret = atof(strtok(NULL, sep));
	char* aux;
	aux = strtok(NULL, sep);  //intoarce zona de memorie unde este acea valoare salvata
	m.model = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(m.model, aux);
	aux = strtok(NULL, sep);
	m.numeSofer = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(m.numeSofer, aux);
	m.serie = strtok(NULL, sep)[0];  //imi returneaza un char pointer, adica sir de caractere, ii dai de 0 pentru a primi elementul de prima pozitie...adica vei lua primul caracter fara \n
	
	
	return m;

}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitire) {

	FILE* file = fopen(numeFisier, "r");
	Masina* masini = NULL;
	(*nrMasiniCitire) = 0;

	while (!feof(file)) {
		adaugareVectorMasini(&masini, nrMasiniCitire, citireMasinaFisier(file));
	}

	fclose(file); // inchizi fisierul

	return masini;


}

void dezalocareVmasini(Masina** m, int* dim) {
	for (int i = 0; i < (*dim); i++) {
		if ((*m)[i].model != NULL)
			free((*m)[i].model);
		if ((*m)[i].numeSofer != NULL)
			free((*m)[i].numeSofer);
	}
	free((*m));
	(*m) = NULL;
	(*dim) = 0;
}

int main() {

	int nrMasini = 0;
	Masina* masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
	afisareVectorMasini(masini, nrMasini);

	dezalocareVmasini(&masini, &nrMasini);

	return 0;
}