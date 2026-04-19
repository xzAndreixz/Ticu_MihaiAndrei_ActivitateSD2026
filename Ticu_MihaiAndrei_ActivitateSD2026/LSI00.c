//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct {
//	int pret;
//	char* model;
//}Masina;
//
//typedef struct Nod{
//	Masina info;
//	struct Nod* next;
//
//}Nod;
//
//void afisareMasina(Masina m) {
//	printf("Pret: %d\n", m.pret);
//	printf("Model: %s\n", m.model);
//}
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareMasina(cap->info);  //dereferentiere si accesare prin ->
//		cap = cap->next;  // te-ai deplasat la urmatorul nod!!!
//	}
//}
//Masina citireMf(FILE* file) {
//	char buffer[150];
//	char sep[3] = ",\n";
//	fgets(buffer, 150, file);
//	char* aux;
//	Masina m1;
//	m1.pret = atof(strtok(buffer, sep));
//	aux = strtok(NULL, sep);
//	m1.model = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(m1.model, aux);
//
//	return m1;
//}
//
//
//void adaugareMasinaInListaLafinal(Nod** cap, Masina masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua; // shallow copy!
//	nou->next = NULL;
//	if ((*cap)) {
//		Nod* p = (*cap);  
//		while (p->next != NULL) { p = p->next; }
//
//		p->next = nou;
//		
//
//	} 
//	else {
//		(*cap) = nou;
//	}
//	
//}
//
//
//
//
//void adaugareInceput(Nod** cap, Masina masinaNous) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNous;
//	
//		nou->next = (*cap);
//		(*cap)= nou;
//}
//
//Nod* citireListaF(const char* numeFisier) {
//	Nod* cap = NULL;
//	FILE* f = fopen(numeFisier, "r");
//	if (f) {
//
//		while (!feof(f)) {
//			//creem lista cu inserare la sfarsit
//			adaugareMasinaInListaLafinal(&cap, citireMf(f));
//			
//		}
//
//
//	}
//	fclose(f);
//	return cap;
//}
//
//int sumaMasini(Nod* cap) {
//	int suma = 0;
//	while (cap != NULL) {
//		suma = suma + cap->info.pret;
//		cap = cap->next;
//	}
//
//	return suma;
//
//
//}
//
//void dezalocare(Nod** cap) {
//	while ((*cap)) {
//		Nod* p = (*cap);
//		(*cap) = (*cap)->next;
//		if (p->info.model != NULL) {
//			free(p->info.model);
//		}
//		free(p);
//	}
//}
//
//void sterge(Nod** cap, const char* model) {
//
//	while ((*cap) && (*cap)->info.model == model) {
//		Nod* aux = *cap;
//		(*cap) = (*cap)->next;
//		if (aux->info.model) {
//			free(aux->info.model);
//		}
//
//		free(aux);
//
//	}
//	//dupa ce iesi din while sti sigur ca pe prima pozitie nu exista seria/modelul respectiv
//	if (!(*cap)) {
//		Nod* p = (*cap);
//		while (p) {
//			while (p->next && p->next->info.model != model) {
//				p = p->next;
//			}
//
//			if (p->next) {
//				Nod* aux = p->next;
//				p->next = aux->next;
//				free(aux->info.model);
//				free(aux);
//			}
//
//
//
//
//		}
//	}
//}
//
//int main() {
//	Nod* cap = citireListaF("masini2.txt");
//	afisareLista(cap);
//
//	int s;
//	s = sumaMasini(cap);
//
//	printf("Suma: %d\n", s);
//
//	dezalocare(&cap);
//	return 0;
//}