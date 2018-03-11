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
#include <string.h>

#include "campogioco.h"
#include "stampe.h"



typedef struct
	{char nome[25];
	char symbol;
	int vittorie; } pl;


int chiediposizione(char campoGioco[][COLONNE], pl * p1);
void datigiocatori(pl * p1);
int checkWin(char campoGioco[][COLONNE], pl * p1);
int numerogiocatori(int * count);


int main()

{
	char campoGioco[RIGHE][COLONNE]; //campo di gioco, utilizzo una matrice
	int mossaplayer1, mossaplayer2; //variabile per memorizzare la mossa del giocatore
	char symbol1= 'X'; //simbolo del giocatore 1
	char symbol2= 'O'; //simbolo del giocatore 2
	char symbol;
	int npl = -1; //variabile che utilizzo per memorizzare il numero di giocatori selezionato dagli utenti

	banneriniziale(); //stampa il banner di benvenuto

	int count = 0; //variabile utilizzata nel ciclo while seguente per tenere conto dei tentativi errati ed uscire nel caso in cui la scelta sia sbagliata per 5 volte

	while (npl==-1) //memorizzo il numero di giocatori umani chiamando la funzione "numerogiocatori"
		{			//ed esco in caso l'utente inserisca un valore diverso da 1 e 2 per più di 5 volte;
			npl=numerogiocatori(&count);
		}

	if (npl==-2)
		{
			exit(0);
		}

	void free(void * count); //libero lo spazio allocato dalla variabile count dato che non mi serve più


	//a seconda del numero di utenti scelti faccio partire il gioco nella modalità human vs cpu oppure human vs human

	//human vs cpu
	if (npl==1)
		{
			pl player1;
			pl * p1;
			p1 = &player1;
			datigiocatori(p1);
			printf("Welcome %s \n", player1.nome);
		}

		//human vs human
		else if (npl==2)
		{
			pl player1; //definisco il giocatore 1 come variabile  "pl" definito nella parte dichiarativa del programma
			pl * p1;		//p1 sarà un puntatore a una variabile di tipo pl
			p1 = &player1;	//definisco p1 come l'indirizzo in cui inizia il dato strutturato
			datigiocatori(p1); //chiamo la procedura dati giocatori in cui l'utente inserirà il proprio nome passando il puntatore della variabile p1 definita in precedenza
			printf("Welcome %s \n", player1.nome); //stampo un messaggio di benvenuto

			pl player2;//ripeto le operazioni per il giocatore 2
			pl * p2;
			p2 = &player2;
			datigiocatori(p2);
			printf("Welcome %s \n", player2.nome);

			riempi_campo(campoGioco); //inizializzo il campo di gioco chiamando la procedura riempi_campo che inserisce il carattere "spazio" all'interno di ogni elemento della matrice
			stampa_campo(campoGioco);//stampo il campo di gioco mediante la procedura campoGioco

			int mosse=0; //inizializzo la variabile "mosse". Sarà utilizzata come contatore delle mosse e tramite l'operazione "mod 2" gestirò il cambio turno (quando l'operazione darà risultato 0 sarà il turno del player 1, quando il risultato sarà 1 sarà il turno del player 2)

			while (1) //inizia il gioco vero e proprio in un ciclo infinito
			{
				if (mosse>=COLONNE*RIGHE) //verifico che le mosse non siano superiori agli spazi contenuti nella matrice, nel caso lo siano termino la partita con un pareggio.
				{
					printf("Partita terminata, non ci sono vincitori!");
							exit(0);
				}

				else if (mosse % 2 == 0) //turno del giocatore 1
					{
						mossaplayer1=chiediposizione(campoGioco, p1); //chiamo la funzione chiediposizione che chiederà all'utente di scegliere la colonna dove posizionare la pedina, informazione che sarà restituita dalla funzione e memorizzata nella variabile "mossaplayer1"
						printf("mossaplayer1: %d", mossaplayer1);
						symbol=symbol1;
						p1->symbol=symbol;
						mettipedina(mossaplayer1, symbol, campoGioco); //chiamo la procedura mettipedina che inserirà il simbolo dell'utente nella posizione scelta
						mosse++; //incremento il contatore delle mosse
						stampa_campo(campoGioco); //stampo il campo di gioco con la nuova pedina inserita tramite la procedura stampa_campo
						int vittoria;
						vittoria=checkWin(campoGioco, p1); //chiamo la funzione checkWin per verificare se ci sono 4 pedine allineate
						if (vittoria != -1)
							{
								stampa_campo(campoGioco);
								exit(0);
							}

					}
				else if (mosse % 2 == 1)//turno del giocatore 2
					{
						mossaplayer2=chiediposizione(campoGioco, p2);
						symbol=symbol2;
						p2->symbol=symbol;
						mettipedina(mossaplayer2, symbol, campoGioco);
						mosse++;
						stampa_campo(campoGioco);
						int vittoria;
						vittoria=checkWin(campoGioco, p2);
						if (vittoria != -1)
							{
								stampa_campo(campoGioco);
								exit(0);
							}

					}
			}
		}



	getchar();
	exit(0);

	}

