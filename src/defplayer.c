/*
 * defplayer.c
 *
 *  Created on: 19 feb 2018
 *      Author: nowhereboy
 */

#include "defplayer.h"

void inserisciutenti()
{
typedef struct PLAYER
	{char nome[25];
	char symbol[1];
	int vittorie;
	} pl;

pl player1;
printf("Giocatore 1, inserisci il tuo nome : \n");
scanf("%c", &player1.nome);
printf("Scegli il simbolo che comparirà nello schermo: \n");
scanf("%c", &player1.symbol);

pl player2;
printf("Giocatore 2, inserisci il tuo nome : \n");
scanf("%c", &player2.nome);
printf("Scegli il simbolo che comparirà nello schermo: \n");
scanf("%c", &player2.symbol);

}



int numerogiocatori( int * count )

	{

	typedef struct PLAYER
		{char nome[25];
		char symbol[1];
		int vittorie;
		} pl;
		int nplayer;
		printf ("inserire 1 per sfidare il computer o 2 per giocare tra umani\n");
		printf ("make your choice");
		scanf("%d", &nplayer);
//		int m;
		if (nplayer==1)
				{
					//pl player1;
					//printf ("hai scelto di giocare contro il computer\n");
					//printf ("Inserisci il tuo nome (max 25 caratteri)\n");
					//scanf("%s[25]", &player1.nome);
					//printf("%s", player1.nome);
				}
			else if (nplayer == 2)
					{
						/*pl player1;
						pl player2;
						printf ("perfetto, siete due giocatori pronti a sfidarvi!\n");
						printf ("Inserisci il  nome del giocatore 1 (max 25 caratteri)\n");
						scanf("%s", &player1.nome);
						printf ("Inserisci il  nome del giocatore 2 (max 25 caratteri)\n");
						scanf("%s", &player2.nome);
						printf("Benvenuti %s e %s, buon divertimento", player1.nome, player2.nome);
						 */
					}
			else if (nplayer != 1 && nplayer != 2 && (* count)>=4)
					{

				printf ("hai effettuato una scelta errata per 5 volte, riapri il programma.\n");
				nplayer=-2;

					}


			else if (nplayer != 1 && nplayer != 2)
					{
				nplayer=-1;
				* count = (* count) +1;
				printf ("hai effettuato una scelta errata %d \n", * count);

					}
			return nplayer;
	}

void datigiocatori(pl * p1)

	{

		printf ("Inserisci il tuo nome (max 25 caratteri-----)\n");

		scanf("%s", p1->nome);


	}

