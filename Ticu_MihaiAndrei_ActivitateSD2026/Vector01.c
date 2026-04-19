//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Caiet {
//	char* tip;
//	int nrPg;
//};
//
//
//
//struct Caiet initializare(const char* tip, int nrPg) {
//	struct Caiet c;
//	c.nrPg = nrPg;
//	c.tip = (char*)malloc(sizeof(char) * strlen(tip) + 1);
//	strcpy_s(c.tip, strlen(tip) + 1, tip);
//
//	return c;
//}
//
//void afisare(struct Caiet c) {
//	printf("Tip: %s\n", c.tip);
//	printf("Nr. pagini: %d\n\n", c.nrPg);
//}
//
//void afisareVector(struct Caiet* a, int dim) {
//	for (int i = 0; i < dim; i++) {
//		afisare(a[i]);
//	}
//}
//
//struct Caiet* copaizaPrimeleNElemente(struct Caiet* c, int dim, int dimCopiaza) {
//	if (dimCopiaza > dim) { printf("Eroare, nu poti copia mai mult de %d elemente", dim); return 0; }
//	struct Caiet* v = (struct Caiet*)malloc(sizeof(struct Caiet) * dimCopiaza);
//	for (int i = 0; i < dimCopiaza; i++) {
//		v[i] = c[i];
//		v[i].tip = (char*)malloc(sizeof(char) * (strlen(c[i].tip) + 1));
//	}
//
//	return v;
//}
//
//void dezalocare(struct Caiet** v, int* nrElemente) {
//	if (*v != NULL) {
//		for (int i = 0; i < (*nrElemente); i++) {
//			if ((*v)[i].tip != NULL)
//				free((*v)[i].tip);
//		}
//		free((*v));
//		(*v) = NULL;
//		(*nrElemente) = 0;
//	}
//}
//
//struct Caiet* copaizaCaiete(struct Caiet* c, int dim, int nrPg,int* dimVcopiat){ // caietele care au mai mult de 80 de pagini
//	struct Caiet* vector;
//	int mem = 0;
//	for (int i = 0; i < dim; i++) {
//		if (c[i].nrPg > 80) mem++;
//	}
//	vector = (struct Caiet*)malloc(sizeof(struct Caiet) * mem);
//	int j = 0;
//	for (int i = 0; i < dim; i++) {
//		if (c[i].nrPg > 80) {
//			vector[j] = c[i];
//			vector[j].tip = (char*)malloc(sizeof(char) * (strlen(c[i].tip) + 1));
//			strcpy_s(vector[j].tip, strlen(c[i].tip) + 1, c[i].tip);
//			j++;
//		
//		}
//	}
//	(*dimVcopiat) = mem;
//	return vector;
//}
//
//void copaizaCaieteV2(struct Caiet* original, int dim, const char* tip, struct Caiet** copie, int* dimReturnata) {  //dereferentierea se mai faci si prin indexare!
//	if ((*copie) != NULL)
//		dezalocare(copie, dimReturnata);  
//	*dimReturnata = 0;
//	for (int i = 0; i < dim; i++) {
//		if (strcmp(original[i].tip, tip) == 0) (*dimReturnata)++;
//	}
//	
//	
//		int j = 0;
//		(*copie) = (struct Caiet*)malloc(sizeof(struct Caiet) * (*dimReturnata));
//		for (int i = 0; i < dim; i++) {
//			if (strcmp(original[i].tip, tip) == 0) {
//				(*copie)[j] = original[i];  //aici mai puteai sa scri *(original+i) inloc de original[i]...se observa dereferentierea prin indexare.
//				(*copie)[j].tip = (char*)malloc(sizeof(char) * (strlen(original[i].tip) + 1));
//				strcpy_s((*copie)[j].tip, strlen(original[i].tip) + 1, original[i].tip);
//				j++;
//			}
//		}
//
//}
//
//struct Caiet getPrimulCaietDupaTip(struct Caiet* a, int dim, const char* tip) {
//	
//	struct Caiet c;
//
//	for (int i = 0; i < dim; i++) {
//		if (strcmp(a[i].tip, tip) == 0) {
//			c = a[i];
//			c.tip = (char*)malloc(sizeof(char) * (strlen(tip) + 1));
//			strcpy_s(c.tip, strlen(tip) + 1, tip);
//			i = dim + 1;
//		}
//	}
//
//	return c;
//
//}
//
//
//int main() {
//	int nrCaiete = 3;
//	struct Caiet* caieteDiv = (struct Caiet*)malloc(sizeof(struct Caiet) * nrCaiete);
//
//	caieteDiv[0] = initializare("Mate", 150);
//	caieteDiv[1] = initializare("Rom", 100);
//	caieteDiv[2] = initializare("Mate", 60);
//	printf("Toate caietele: \n");
//	afisareVector(caieteDiv, nrCaiete);
//
//	int nrCaietePeste80DeFile;
//	struct Caiet* caietePeste80File;
//	caietePeste80File = copaizaCaiete(caieteDiv, nrCaiete, 80, &nrCaietePeste80DeFile);
//	printf("Toate aceste caiete au peste 80 de file: \n");
//	afisareVector(caietePeste80File, nrCaietePeste80DeFile);
//	
//	int dimCaieteDeMate = 0;
//	struct Caiet* caieteDeMate = NULL;
//	copaizaCaieteV2(caieteDiv, nrCaiete, "Mate", &caieteDeMate, &dimCaieteDeMate);
//	printf("\nAfisam doar caietele de mate: \n");
//	afisareVector(caieteDeMate, dimCaieteDeMate);
//	printf("Dimensiunea vectorului cu caietele de matematica: %d\n", dimCaieteDeMate);
//
//	copaizaCaieteV2(caieteDiv, nrCaiete, "Rom", &caieteDeMate, &dimCaieteDeMate);
//	printf("\nAfisam doar caietele de romana: \n");
//	afisareVector(caieteDeMate, dimCaieteDeMate);
//	printf("Dimensiunea vectorului cu caietele de romana: %d\n", dimCaieteDeMate);
//
//	
//	printf("\nPrimul caiet de mate: \n");
//	struct Caiet primul = getPrimulCaietDupaTip(caieteDiv, nrCaiete, "Mate");
//	afisare(primul);
//
//
//	return 0;
//}