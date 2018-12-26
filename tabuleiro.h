/*******************************************************************************
 * tabuleiro.h                                                                 *
 * Propósito: Apenas uma interface para as funções básicas do tabuleiro.       *
 *                                                                             *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#ifndef _TABULEIRO_H_
#define _TABULEIRO_H_

void inicializaTab(char tabuleiro[8][8]);
void inicializaTabPeso(int tabuleiroPeso[8][8]);
void imprimeTab(char tabuleiro[8][8]);
void atualizaTab (char tabuleiro[8][8], int posH, int posV, char jogador);

#endif