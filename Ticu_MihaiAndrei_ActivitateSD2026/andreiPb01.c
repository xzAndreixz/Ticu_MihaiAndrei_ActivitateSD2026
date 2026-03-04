#include <stdio.h>

int main() {


	printf("Salut, Andrei!\n");

	int var = 0;
	printf("Te rog sa introduci un numar intreg:");
	scanf_s("%d", &var);

	printf("Ai introdus: %d \n", var);

	float s;
	printf("Introdu o variabila reala: ");
	scanf_s("%f", &s);
	printf("Ai introdus: %f", s);

	return 0;
}