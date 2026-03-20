#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct Stick {

	int capacitate;
	float viteza;
	char* model;

}Stick;


Stick initializare(int capacitate, float viteza, const char* model) {
	Stick i;
	i.capacitate = capacitate;
	i.viteza = viteza;
	i.model = (char*)malloc(sizeof(char) * (strlen(model) + 1));
	strcpy(i.model, model);

	return i;
}



void afisare(Stick s) {
	printf("\n");
	if (s.capacitate > 0)
		printf("Capacitatea: %d\n", s.capacitate);
	else 
		printf("Capacitatea: Necunoscuta\n");
	
	if (s.viteza > 0)
		printf("Viteza: %.1f\n", s.viteza);
	else
		printf("Viteza: Necunoscuta\n");

	if (s.model != NULL && strlen(s.model) > 0) {
		printf("Model: %s\n", s.model);
	}
	else {
		printf("Model: Necunoscut\n");
	}
	printf("\n");

}



int main() {


	Stick s1 = initializare(64, 30, "Samsung");
	Stick s2 = initializare(16, 10, "W");
	Stick s3 = initializare(8, 10, "Apacer");

	afisare(s1);
	afisare(s2);
	afisare(s3);



	return 0;

}