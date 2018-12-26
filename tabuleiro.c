/*******************************************************************************
 * tabuleiro.c                                                                 *
 * Propósito: Funções básicas para criação/manipulação do tabuleiro do jogo    *
 *            Reversi - 8 x 8                                                  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

void inicializaTab(char tabuleiro[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if ((i == 3 && j == 3) || (i == 4 && j == 4)){
                tabuleiro[i][j] = 'B';
            } else if ((i == 4 && j == 3) || (i == 3 && j == 4)){
                tabuleiro[i][j] = 'P';
            } else {
                tabuleiro[i][j] = '_';
            }
        }
    }
}

void inicializaTabPeso(int tabuleiroPeso[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if ((i == 3 && j == 3) || (i == 4 && j == 4) ||
                (i == 4 && j == 3) || (i == 3 && j == 4)){
                tabuleiroPeso[i][j] = 0; // Posições iniciais
            } else if ((i == 0 && j == 0) || (i == 7 && j == 7) ||
                       (i == 0 && j == 7) || (i == 7 && j == 0)){
                tabuleiroPeso[i][j] = 5; // Quinas do tabuleiro
            } else if ((i == 0 && j == 1) || (i == 0 && j == 6) ||
                       (i == 1 && j == 0) || (i == 1 && j == 7) ||
                       (i == 6 && j == 0) || (i == 6 && j == 7) ||
                       (i == 7 && j == 1) || (i == 7 && j == 6)){
                tabuleiroPeso[i][j] = -1; // Laterais perigosas
            } else if ((i == 1 && j == 1) || (i == 1 && j == 6) ||
                       (i == 6 && j == 1) || (i == 6 && j == 6)) {
                tabuleiroPeso[i][j] = -2; // Diagonais da quina
            } else if ((i == 0 && j == 2) || (i == 0 && j == 5) ||
                       (i == 2 && j == 0) || (i == 2 && j == 7) ||
                       (i == 5 && j == 0) || (i == 5 && j == 7) ||
                       (i == 7 && j == 2) || (i == 7 && j == 5)){
                tabuleiroPeso[i][j] = 2; // laterais boas
            } else {
                tabuleiroPeso[i][j] = 1;
            }
        }
    }
}

void imprimeTab(char tabuleiro[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void atualizaTab (char tabuleiro[8][8], int posH, int posV, char jogador) {
    if (jogadaValida (tabuleiro, posH, posV, jogador)) {
        //
    } else {
        printf("Esta não é uma jogada valida\n");
    }
}
