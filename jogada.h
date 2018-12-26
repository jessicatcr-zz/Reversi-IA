/*******************************************************************************
 * jogada.h                                                                    *
 * Propósito: Apenas uma interface para as funções relativas as jogadas.       *
 *                                                                             *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#ifndef _JOGADA_H_
#define _JOGADA_H_

bool jogadaValida (char tabuleiro[8][8], int posH, int posV, char jogador);
void vitoria(bool gameOver, int ptsP, int ptsB);

#endif
