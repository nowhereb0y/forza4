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
#include "mosse.h"

typedef struct
	{char nome[25];
	char symbol[1];
	int vittorie; } pl;


int chiediposizione(char campoGioco[][COLONNE], pl * p1);
void datigiocatori(pl * p1);
//void inserisciNome(int npl);


int main()

{
	char campoGioco[RIGHE][COLONNE]; //campo di gioco
	int mossaplayer1, mossaplayer2; //variabile per memorizzare la mossa del giocatore
	char symbol1= 'X'; //simbolo del giocatore 1
	char symbol2= 'O'; //simbolo del giocatore 2
	char symbol;
	int npl = -1;

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

	void free(void * count);


	if (npl==1)
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
			riempi_campo(campoGioco);
			stampa_campo(campoGioco);
			int mosse=0;
			while (1)
			{
				if (mosse % 2 == 0)
					{
						mossaplayer1=chiediposizione(campoGioco, p1);
						printf("mossaplayer1: %d", mossaplayer1);
						symbol=symbol1;
						mettipedina(mossaplayer1, symbol, campoGioco);
						mosse++;
						stampa_campo(campoGioco);
						//checkVittoria
					}
				else
					{
						mossaplayer2=chiediposizione(campoGioco, p2);
						symbol=symbol2;
						mettipedina(mossaplayer2, symbol, campoGioco);
						mosse++;
						stampa_campo(campoGioco);
						//checkVittoria
					}
			}
		}



	getchar();
	exit(0);

	}

int chiediposizione(char campoGioco[][COLONNE], pl * p1)
{
		int ncol;
		do{
		printf("%s, Inserisci la colonna dove posizionare la pedina: ", p1->nome);
		scanf("%d" , &ncol);
		printf("---1---Stampa colonna: %d", ncol-1);
		if((ncol<1) || (ncol >(COLONNE)))
		{
			printf("Scelta errata, la posizione è fuori dalla griglia!\n");

		}
}
		while ((ncol < 1) || (ncol > COLONNE) || (campoGioco[0][ncol-1] != ' '));
		printf("Stampa colonna: %d \n", ncol) ;
		return ncol;

}

/*void inserisciNome(int npl)
	{
		if (npl==1)
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
}*/



void datigiocatori(pl * p1)

	{
		printf ("Inserisci il tuo nome: (max 25 caratteri-----)\n");
		scanf("%s", p1->nome);
//		printf ("%s, scegli il tuo simbolo: \n", p1->nome);
//		scanf("%s", p1->symbol);
	}
