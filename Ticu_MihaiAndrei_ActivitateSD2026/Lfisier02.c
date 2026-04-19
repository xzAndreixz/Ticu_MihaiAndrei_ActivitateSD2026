//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct {
//	char* culoare;
//	
//}Pix;
//
//Pix initializare(const char* culoare) {
//	Pix p;
//	p.culoare = (char*)malloc(sizeof(char) * strlen((culoare)+1));
//	strcpy(p.culoare, culoare);
//
//	return p;
//}
//
//void afisare(Pix p) {
//	printf("\nCuloare: %s\n", p.culoare);
//}
//
//void afisareVPixuri(Pix* p, int dim) {
//	for (int i = 0; i < dim; i++)
//		afisare(p[i]);
//}
//
//
//Pix* adaugareLaFinalVector(Pix** vector, int* dim, Pix elNou) {
//
//	Pix* aux = (Pix*)malloc(sizeof(Pix) * ((*dim) + 1));
//	for (int i = 0; i < (*dim); i++) {
//		aux[i] = (*vector)[i];
//	}
//	aux[(*dim)] = elNou;
//	free((*vector));
//	(*vector) = aux;
//	(*dim)++;
//
//	return (*vector);
//}
//
//
//Pix* citireDinFisier(const char* numeF, int* nrPixuriCitite) {
//	FILE* file = fopen(numeF, "r");
//	Pix* pixuri = NULL;
//	char buffer[150];
//	char sep[4] = ",;\n";
//	*nrPixuriCitite = 0;
//	fgets(buffer, 150, file);
//	char* aux = strtok(buffer, sep);
//
//	while (aux != NULL) {
//		Pix p;
//		p.culoare = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//		strcpy(p.culoare, aux);
//		adaugareLaFinalVector(&pixuri, nrPixuriCitite, p);
//		aux = strtok(NULL, sep);
//	}
//	fclose(file);
//	return pixuri;
//}
//
//
//int main() {
//
//	Pix p1 = initializare("Albastru");
//
//	afisare(p1);
//
//
//
//	Pix* pixuri = (Pix*)malloc(sizeof(Pix) * 2);
//	pixuri[0] = initializare("Maro");
//	pixuri[1] = initializare("Rosu");
//	afisareVPixuri(pixuri, 2);
//	int n = 0;
//	Pix* fisierPixuri;
//	fisierPixuri = citireDinFisier("pixuri.txt", &n);
//
//
//	afisareVPixuri(fisierPixuri, n);
//
//	return 0;
//}