/*
 * mosse.c
 *
 *  Created on: 19 feb 2018
 *      Author: nowhereboy
 */

#define COLONNE 7
#define RIGHE 6

int mettipedina(int mossaplayer1, symbol1)

{
	int c;
	char campoGioco[RIGHE][COLONNE];
    if(campoGioco[RIGHE-1][mossaplayer1-1] == ' ')
    		{
    			campoGioco[RIGHE-1][mossaplayer1-1] = symbol1;
    			return COLONNE-1;
    		}
    else
    		{
        		for(c=0; c<COLONNE; c++)
        		{
        			if(campoGioco[c][mossaplayer1-1] != ' ')
            		{
            			campoGioco[c-1][mossaplayer1-1] = symbol1;
            			return c-1;
            		}
        		}
    		}
}

char turno(contamosse)
	{

    if(contamosse %2 == 0)
        return 'player1';
    else
    return 'player2';
	}

