/*******************************************************************************
 * main.c                                                                      *
 * Propósito: Criar jogo Reversi, utilizando do algoritmo MiniMax com          *
 * estratégia poda Alfa-Beta                                                   *
 *                                                                             *
 * Entrada: Estado tabuleiro                                                   *
 * Retorno: Jogada valida                                                      *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/11/2018                                                     *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool jogadaValida (char tabuleiro[8][8], int posH, int posV, char jogador) {
    // Verifica se não é uma posição isolada no tabuleiro
    if (tabuleiro[posV-1][posH] == '_' && tabuleiro[posV+1][posH] == '_' &&
        tabuleiro[posV][posH-1] == '_' && tabuleiro[posV][posH+1] == '_') {
        return false;
    } else if (posH > 7 || posV > 7) { //Não ultrapassa os limites
        return false;
    } else {
        if (jogador == 'P') {
            // Também tem que considerar um da mesma cor a pelo menos 1 de distância
            if (tabuleiro[posV-1][posH] == 'B' || tabuleiro[posV+1][posH] == 'B' ||
                tabuleiro[posV][posH-1] == 'B' || tabuleiro[posV][posH+1] == 'B' ||
                tabuleiro[posV-1][posH-1] == 'B' || tabuleiro[posV+1][posH+1] == 'B' ||
                tabuleiro[posV-1][posH+1] == 'B' || tabuleiro[posV+1][posH-1] == 'B') {
                return true;
            } else {
                return false;
            }
        } else if (jogador == 'B') {
            if (tabuleiro[posV-1][posH] == 'P' || tabuleiro[posV+1][posH] == 'P' ||
                tabuleiro[posV][posH-1] == 'P' || tabuleiro[posV][posH+1] == 'P' ||
                tabuleiro[posV-1][posH-1] == 'P' || tabuleiro[posV+1][posH+1] == 'P' ||
                tabuleiro[posV-1][posH+1] == 'P' || tabuleiro[posV+1][posH-1] == 'P') {
                return true;
            } else {
                return false;
            }
        }
    }
}

void atualizaTab (char tabuleiro[8][8], int posH, int posV, char jogador) {
    if (jogadaValida (tabuleiro, posH, posV, jogador)) {
        //
    } else {
        printf("Esta não é uma jogada valida\n");
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

int main() {
    char tabuleiro[8][8];
    int tabuleiroPeso[8][8];
    int posH, posV, ptsB = 2, ptsP = 2;
    bool gameOver = false;

    inicializaTab(tabuleiro);
    inicializaTabPeso (tabuleiroPeso); // Para melhoria de estratégia
    imprimeTab(tabuleiro); 
    
    // while(!gameOver) {
    //     printf("Qual a posição da sua próxima jogada?\n");
    //     printf("Horizontalmente: 0 1 2 3 4 5 6 7\n");
    //     scanf("%d", &posH);
    //     printf("E verticalmente: 0 1 2 3 4 5 6 7\n");
    //     scanf("%d", &posV);
    //     if (posH == 1) gameOver = true;
    //     printf("%dH - %dV\n", posH, posV);
    // }

    vitoria(gameOver, ptsP, ptsB);
    return 0;
}