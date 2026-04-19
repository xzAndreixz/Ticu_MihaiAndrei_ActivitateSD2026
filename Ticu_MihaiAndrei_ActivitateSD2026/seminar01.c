//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//
//typedef struct Depozit Depozit;
//
//struct Depozit {
//	int id;
//	float suprafata;
//	int volum;
//	char* denumire;
//	char clasa;
//};
//
//struct Depozit intializare(int id, float suprafata, int volum, const char* denumire, char clasa) {
//	struct Depozit s;
//	s.id = id;
//	s.suprafata = suprafata;
//	s.volum = volum;
//	s.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
//	strcpy(s.denumire, denumire);
//	return s;
//}
//
//int main() {
//
//	Depozit dep1 = intializare(1, 100, 300, "DEP1", 'A');
//
//	printf("%d", dep1.id);
//
//
//	return 0;
//}