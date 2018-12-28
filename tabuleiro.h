/*******************************************************************************
 * tabuleiro.h                                                                 *
 * Propósito: Apenas uma interface para as funções básicas do tabuleiro.       *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#ifndef _TABULEIRO_H_
#define _TABULEIRO_H_

typedef struct jogo {
    char tabuleiro[8][8];
    int ptsB;
    int ptsP;
    int limiteCima;
    int limiteDir;
    int limiteBaixo;
    int limiteEsq;
} jogo;

void inicializaTab(jogo *jg);
// void inicializaTabPeso(int tabuleiroPeso[8][8]);
void imprimeTab(jogo *jg);
void copiaTab (jogo *fonte, jogo *destino);
void atualizaTab (jogo *jg, int x, int y, char jogador);
int min (int a, int b);
int max (int a, int b);

#endif