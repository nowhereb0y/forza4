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
#include "defplayer.h"


//#include "campogioco.c"
//#define COLONNE 7
//#define RIGHE 6
//void riempi_Matrice(char campoGioco[][COLONNE]); //funzione per inizializzare la matrice
//void stampa_Matrice(char campoGioco[][COLONNE]); //funzione per stampare la matrice
int chiediposizione(char campoGioco[][COLONNE]);

int main()

{
	char campoGioco[RIGHE][COLONNE]; //campo di gioco
	int r,c; //righe e colonne
	int mossaplayer1, mossaplayer2; //variabile per memorizzare la mossa del giocatore
	char symbol1= 'X'; //simbolo del giocatore 1
	char symbol2= 'O'; //simbolo del giocatore 2
	char symbol;
	int contamosse;
	char whichplayer;
	int npl = -1;
	//int numutenti();

	typedef struct
		{char nome[25];
		char symbol[1];
		int vittorie;
		} pl;


	banneriniziale();


	int count = 0;
	while (npl==-1) //memorizzo il numero di giocatori umani chiamando la funzione "numerogiocatori"
		{			//ed esco in caso l'utente inserisca un valore diverso da 1 e 2 per più di 5 volte;
			npl=numerogiocatori(&count);
		}
	if (npl==-2)
		{
		exit(0);
		}
	else if (npl==1)
		{
			pl player1;
			pl * p1;
			p1 = &player1;
			datigiocatori(p1);
			printf("Welcome %s \n", player1.nome);
		}

	else if (npl==2)
		{
			pl player1;
			pl * p1;
			p1 = &player1;
			datigiocatori(p1);
			printf("Welcome %s \n", player1.nome);
			pl player2;
			pl * p2;
			p2 = &player2;
			datigiocatori(p2);
			printf("Welcome %s \n", player2.nome);

		}

	free(count);

	riempi_campo(campoGioco);
	stampa_campo(campoGioco);


	//chiedo la pedina al giocatore
	mossaplayer1 = chiediposizione(campoGioco);
	//inserisco la pedina nella griglia

	symbol=symbol1;
	mettipedina(mossaplayer1, symbol, campoGioco);

	//printf("%d \n", nonso);
	stampa_campo(campoGioco);

	mossaplayer2=4;
	symbol=symbol2;
	mettipedina(mossaplayer2, symbol, campoGioco);
	stampa_campo(campoGioco);

	mossaplayer2=4;
	symbol=symbol1;
	mettipedina(mossaplayer2, symbol, campoGioco);
	stampa_campo(campoGioco);

	mossaplayer1=4;
	symbol=symbol2;
	mettipedina(mossaplayer1, symbol, campoGioco);
	stampa_campo(campoGioco);


//printf("%s", player1.nome)
/*
	 typedef struct PLAYER
		{char nome[25];
		char symbol[1];
		int vittorie;
		} pl;

		//int nplayer;
		printf ("inserire 1 per sfidare il computer o 2 per giocare tra umani\n");
		printf ("make your choice");
		scanf("%d", &nplayer);
		//return nplayer;

		if (nplayer==1)
				{
					pl player1;
					printf ("hai scelto di giocare contro il computer\n");
					printf ("Inserisci il tuo nome (max 25 caratteri)\n");
					scanf("%s[25]", &player1.nome);
					printf("%s", player1.nome);
					return 1;

				}
			else if (nplayer == 2)
					{
						pl player1;
						pl player2;
						printf ("perfetto, siete due giocatori pronti a sfidarvi!\n");
						printf ("Inserisci il  nome del giocatore 1 (max 25 caratteri)\n");
						scanf("%s", &player1.nome);
						printf ("Inserisci il  nome del giocatore 2 (max 25 caratteri)\n");
						scanf("%s", &player2.nome);
						printf("Benvenuti %s e %s, buon divertimento", player1.nome, player2.nome);
						return 2;
					}
			else if (nplayer != 1 && nplayer != 2)
					{
				printf ("hai effettuato una scelta errata");
				return -1;
					}
*/
	//riempi_campo(campoGioco);

	//proviamo a mettere qualche mossa

	//contamosse=0;

	//whichplayer = turno(contamosse);











	//stampa_campo(campoGioco);



//	printf("\n %s è il tuo turno, fai la tua mossa scegliendo il numero della colonna \n", nomeplayer1);

	//scanf("%d", &mossaplayer);






	//devo calcolare a che riga la colonna è libera - anche no!
/*
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

*/
	//	GRAVITA'?????????

//	int posiziona_pedina(int pos, char gio)
	/*La funzione posiziona la pedina nella griglia e ritorna le y*/

	//mettipedina(mossaplayer)
	//
	//stampa_campo(campoGioco);

	getchar();
	exit(0);

	}

int chiediposizione(char campoGioco[][COLONNE])
{
		int ncol;
		do{
		printf("Inserisci la colonna dove posizionare la pedina: ");
		scanf("%d" , &ncol);
		//printf("---1---Stampa colonna: %d", ncol-1);
		if((ncol<1) || (ncol >(COLONNE)))

			printf("Scelta errata, la posizione è fuori dalla griglia!\n");

		}
		while ((ncol < 1) || (ncol > COLONNE) || (campoGioco[0][ncol-1] != ' '));
//		return ncol-1;
		return ncol;
		printf("Stampa colonna: %d \n", ncol-1) ;
}
