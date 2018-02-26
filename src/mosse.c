/*
 * mosse.c
 *
 *  Created on: 19 feb 2018
 *      Author: nowhereboy
 */
#include <stdio.h>
#define COLONNE 7
#define RIGHE 6

int mettipedina(int mossaplayer1, char symbol, char campoGioco[][COLONNE])

{
	int c;
	int ritorno;
	printf("Prima mossa inserita nel mettipedina: %d \n", mossaplayer1);
	//char campoGioco[RIGHE][COLONNE];
	printf("%c \n--SIMBOLO INSERITO--\n  -%c-  \n", symbol, campoGioco[RIGHE-1][mossaplayer1-1]);

    if(campoGioco[RIGHE -1][mossaplayer1-1] == ' ')
    		{
    			campoGioco[RIGHE-1][mossaplayer1-1] = symbol;
    			printf("-PRIMA IF: STAMPO IL VALORE NELLA MATRICE-\n %c \n", campoGioco[RIGHE-1][mossaplayer1-1]);
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

char turno(contamosse)
	{

    if(contamosse %2 == 0)
        return 'player1';
    else
    return 'player2';
	}

/*int chiediposizione(player)
{
		int ncol;
		do
		{

			printf("Inserisci la colonna dove posizionare la pedina: ");
			scanf("%d" , &ncol);
			if((ncol<1) || (ncol >(COLONNE)))
            printf("Scelta errata, la posizione è fuori dalla griglia!\n");
		}
		while ((ncol < 1) || (ncol > 10) || (griglia[0][ncol-1] != ' '));
		return ncol-1;
}*/
