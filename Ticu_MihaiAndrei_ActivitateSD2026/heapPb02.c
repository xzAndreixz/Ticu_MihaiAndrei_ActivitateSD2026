
#include <stdio.h>
#include<stdlib.h>

typedef struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
}Masina;

void initializareMasina(int id, int nrUsi, float pret, const char* model, const char* numeSofer, unsigned char serie) {
	Masina m;
	m.id = id;
	m.nrUsi = nrUsi;
	m.pret = pret;
	m.model = (char*)malloc(sizeof(char) * (1 + strlen(model)));
	m.numeSofer = (char*)malloc(sizeof(char) * (1 + strlen(numeSofer)));
	m.serie = serie;
}

typedef struct Heap {

	Masina* vectorMasini;
	int dimensiune;
	int capacitate;

}Heap;


Heap intializareHeap(int capacitate) {
	Heap h;
	h.capacitate = capacitate;
	h.dimensiune = 0;
	h.vectorMasini = (Masina*)malloc(sizeof(Masina) * capacitate);

	return h;
}



int main() {




	return 0;

}