/*
 * campogioco.c
 *
 *  Created on: 18 feb 2018
 *      Author: nowhereboy
 */


#include "campogioco.h"
#include <stdio.h>
#include <stdlib.h>


//procedura utilizzata per riempire il campo campo di gioco con il carattere spazio.
//Per farlo utilizzo due cicli for annidati uno all'interno dell'altro, per definire il numero di righe e colonne utilizzo le costanti RIGHE e COLONNE definite nel file di header campogioco.h.

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


//Procedura che stampa a video il contenuto della matrice contenente il campo da gioco.
//Per farlo utilizzo due cicli for annidati uno all'interno dell'altro, per definire il numero di righe e colonne utilizzo le costanti RIGHE e COLONNE definite nel file di header campogioco.h.


void stampa_campo(char campoGioco[][COLONNE])

{
	int i;
	int j;

	printf("\n\n");
	printf("\t\t---------------------\n");
	for (i=0;i<RIGHE;i++)
	{
		printf("\t\t");
		for (j=0;j<COLONNE;j++)
		{

			printf("|%c|", campoGioco[i][j]);
		}

		printf("\n");
	}
	printf("\t\t---------------------\n");
	printf("\t\t|1||2||3||4||5||6||7|\n\n\n");
}

int mettipedina(int mossaplayer1, char symbol, char campoGioco[][COLONNE])

{
	int c;
	int ritorno;
	//printf("Prima mossa inserita nel mettipedina: %d \n", mossaplayer1);
	//char campoGioco[RIGHE][COLONNE];
	//printf("%c \n--SIMBOLO INSERITO--\n  -%c-  \n", symbol, campoGioco[RIGHE-1][mossaplayer1-1]);

    if(campoGioco[RIGHE -1][mossaplayer1-1] == ' ')
    		{
    			campoGioco[RIGHE-1][mossaplayer1-1] = symbol;
    			//printf("-PRIMA IF: STAMPO IL VALORE NELLA MATRICE-\n %c \n", campoGioco[RIGHE-1][mossaplayer1-1]);
    			ritorno = COLONNE-1;
    		}
    else
    		{
        		for(c=(RIGHE-1); c>=0; c--)
        		{
        			if(campoGioco[c-1][mossaplayer1-1] == ' ')
            		{
            			campoGioco[c-1][mossaplayer1-1] = symbol;

            			c=-1;
            			ritorno=c-1;
            		}
        		}
    		}
    return ritorno;
}
