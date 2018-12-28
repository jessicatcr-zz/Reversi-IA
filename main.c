/*******************************************************************************
 * main.c                                                                      *
 * Propósito: Criar jogo Reversi, utilizando do algoritmo MiniMax com          *
 * estratégia poda Alfa-Beta                                                   *
 *                                                                             *
 * Entrada: Estado tabuleiro                                                   *
 * Retorno: Jogada valida                                                      *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabuleiro.h"
#include "jogada.h"

// Preto: jogador; branco: computador.
int main() {
    jogo jg;
    // int tabuleiroPeso[8][8];
    char y;
    int x, nJogadasValidas, i;
    jogada jogadas[28];
    bool gameOver = false, vezJogador = true, passouVez = false, verEntrada;

    inicializaTab(&jg);
    // inicializaTabPeso (tabuleiroPeso); // Para melhoria de estratégia

    while(!gameOver) {
        imprimeTab(&jg);        
        if (vezJogador) {
            nJogadasValidas = jogadasValidas(&jg, 'P', jogadas);
            if (nJogadasValidas > 0) {
                verEntrada = true;
                do {
                    printf("\nQual a posição da sua próxima jogada?\n"); //preto começa
                    printf("Número: 1 2 3 4 5 6 7 8\n");
                    scanf(" %d", &x);
                    printf("Letra: a b c d e f g h\n");
                    scanf(" %c", &y);
                    if ((x >= 1 && x <= 8) && (y >= 'a' && y <= 'h')) {
                        y -= 'a';
                        x -= 1;
                        for (i = 0; i < nJogadasValidas; i++) {
                            if (x == jogadas[i].x && y == jogadas[i].y) {
                                verEntrada = false;
                            }
                        }
                        if (verEntrada) printf("Jogada Inválida!\n");
                    }
                } while(verEntrada);

                // printf("[DEBUG] JOGADOR: (%d,%c)", x+1, y+'a');
                atualizaTab(&jg, x, y, 'P');
            } else {
                passouVez = true;
            }
            vezJogador = false;    
        } else {
            jogada jogadaComputador;
            nJogadasValidas = jogaComputador(&jg, &jogadaComputador);
            if (nJogadasValidas > 0) {
                passouVez = false;

                // printf("[DEBUG] COMPUTADOR: (%d,%c)", jogadas[0].x+1, jogadas[0].y+'a');
                atualizaTab(&jg, jogadaComputador.x, jogadaComputador.y, 'B');
            }
            vezJogador = true;
        }
        if (passouVez && vezJogador) gameOver = true;
    }

    vitoria(&jg);
    return 0;
}
