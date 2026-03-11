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

int main() {

	

	return 0;
}