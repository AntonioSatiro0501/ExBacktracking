/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define TAM 8

int pegaAlvo(int fosforos[TAM], int qfosforos){
    int total = 0;
    
    for (int i = 0 ; i < qfosforos ; i++ ){
        total += fosforos[i];
    }
    
    printf("%i \n", (total % 4));
    int resto = total % 4;
    
    if(resto != 0 || qfosforos < 4){
        return 0;
    }
    
    int lado = total/4;
    
    return lado;
}

bool validaQuadrado(int fosforos[TAM], int qfosforos){
    int p = pegaAlvo(fosforos, qfosforos);
    
    if(p == 0){
        return false;
    }
    
    return true;
}

bool backtrack(int lados[4], int fosforos[TAM], int indicesAcessados[TAM], int qfosforos, int afosforo, int ladoAtual, int alvo){
    
    if(lados[0] == alvo && lados[1] == alvo && lados[2] == alvo && lados[3] == alvo && afosforo == qfosforos){
        return true;
    }
    
    for (int i = 0; i < qfosforos; i++){
        
        bool checa = true;
        
        for (int j = 0; j < afosforo ; j++){
            if (i == indicesAcessados[j]){
                checa = false;
            }
        }
        
        if (checa){
            if (lados[ladoAtual] + fosforos[i] < alvo){
                lados[ladoAtual] += fosforos[i];
                indicesAcessados[afosforo] = i;
                if(backtrack(lados, fosforos, indicesAcessados, qfosforos, afosforo + 1, ladoAtual, alvo)){
                    return true;
                }
                lados[ladoAtual] -= fosforos[i];
                
            }
            
            if (lados[ladoAtual] + fosforos[i] == alvo){
                lados[ladoAtual] += fosforos[i];
                indicesAcessados[afosforo] = i;
                if (backtrack(lados, fosforos, indicesAcessados, qfosforos, afosforo + 1, ladoAtual + 1, alvo)){
                    return true;
                }
                lados[ladoAtual] -= fosforos[i];
                
            }
        }
    }
    
    return false;
}


int main()
{

int lados[4] = {0,0,0,0};
int fosforos[TAM] = {4, 4, 4, 4, 4, 4, 4, 4};
int qfosforos = TAM;
int indicesAcessados[TAM];

if(!validaQuadrado){
    printf("Nao possivel quadrado");
    return 0;
}

int alvo = pegaAlvo(fosforos, qfosforos);
printf("%i", alvo);

if(backtrack(lados, fosforos, indicesAcessados, qfosforos, 0, 0, alvo)){
    for (int i = 0; i < TAM; i++){
        printf("\n%i", indicesAcessados[i]);
    }
    printf("\nquadrado possivel");
}

}