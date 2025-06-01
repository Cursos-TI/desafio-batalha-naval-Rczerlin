#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. Inicialização do tabuleiro 10x10 com água (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // 2. Definição dos navios (tamanho 3 cada)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaHoriz = 2, colunaHoriz = 4; // Navio horizontal na linha 2
    int linhaVert = 5, colunaVert = 7;   // Navio vertical na coluna 7

    // Validação simples para garantir que cabem no tabuleiro
    if (colunaHoriz + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaVert + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // 3. Posicionar o navio horizontal no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaHoriz][colunaHoriz + i] = navioHorizontal[i];
        }

        // 4. Posicionar o navio vertical no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se há sobreposição com o navio horizontal
            if (tabuleiro[linhaVert + i][colunaVert] == 0) {
                tabuleiro[linhaVert + i][colunaVert] = navioVertical[i];
            } else {
                printf("Erro: sobreposição de navios detectada!\n");
                return 1;
            }
        }

        // 5. Exibir o tabuleiro
        printf("Tabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");
        for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
            for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
                printf("%d ", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }
    } else {
        printf("Erro: navios fora dos limites do tabuleiro!\n");
    }

    return 0;
}