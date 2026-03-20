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



int main() {


	Stick s1 = initializare(64, 30, "Samsung");
	Stick s2 = initializare(16, 10, "W");
	Stick s3 = initializare(8, 10, "Apacer");





	return 0;

}