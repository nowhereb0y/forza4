/*
 * defplayer.h
 *
 *  Created on: 19 feb 2018
 *      Author: nowhereboy
 */

#ifndef SRC_DEFPLAYER_H_
#define SRC_DEFPLAYER_H_

void inserisciutenti();
int numerogiocatori();

typedef struct
	{char nome[25];
	char symbol[1];
	int vittorie;
	} pl;
void datigiocatori(pl * p1);
#endif /* SRC_DEFPLAYER_H_ */
