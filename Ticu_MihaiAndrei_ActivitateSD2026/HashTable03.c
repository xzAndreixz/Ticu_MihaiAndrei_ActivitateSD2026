#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
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


Masina citireMasinaFisier(FILE* numefisier) {
	Masina m;
	char buffer[100];
	fgets(buffer, 100, numefisier);
	char delimitatori[] = ",\n";
	char* token = strtok(buffer, delimitatori);
	m.id = atoi(token);
	m.nrUsi = atoi(strtok(NULL, delimitatori));
	m.pret = atof(strtok(NULL, delimitatori));
	token = strtok(NULL, delimitatori);
	m.model = (char*)malloc(strlen(token) + 1);
	strcpy(m.model, token);
	token = strtok(NULL, delimitatori);
	m.numeSofer = (char*)malloc(strlen(token) + 1);
	strcpy(m.numeSofer, token);
	m.serie = (*strtok(NULL, delimitatori));
	return m;
}


void adaugaVectorMasini(Masina** masini, Masina m, int* dim) {
	Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*dim) + 1));
	for (int i = 0; i < (*dim); i++)
		aux[i] = (*masini)[i];
	aux[(*dim)] = m;
	free(*masini);
	(*masini) = aux;
	(*dim)++;
}

Masina* citireMasini(const char* numeFisier, int* dim) {

	FILE* f = fopen(numeFisier, "r");
	Masina* masini = NULL;
	if (f != NULL) {
		while (!feof(f)) {
			Masina m;
			m = citireMasinaFisier(f);
			adaugaVectorMasini(&masini,m, dim);
		}
		fclose(f);
	}
	
	return masini;
}

void afisareMasina(Masina m) {
	printf("\n");
	printf("Id: %d\n", m.id);
	printf("NrUsi: %d\n", m.nrUsi);
	printf("Pret: %.2f\n", m.pret);
	printf("Model: %s\n", m.model);
	printf("Nume sofer: %s\n", m.numeSofer);
	printf("Serie: %c\n", m.serie);


}

void afisareVectorMasini(Masina* m, int dim) {
	for (int i = 0; i < dim; i++) {
		afisareMasina(m[i]);
	}
}


typedef struct Nod {
	Masina m;
	struct Nod* next;
}Nod;

void adaugaListaInceput(Nod** cap, Masina m) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->m = m;
	nou->next = (*cap);
	(*cap) = nou;
}

void adaugaListaFinal(Nod** cap, Masina m) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->m = m;
	nou->next = NULL;
	Nod* curent = (*cap);

	if ((*cap) == NULL) {
		(*cap) = nou;
	}
	else {


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

HashTable initializareHash(int dim) {
	HashTable h;
	h.dim = dim;
	h.liste = (Nod**)malloc(sizeof(Nod*) * dim);
	for (int i = 0; i < h.dim; i++) {
		h.liste[i] = NULL;
	}

	return h;
	
}

int calcHash(HashTable h, int id) {
	return id % h.dim;
}

void insereazaHash(HashTable h, Masina m) {
	int index = calcHash(h, m.id);
	adaugaListaFinal(&h.liste[index], m);
}


void afisareHash(HashTable h) {
	for (int i = 0; i < h.dim; i++) {
		if (h.liste[i] != NULL) {
			printf("Lista[%d]: ", i);
			Nod* curent = h.liste[i];
			while (curent != NULL) {
				afisareMasina(curent->m);
				curent = curent->next;
			}
		}
		printf("\n");
	}
}



int main() {
	int dim=0;
	Masina* masini;
	masini = citireMasini("masini.txt", &dim);

	//afisareVectorMasini(masini,dim);

	HashTable h;
	h = initializareHash(10);
	for (int i = 0; i < dim; i++) {
		insereazaHash(h, masini[i]);
	}
	afisareHash(h);

	return 0;
}