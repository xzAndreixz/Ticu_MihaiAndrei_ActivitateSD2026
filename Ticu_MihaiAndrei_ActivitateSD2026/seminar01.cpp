#include <stdio.h>
#include <malloc.h>

int main() {

	typedef struct Depozit Depozit;

	struct Depozit {
		int id;
		float suprafata;
		int volum;
		char* denumire;
		char clasa;
	};


	return 0;
}