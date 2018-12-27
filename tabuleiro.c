/*******************************************************************************
 * tabuleiro.c                                                                 *
 * Propósito: Funções básicas para criação/manipulação do tabuleiro do jogo    *
 *            Reversi - 8 x 8                                                  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabuleiro.h"

void inicializaTab(jogo *jg) {
    int i, j;
    
    jg->ptsB = 2;
    jg->ptsP = 2;
    jg->limiteCima = 2;
    jg->limiteDir = 5;
    jg->limiteBaixo = 5;
    jg->limiteEsq = 2;

    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if ((i == 3 && j == 3) || (i == 4 && j == 4)){
                jg->tabuleiro[i][j] = 'B';
            } else if ((i == 4 && j == 3) || (i == 3 && j == 4)){
                jg->tabuleiro[i][j] = 'P';
            } else {
                jg->tabuleiro[i][j] = '_';
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

void imprimeTab(jogo *jg) {
    int i, j;
    printf("\n");
    printf("  a b c d e f g h\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for (j = 0; j < 8; j++) {
            printf("%c ", jg->tabuleiro[i][j]);
        }
        printf("%d ", i+1);
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

int min (int a, int b) {
    if (a < b) return a;
    else return b;
}

int max (int a, int b) {
    if (a > b) return a;
    else return b;
}

void atualizaTab (jogo *jg, int x, int y, char jogador) {
    bool valido, procurando;
    int i, j, ptsGanhos = 0;

    jg->tabuleiro[x][y] = jogador;
    ptsGanhos++;

    jg->limiteCima = min(jg->limiteCima, (x-1 < 0 ? 0 : x-1));
    jg->limiteDir =  max(jg->limiteDir, (y+1 > 7 ? 7 : y+1));
    jg->limiteBaixo = max(jg->limiteBaixo, (x+1 > 7 ? 7 : x+1));
    jg->limiteEsq = min(jg->limiteEsq, (y-1 < 0 ? 0 : y-1));


    // Percorrendo linhas
    i = x - 1, procurando = true, valido = false;
    while (i >= 0 && procurando) {
        if (jg->tabuleiro[i][y] == '_') {
            procurando = false;
        } else if (abs(i - x) == 1 && jg->tabuleiro[i][y] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[i][y] == jogador) {
            procurando = false;
            valido = true;
        }
        i--;
    }

    for(j = i + 1; valido && j < x; j++)
        jg->tabuleiro[j][y] = jogador, ptsGanhos++;

    i = x + 1, procurando = true, valido = false;
    while (!valido && procurando && i <= 7) {
        if (jg->tabuleiro[i][y] == '_') {
            procurando = false;
        } else if (abs(i - x) == 1 && jg->tabuleiro[i][y] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[i][y] == jogador) {
            procurando = false;
            valido = true;
        }
        i++;
    }

    for(j = i - 1; valido && j > x; j--)
        jg->tabuleiro[j][y] = jogador, ptsGanhos++;

    // Percorrendo colunas
    i = y - 1, procurando = true, valido = false;
    while (!valido && procurando && i >= 0) {
        if (jg->tabuleiro[x][i] == '_') {
            procurando = false;
        } else if (abs(i - y) == 1 && jg->tabuleiro[x][i] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[x][i] == jogador) {
            procurando = false;
            valido = true;
        }
        i--;
    }

    for(j = i + 1; valido && j < y; j++)
        jg->tabuleiro[x][j] = jogador, ptsGanhos++;

    i = y + 1, procurando = true, valido = false;
    while (!valido && procurando && i <= 7) {
        if (jg->tabuleiro[x][i] == '_') {
            procurando = false;
        } else if (abs(i - y) == 1 && jg->tabuleiro[x][i] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[x][i] == jogador) {
            procurando = false;
            valido = true;
        }
        i++;
    }

    for(j = i - 1; valido && j > y; j--)
        jg->tabuleiro[x][j] = jogador, ptsGanhos++;

    // Percorrendo diagonais
    i = 1, procurando = true, valido = false;
    while (!valido && procurando && (y + i <= 7) && (x + i <= 7)) {
        if (jg->tabuleiro[x+i][y+i] == '_') {
            procurando = false;
        } else if (i == 1 && jg->tabuleiro[x+i][y+i] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[x+i][y+i] == jogador) {
            procurando = false;
            valido = true;
        }
        i++;
    }

    for(j = i - 1; valido && j > 0; j--)
        jg->tabuleiro[x+j][y+j] = jogador, ptsGanhos++;

    i = 1, procurando = true, valido = false;
    while (!valido && procurando && (y - i >= 0) && (x - i >= 0)) {
        if (jg->tabuleiro[x-i][y-i] == '_') {
            procurando = false;
        } else if (i == 1 && jg->tabuleiro[x-i][y-i] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[x-i][y-i] == jogador) {
            procurando = false;
            valido = true;
        }
        i++;
    }

    for(j = i - 1; valido && j > 0; j--)
        jg->tabuleiro[x-j][y-j] = jogador, ptsGanhos++;

    i = 1, procurando = true, valido = false;
    while (!valido && procurando && (y - i >= 0) && (x + i <= 7)) {
        if (jg->tabuleiro[x+i][y-i] == '_') {
            procurando = false;
        } else if (i == 1 && jg->tabuleiro[x+i][y-i] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[x+i][y-i] == jogador) {
            procurando = false;
            valido = true;
        }
        i++;
    }

    for(j = i - 1; valido && j > 0; j--)
        jg->tabuleiro[x+j][y-j] = jogador, ptsGanhos++;


    i = 1, procurando = true, valido = false;
    while (!valido && procurando && (y + i <= 7) && (x - i >= 0)) {
        if (jg->tabuleiro[x-i][y+i] == '_') {
            procurando = false;
        } else if (i == 1 && jg->tabuleiro[x-i][y+i] == jogador) {
            procurando = false;
        } else if(jg->tabuleiro[x-i][y+i] == jogador) {
            procurando = false;
            valido = true;
        }
        i++;
    }

    for(j = i - 1; valido && j > 0; j--)
        jg->tabuleiro[x-j][y+j] = jogador, ptsGanhos++;

    if(jogador == 'P') {
        jg->ptsP += ptsGanhos;
        jg->ptsB -= (ptsGanhos-1);
    } else {
        jg->ptsB += ptsGanhos;
        jg->ptsP -= (ptsGanhos-1);
    }
}
