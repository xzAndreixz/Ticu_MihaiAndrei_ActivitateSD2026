#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Laptop {
	char* model;
	float pret;
}Laptop;

Laptop initializare(const char* model, float pret) {
	Laptop r;
	r.model = (char*)malloc(sizeof(char) * (1 + strlen(model)));
	strcpy_s(r.model, 1 + strlen(model), model);
	r.pret = pret;
	return r;
}

void afisareLaptop(Laptop l) {
	printf("Model: %s\n", l.model);
	printf("Pret: %.2f\n", l.pret);

}

void dezalocareLaptop(Laptop* l) {
	if (l->model != NULL) {
		free(l->model);
		l->model = NULL;
	}
	l->pret = 0;
}

Laptop copiazaLaptop(Laptop l) {
	Laptop c;
	c.model = (char*)malloc(sizeof(char) * (strlen(l.model) + 1));
	strcpy_s(c.model, 1 + strlen(l.model), l.model);
	c.pret = l.pret;

	return c;
}


int main() {
	
	Laptop l1 = initializare("ASUS", 3499.99);
	afisareLaptop(l1);
	


	return 0;
}