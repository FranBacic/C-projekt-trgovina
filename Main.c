#include "Header.h"

int main(void) {

	int inputOption;
	char* fileName = "Proizvodi.bin";
	static PROIZVOD* poljeProizvoda = NULL;
	static PROIZVOD* pronadeniProizvod = NULL;
	char* fileNarudzba = "Narudzba.bin";

	do {
		printf("-----------------------------------------------------------\n");
		menu();

		scanf("%d", &inputOption); getchar();

		switch (inputOption) {

		case 1:
			dodavanjeProizvoda(fileName);
			break;

		case 2:
			if (poljeProizvoda != NULL) {
				free(poljeProizvoda);
				poljeProizvoda = NULL;
			}
			poljeProizvoda = (PROIZVOD*)ucitavanjeProizvoda(fileName);
			if (poljeProizvoda == NULL) {
				exit(EXIT_FAILURE);
			}

			break;

		case 3:
			ispisivanje(fileName, -1);
			break;

		case 5:
			narucivanjeProizvoda(fileNarudzba);
			break;
		case 6:
			ispisivanjeNarudzba(fileNarudzba, -1);
			break;
		case 4:
			pronadeniProizvod = (PROIZVOD*)pretrazivanje(&poljeProizvoda, fileName);
			break;
		case 8:
			brisanje(fileName);
			break;
		case 9:
			brisanjeProizvoda(&pronadeniProizvod, poljeProizvoda, fileName);
			break;
		case 10:
			inputOption = exitProgram();
			break;
		default:
			puts("Broj koji ste upisali ne odgovara niti jednoj radnji!\n");
			break;
		}
	} while (inputOption != 10);

	return 0;
}