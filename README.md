# Reversi_IA - Jéssica Rodrigues

### Instruções básicas:
1. A cada jogada, escolher uma posição a se colocar a peça do jogador. 
2. A posição será dada, digitando a coordenada horizontal, de 0 a 7 e a vertical, também de 0 a 7.
3. Pode ser usado em qualquer sistema operacional.
---
### Regras:
1. Se um jogador não possui nenhuma jogada válida, ele deve passar a vez.
2. O jogo termina quando nenhum jogador possui mais jogadas válidas.
3. Ganha quem tiver mais peças no tabuleiro.
---
### Lembrar:
Mesmo com a Poda-Alfa-Beta, você não irá conseguir percorrer todo o espaço de estados em tempo hábil, portanto você deverá determinar uma profundidade máxima para a busca (que pode ser variável) e implementar
funções de avaliação que determinem o valor de um determinado estado.
<br>Várias características podem ser utilizadas em sua função de avaliação. Procure limitar o tempo máximo de uma jogada
para o seu jogo não demorar demais.