int chiediposizione(char campoGioco[][COLONNE], pl * p1) //funzione che chiede all'utente la posizione dove inserire la sua pedina
{
		int ncol;
		do{
		printf("%s, Inserisci la colonna dove posizionare la pedina: ", p1->nome);
		scanf("%d" , &ncol);
		if((ncol<1) || (ncol >(COLONNE))) //verifico che l'utente non inserisca un valore fuori dal campo di gioco
		{
			printf("Scelta errata, la posizione è fuori dalla griglia!\n");

		}
		else if(campoGioco[0][ncol-1] != ' ') //verifico che la colonna selezionata non sia piena
		{
			printf("La colonna selezionata è piena! Ripeti la selezione. \n") ;
		}
}
		while ((ncol < 1) || (ncol > COLONNE) || (campoGioco[0][ncol-1] != ' '));

		return ncol; //restituisco la colonna scelta dall'utente al codice che ha invocato la funzione

}


void datigiocatori(pl * p1) //procedura richiamata per far inserire il nome all'utente nella variabile di tupo strutturato pl

	{
		printf ("Inserisci il tuo nome: (max 25 caratteri-----)\n");
		scanf("%s", p1->nome);
//		printf ("%s, scegli il tuo simbolo: \n", p1->nome);
//		scanf("%s", p1->symbol);
	}


int checkWin(char campoGioco[][COLONNE], pl * p1)

	{
	int i,j;
	int ritorno= -1;
	char symbol;
	symbol=p1->symbol;
	//strncpy (symbol, p1->symbol[1], 1);

	//Check orizzontale
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{
				if ( j+3 <= COLONNE-1 && campoGioco[i][j]==symbol && campoGioco[i][j+1]==symbol && campoGioco[i][j+2]==symbol && campoGioco[i][j+3]==symbol)
					{
						printf("VITTORIA ORIZZONTALE per %s!!!! \n", p1->nome );
						ritorno=1;
					}

			}
		}
	//Chech verticale
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{
				if (i+3 >= RIGHE-1 && campoGioco[i][j]==symbol && campoGioco[i+1][j]==symbol && campoGioco[i+2][j]==symbol && campoGioco[i+3][j]==symbol)
					{
						printf("VITTORIA VERTICALE per %s!!!! \n", p1->nome );
						ritorno=2;
					}
			}
		}
	//Chech diagonale decrescente
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{
				if (i+3 >= RIGHE-1 && j+3 <= COLONNE-1 && campoGioco[i][j]==symbol && campoGioco[i+1][j+1]==symbol && campoGioco[i+2][j+2]==symbol && campoGioco[i+3][j+3]==symbol)
					{
						printf("VITTORIA DIAGONALE DECRESCENTE per %s!!!! \n", p1->nome);
						ritorno=3;
					}
			}
		}





	//Chech diagonale crescente
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{


				 if (i-3 >= 0 && j+3 <= COLONNE-1 && campoGioco[i][j]==symbol && campoGioco[(i-1)][j+1]==symbol && campoGioco[i-2][j+2]==symbol && campoGioco[i-3][j+3]==symbol)
					{
						printf("Punti: %d %d \n", i, j);
						printf("VITTORIA DIAGONALE CRESCENTE per %s!!!!\n", p1->nome);
						printf("simbolo: %c \n", symbol);
						printf("i: %d \n" , i);
						printf("j: %d \n" , j);
						printf("%c %c %c %c \n", campoGioco[i][j], campoGioco[(i-1)][(j+1)], campoGioco[(i-2)][(j+2)], campoGioco[(i-3)][(j+3)]);
						printf("campoGioco[%d][%d], campoGioco[%d][%d], campoGioco[%d][%d], campoGioco[%d][%d] \n",i,j,(i-1),(j+1), (i-2),(j+2), (i-3),(j+3));
						//printf("Prova: 1%c 2%c 3%c 4%c \n", campoGioco[5][5], campoGioco[4][6], campoGioco[3][7], campoGioco[2][8]);
						//printf("Prova: %c %c %c %c \n", campoGioco[5][5], campoGioco[6][6], campoGioco[7][7], campoGioco[8][8]);
						ritorno=4;
					}
			}
		}
	return ritorno;
	}

int numerogiocatori( int * count )

	{

/*	typedef struct PLAYER
		{char nome[25];
		char symbol[1];
		int vittorie;
		} pl;*/
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
