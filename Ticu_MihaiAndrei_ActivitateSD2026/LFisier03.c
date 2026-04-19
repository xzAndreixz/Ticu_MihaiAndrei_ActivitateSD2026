//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct {
//	float suprafata;
//	char* locatie;
//}Casa;
//
//Casa initializare(float sup, const char* loc) {
//	Casa c;
//	c.suprafata = sup;
//	c.locatie = (char*)malloc(sizeof(char) * (strlen(loc) + 1));
//	strcpy(c.locatie, loc);
//	return c;
//}
//
//
//void adaugaElVectFinal(Casa** vector, int* dimV, Casa elNou) {
//	Casa* aux = (Casa*)malloc(sizeof(Casa) * ((*dimV) + 1));
//	for (int i = 0; i < (*dimV); i++) {
//		aux[i] = (*vector)[i];
//	}
//	aux[(*dimV)] = elNou;
//	free((*vector));
//	(*vector) = aux;
//	(*dimV)++;
//
//}
//
//
//Casa citireElFis(FILE* file) {
//	Casa c;
//	char buffer[150];
//	char sep[4] = ",;\n";
//	fgets(buffer, 150, file);
//	c.suprafata = atof(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	c.locatie = (char*)malloc(sizeof(char) * ((strlen(aux) + 1)));
//	strcpy(c.locatie, aux);
//
//	return c;
//
//}
//
//Casa* citireVFisier(const char* numeF, int* dim) {
//
//	FILE* file = fopen(numeF, "r");
//	Casa* casele = NULL;
//	(*dim) = 0;
//
//	while (!feof(file)) {
//		Casa c = citireElFis(file);
//		adaugaElVectFinal(&casele, dim, c);
//	}
//
//	fclose(file);
//	return casele;
//
//
//}
//
//
//void dezalocare(Casa* c) {
//	free((*c).locatie);
//}
//void dezVect(Casa** c, int* dim) {
//	for (int i = 0; i < (*dim); i++) {
//		free((*c)[i].locatie);
//	}
//
//	free(*c);
//}
//
//
//
//int main() {
//	int n = 0;
//	Casa* casele = citireVFisier("case.txt", &n);
//
//	
//
//	return 0;
//}