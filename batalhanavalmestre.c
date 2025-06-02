#include <stdio.h>

#define TAM 10
#define TAM_HAB 5  // Tamanho das matrizes de habilidade (5x5)

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Sobrepõe uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int meio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha - meio + i;
                int colunaTab = origemColuna - meio + j;
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM && tabuleiro[linhaTab][colunaTab] == 0) {
                    tabuleiro[linhaTab][colunaTab] = 5; // 5 = área de efeito da habilidade
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posicionando 4 navios fixos (2 normais, 2 diagonais)
    tabuleiro[1][1] = tabuleiro[1][2] = tabuleiro[1][3] = 3; // Horizontal
    tabuleiro[3][5] = tabuleiro[4][5] = tabuleiro[5][5] = 3; // Vertical
    tabuleiro[6][1] = tabuleiro[7][2] = tabuleiro[8][3] = 3; // Diagonal descendo
    tabuleiro[6][8] = tabuleiro[7][7] = tabuleiro[8][6] = 3; // Diagonal subindo

    // Criando matriz de habilidade - Cone (forma de V invertido)
    int cone[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Criando matriz de habilidade - Cruz
    int cruz[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        cruz[i][TAM_HAB / 2] = 1;
        cruz[TAM_HAB / 2][i] = 1;
    }

    // Criando matriz de habilidade - Octaedro (losango)
    int octaedro[TAM_HAB][TAM_HAB] = {0};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicando habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone na posição (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz na posição (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro na posição (7,7)

    // Exibindo o resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}