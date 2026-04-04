#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Masina {
	int cP;
	int nrLocuri;
	float consum;
}Masina;

Masina initializareMasina(int cP, int nrLocuri, float consum) {
	Masina m;
	m.cP = cP;
	m.nrLocuri = nrLocuri;
	m.consum = consum;
	return m;
}

void afisareMasina(Masina m) {
	printf("Cai putere: %d\n", m.cP);
	printf("Nr. locuri: %d\n", m.nrLocuri);
	printf("Consum: %.2f\n", m.consum);
}

typedef struct Heap {
	Masina* elemente;
	int lungime;
	int nrEl;

}Heap;

Heap intializareHeap(int lungime) {
	Heap h;
	h.elemente = (Masina*)malloc(sizeof(Masina)*lungime);
	h.lungime = lungime;  //pentru cate am alocat memorie
	h.nrEl = 0;  //cate avem in heap
	return h;
}

void filtreazaHeap(Heap heap, int pozNod) {

	int stg = 2 * pozNod + 1;
	int dr = 2 * pozNod + 2;
	int max = pozNod;
	if (stg<heap.nrEl && heap.elemente[stg].consum>heap.elemente[max].consum) {
		max = stg;
	}
	if (dr<heap.nrEl && heap.elemente[dr].consum>heap.elemente[max].consum) {
		max = dr;
	}

	if (max != pozNod) {
		Masina temp = heap.elemente[pozNod];
		heap.elemente[pozNod] = heap.elemente[max];
		heap.elemente[max] = temp;
		filtreazaHeap(heap, max);
	}



}




int main() {

	Masina m;
	m = initializareMasina(110, 5, 4.9);
	afisareMasina(m);

	Heap h1 = intializareHeap(10);


	return 0;
}