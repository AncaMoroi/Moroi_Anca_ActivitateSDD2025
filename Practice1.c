#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

struct Firma {
	int nrAngajati;
	char* numeFirma;
};

struct Firma initializareF(int nrAngajati, const char* numeFirma) {
	struct Firma f;
	f.nrAngajati = nrAngajati;
	f.numeFirma = (char*)malloc((strlen(numeFirma) + 1) * sizeof(char));
	strcpy_s(f.numeFirma, strlen(numeFirma) + 1, numeFirma);
	return f;
}

void afisareFirma(struct Firma f) {
	printf("Nr angajati: %d\n", f.nrAngajati);
	printf("Nume firma: %s\n", f.numeFirma);
}

//int main() {
//	struct Firma f1 = initializareF(20, "Haine");
//
//	afisareFirma(f1);
//	return 0;
//}