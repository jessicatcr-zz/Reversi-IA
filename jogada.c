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

bool jogadaValida (char tabuleiro[8][8], int posH, int posV, char jogador) {
    // Não ultrapassar os limites
    if (posH > 7 || posV > 7 || posH < 0 || posV < 0) {
        return false;
    // Se todos ao redor são da mesma cor
    } else if (tabuleiro[posV-1][posH] == jogador && tabuleiro[posV+1][posH] == jogador &&
               tabuleiro[posV][posH-1] == jogador && tabuleiro[posV][posH+1] == jogador &&
               tabuleiro[posV-1][posH-1] == jogador && tabuleiro[posV+1][posH+1] == jogador &&
               tabuleiro[posV-1][posH+1] == jogador && tabuleiro[posV+1][posH-1] == jogador) {
        return false;
    // Se todos ao redor são vazios (caso geral)
    } else if (tabuleiro[posV-1][posH] == '_' && tabuleiro[posV+1][posH] == '_' &&
               tabuleiro[posV][posH-1] == '_' && tabuleiro[posV][posH+1] == '_' &&
               tabuleiro[posV-1][posH-1] == '_' && tabuleiro[posV+1][posH+1] == '_' &&
               tabuleiro[posV-1][posH+1] == '_' && tabuleiro[posV+1][posH-1] == '_') {
        return false;
    // Se todos ao redor são vazios (laterais)
    } else if (posV == 0 || posV == 7 || posV == 0 || posV == 7) {
        // if (posV == 0 &&)
        return false;
    } else {
        return true;
    }

}

void vitoria(bool gameOver, int ptsP, int ptsB) {
    if (gameOver) {
        if (ptsP > ptsB) {
            printf("Preto venceu!\n");
        } else if (ptsP < ptsB){
            printf("Branco venceu!\n");
        } else {
            printf("Preto e branco empataram!\n");
        }
    }
}
