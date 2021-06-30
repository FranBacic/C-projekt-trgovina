#include "Header.h"
static int brojProizvoda = 0;


void menu() {
	printf("Odaberite opciju\n");
	printf("1: Dodavanje proizvoda\n");
	printf("2: Ucitavanje proizvoda\n");
	printf("3: Ispisivanje proizvoda\n");
	printf("4: Pretrazivanje proizvoda\n");
	printf("5: Narucivanje proizvoda\n");
	printf("6: Ispis narucenih proizvoda\n");
	printf("7: Ispis sortiranih proizvoda po cijeni\n");
	printf("8: Brisanje datoteke\n");
	printf("9: Brisanje proizvoda\n");
	printf("10: Izlaz iz programa\n");
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
	brojProizvoda++;
	getchar();

}

void* ucitavanjeProizvoda(const char* const fileName) {
	int brojProizvoda = 0;
	int i;
	FILE* File1 = fopen(fileName, "rb");
	if (File1 == NULL) {
		printf("Greska tijekom otvaranja datoteke\n");
		return;
	}
	fread(&brojProizvoda, sizeof(int), 1, File1);
	printf("Broj proizvoda:%d\n", brojProizvoda);
	PROIZVOD* poljeProizvoda = (PROIZVOD*)malloc(brojProizvoda *sizeof(PROIZVOD));
	if (poljeProizvoda == NULL) {
		printf("Greska prilikom stvaranja polja");
		return NULL;
	}
	fread(poljeProizvoda, sizeof(PROIZVOD), brojProizvoda, File1);
	for (i = 0; i < brojProizvoda; i++) {
		printf("\n%s\n", poljeProizvoda + i);
	}
	return poljeProizvoda;
}






void ispisivanje(const PROIZVOD* const poljeProizvoda, char* fileName) {
	if (poljeProizvoda == NULL) {
		printf("Polje proizvoda je prazno!\n");
		return;
	}
	FILE* File1 = fopen(fileName, "rb");
	if (File1 == NULL) {
		printf("Greska pri otvaranju datoteke");
	}
	fread(&brojProizvoda, sizeof(int), 1, File1);
	int i;
	for (i = 0; i < brojProizvoda; i++)
	{
		printf("naziv: %s\n", (poljeProizvoda + i)->naziv);
		printf("cijena: %.2f kn\n", (poljeProizvoda + i)->cijena);
		printf("platforma: %s\n", (poljeProizvoda + i)->platforma);
		printf("id: %ld\n", (poljeProizvoda + i)->id);
	}
	return;
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
				printf("Cijena: %.2f kn\n", igra.cijena);
				printf("Platforma: %s\n", igra.platforma);
				printf("ID: %ld\n", igra.id);
			}
		}
		fclose(File1);
	}
	puts("\nKRAJ\n");
}


void* pretrazivanje(PROIZVOD* const poljeProizvoda, char* fileName) {
	if (poljeProizvoda == NULL) {
		printf("Polje proizvoda je prazno.\n");
		return NULL;
	}
	int brojProizvoda = 0;
	int i;
	const char* trazeniProizvod[50] = { '\0' };
	FILE* File1 = fopen(fileName, "rb");
	if (File1 == NULL) {
		printf("Greska pri otvaranju datoteke");
	}
	fread(&brojProizvoda, sizeof(int), 1, File1);
	printf("Unesite ime igre koju trazite.\n");
	scanf("%49[^\n]", trazeniProizvod);
	getchar();
	for (i = 0; i < 5; i++)
	{
		if (!strcmp(trazeniProizvod, (poljeProizvoda + i)->naziv)) {
			printf("naziv: %s\n", (poljeProizvoda + i)->naziv);
			printf("cijena: %.2f kn\n", (poljeProizvoda + i)->cijena);
			printf("platforma: %s\n", (poljeProizvoda + i)->platforma);
			printf("id: %ld\n", (poljeProizvoda + i)->id);
			return (poljeProizvoda + i);
		}
	}

	printf("Proizvod nije pronaden!\n");
	return NULL;

}

