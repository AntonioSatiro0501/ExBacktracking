
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#define TAM 8

void printTabuleiro(char tabuleiro[TAM][TAM]){

    for (int i = 0; i < TAM; i++){

        for (int j = 0; j < TAM; j++){

            printf("%c", tabuleiro[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

bool validaJogada(int linha, int coluna, int direcao, char tabuleiro[TAM][TAM]){
    
    if (direcao == 0){

        if (linha + 1 <= TAM - 1 && coluna - 2 >= 0){
        
            if (tabuleiro[linha + 1][coluna - 2] == 'o'){
            
                return true;
            }
        }

        return false;
    }
    
    if (direcao == 1){

        if (linha - 1 >= 0 && coluna - 2 >= 0){
        
            if (tabuleiro[linha - 1][coluna - 2] == 'o'){
            
                return true;
            }
        }

        return false;
    }
    
    if (direcao == 2){

        if (linha - 2 >= 0 && coluna - 1 >= 0){
        
            if (tabuleiro[linha - 2][coluna - 1] == 'o'){
            
                return true;
            }
        }

        return false;
    }
    
    if (direcao == 3){

        if (linha - 2 >= 0 && coluna + 1 <= TAM - 1){
        
            if (tabuleiro[linha - 2][coluna + 1] == 'o'){
            
                return true;
            }
        }

        return false;
    }
    
    if (direcao == 4){

        if (linha - 1 >= 0 && coluna + 2 <= TAM - 1){
        
            if (tabuleiro[linha - 1][coluna + 2] == 'o'){
            
                return true;
            }
        }

        return false;
    }

    if (direcao == 5){

        if (linha + 1 <= TAM - 1 && coluna + 2 <= TAM -1){
        
            if (tabuleiro[linha + 1][coluna + 2] == 'o'){
            
                return true;
            }
        }

        return false;
    }
    
    if (direcao == 6){

        if (linha + 2 <= TAM - 1 && coluna + 1 <= TAM -1){
        
            if (tabuleiro[linha + 2][coluna + 1] == 'o'){
            
                return true;
            }
        }

        return false;
    }
    
    if (direcao == 7){

        if (linha + 2 <= TAM - 1 && coluna - 1 >= 0){
        
            if (tabuleiro[linha + 2][coluna - 1] == 'o'){
            
                return true;
            }
        }

        return false;
    }

    return false;
}

int fazJogada(int posicao, int linha, int coluna, int direcao, char tabuleiro[TAM][TAM], int jogada, int solucao[TAM * TAM]){

    tabuleiro[linha][coluna] = '#';

    if (direcao == 0){
        
        solucao[jogada] = posicao;
        return posicao + 6;

    }
    
    else if (direcao == 1){
        
        solucao[jogada] = posicao;
        return posicao - 10;

    }
    
    else if (direcao == 2){
        
        solucao[jogada] = posicao;
        return posicao - 17;

    }
    
    else if (direcao == 3){
        
        solucao[jogada] = posicao;
        return posicao - 15;

    }
    
    else if (direcao == 4){
        
        solucao[jogada] = posicao;
        return posicao - 6;

    }
    
    else if (direcao == 5){
        
        solucao[jogada] = posicao;
        return posicao + 10;

    }
    
    else if (direcao == 6){
        
        solucao[jogada] = posicao;
        return posicao + 17;

    }
    
    solucao[jogada] = posicao;
    return posicao + 15;

}

void backtrack(char tabuleiro[TAM][TAM], int posicao, int solucao[TAM * TAM], int jogada){

    if (jogada == TAM * TAM){

        for (int i = 0; i < jogada; i++){
            printf("%i ", solucao[i]);
        }

        exit(0);
    }

    int linha = posicao / TAM;
    int coluna = posicao % TAM;

    tabuleiro[linha][coluna] = 'A';
    printf("%i\n", jogada);

    for (int i = 0 ; i <  8; i++){

        if (validaJogada(linha, coluna, i, tabuleiro)){

            int proxposicao = fazJogada(posicao, linha, coluna, i, tabuleiro, jogada, solucao);
            backtrack(tabuleiro, proxposicao, solucao, jogada + 1);
            tabuleiro[linha][coluna] = 'A';
        }

    }

    tabuleiro[linha][coluna] = 'o';
}


int main(){
    
    char tabuleiro[TAM][TAM];
    int solucao[TAM * TAM];
    
    for (int i = 0; i < TAM; i++){
        
        for (int j = 0; j < TAM; j++){
            
            tabuleiro[i][j] = 'o';
            
        }
    }
    
    for (int i = 0; i < TAM * TAM; i++){
        solucao[0] = i;
        backtrack(tabuleiro, i, solucao, 1);
    }
}