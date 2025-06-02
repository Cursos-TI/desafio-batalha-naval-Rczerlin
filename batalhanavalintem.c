#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAM 10
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Função auxiliar para verificar se pode posicionar o navio
    int pode_posicionar(int linha[], int coluna[]) {
        for (int i = 0; i < NAVIO; i++) {
            if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
                return 0;
            if (tabuleiro[linha[i]][coluna[i]] != 0)
                return 0;
        }
        return 1;
    }

    // Função para posicionar o navio no tabuleiro
    void posicionar_navio(int linha[], int coluna[]) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha[i]][coluna[i]] = 3;
        }
    }

    // -------------------------------
    // Navio 1 - Horizontal (linha 1, colunas 2-4)
    int l1[] = {1, 1, 1};
    int c1[] = {2, 3, 4};

    if (pode_posicionar(l1, c1)) {
        posicionar_navio(l1, c1);
    }

    // Navio 2 - Vertical (linha 4-6, coluna 6)
    int l2[] = {4, 5, 6};
    int c2[] = {6, 6, 6};

    if (pode_posicionar(l2, c2)) {
        posicionar_navio(l2, c2);
    }

    // Navio 3 - Diagonal ↘ (linha 0-2, coluna 0-2)
    int l3[] = {0, 1, 2};
    int c3[] = {0, 1, 2};

    if (pode_posicionar(l3, c3)) {
        posicionar_navio(l3, c3);
    }

    // Navio 4 - Diagonal ↙ (linha 2-0, coluna 7-9)
    int l4[] = {2, 1, 0};
    int c4[] = {7, 8, 9};

    if (pode_posicionar(l4, c4)) {
        posicionar_navio(l4, c4);
    }

    // -------------------------------
    // Exibição do tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}