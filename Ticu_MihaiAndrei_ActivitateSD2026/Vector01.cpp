#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Caiet {
	char* tip;
	int nrPg;
};

struct Caiet initializare() {
	struct Caiet c;
	c.nrPg = 60;
	c.tip = (char*)malloc(sizeof(char) * strlen("Matematica") + 1);
	strcpy_s(c.tip, strlen("Matematica") + 1, "Matematica");

	return c;
}


struct Caiet initializare(const char* tip, int nrPg) {
	struct Caiet c;
	c.nrPg = nrPg;
	c.tip = (char*)malloc(sizeof(char) * strlen(tip) + 1);
	strcpy_s(c.tip, strlen(tip) + 1, tip);

	return c;
}

void afisare(struct Caiet c) {
	printf("Tip: %s\n", c.tip);
	printf("Nr. pagini: %d\n\n", c.nrPg);
}

void afisareVector(struct Caiet* a, int dim) {
	for (int i = 0; i < dim; i++) {
		afisare(a[i]);
	}
}

struct Caiet* copaizaPrimeleNElemente(struct Caiet* c, int dim, int dimCopiaza) {
	if (dimCopiaza > dim) { printf("Eroare, nu poti copia mai mult de %d elemente", dim); return 0; }
	struct Caiet* v = (struct Caiet*)malloc(sizeof(struct Caiet) * dimCopiaza);
	for (int i = 0; i < dimCopiaza; i++) {
		v[i] = c[i];
		v[i].tip = (char*)malloc(sizeof(char) * (strlen(c[i].tip) + 1));
	}

	return v;
}



int main() {

	int nrCaiete = 3;
	struct Caiet* vectorDeCaiete;
	vectorDeCaiete = (struct Caiet*)malloc(sizeof(struct Caiet) * nrCaiete);
	
	vectorDeCaiete[0] = initializare("Matematica", 150);
	vectorDeCaiete[1] = initializare("Romana", 150);
	vectorDeCaiete[2] = initializare();
	return 0;
}