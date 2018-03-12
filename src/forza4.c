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
int checkwin(char campoGioco[][COLONNE], pl * p1);
int numerogiocatori(int * count);
int rivincita(int * count, char campoGioco[][COLONNE]);
void fineturno(pl * p1, pl * p2, int * mosse);

int main()

{
	char campoGioco[RIGHE][COLONNE]; //campo di gioco, utilizzo una matrice

	int mossaplayer1, mossaplayer2; //variabile per memorizzare la mossa del giocatore
	char symbol;
	int count = 0; //variabile utilizzata nel ciclo while per tenere conto dei tentativi errati ed uscire nel caso in cui la scelta sia sbagliata per 5 volte

	int npl = -1; //variabile che utilizzo per memorizzare il numero di giocatori selezionato dagli utenti

	banneriniziale(); //stampa il banner di benvenuto


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
			p1->symbol='X';
			p1->vittorie=0;
			printf("\n  Benvenuto %s, ecco il tuo simbolo sul campo di gioco: \"X\" \n\n", player1.nome); //stampo un messaggio di benvenuto

			pl player2;//ripeto le operazioni per il giocatore 2
			pl * p2;
			p2 = &player2;
			datigiocatori(p2);
			p2->symbol='O';
			p2->vittorie=0;
			printf("\n  Benvenuto %s, ecco il tuo simbolo sul campo di gioco: \"O\" \n\n", player2.nome);
			printf("\n\n\n  Premere il tasto invio per iniziare la partita");
			fflush (stdin);
			getchar();
			riempi_campo(campoGioco); //inizializzo il campo di gioco chiamando la procedura riempi_campo che inserisce il carattere "spazio" all'interno di ogni elemento della matrice
			//stampa_campo(campoGioco);//stampo il campo di gioco mediante la procedura campoGioco

			int mosse=0; //inizializzo la variabile "mosse". Sarà utilizzata come contatore delle mosse e tramite l'operazione "mod 2" gestirò il cambio turno (quando l'operazione darà risultato 0 sarà il turno del player 1, quando il risultato sarà 1 sarà il turno del player 2)
			int vittoria=-1;

			while (vittoria==-1) //inizia il gioco vero e proprio in un ciclo verificato fino a che
			{

				if (mosse==COLONNE*RIGHE) //verifico che le mosse non siano superiori agli spazi contenuti nella matrice, nel caso lo siano termino la partita con un pareggio.
				{
					printf("Partita terminata, non ci sono vincitori!");
							exit(0);
				}

				else if (mosse % 2 == 0) //turno del giocatore 1
					{
						mossaplayer1=chiediposizione(campoGioco, p1); //chiamo la funzione chiediposizione che chiederà all'utente di scegliere la colonna dove posizionare la pedina, informazione che sarà restituita dalla funzione e memorizzata nella variabile "mossaplayer1"
						symbol=p1->symbol;
						mettipedina(mossaplayer1, symbol, campoGioco); //chiamo la procedura mettipedina che inserirà il simbolo dell'utente nella posizione scelta
						mosse++; //incremento il contatore delle mosse
						//int vittoria;
						vittoria=checkwin(campoGioco, p1); //chiamo la funzione checkwin per verificare se ci sono 4 pedine allineate
						if (vittoria != -1)
							{
								p1->vittorie++;
								//printf("%d \n\n",p1->vittorie);
								//printf("%d", vittoria);
								stampa_campo(campoGioco);
								bannervittoria();
								printf ("\t\t Complimenti %s!!\n", p1->nome);
								fineturno(p1, p2, &mosse);

								//exit(0);
							}

					}
				else if (mosse % 2 == 1)//turno del giocatore 2
					{
						mossaplayer2=chiediposizione(campoGioco, p2);
						//stampa_campo(campoGioco); //stampo il campo di gioco con la nuova pedina inserita tramite la procedura stampa_campo
						symbol=p2->symbol;
						mettipedina(mossaplayer2, symbol, campoGioco);
						mosse++;
						//stampa_campo(campoGioco);

						vittoria=checkwin(campoGioco, p2);
						if (vittoria != -1)
							{
								p2->vittorie++;
								//printf("%d \n\n",p2->vittorie);
								//printf("%d", vittoria);

								stampa_campo(campoGioco);
								bannervittoria();
								fineturno(p1, p2,&mosse);
								printf ("\t\t Complimenti %s!!", p2->nome);
								//exit(0);
							}


					}

				 if (vittoria != -1)
				{
				printf("\n\n\nWANNA PLAY AGAIN????");
				vittoria=rivincita(&count, campoGioco);
				printf("\n\n\nVITTORIA: %d \n\n", vittoria);
				}
			}



		}



	getchar();
	exit(0);

	}

