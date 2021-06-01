#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct proizvod {
	char naziv[50];
	float cijena;
	char platforma[20];
	long id;
}PROIZVOD;

void menu();
void dodavanjeProizvoda(char* fileName);
void* ucitavanjeProizvoda(const char* const fileName);
void unesiProizvod(PROIZVOD* igra);
void ispisivanje(char* fileName, int id);
void* pretrazivanje(PROIZVOD* const);
void narucivanjeProizvoda(char* fileNarudzba);
void ispisivanjeNarudzba(char* fileNarudzba, int id);
int exitProgram();
int checkCondition(char* str);
void brisanje(char* fileName);
#endif