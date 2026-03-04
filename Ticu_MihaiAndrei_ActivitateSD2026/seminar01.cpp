#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Depozit Depozit;

struct Depozit {
	int id;
	float suprafata;
	int volum;
	char* denumire;
	char clasa;
};

struct Depozit intializare(int id, float suprafata, int volum, const char* denumire, char clasa) {
	struct Depozit s;
	s.id = id;
	s.suprafata = suprafata;
	s.volum = volum;
	s.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
	strcpy(s.denumire, denumire);
	return s;
}

int main() {

	




	return 0;
}