
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


Heap initializareHeap(int capacitate) {
	Heap h;
	h.capacitate = capacitate;
	h.dimensiune = 0;
	h.vectorMasini = (Masina*)malloc(sizeof(Masina) * capacitate);

	return h;
}




void filtarereHeapMax(Heap h, int pozitieNod) {

	if (pozitieNod >= 0 && pozitieNod < h.dimensiune) {
		
		int stanga = 2 * pozitieNod + 1;
		int dreapta = stanga + 1;
		int pozMax = pozitieNod;

		if (stanga < h.dimensiune && h.vectorMasini[stanga].pret > h.vectorMasini[pozMax].pret) {
			pozMax = stanga;
		}

		if (dreapta < h.dimensiune && h.vectorMasini[dreapta].pret > h.vectorMasini[pozMax].pret) {
			pozMax = dreapta;
		}

		if (pozMax != pozitieNod) {
			Masina aux = h.vectorMasini[pozitieNod];
			h.vectorMasini[pozitieNod] = h.vectorMasini[pozMax];
			h.vectorMasini[pozMax] = aux;

			filtarereHeapMax(h, pozMax);
		}

	}

}


int main() {

	Heap h = initializareHeap(5);



	return 0;

}