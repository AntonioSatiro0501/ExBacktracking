/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define TAM 8

bool validaJogada(int posicao, int direcao, char tabuleiro[TAM][TAM]){
    
    int linha = posicao / TAM;
    int coluna = posicao % TAM;
    
    if (direcao == 0 && linha + 1 <= 7 && coluna - 3 >= 0){
        
        if (tabuleiro[linha + 1][coluna - 3] == 'o'){
            
            return true;
        }
    }
    
    else if (direcao == 1 && linha - 1 >= 0 && coluna - 3 >= 0){
        
        if (tabuleiro[linha - 1][coluna - 3] == 'o'){
            
            return true;
        }
    }
    
    else if (direcao == 2 && linha - 3 >= 0 && coluna - 1 >= 0){
        
        if (tabuleiro[linha - 3][coluna - 1] == 'o'){
            
            return true;
        }
    }
    
    else if (direcao == 3 && linha - 3 >= 0 && coluna + 1 <= 7){
        
        if (tabuleiro[linha - 3][coluna + 1] == 'o'){
            
            return true;
        }
    }
    
    else if (direcao == 4 && linha - 1 >= 0 && coluna + 3 <= 7){
        
        if (tabuleiro[linha - 1][coluna + 3] == 'o'){
            
            return true;
        }
    }
    
    else if (direcao == 5 && linha + 1 <= 7 && coluna + 3 <= 7){
        
        if (tabuleiro[linha + 1][coluna + 3] == 'o'){
            
            return true;
        }
    }
    
    else if (direcao == 6 && linha + 3 <= 7 && coluna + 1 <= 7){
        
        if (tabuleiro[linha + 3][coluna + 1] == 'o'){
            
            return true;
        }
    }
    
    else if (direcao == 7 && linha + 3 <= 7 && coluna - 1 >= 0){
        
        if (tabuleiro[linha + 3][coluna + 1] == 'o'){
            
            return true;
        }
    }
}


int main(){
    
    char tabuleiro[TAM][TAM];
    
    for (int i = 0; i < TAM; i++){
        
        for (int j = 0; i < TAM; j++){
            
            tabuleiro[i][j] = 'o';
            
        }
    } 
}