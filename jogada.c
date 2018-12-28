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
#include <limits.h>
#include "jogada.h"

#define INFINITOPOS INT_MAX
#define INFINITONEG INT_MIN

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

int minimax (jogo *noJogo, int profundidade, bool maximizar, int alfa, int beta) {
    int nJogadasValidas, melhorValor, valor, i;
    char jogador;
    jogo jogobkp;
    jogada jogadas[28];

    if(maximizar) jogador = 'B';
    else jogador = 'P';
    
    nJogadasValidas = jogadasValidas(noJogo, jogador, jogadas);
    
    if (nJogadasValidas == 0 || profundidade == 0) {
        return noJogo->ptsB;
    }

    if (maximizar) {
        melhorValor = INFINITONEG;

        for(i = 0; i < nJogadasValidas; i++) {
            copiaTab(noJogo, &jogobkp);
            atualizaTab(noJogo, jogadas[i].x, jogadas[i].y, 'B');
            valor = minimax(noJogo, profundidade-1, false, alfa, beta);
            melhorValor = max(melhorValor, valor);
            alfa = max(alfa, melhorValor);
            copiaTab(&jogobkp, noJogo);

            if (beta <= alfa)
                break;
        }

        return melhorValor;
    } else {
        melhorValor = INFINITOPOS;

        for(i = 0; i < nJogadasValidas; i++) {
            copiaTab(noJogo, &jogobkp);
            atualizaTab(noJogo, jogadas[i].x, jogadas[i].y, 'P');
            valor = minimax(noJogo, profundidade-1, true, alfa, beta);
            melhorValor = min(melhorValor, valor);
            beta = min(beta, melhorValor);
            copiaTab(&jogobkp, noJogo);

            if (beta <= alfa)
                break;
        }

        return melhorValor;
    }
}

int jogaComputador(jogo *jg, jogada *melhorJogada) {
    int nJogadasValidas;
    jogada jogadas[28];

    nJogadasValidas = jogadasValidas(jg, 'B', jogadas);
    if(nJogadasValidas == 0) {
        return 0;
    } else {
        jogo jogobkp, *noJogo;
        int melhorValor, profundidade, valor, melhorIndice = 0, alfa, beta, i; 

        noJogo = jg;
        profundidade = 3;
        alfa = INFINITONEG;
        beta = INFINITOPOS;


        melhorValor = INFINITONEG;

        for(i = 0; i < nJogadasValidas; i++) {
            copiaTab(noJogo, &jogobkp);
            atualizaTab(noJogo, jogadas[i].x, jogadas[i].y, 'B');
            valor = minimax(noJogo, profundidade-1, false, alfa, beta);
            
            if (valor > melhorValor) {
                melhorIndice = i;
                melhorValor = valor;
            }

            alfa = max(alfa, melhorValor);
            copiaTab(&jogobkp, noJogo);

            if (beta <= alfa)
                break;
        }

        melhorJogada->x = jogadas[melhorIndice].x;
        melhorJogada->y = jogadas[melhorIndice].y;

        return 1;
    }
}

void vitoria(jogo *jg) {
    printf("Jogador [P] %d vs %d [B] Computador\n\n", jg->ptsP, jg->ptsB);

    if (jg->ptsP > jg->ptsB) {
        printf("Jogador venceu!\n");
    } else if (jg->ptsP < jg->ptsB){
        printf("Computador venceu!\n");
    } else {
        printf("Empate!\n");
    }  
}
