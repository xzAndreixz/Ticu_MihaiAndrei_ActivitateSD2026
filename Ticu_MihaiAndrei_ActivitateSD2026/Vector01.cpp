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



int main() {

	int nrCaiete = 3;
	struct Caiet* vectorDeCaiete;
	vectorDeCaiete = (struct Caiet*)malloc(sizeof(struct Caiet) * nrCaiete);


	return 0;
}