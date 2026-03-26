#include <stdio.h>
#include <stdbool.h>
#define TAM 8

bool verificaOrdenacao(int vetor[TAM]){

    for (int i = 0; i < TAM - 1; i++){

        if (vetor[i] > vetor[i + 1]){
            return false;
        }
    }

    return true;
}

bool backtrack(int vetor[TAM]){

    if(verificaOrdenacao(vetor)){

        return true;
    }

    for (int i = 0; i < TAM - 1; i++){

        if (vetor[i] > vetor[i + 1]){

            int backup = vetor[i];
            vetor[i] = vetor[i + 1];
            vetor[i + 1] = backup;

            if (backtrack(vetor)){
                return true;
            }

            vetor[i + 1] = vetor[i];
            vetor[i] = backup;
        }


    }

    return false;
}


int main(){

    int vetor[TAM] = {8, 5, 3, 1, 8, 9, 2, 4};

    if(backtrack(vetor)){
        
        printf("\n");

        for (int i = 0; i < TAM; i++){

            printf("%i ", vetor[i]);
        }

        printf("\nVetor ordenado\n");
    }

    else {

        printf("DEU RUIM");
    }
}