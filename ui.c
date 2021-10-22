#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"


char desenhoFantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoParede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoHero[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};
char desenhoPilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};


void printsPart(char desenho[4][7], int parte){
    printf("%s", desenho[parte]);
}

void printsMap(MAPA* m){
    for(int i = 0; i < m->linhas; i++){

        for(int parte = 0; parte < 4; parte++){
            for(int j = 0; j < m->colunas; j++){
                switch(m->matriz[i][j]){
                    case GHOST:
                        printsPart(desenhoFantasma, parte);
                        break;
                    case HERO:
                        printsPart(desenhoHero, parte);
                        break;
                    case VAZIO:
                        printsPart(desenhoVazio, parte);
                        break;
                    case PAREDEHORIZONTAL:
                    case PAREDEVERTICAL:
                        printsPart(desenhoParede, parte);
                        break;
                    case PILULA:
                        printsPart(desenhoPilula, parte);
                        break;                    
                }   
            }
            printf("\n");
        }
    }
}