#include <stdio.h>
#include <stdbool.h>
#define TAM 8





bool backtrack(int lados[4], int fosforos[TAM], int indicesAcessados[TAM], int , int afosforo, int ladoAtual, int alvo){
    
    for (int i = 0; i < qfosforos; i++){
        
        bool checa = true;
        
        for (int j = 0; j < afosforo ; j++){
            if (i == indicesAcessados[j]){
                checa = false;
            }
        }
        
        
        }
    
    return false;
}