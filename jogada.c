/*******************************************************************************
 * jogada.c                                                                    *
 * Propósito: Funções básicas para criação/manipulação das jogadas efetuadas   *
 *            no jogo Reversi                                                  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "jogada.h"

bool jogadaValida (jogo *jg, int x, int y, char jogador) {
    // Não ultrapassar os limites
    if (y > 7 || x > 7 || y < 0 || x < 0 || jg->tabuleiro[x][y] != '_') {
        return false;
    } else {
        int i;
        bool valido = false, procurando;
        
        // Percorrendo linhas
        i = x - 1, procurando = true;
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

        i = x + 1, procurando = true;
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

        // Percorrendo colunas
        i = y - 1, procurando = true;
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

        i = y + 1, procurando = true;
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

        // Percorrendo diagonais
        i = 1, procurando = true;
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

        i = 1, procurando = true;
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

        i = 1, procurando = true;
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

        i = 1, procurando = true;
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
        return valido;
    }
}
// 28 é o máximo de posições de jogadas validas possíveis.
int jogadasValidas(jogo *jg, char jogador, jogada jogadas[28]) { 
    int cont = 0;
    int i, j;

    for (i = jg->limiteCima; i <= jg->limiteBaixo; i++) {
        for (j = jg->limiteEsq; j <= jg->limiteDir; j++) {
            if (jogadaValida (jg, i, j, jogador)){
                jogadas[cont].x = i;
                jogadas[cont].y = j;
                cont++;
            }
        }
    }
    return cont;
} 

void vitoria(int ptsP, int ptsB) {
    if (ptsP > ptsB) {
        printf("Jogador venceu!\n");
    } else if (ptsP < ptsB){
        printf("Computador venceu!\n");
    } else {
        printf("Empate!\n");
    }
}
