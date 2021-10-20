#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSITION hero;


int acabou(){
    return 0;
}

void move(char direction) {

    m.matriz[hero.x][hero.y] = '.';

    switch(direction) {
        case 'a':
            m.matriz[hero.x][hero.y-1] = '@';
            hero.y--;
            break;
        case 'w':
            m.matriz[hero.x-1][hero.y] = '@';
            hero.x--;
            break;
        case 's':
            m.matriz[hero.x+1][hero.y] = '@';
            hero.x++;
            break;
        case 'd':
            m.matriz[hero.x][hero.y+1] = '@';
            hero.y++;
            break;
    }

}

int main(){

    readsMap(&m);
    findMap(&m, &hero, '@');
    do{

        printsMap(&m);
        char command;
        scanf(" %c", &command);
        move(command);

    }while(!acabou());



    freeMap(&m);


}