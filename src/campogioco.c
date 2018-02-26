/*
 * campogioco.c
 *
 *  Created on: 18 feb 2018
 *      Author: nowhereboy
 */


#include "campogioco.h"

#include <stdio.h>
#include <stdlib.h>



void riempi_campo(char campoGioco[][COLONNE])




{

	int i;
	int j;

	for (i=0;i<RIGHE;i++)
	{
		for (j=0;j<COLONNE;j++)
		{
			campoGioco[i][j]=' ';
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
	printf("---------------------\n");
	printf("|1||2||3||4||5||6||7|\n");
}

/*
int chiediposizione(player)
{
		int ncol;
		do
		{

			printf("Inserisci la colonna dove posizionare la pedina: ");
			scanf("%d" , &ncol);
			if((ncol<1) || (ncol >(COLONNE)))
            printf("Scelta errata, la posizione è fuori dalla griglia!\n");
		}
		while ((ncol < 1) || (ncol > 10) || (campoGioco[0][ncol-1] != ' '));
		return ncol-1;
}
*/
