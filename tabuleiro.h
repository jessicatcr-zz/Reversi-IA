/*******************************************************************************
 * tabuleiro.h                                                                 *
 * Propósito: Apenas uma interface para as funções básicas do tabuleiro.       *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#ifndef _TABULEIRO_H_
#define _TABULEIRO_H_

#include "jogada.h"

void inicializaTab(jogo *jg);
// void inicializaTabPeso(int tabuleiroPeso[8][8]);
void imprimeTab(jogo *jg);
void atualizaTab (jogo *jg, int x, int y, char jogador);

#endif