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


		printf("\n");
	}
}
