#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char* numeAngajat;
	char* departament;
	int* salariu;
	int nrAngajati;
} Angajat;


//constructor

 Angajat constructor(char* numeAngajat, char* departament, int* salariu, int nrAngajati) {
	 Angajat c;
	c.numeAngajat = (char*)malloc((strlen(numeAngajat) + 1) * sizeof(char));
	strcpy_s(c.numeAngajat, strlen(numeAngajat) + 1, numeAngajat);
	c.departament = (char*)malloc((strlen(departament) + 1) * sizeof(char));
	strcpy_s(c.departament, strlen(departament) + 1, departament);
	c.salariu = (int*)malloc(nrAngajati * sizeof(int));
	for (int i = 0; i < nrAngajati; i++) {
		c.salariu[i] = salariu[i];
	}
	c.nrAngajati = nrAngajati;

	return c;
}

 //afisare

 void afisare(Angajat c) {
	 printf("Nume angajat: %s\n", c.numeAngajat);
	 printf("Departament: %s\n", c.departament);
	 printf("nrAngajati: %d\n", c.nrAngajati);
	 for (int i = 0; i < c.nrAngajati; i++) {
		 printf("Salariu: [%d] = %d\n", i, c.salariu[i]);
	 }
 }


//lista simpla
typedef struct
{
	Angajat inf;
	struct nodeLS* next;
} nodLS;

//lista de liste
typedef struct {
	struct nodeLS* inf;
	struct nodLP* next;
} nodLP;

int main() {
	int salarii[] = { 2500, 3000 };
	Angajat a1 = constructor("Popescu Marinel", "Servicii", salarii, 2);
	afisare(a1);
}