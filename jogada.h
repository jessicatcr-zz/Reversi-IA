/*******************************************************************************
 * jogada.h                                                                    *
 * Propósito: Apenas uma interface para as funções relativas as jogadas.       *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#ifndef _JOGADA_H_
#define _JOGADA_H_

typedef struct jogo {
    char tabuleiro[8][8];
    int ptsB;
    int ptsP;
    int limiteCima;
    int limiteDir;
    int limiteBaixo;
    int limiteEsq;
} jogo;


typedef struct jogada {
    int x;
    int y;
} jogada;

bool jogadaValida (jogo *jg, int x, int y, char jogador);
int jogadasValidas(jogo *jg, char jogador, jogada jogadas[28]);
void vitoria(int ptsP, int ptsB);

#endif
