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
	stampa_campo(campoGioco);

	getchar();
	exit(0);

	}


