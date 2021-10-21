#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"
#include <string.h>

MAPA m;
POSITION hero;


void ghosts( ){

    MAPA copia;

    copiaMapa(&copia, &m);
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(copia.matriz[i][j] == GHOST){
                if(ehvalida(&m, i, j+1) && ehVazia(&m, i, j + 1)){
                    andanomapa(&m,i,j,i,j+1);
                }
            }
        }
    }
    freeMap(&copia);
}

int acabou(){
    return 0;
}

int ehdirecao(char direction){
    return direction != ESQUERDA || direction != CIMA || direction != BAIXO 
        || direction != DIREITA;
}

void move(char direction) {
    
    if(!ehdirecao(direction)) return;

    int proximox = hero.x;
    int proximoy = hero.y;

    switch(direction) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }

    if(!ehvalida(&m, proximox, proximoy)) return;
    if(!ehVazia(&m, proximox, proximoy)) return;

    andanomapa(&m, hero.x, hero.y, proximox, proximoy);
    hero.x = proximox;
    hero.y = proximoy;

}

int main(){


    readsMap(&m);
    findMap(&m, &hero, HERO);
    do{

        printsMap(&m);
        char command;
        scanf(" %c", &command);
        move(command);
        ghosts();

    }while(!acabou());



    freeMap(&m);


}