#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include <time.h>
#include "mapa.h"
#include <string.h>
#include "ui.h"

MAPA m;
POSITION hero;
int tempilula = 0;

int praondeofantasmavai(int xatual, int yatual, int* xdestino, int* ydestino){

    int opcoes[4][2] = {
        {xatual, yatual + 1},
        {xatual + 1, yatual},
        {xatual, yatual - 1},
        {xatual - 1, yatual}
    };

    srand(time(0));
    for(int i = 0; i < 10;i++){
        int posicao = rand() % 4;
        if(podeAndar(&m, GHOST, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0]; 
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }
    return 0;

}

void ghosts( ){

    MAPA copia;

    copiaMapa(&copia, &m);
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(copia.matriz[i][j] == GHOST){

                int xdestino, ydestino;

                int encontrou = praondeofantasmavai(i, j, &xdestino, &ydestino);

                if(encontrou){
                    andanomapa(&m,i,j,xdestino,ydestino);
                }
            }
        }
    }
    freeMap(&copia);
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

    if(!podeAndar(&m, HERO,proximox, proximoy)) return;

    if(ehPersongagem(&m,PILULA, proximox,proximoy))
        tempilula = 1;

    andanomapa(&m, hero.x, hero.y, proximox, proximoy);
    hero.x = proximox;
    hero.y = proximoy;

}
int acabou(){
    POSITION pos;
    int fogefogenomapa = findMap(&m, &pos,HERO );
    return !fogefogenomapa;
}

void explodePilula(){
    if (!tempilula) return;
    explodePilula2(hero.x,hero.y,0,1, 3);
    explodePilula2(hero.x,hero.y,0,-1, 3);
    explodePilula2(hero.x,hero.y,1,0, 3);
    explodePilula2(hero.x,hero.y,-1,0 , 3);

    tempilula = 0;
}
void explodePilula2(int x, int y, int somax, int somay, int qtd){

    if(qtd == 0) return;

    int novox = x + somax;
    int novoy = y + somay;

    if(!ehvalida(&m, novox, novoy)) return;
    if(ehParede(&m, novox, novoy)) return;

    m.matriz[novox][novoy] = VAZIO;
    explodePilula2(novox, novoy,somax, somay, qtd - 1);

}

int main(){
    readsMap(&m);
    findMap(&m, &hero, HERO);
    do{
        printf("Tem pilula? %s\n", (tempilula?"SIM":"NAO"));
        printsMap(&m);
        char command;
        scanf(" %c", &command);
        move(command);
        if(command == BOMBA) explodePilula();
        ghosts();

    }while(!acabou());

    freeMap(&m);
}