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



int main() {

	Masina m;
	m = initializare(110, 5, 4.9);
	afisareMasina(m);


	return 0;
}