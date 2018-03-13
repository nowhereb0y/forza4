/*
 * stampe.c
 *
 *
 *      Autore: Salvatore Albino
 */

#include <stdio.h>


void banneriniziale() //procedura che stampa il banner di benvenuto

	{
	printf("\t\t _______ _______ _______ _______ _______     _______     _______ _______ \n");
	printf("\t\t|\\     /|\\     /|\\     /|\\     /|\\     /|   |\\     /|   |\\     /|\\     /|\n");
	printf("\t\t| +---+ | +---+ | +---+ | +---+ | +---+ |   | +---+ |   | +---+ | +---+ |\n");
	printf("\t\t| |   | | |   | | |   | | |   | | |   | |   | |   | |   | |   | | |   | |\n");
	printf("\t\t| |F  | | |O  | | |R  | | |Z  | | |A  | |   | |4  | |   | |!  | | |!  | |\n");
	printf("\t\t| +---+ | +---+ | +---+ | +---+ | +---+ |   | +---+ |   | +---+ | +---+ |\n");
	printf("\t\t|/_____\\|/_____\\|/_____\\|/_____\\|/_____\\|   |/_____\\|   |/_____\\|/_____\\|\n");

	printf("\n\n\n\n");
	printf("\t\tBenvenuti nel gioco Forza 4!\n");
	printf("\t\tLo scopo del gioco è quello di allineare 4 pedine in orizzontale, verticale o in una delle due diagonali\n");
	printf("\t\tBuon divertimento!\n\n");
	}


void bannervittoria() //procedura che stampa un banner in caso di vittoria

	{
	printf(" _______ _______ _______     _______ _______ _______ _______ _______     _______ \n");
	printf("|\\     /|\\     /|\\     /|   |\\     /|\\     /|\\     /|\\     /|\\     /|   |\\     /|\n");
	printf("| +---+ | +---+ | +---+ |   | +---+ | +---+ | +---+ | +---+ | +---+ |   | +---+ |\n");
	printf("| |   | | |   | | |   | |   | |   | | |   | | |   | | |   | | |   | |   | |   | |\n");
	printf("| |H  | | |A  | | |I  | |   | |V  | | |I  | | |N  | | |T  | | |O  | |   | |!  | |\n");
	printf("| +---+ | +---+ | +---+ |   | +---+ | +---+ | +---+ | +---+ | +---+ |   | +---+ |\n");
	printf("|/_____\\|/_____\\|/_____\\|   |/_____\\|/_____\\|/_____\\|/_____\\|/_____\\|   |/_____\\|\n");
	printf("\n\n\n\n");

	}
