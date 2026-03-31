#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 8

void ordena(int C[TAM]) {
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1 - i; j++) {
            if (C[j] > C[j + 1]) {
                int tmp = C[j];
                C[j]     = C[j + 1];
                C[j + 1] = tmp;
            }
        }
    }
}

void troco(int C[TAM], int valor, int S[TAM]) {

    for (int i = 0; i < TAM; i++) S[i] = 0;

    int soma = 0;
    int indiceMaior = TAM - 1;

    while (indiceMaior >= 0 && soma < valor) {
        int m = C[indiceMaior];

        if (soma + m <= valor) {
            soma += m;
            S[indiceMaior] += 1;
        } else {
            indiceMaior -= 1;
        }
    }

    if (soma == valor) {
        return;
    } else {
        printf("Valor nao encontrado\n");
    }
}

int main() {
    int C[TAM] = {1, 4, 5, 7, 10, 25, 90, 30};
    ordena(C);

    int COrdenado[TAM];
    memcpy(COrdenado, C, sizeof(C));

    int s[TAM];
    troco(COrdenado, 50, s);
    for (int i = 0; i < TAM; i++) {
        if (s[i] > 0) {
            printf("%d moedas de %d\n", s[i], COrdenado[i]);
        }
    }

    return 0;
}