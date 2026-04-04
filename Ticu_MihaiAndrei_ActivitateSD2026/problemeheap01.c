#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Masina {
	int cP;
	int nrLocuri;
	float consum;
}Masina;

Masina initializare(int cP, int nrLocuri, float consum) {
	Masina m;
	m.cP = cP;
	m.nrLocuri = nrLocuri;
	m.consum = consum;
	return m;
}

void afisareMasina(Masina m) {
	printf("Cai putere: %d\n", m.cP);
	printf("Nr. locuri: %d\n", m.nrLocuri);
	printf("Consum: %.2f\n", m.consum);
}

typedef struct Heap {
	Masina* elemente;
	int lungime;
	int nrEl;

}Heap;

Heap intializare(int lungime) {
	Heap h;
	h.elemente = (Masina*)malloc(sizeof(Masina)*lungime);
	h.lungime = lungime;
	h.nrEl = 0;
	return h;
}


int main() {

	Masina m;
	m = initializare(110, 5, 4.9);
	afisareMasina(m);

	Heap h1 = intializare(10);


	return 0;
}