int chiediposizione(char campoGioco[][COLONNE], pl * p1) //funzione che chiede all'utente la posizione dove inserire la sua pedina
{
		int ncol;
		do	{
				printf("\n\n  %s, scegli la colonna dove posizionare la pedina", p1->nome);
				stampa_campo(campoGioco); //stampo il campo di gioco con la nuova pedina inserita tramite la procedura stampa_campo
				printf("\n\n  Inserisci un numero da 1 a 7:");
				scanf("%d" , &ncol);
				if((ncol<1) || (ncol >(COLONNE))) //verifico che l'utente non inserisca un valore fuori dal campo di gioco

				{
					printf("  Scelta errata, la posizione è fuori dalla griglia!\n");
				}

				else if(campoGioco[0][ncol-1] != ' ') //verifico che la colonna selezionata non sia piena
					{
					printf("  La colonna selezionata è piena! Ripeti la selezione. \n") ;
					}
			}

		while ((ncol < 1) || (ncol > COLONNE) || (campoGioco[0][ncol-1] != ' '));

		return ncol; //restituisco la colonna scelta dall'utente al codice che ha invocato la funzione

}


void datigiocatori(pl * p1) //procedura richiamata per far inserire il nome all'utente nella variabile di tupo strutturato pl

	{
		printf ("  Inserisci il tuo nome (max 25 caratteri):");
		scanf("%s", p1->nome);

	}


int checkwin(char campoGioco[][COLONNE], pl * p1)

	{
	int i,j;
	int ritorno= -1;
	//char symbol;
	//symbol=p1->symbol;


	//Check orizzontale
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{
				if ( j+3 <= COLONNE-1 && campoGioco[i][j]==p1->symbol && campoGioco[i][j+1]==p1->symbol && campoGioco[i][j+2]==p1->symbol && campoGioco[i][j+3]==p1->symbol)
					{
						printf("\n\nVITTORIA ORIZZONTALE per %s!!!! \n", p1->nome );
						ritorno=1;
					}

			}
		}
	//Chech verticale
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{
				if (i+3 >= RIGHE-1 && campoGioco[i][j]==p1->symbol && campoGioco[i+1][j]==p1->symbol && campoGioco[i+2][j]==p1->symbol && campoGioco[i+3][j]==p1->symbol)
					{
						printf("\n\nVITTORIA VERTICALE per %s!!!! \n", p1->nome );
						ritorno=2;
					}
			}
		}
	//Chech diagonale decrescente
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{
				if (i+3 >= RIGHE-1 && j+3 <= COLONNE-1 && campoGioco[i][j]==p1->symbol && campoGioco[i+1][j+1]==p1->symbol && campoGioco[i+2][j+2]==p1->symbol && campoGioco[i+3][j+3]==p1->symbol)
					{
						printf("\n\nVITTORIA DIAGONALE DECRESCENTE per %s!!!! \n", p1->nome);
						ritorno=3;
					}
			}
		}


	//Chech diagonale crescente
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE;j++)
			{


				 if (i-3 >= 0 && j+3 <= COLONNE-1 && campoGioco[i][j]==p1->symbol && campoGioco[(i-1)][j+1]==p1->symbol && campoGioco[i-2][j+2]==p1->symbol && campoGioco[i-3][j+3]==p1->symbol)
					{

						printf("\n\nVITTORIA DIAGONALE CRESCENTE per %s!!!!\n", p1->nome);
						ritorno=4;
					}
			}
		}
	return ritorno;
	}

//funzione che chiede di specificare il numero di giocatori; se l'utente inserisce un numero diverso da 1 e 2 per 5 volte esco dal programma.

int numerogiocatori( int * count )

	{


		int nplayer;
		printf ("  Inserire 1 per sfidare il computer o 2 per giocare tra umani\n\n");
		printf ("  make your choice :)\n\n");
		scanf("%d", &nplayer);

			 if (nplayer != 1 && nplayer != 2 && (* count)>=4)
					{

				printf ("  Hai effettuato una scelta errata per 5 volte, riapri il programma.\n");
				nplayer=-2;

					}


			else if (nplayer != 1 && nplayer != 2)
					{
				nplayer=-1;
				* count = (* count) +1;
				printf ("hai effettuato una scelta errata! \n");

					}
			return nplayer;
	}


int rivincita ( int * count,  char campoGioco[][COLONNE] )

	{


		int rivincita;
		printf ("  Inserire 1 per effettuare una nuova partita oppure 2 per uscire\n\n");
		printf ("  make your choice :)\n\n");
		scanf("%d", &rivincita);

			 if (rivincita != 1 && rivincita != 2 && (* count)>=4)
					{

				printf ("  Hai effettuato una scelta errata per 5 volte, esco dal programma.\n");
				rivincita=-2;

					}


			else if (rivincita != 1 && rivincita != 2)
					{
				rivincita=-1;
				* count = (* count) +1;
				printf ("hai effettuato una scelta errata! \n");

					}


			else if (rivincita ==1)
					{
				rivincita=-1;
				riempi_campo(campoGioco);

				* count=0;

				printf ("Si rigioca! \n");
				printf ("RIVINCITA: %d\n", rivincita);
					}
			return rivincita;
	}

void fineturno(pl * p1, pl * p2, int * mosse)
	{
		printf("\t\t %s , hai vinto %d partite!\n", p1->nome, p1->vittorie);
		printf("\t \t%s , hai vinto %d partite!\n", p2->nome, p2->vittorie);

	}
