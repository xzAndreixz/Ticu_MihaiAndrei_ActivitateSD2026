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

void dezalocare(Stick* s) {
	if ((*s).model != NULL) {
		free((*s).model);
		(*s).model = NULL;
	}
}

void copiereDeep(Stick* destinatie, Stick sursa) {
	if (destinatie->model != NULL) {
		free(destinatie->model);
	}
	(*destinatie) = sursa;
	destinatie->model = (char*)malloc(sizeof(char) * (strlen(sursa.model) + 1));
	strcpy(destinatie->model, sursa.model);
}


void introducereInVector(Stick** vector, Stick introduc, int* dimVect) {
	Stick* aux = (Stick*)malloc(sizeof(Stick) * ((*dimVect)+1));
	int i = 0;
	if ((*vector) != NULL) {
		for (i = 0; i < (*dimVect); i++) {
			aux[i] = (*vector)[i];
		}
		free((*vector));
	}
	aux[i] = introduc;
	aux[i].model = (char*)malloc(sizeof(char) * (strlen(introduc.model) + 1));
	strcpy(aux[i].model, introduc.model);
	(*vector) = aux;  
	(*dimVect)++;
}

void afisareVector(Stick* vector, int dim) {
	if (vector != NULL) {
		for (int i = 0; i < dim; i++) {
			afisare(vector[i]);
		}
	}
	else {
		printf("Vectorul nu contine date!");
	}
}

void dezalocareVector(Stick** v, int* dimV) {
	if ((*v) != NULL) {
	for (int i = 0; i < (*dimV); i++) {
		dezalocare(&((*v)[i]));
	}
	free(*v);
	(*v) = NULL;
	(*dimV) = 0;
	}
	
}

void stergereElDupaIndex(Stick** v,int* dimV ,int pozitieSters) {
	if ((*v) != NULL) {
		if ((*dimV) > pozitieSters) {
			Stick* aux = (Stick*)malloc(sizeof(Stick) * (*dimV - 1));
			for (int i = 0; i < (*dimV); i++) {

				if (i < pozitieSters) {
					aux[i] = (*v)[i];
				}
				else {
					if (i > pozitieSters) {
						aux[i - 1] = (*v)[i];
					}
					else {
						dezalocare(&((*v)[i]));
					}
				}
			}
			free((*v));
			(*v) = aux;

			(*dimV)--;
		}
		else {
			printf("Numar maxim elemente %d. Tu ai dat %d\n", (*dimV), pozitieSters);
		}
	}
	else {
		printf("Nu ai ce sterge, vectorul nu are elemente!\n");
	}
}

int main() {


	Stick s1 = initializare(64, 30, "Samsung");
	Stick s2 = initializare(16, 10, "W");
	Stick s3 = initializare(8, 10, "Apacer");

	Stick* vector = NULL;
	int n = 0;
	introducereInVector(&vector, s1, &n);
	introducereInVector(&vector, s2, &n);
	introducereInVector(&vector, s3, &n);
	introducereInVector(&vector, s1, &n);
	
	afisareVector(vector, n);
	//afisare(*(vector));

	stergereElDupaIndex(&vector, &n, 22);
	printf("Dupa stergerea elementului!\n");
	afisareVector(vector, n);
	

	dezalocareVector(&vector, &n);
	afisareVector(vector, n);


	return 0;

}