#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>

void findMap(MAPA* m, POSITION* p, char c){
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void freeMap(MAPA* m){
    for(int i = 0; i < m->linhas ; i++)
        free(m->matriz[i]);
    free((m->matriz));  
}

void alocatesMap(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas ) ;
    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}


void readsMap(MAPA* m){
    FILE* f;

    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Mapa nao carregado.");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocatesMap(m);

    for(int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    
    fclose(f);
}

void printsMap(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}