#include <stdio.h>
#include <stdbool.h>
#define TAM 4


void backtrack(int valores[TAM], int indicesAcessados[TAM], int indiceAtual, int s[TAM], int *max){
    
    int soma = 0;

    if (indiceAtual == TAM){

        for (int i = 0; i < TAM - 1; i++){

            int permuta = s[i] - s[i + 1];
            if (permuta < 0){
                permuta = permuta * - 1;
                
            }
            soma += permuta;
        }

        if (soma > *max){
            *max = soma;
        }

        

    }

    for (int i = 0; i < TAM; i++){

        if (indicesAcessados[i] == 0){

            indicesAcessados[i] = 1;
            s[indiceAtual] = valores[i];
            backtrack(valores, indicesAcessados, indiceAtual + 1, s, max);
            indicesAcessados[i] = 0;

        }

    }
}

int main(){

    int valores[TAM] = {4, 5, 1, 2};
    int indicesAcessados[TAM];
    int max= 0;
    int s[TAM];

    for (int i = 0; i < TAM; i++){
        indicesAcessados[i] = 0;
    }

    backtrack(valores, indicesAcessados, 0, s, &max);
    printf("%i\n", max);
}