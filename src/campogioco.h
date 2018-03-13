/*
 * campogioco.h
 *
 *  Created on: 18 feb 2018
 *      Author: nowhereboy
 */

#ifndef SRC_CAMPOGIOCO_H_
#define SRC_CAMPOGIOCO_H_

#define COLONNE 7
#define RIGHE 6

void riempi_campo(char campoGioco[][COLONNE]); //funzione per inizializzare la matrice
void stampa_campo(char campoGioco[][COLONNE]); //funzione per stampare la matrice
void mettipedina(int pos, char symbol, char campoGioco[][COLONNE]);

char campoGioco[RIGHE][COLONNE]; //campo di gioco, utilizzo una matrice
#endif /* SRC_CAMPOGIOCO_H_ */
