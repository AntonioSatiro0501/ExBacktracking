#include <stdio.h>
#include <stdbool.h>
#define TAM 7


bool backtrack(int valores[TAM], int solucao[TAM], int alvo){

    int somatorio = 0;

    for (int i = 0; i < TAM; i++){

        if (solucao[i] == 1){
            somatorio += valores[i];
        } 
    }

    if (somatorio == alvo){
        for (int i = 0; i < TAM; i++){

            if (solucao[i] == 1){
                printf("\n%i", valores[i]);
            }
        }
        return true;
    }

    for (int i = 0; i < TAM; i++){

        if (solucao[i] == 0){
            solucao[i] = 1;
            if (backtrack(valores, solucao, alvo)){
                return true;
            }
            solucao[i] = 0;
        }
    }

    return false;
}

int main(){
    int valores[TAM] = {30, 40, 10, 15, 11, 60, 54};
    int solucao[TAM];

    for (int i = 0; i < TAM; i++){

        solucao[i] = 0;
    }

    if (backtrack(valores, solucao, 55)){
        printf("\nSubgrupo encontrado\n");
    }
    else {
        printf("\n TUDO DE RUIM");
    }
    
}

