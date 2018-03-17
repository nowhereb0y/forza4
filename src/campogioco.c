/*
 * campogioco.c
 *
 *
 *      Autore: Salvatore Albino
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

void mettipedina(int mossaplayer1, char symbol, char campoGioco[][COLONNE])

{
	int i;

        		for(i=(RIGHE -1); i>=0; i--)
        		{
        			if(campoGioco[i][mossaplayer1-1] == ' ')
            		{
            			campoGioco[i][mossaplayer1-1] = symbol;

            			i=-1;

            		}
        		}


}
