#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	float suprafata;
	char* locatie;
}Casa;

Casa initializare(float sup, const char* loc) {s
	Casa c;
	c.suprafata = sup;
	c.locatie = (char*)malloc(sizeof(char) * (strlen(loc) + 1));
	strcpy(c.locatie, loc);
	return c;
}





void dezalocare(Casa* c) {
	free((*c).locatie);
}
void dezVect(Casa** c, int* dim) {
	for (int i = 0; i < (*dim); i++) {
		free((*c)[i].locatie);
	}

	free(*c);
}



int main() {

	
	return 0;
}