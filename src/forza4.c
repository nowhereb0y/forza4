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
#include "stampe.h"
//#include "campogioco.c"
//#define COLONNE 7
//#define RIGHE 6
//void riempi_Matrice(char campoGioco[][COLONNE]); //funzione per inizializzare la matrice
//void stampa_Matrice(char campoGioco[][COLONNE]); //funzione per stampare la matrice
int main()
	{
	char campoGioco[RIGHE][COLONNE]; //campo di gioco
	int nplayer; //variabile per far scegliere tra human vs pc | human vs human
	char nomeplayer1[25];
	char nomeplayer2[25];
	int mossaplayer1, mossaplayer2; //variabile per memorizzare la mossa del giocatore
	char symbol1= 'X'; //simbolo del giocatore 1
	char symbol2= 'O'; //simbolo del giocatore 2
	banneriniziale();

	printf ("inserire 1 per sfidare il computer o 2 per giocare tra umani\n");
	printf ("make your choice");
	scanf("%d", &nplayer);

	if (nplayer==1)
			{
				printf ("hai scelto di giocare contro il computer\n");
				printf ("Inserisci il tuo nome (max 25 caratteri)\n");
				scanf("%s[25]", nomeplayer1);
				printf("%s", nomeplayer1);

			}
		else if (nplayer == 2)
				{
					printf ("perfetto, siete due giocatori pronti a sfidarvi!\n");
					printf ("Inserisci il  nome del giocatore 1 (max 25 caratteri)\n");
					scanf("%s", nomeplayer1);
					printf ("Inserisci il  nome del giocatore 2 (max 25 caratteri)\n");
					scanf("%s", nomeplayer2);
				}
		else if (nplayer != 1 && nplayer != 2)
				{
			printf ("hai effettuato una scelta errata");
				}


	riempi_campo(campoGioco);

	//proviamo a mettere qualche mossa
	stampa_campo(campoGioco);
	printf("\n %s è il tuo turno, fai la tua mossa scegliendo il numero della colonna \n", nomeplayer1);

	scanf("%d", &mossaplayer1);

	//devo calcolare a che riga la colonna è libera

	int i,j;
	int liberi[7];
	for (i=0; i<RIGHE; i++)
		{
		for (j=0;j<COLONNE;j++)
			{
				if (campoGioco[i][j] == '1')
				{
					liberi[i]=j;
					printf("%d............\n", liberi[i]);
				}
			}
		}

	for (i=0; i<COLONNE; i++)

		{
			printf("-%d", liberi[i]);
		}

	/*	GRAVITA'?????????
	 *
	 *     if(colonna>=1 && colonna<=5)
     {

         for(i=5; griglia[i][colonna] == ' ' ; i--)
            griglia[i][colonna]==simbolo[turno_utente];

        }
	 */

	//
	stampa_campo(campoGioco);

	getchar();
	exit(0);

	}