void brisanjeProizvoda(PROIZVOD** const trazeniProizvod, const PROIZVOD* const poljeProizvoda,
	const char* const fileName) {
	FILE* File1 = fopen(fileName, "wb");
	if (File1 == NULL) {
		printf("Nije pronadena binarna datoteka!\n");
	}
	fseek(File1, sizeof(int), SEEK_SET);
	int i;
	int brojProizvoda = 0;
	fread(&brojProizvoda, sizeof(int), 1, File1);
	int noviBrojacProizvoda = 0;
	for (i = 0; i < brojProizvoda; i++)
	{
		if (*trazeniProizvod != (poljeProizvoda + i)) {
			fwrite((poljeProizvoda + i), sizeof(PROIZVOD), 1, File1);
			noviBrojacProizvoda++;
		}
	}
	rewind(File1);
	fwrite(&noviBrojacProizvoda, sizeof(int), 1, File1);
	fclose(File1);
	printf("Proizvod je uspjesno obrisan!\n");
	*trazeniProizvod = NULL;
}

void brisanje(const char* fileName) {
	printf("Zelite li obrisati datoteku %s?\n", fileName);
	printf("Utipkajte da ili ne\n");
	char potvrda[3] = { '\0' };
	scanf("%2s", potvrda);
	if (!strcmp("da", potvrda)) {
		remove(fileName) == 0 ? printf("Uspjesno obrisana datoteka %s!\n",
			fileName) : printf("Neuspjesno brisanje datoteke %s!\n", fileName);
	}
}

void zamjena(PROIZVOD* veci, PROIZVOD* manji) {
	PROIZVOD temp = { 0 };
	temp = *manji;
	*manji = *veci;
	*veci = temp;
}

void selectionSortNajjefCijena(PROIZVOD* poljeProizvoda, char* fileName) {
	int min = -1;
	int i, j;
	FILE* File1 = fopen(fileName, "rb");
	if (File1 == NULL) {
		printf("Greska pri otvaranju datoteke");
	}
	if (poljeProizvoda == NULL) {
		printf("Polje proizvoda je prazno.\n");
		return NULL;
	}
	fread(&brojProizvoda, sizeof(int), 1, File1);
	printf("Sortirani artikli po cijeni od najjeftinijeg do najskupljeg.\n");
	for (i = 0; i < brojProizvoda - 1; i++)
	{
		min = i;
		for (j = i + 1; j < brojProizvoda; j++)
		{
			if ((poljeProizvoda + j)->cijena < (poljeProizvoda + min)->cijena) {
				min = j;
			}
		}
		zamjena((poljeProizvoda + i), (poljeProizvoda + min));
	}

	for (i = 0; i < brojProizvoda; i++)
	{
		if (i == 0) {
			printf("Naziv: %s\nCijena: %f\nPlatforma: %s\nID: %ld\n\n", (poljeProizvoda + i)->naziv, (poljeProizvoda + i)->cijena, (poljeProizvoda + i)->platforma, (poljeProizvoda + i)->id);

		}
		else if (i > 0 && i < brojProizvoda - 1) {
			printf("Naziv: %s\nCijena: %f\nPlatforma: %s\nID: %ld\n\n", (poljeProizvoda + i)->naziv, (poljeProizvoda + i)->cijena, (poljeProizvoda + i)->platforma, (poljeProizvoda + i)->id);

		}
		else {
			printf("Naziv: %s\nCijena: %f\nPlatforma: %s\nID: %ld\n\n", (poljeProizvoda + i)->naziv, (poljeProizvoda + i)->cijena, (poljeProizvoda + i)->platforma, (poljeProizvoda + i)->id);

		}
	}
	printf("\n");
}


int exitProgram() {
	char str[3], c;
	int i = 0, counter = 0;
	puts("\nJeste li sigurni da zelite zavrsiti program?\n");
	do {
		printf("Unesi da/ne: ");
		fgets(str, 3, stdin);

		if (toupper(str[0]) == 'D' && toupper(str[1]) == 'A' && str[2] == '\0')
			exit(EXIT_SUCCESS);

	} while (checkCondition(str));
	return 1;
}

int checkCondition(char* str) {
	if (toupper(str[0]) == 'N' && toupper(str[1]) == 'E' && toupper(str[2]) == '\0') return 0;
	return 1;
}
int izlazIzPrograma(PROIZVOD* poljeProizvoda) {
	free(poljeProizvoda);
}