#include<stdio.h>
#include<malloc.h>


struct Masina {
	int codMasina;
	double pret;
	char* producator;
	char clasa;
};

struct Masina initializareM(int codMasina, double pret, char* producator, char clasa) {
	struct Masina m;
	m.codMasina = codMasina;
	m.pret = pret;
	m.producator = (char*)malloc(strlen(producator) + 1);
	strcpy_s(m.producator, strlen(producator) + 1, producator);
	m.clasa = clasa;
	return m;

}

void afisareMasina(struct Masina m) {
	printf("Cod Masina: %d\n", m.codMasina);
	printf("Pret: %lf\n", m.pret);
	printf("Producator: %s\n", m.producator);
	printf("Clasa: %c\n", m.clasa);
}

void afisareVector(struct Masina* mVector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareMasina(mVector[i]);
	}
}

void eliberareMasina(struct Masina* m) {
	if (m->producator != NULL) {
		free(m->producator);
		m->producator = NULL;
	}
}

void eliberareVector(struct Masina* mVector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		eliberareMasina(&mVector[i]);  
	}
	free(mVector);  
}



int main() {

	struct Masina m1 = initializareM(1, 2000, "Mazda", 'S');
	afisareMasina(m1);


	eliberareMasina(&m1);

	struct Masina* masini = NULL;
	int nrMasini = 3;
	masini = (struct Masina*)malloc(sizeof(struct Masina) * nrMasini);
	masini[0] = initializareM(2, 4000, "Dacia", 'M');
	masini[1] = initializareM(3, 4000, "Honda", 'H');
	masini[2] = initializareM(4, 4000, "Tesla", 'T');



	afisareVector(masini, nrMasini);


	eliberareVector(masini, nrMasini);

	

	return 0;
}