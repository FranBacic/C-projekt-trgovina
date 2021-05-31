#include "Header.h"
void menu() {
	printf("Odaberite opciju\n");
	printf("1: Dodavanje proizvoda\n");
	printf("2: Ucitavanje proizvoda\n");
	printf("3: Ispisivanje proizvoda\n");
	printf("4: Pretrazivanje proizvoda\n");
	printf("5: Narucivanje proizvoda\n");
	printf("6: Ispis narucenih proizvoda\n");
	printf("7: Ispis sortiranih proizvoda po cijeni\n");
	printf("8: Izlaz iz programa\n");
}



void dodavanjeProizvoda(char* fileName) {
	int brojProizvoda = 0;
	FILE* File1 = fopen(fileName, "rb+");
	if (File1 == NULL) {
		File1 = fopen(fileName, "wb");
		fwrite(&brojProizvoda, sizeof(int), 1, File1);
	}
	else {
		fread(&brojProizvoda, sizeof(int), 1, File1);
	}
	PROIZVOD igra;
	unesiProizvod(&igra);
	brojProizvoda++;
	rewind(File1);
	fwrite(&brojProizvoda, sizeof(int), 1, File1);

	fseek(File1, 0, SEEK_END);
	fwrite(&igra, sizeof(PROIZVOD), 1, File1);

	puts("\nProizvod dodan!\n\n");

	fclose(File1);
}

void unesiProizvod(PROIZVOD* igra) {
	printf("Unesite naziv igre: ");
	scanf(" %[^\n]s", igra->naziv);

	printf("Unesite cijenu igre: ");
	scanf("%f", &igra->cijena);
	getchar();

	printf("Unesite platformu: ");
	scanf(" %[^\n]s", igra->platforma);

	printf("Unesite ID igre: ");
	scanf("%ld", &igra->id);
	getchar();

}

void* ucitavanjeProizvoda(const char* const fileName) {
	int brojProizvoda = 0;
	FILE* File1 = fopen(fileName, "rb");
	if (File1 == NULL) {
		printf("Greska tijekom otvaranja datoteke");
		fread(&brojProizvoda, sizeof(int), 1, File1);
		printf("Broj proizvoda: %d", brojProizvoda);
		PROIZVOD* poljeProizvoda = (PROIZVOD*)malloc(brojProizvoda, sizeof(PROIZVOD));
		if (poljeProizvoda == NULL) {
			printf("Greska prilikom stvaranja polja");
			return NULL;
		}
		fread(poljeProizvoda, sizeof(PROIZVOD), brojProizvoda, File1);
		return poljeProizvoda;
	}
}





void ispisivanje(char* fileName, int id) {
	FILE* File1 = fopen(fileName, "rb");
	if (File1 == NULL) {
		printf("Nisu unesene igre!\n");
	}
	PROIZVOD igra;
	int brojProizvoda, i;
	if (File1 != NULL) {
		fread(&brojProizvoda, sizeof(int), 1, File1);
		for (i = 0; i < brojProizvoda; i++) {
			fread(&igra, sizeof(PROIZVOD), 1, File1);
		if (id == -1) {
				printf("\nNaziv: %s\n", igra.naziv);
				printf("Cijena: %f kn\n", igra.cijena);
				printf("Platforma: %s\n", igra.platforma);
				printf("ID: %ld\n", igra.id);
			}
		}
		fclose(File1);
	}
	puts("\nKRAJ\n");
}



void narucivanjeProizvoda(char* fileNarudzba) {
	int brojProizvoda = 0;
	FILE* File1 = fopen(fileNarudzba, "rb+");
	if (File1 == NULL) {
		File1 = fopen(fileNarudzba, "wb");
		fwrite(&brojProizvoda, sizeof(int), 1, File1);
	}
	else {
		fread(&brojProizvoda, sizeof(int), 1, File1);
	}
	PROIZVOD igra;
	unesiProizvod(&igra);
	brojProizvoda++;
	rewind(File1);
	fwrite(&brojProizvoda, sizeof(int), 1, File1);

	fseek(File1, 0, SEEK_END);
	fwrite(&igra, sizeof(PROIZVOD), 1, File1);

	puts("\nProizvod dodan!\n\n");

	fclose(File1);
}
void ispisivanjeNarudzba(char* fileNarudzba, int id) {
	FILE* File1 = fopen(fileNarudzba, "rb");
	if (File1 == NULL) {
		printf("Nema narucenih igara!");
	}
	PROIZVOD igra;
	int brojProizvoda, i;
	if (File1 != NULL) {
		fread(&brojProizvoda, sizeof(int), 1, File1);
		for (i = 0; i < brojProizvoda; i++) {
			fread(&igra, sizeof(PROIZVOD), 1, File1);
			if (id == -1) {
				printf("\nNaziv: %s\n", igra.naziv);
				printf("Cijena: %f kn\n", igra.cijena);
				printf("Platforma: %s\n", igra.platforma);
				printf("ID: %ld\n", igra.id);
			}
		}
		fclose(File1);
	}
	puts("\nKRAJ\n");
}


void* pretrazivanje(PROIZVOD* const poljeProizvoda) {
	if (poljeProizvoda == NULL) {
		printf("Polje proizvoda je prazno.\n");
		return NULL;
	}
	int brojProizvoda = 0;
	int i;
	char trazeniProizvod[20] = { '\0' };
	fread(&brojProizvoda, sizeof(int), 1, poljeProizvoda);
	printf("Unesite ime igre koju trazite.\n");
	getchar();
	scanf("%19[^\n]", trazeniProizvod);

	for (i = 0; i < brojProizvoda; i++)
	{
		if (strcmp(trazeniProizvod, (poljeProizvoda + i)->naziv)) {
			printf("naziv: %s\n", (poljeProizvoda + i)->naziv);
			printf("cijena: %f\n", (poljeProizvoda + i)->cijena);
			printf("platforma: %s\n", (poljeProizvoda + i)->platforma);
			printf("id: %ld\n", (poljeProizvoda + i)->id);
		}
	}
	if (!strcmp(trazeniProizvod, (poljeProizvoda + i)->naziv)) {
	printf("Proizvod nije pronaden!\n");
}
	return NULL;
}
