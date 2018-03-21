
/*
 ============================================================================
 Name        : FORZA 4
 Author      : Salvatore Albino
 Version     : 0.2a
 Copyright   : GNU General Public License v3.0
 Description : Sviluppo in C del gioco Forza 4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "campogioco.h"
#include "stampe.h"

typedef struct
	{char nome[25];
	char symbol;
	int vittorie; } pl;

void datigiocatori(pl * p1);
int chiediposizione(char campoGioco[][COLONNE], pl * p1);
int checkwin(char campoGioco[][COLONNE], pl * p1);
//int numerogiocatori(int * count);
void fineturno(pl * p1, pl * p2, int pareggi);
int rivincita(int * count, char campoGioco[][COLONNE], int partite,int * mosse );


int main()

{
	int mossaplayer1, mossaplayer2; //variabile per memorizzare la mossa del giocatore
	char symbol;	//variabile utilizzata per passare il simbolo
	int count = 0; //variabile utilizzata nel ciclo while per tenere conto dei tentativi errati ed uscire nel caso in cui la scelta sia sbagliata per 5 volte
	int pareggi = 0; //variabile intera utilizzata come contatore delle partite terminate senza vincitore
	int partite = 0; //variabile intera utilizzata come contatore per permettere ai giocatori di iniziare la partita una volta ciascuno

	banneriniziale(); //stampa il banner di benvenuto

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

	int mosse=0; //inizializzo la variabile "mosse". Sarà utilizzata come contatore delle mosse e tramite l'operazione "mod 2" gestirò il cambio turno (quando l'operazione darà risultato 0 sarà il turno del player 1, quando il risultato sarà 1 sarà il turno del player 2)
	int vittoria=-1;

	while (vittoria==-1) //inizia il gioco vero e proprio in un ciclo verificato fino a che
	{
		if (mosse==COLONNE*RIGHE||mosse==(1+(2*COLONNE*RIGHE))) //verifico che le mosse non siano superiori agli spazi contenuti nella matrice, nel caso lo siano termino la partita con un pareggio.
				{
					stampa_campo(campoGioco);
					printf("\n\n\t\tPartita terminata, non ci sono vincitori!\n\n");
					partite++; //aumento il contatore delle partite
					pareggi++; //aumento il contatore dei pareggi
					fineturno(p1, p2, pareggi); //richiamo
					vittoria=-3; //imposto il valore di vittoria al valore -3 (è un valore scelto arbitrariamente, mi basta che sia diverso da -1 per far scattare l'ultima if all'interno di questo ciclo while)

				}

		else if (mosse % 2 == 0) //turno del giocatore 1
				{
					mossaplayer1=chiediposizione(campoGioco, p1); //chiamo la funzione chiediposizione che chiederà all'utente di scegliere la colonna dove posizionare la pedina, informazione che sarà restituita dalla funzione e memorizzata nella variabile "mossaplayer1"
					symbol=p1->symbol; //valorizzo la variabile symbol con il simbolo assegnato al giocatore 1. Utilizzerò la variabile appena inizializzata per passarla come valore alla procedura mettipedina
					mettipedina(mossaplayer1, symbol, campoGioco); //chiamo la procedura mettipedina che inserirà il simbolo dell'utente nella posizione scelta
					mosse++; //incremento il contatore delle mosse
					vittoria=checkwin(campoGioco, p1); //chiamo la funzione checkwin per verificare se ci sono 4 pedine allineate
					if (vittoria != -1)//nel caso in cui riscontro la vittoria da parte del giocatore eseguo le seguenti azioni
							{
								p1->vittorie++; //incremento il contatore delle vittorie sulla variabile strutturata del giocatore
								partite++; //incremento il contatore delle partite
								stampa_campo(campoGioco); //stampo la matrice per far controllare ai giocatori il campo di gioco
								bannervittoria(); //stampo il messaggio di vittoria
								fineturno(p1, p2, pareggi); //chiamo la procedura fineturno che stampa il numero di vittorie per ciascun giocatore ed il numero di pareggi

							}

				}
		else if (mosse % 2 == 1)//turno del giocatore 2
				{
					mossaplayer2=chiediposizione(campoGioco, p2);
					symbol=p2->symbol;
					mettipedina(mossaplayer2, symbol, campoGioco);
					mosse++;
					vittoria=checkwin(campoGioco, p2);
					if (vittoria != -1)
							{
								p2->vittorie++;
								partite++;
								stampa_campo(campoGioco);
								bannervittoria();
								fineturno(p1, p2, pareggi);
								printf ("\t\t Complimenti %s!!", p2->nome);
							}


					}

		if (vittoria != -1) //se c'è una vittoria o un pareggio
				{
				printf("\n\n\nVuoi giocare ancora????");
				vittoria=rivincita(&count, campoGioco, partite, &mosse); //chiamo la funzione per chiedere all'utente se vuole giocare ancora o se vuole uscire
				}
			}


	getchar();
	exit(0);

	}

void datigiocatori(pl * p1) //procedura richiamata per far inserire il nome all'utente nella variabile di tipo strutturato pl

	{
		printf ("  Inserisci il tuo nome (max 25 caratteri): ");
		scanf("%s", p1->nome); //memorizzo il nome inserito dal giocatore nella variabile strutturata contenente i dati del giocatore

	}

int chiediposizione(char campoGioco[][COLONNE], pl * p1) //funzione che chiede all'utente la posizione dove inserire la sua pedina
{
		 int ncol; //valore della colonna inserito dall'utente
		 int isint; //variabile per memorizzare il risultato della verifica del tipo inserito dall'utente
		 char stringa[32]; //stringa utilizzata per memorizzare l'input dell'utente e successivamente validarlo

		do	{
				printf("\n\n  %s, scegli la colonna dove posizionare la pedina", p1->nome);
				stampa_campo(campoGioco); //stampo il campo di gioco tramite la procedura stampa_campo
				printf("\n\n  Inserisci un numero da 1 a 7:");
				fgets(stringa, sizeof stringa, stdin); 	//al fine di validare l'input inserito dall'utente, non uso una semplice scanf
														//per evitare errori indotti dall'immissione da parte dell'utente di caratteri piuttosto che interi
														//utilizzo una stringa di appoggio (stringa) per memorizzare l'input dell'utente

				isint = sscanf(stringa, "%d", &ncol);	//con il comando sscanf verifico che l'utente abbia inserito un numero, in caso positivo "isint" sarà valorizzato a 1





				if (isint != 1)						//con if viene valutata nel caso in cui con la funzione sscanf il programma rileva l'inserimento di un carattere
													//e non di un intero
				{
					printf("  Inserire un numero! \n");

				}



				else if((ncol<1) || (ncol >(COLONNE))) //verifico che l'utente non inserisca un valore fuori dal campo di gioco

				{
					printf("  Scelta errata, la posizione è fuori dalla griglia!\n");
					//ncol=0;
					//fflush (stdin);
					 //void free (void *ncol);
					// ungetc(ncol, stdin);
				}

				else if(campoGioco[0][ncol-1] != ' ') //verifico che la colonna selezionata non sia piena
					{
					printf("  La colonna selezionata è piena! Ripeti la selezione. \n");
					}
			}

		while ((ncol < 1) || (ncol > COLONNE) || (campoGioco[0][ncol-1] != ' ')|| (isint != 1) );
		return ncol; //restituisco la colonna scelta dall'utente al codice che ha invocato la funzione

}





int checkwin(char campoGioco[][COLONNE], pl * p1)

	{
	int i,j;
	int ritorno= -1;



	//Check orizzontale
	for (i=0; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE-3 ;j++)
			{
				if (  campoGioco[i][j]==p1->symbol && campoGioco[i][j+1]==p1->symbol && campoGioco[i][j+2]==p1->symbol && campoGioco[i][j+3]==p1->symbol) //oltre a verificare che ci siano le 4 pedine allineate orizzontalmente verifico che l'incremento della colonna non sia eccessivo
					{
						printf("\n\nVITTORIA ORIZZONTALE per %s!!!! \n", p1->nome );
						ritorno=1;
					}

			}
		}
	//Chech verticale
	for (i=0; i<RIGHE-3; i++)
		{
		for (j=0; j<COLONNE;j++)
			{
				if ( campoGioco[i][j]==p1->symbol && campoGioco[i+1][j]==p1->symbol && campoGioco[i+2][j]==p1->symbol && campoGioco[i+3][j]==p1->symbol) //oltre a verificare che ci siano le 4 pedine allineate verticalmente verifico che l'incremento della riga non sia eccessivo
					{
						printf("\n\nVITTORIA VERTICALE per %s!!!! \n", p1->nome );
						ritorno=2;
					}
			}
		}
	//Chech diagonale decrescente
	for (i=0; i<RIGHE-3; i++)
		{
		for (j=0; j<COLONNE-3;j++)
			{
				if ( campoGioco[i][j]==p1->symbol && campoGioco[i+1][j+1]==p1->symbol && campoGioco[i+2][j+2]==p1->symbol && campoGioco[i+3][j+3]==p1->symbol) //oltre a verificare che ci siano le 4 pedine allineate diagonalmente verifico che l'incremento  di riga e colonna non sia eccessivo

					{
						printf("\n\nVITTORIA DIAGONALE DECRESCENTE per %s!!!! \n", p1->nome);
						ritorno=3;
					}
			}
		}


	//Chech diagonale crescente
	for (i=3; i<RIGHE; i++)
		{
		for (j=0; j<COLONNE-3;j++)
			{


				 if (campoGioco[i][j]==p1->symbol && campoGioco[(i-1)][j+1]==p1->symbol && campoGioco[i-2][j+2]==p1->symbol && campoGioco[i-3][j+3]==p1->symbol) //oltre a verificare che ci siano le 4 pedine allineate diagonalmente verifico che l'incremento o la sottrazione  di riga e colonna non sia eccessivo
					{

						printf("\n\nVITTORIA DIAGONALE CRESCENTE per %s!!!!\n", p1->nome);
						ritorno=4;
					}
			}
		}
	return ritorno;
	}



void fineturno(pl * p1, pl * p2, int pareggi) //procedura che stampa il numero di vittorie ottenute dai due giocatori oltre al numero di pareggi

	{
		printf("\t\t %s , hai vinto %d partite!\n", p1->nome, p1->vittorie);
		printf("\t\t %s , hai vinto %d partite!\n", p2->nome, p2->vittorie);
		printf("\t\t Pareggi: %d\n\n", pareggi);
	}

int rivincita ( int * count,  char campoGioco[][COLONNE], int partite, int * mosse ) //funzione che chiede all'utente se desidera giocare nuovamente o se vuole uscire dal programma

	{


		int rivincita; //variabile intera che utilizzo per memorizzare il valore inserito dall'utente
		printf ("  Inserire 1 per effettuare una nuova partita oppure 2 per uscire\n\n");
		scanf("%d", &rivincita);

			 if (rivincita != 1 && rivincita != 2 && (* count)>=4) //se la variabile rivincita è diversa da 1 e 2 avviso l'utente della scelta errata e incremento il contatore count passato tramite puntatore alla funzione. Raggiunti i 5 tentativi esco dal programma
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


			else if (rivincita==1) // l'utente sceglie di rigiocare
				{
					riempi_campo(campoGioco); //reinizializzo la matrice
					if (partite % 2 == 0)	//se il numero di partite giocate è pari faccio iniziare il giocatore 1 inizializzando a 0 il contatore mosse (la differenza sta nel valorizzare mosse con un numero pari piuttosto che dispari, vedi i due else if del ciclo while principale)
					{
						* mosse=0;
					}

					else if (partite % 2 == 1)
					{
						* mosse=(COLONNE*RIGHE)+1; //se il numero di partite giocate è dispari faccio iniziare il giocatore 2
					}
				rivincita=-1; //il valore che sarà tornato dalla funzione e memorizzato nel prigramma principale nella variabile guardia vittoria: in questo modo non esco dal ciclo principale while.


				printf ("Si rigioca! \n");
					}

			else if (rivincita==2) //non si rigioca, esco
					{

				printf ("\n\n\t\t Grazie per aver giocato a Forza 4!");
				exit(0);

					}
			return rivincita; //ritorno il valore di rivincita

	}
