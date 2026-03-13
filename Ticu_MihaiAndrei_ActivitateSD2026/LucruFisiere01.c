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





int main() {

	

	return 0;
}