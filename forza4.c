/*
 ============================================================================
 Name        : FORZA 4
 Author      : Salvatore Albino
 Version     : 0.1a
 Copyright   : Your copyright notice
 Description : Sviluppo in C del gioco Forza 4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "campogioco.h"
//#include "campogioco.c"
//#define COLONNE 7
//#define RIGHE 6
//void riempi_Matrice(char campoGioco[][COLONNE]); //funzione per inizializzare la matrice
//void stampa_Matrice(char campoGioco[][COLONNE]); //funzione per stampare la matrice
int main()
	{

	char campoGioco[RIGHE][COLONNE];

	riempi_campo(campoGioco);
	stampa_campo(campoGioco);

	getchar();
	exit(0);

	}


