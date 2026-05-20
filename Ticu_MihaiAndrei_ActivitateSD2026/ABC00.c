#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct Masina {

	int id;
	float pret;
	char* model;

}Masina;

typedef struct Nod {
	Masina info;
	struct Nod* stanga;
	struct Nod* dreapta;

}Nod;





int main() {

	



	return 0;
}
