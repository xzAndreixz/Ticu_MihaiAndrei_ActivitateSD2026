
#include <stdio.h>
#include<stdlib.h>

typedef struct Masina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;

}Masina;


Masina initializareMasina(int id, int nrUsi, float pret, const char* model, const char* numeSofer) {
	Masina m;
	m.id = id;
	m.nrUsi = nrUsi;
	m.pret = pret;
	m.model = (char*)malloc(sizeof(char) * (1 + strlen(model)));
	m.numeSofer = (char*)malloc(sizeof(char) * (1 + strlen(numeSofer)));
	return m;
}

void afisareMasina(Masina m) {
	printf("Id: %d\n", m.id);
	printf("Nr usi: %d\n", m.nrUsi);
	printf("Pret: %.2f\n", m.pret);
	printf("Model: %s\n", m.model);
	printf("Nume sofer: %s\n", m.numeSofer);
	
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

void afisareHeap(Heap h) {
	for (int i = 0; i < h.dimensiune; i++) {
		printf("Pozitia %d:\n", i);
		afisareMasina(h.vectorMasini[i]);
	}

int main() {

	Heap h = initializareHeap(5);

	h.vectorMasini[0] = initializareMasina(1, 4, 12000, "BMW", "Ana");
	h.vectorMasini[1] = initializareMasina(2, 2, 8000, "Audi", "Dan");
	h.vectorMasini[2] = initializareMasina(3, 4, 15000, "Mercedes", "Ion");
	h.vectorMasini[3] = initializareMasina(4, 5, 7000, "Dacia", "Maria");
	h.vectorMasini[4] = initializareMasina(5, 4, 20000, "Tesla", "Radu");

	h.dimensiune = 5;

	for (int i = (h.dimensiune - 2) / 2; i >= 0; i--) {
		filtarereHeapMax(h, i);
	}



	return 0;

}