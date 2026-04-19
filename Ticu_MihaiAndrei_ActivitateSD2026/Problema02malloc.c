//#include <stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct Film {
//	int id;
//	char* titlu;
//	float rating;
//	int anAparitie;
//};
//
//struct Film initializare(int id, const char* titlu, float rating, int anAparitie) {
//	struct Film f;
//	f.id = id;
//	f.titlu = (char*)malloc(sizeof(char) * (strlen(titlu) + 1));
//	strcpy_s(f.titlu, strlen(titlu) + 1, titlu);
//	f.rating = rating;
//	f.anAparitie = anAparitie;
//
//	return f;
//}
//
//void afisare(struct Film a) {
//	printf("Id film: %d\n", a.id);
//	if (a.titlu == NULL) {
//		printf("Titlu film: Necunoscut\n");
//	}
//	else {
//		printf("Titlu film: %s\n", a.titlu);
//	}
//	printf("Rating: %.1f\n", a.rating);
//	printf("An aparitie: %d\n", a.anAparitie);
//}
//
//void dezalocare(struct Film* d) {
//	if (d->titlu != NULL) {
//		free(d->titlu);
//		d->titlu = NULL;
//	}
//}
//
//
//void afiseazaColectieFilme(const struct Film* filme, int n) {  //am pus const pentru a fi sigur ca in interiorul functiei nu modific filmele
//	for (int i = 0; i < n; i++) {
//		afisare(filme[i]);  //aici se face dereferentiera implicit. Poti scrie si *(filme+i)
//	}
//}
//
//struct Film* copiazaPrimeleNElemente(const struct Film* t, int nrElemente, int nrElementeDorite) {
//	struct Film* filmeNou;
//	filmeNou = (struct Film*)malloc(sizeof(struct Film) * nrElementeDorite);
//
//	for (int i = 0; i < nrElementeDorite; i++) {
//		filmeNou[i] = t[i];  //doar asta inseamna shallow copy
//		filmeNou[i].titlu = (char*)malloc(sizeof(char) * strlen(t[i].titlu) + 1);
//		strcpy_s(filmeNou[i].titlu, strlen(t[i].titlu) + 1, t[i].titlu);  //cu aceste doua randuri am facut deep copy :)
//	}
//	
//	return filmeNou;
//	
//}
//
//void dezalocareV(struct Film** vector, int* nrElemente) {
//	for (int i = 0; i < (*nrElemente); i++) {
//		free((*vector)[i].titlu);
//	}
//
//	free(*vector);
//	*vector = NULL;
//	*nrElemente = 0;
//}
//
//int main() {
//
//	struct Film* filme;
//	filme = (Film*)malloc(sizeof(Film) * 3);
//	filme[0] = initializare(1, "Avengers", 9.9, 2012);
//	filme[1] = initializare(2, "Spider Man", 8.5, 2002);
//	filme[2] = initializare(3, "Iron Man", 10, 2008);
//
//	afiseazaColectieFilme(filme, 3);
//
//	struct Film* colectCopiata = NULL;
//	int nrDimFilmeNou = 2;
//
//	colectCopiata = copiazaPrimeleNElemente(filme, 3, nrDimFilmeNou);
//
//	afiseazaColectieFilme(colectCopiata, nrDimFilmeNou);
//
//	dezalocareV(&colectCopiata, &nrDimFilmeNou);
//	afiseazaColectieFilme(colectCopiata, nrDimFilmeNou);
//	return 0;
//}