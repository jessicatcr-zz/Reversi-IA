/*******************************************************************************
 * jogada.h                                                                    *
 * Propósito: Apenas uma interface para as funções relativas as jogadas.       *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#ifndef _JOGADA_H_
#define _JOGADA_H_

#include "tabuleiro.h"

typedef struct jogada {
    int x;
    int y;
} jogada;

bool jogadaValida (jogo *jg, int x, int y, char jogador);
int jogadasValidas(jogo *jg, char jogador, jogada jogadas[28]);
int jogaComputador(jogo *jg, jogada *melhorJogada);
void vitoria(jogo *jg);

#endif
