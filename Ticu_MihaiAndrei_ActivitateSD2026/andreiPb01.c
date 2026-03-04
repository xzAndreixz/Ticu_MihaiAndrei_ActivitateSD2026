#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int varsta;
	char nume[50];
	double avere;

	printf("Nume: "); scanf_s("%s", nume, (unsigned)sizeof(nume)); 
	printf("Varsta: "); scanf_s("%d", &varsta);
	printf("Avere: "); scanf_s("%lf", &avere);


	printf("%s are la varsta de %d ani o avere de aproximativ %5.2lf euro", nume, varsta, avere);


	return 0;
}