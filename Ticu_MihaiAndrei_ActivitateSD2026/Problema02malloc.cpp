#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct Film {
	int id;
	char* titlu;
	float rating;
	int anAparitie;
};

struct Film initializare(int id, const char* titlu, float rating, int anAparitie) {
	struct Film f;
	f.id = id;
	f.titlu = (char*)malloc(sizeof(char) * (strlen(titlu) + 1));
	strcpy_s(f.titlu, strlen(titlu) + 1, titlu);
	f.rating = rating;
	f.anAparitie = anAparitie;

	return f;
}

void afisare(struct Film a) {
	printf("Id film: %d\n", a.id);
	if (a.titlu == NULL) {
		printf("Titlu film: Necunoscut\n");
	}
	else {
		printf("Titlu film: %s\n", a.titlu);
	}
	printf("Rating: %.1f\n", a.rating);
	printf("An aparitie: %d\n", a.anAparitie);
}

void dezalocare(struct Film* d) {
	if (d->titlu != NULL) {
		free(d->titlu);
		d->titlu = NULL;
	}
}

int main() {

	struct Film filmul1 = initializare(1, "Avengers", 9.9, 2012);
	afisare(filmul1);
	

	return 0;
}