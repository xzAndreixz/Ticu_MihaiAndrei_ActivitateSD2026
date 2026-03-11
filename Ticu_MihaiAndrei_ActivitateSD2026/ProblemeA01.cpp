#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string>
struct Rezervare {

	int id;
	char numeClient[50];
	int numarCamera;
	int nopti;
	float pretPerNoapte;
};

struct Rezervare initializare(int id, const char numeClient[50], int numarCamera, int nopti, float pretPerNoapte) {
	struct Rezervare i1;
	i1.id = id;
	if (strlen(numeClient) < 50)
		strcpy(i1.numeClient, numeClient);
	else {
		printf("Ai depasit numarul de caractere!");
	}
	i1.numarCamera = numarCamera;
	i1.nopti = nopti;
	i1.pretPerNoapte = pretPerNoapte;

	return i1;
}

void afisare(struct Rezervare afisare) {
	printf("Id rezervare: %d\n", afisare.id);
	printf("Nume client: %s\n", afisare.numeClient);
	printf("Camera: %d\n", afisare.numarCamera);
	printf("Nopti: %d\n", afisare.nopti);
	printf("Pret per noapte: %.2f\n", afisare.pretPerNoapte);
}

int main() {

	struct Rezervare r1;
	r1 = initializare(1, "Andrei", 108, 3, 150);
	afisare(r1);

	return 0;
}