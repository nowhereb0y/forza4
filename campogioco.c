#include <stdio.h>
#include <stdlib.h>
#include "campogioco.h"
//#define COLONNE 9
//#define RIGHE 6


void riempi_campo(char campoGioco[][COLONNE])

{

	int i;
	int j;

	for (i=0;i<RIGHE;i++)
	{
		for (j=0;j<COLONNE;j++)
		{
			campoGioco[i][j]='1';
		}
	}
}

void stampa_campo(char campoGioco[][COLONNE])

{
	int i;
	int j;


	for (i=0;i<RIGHE;i++)
	{
		for (j=0;j<COLONNE;j++)
		{
			printf("|%c|", campoGioco[i][j]);
		}

		printf("\n");
	}
}
