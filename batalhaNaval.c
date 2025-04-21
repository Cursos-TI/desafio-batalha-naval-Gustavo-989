#include <stdio.h>

#define TAMANHO 5  // Todas as habilidades terão uma matriz 5x5 para centralizar a origem

// Função para imprimir uma matriz
void imprimirMatriz(int matriz[TAMANHO][TAMANHO], const char* nome) {
    printf("\nPadrão de habilidade: %s\n", nome);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int cone[TAMANHO][TAMANHO] = {0};
    int cruz[TAMANHO][TAMANHO] = {0};
    int octaedro[TAMANHO][TAMANHO] = {0};

    int centro = TAMANHO / 2; // Centro da matriz: posição (2,2)

    // Preencher padrão em CONE (forma de pirâmide voltada para baixo)
    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            cone[centro - i][j] = 1;
        }
    }

    // Preencher padrão em CRUZ (uma linha e uma coluna cruzando o centro)
    for (int i = 0; i < TAMANHO; i++) {
        cruz[centro][i] = 1; // linha central
        cruz[i][centro] = 1; // coluna central
    }

    // Preencher padrão em OCTAEDRO (forma de losango)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (abs(i - centro) + abs(j - centro) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Exibição
    imprimirMatriz(cone, "CONE");
    imprimirMatriz(cruz, "CRUZ");
    imprimirMatriz(octaedro, "OCTAEDRO");

    return 0;
}
