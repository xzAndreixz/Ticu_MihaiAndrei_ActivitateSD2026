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



int main() {

	

	return 0;
}