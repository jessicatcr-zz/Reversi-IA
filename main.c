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


int main() {
    char tabuleiro[8][8];
    int tabuleiroPeso[8][8];
    int posH, posV, ptsB = 2, ptsP = 2;
    bool gameOver = false;

    inicializaTab(tabuleiro);
    inicializaTabPeso (tabuleiroPeso); // Para melhoria de estratégia
    imprimeTab(tabuleiro);

    // while(!gameOver) {
        printf("Qual a posição da sua próxima jogada?\n");
        printf("Horizontalmente: 0 1 2 3 4 5 6 7\n");
        scanf("%d", &posH);
        printf("E verticalmente: 0 1 2 3 4 5 6 7\n");
        scanf("%d", &posV);
    //     if (posH == 1) gameOver = true; //Para testar
        // printf("%dH - %dV\n", posH, posV);
    // }

    vitoria(gameOver, ptsP, ptsB);
    return 0;
}
