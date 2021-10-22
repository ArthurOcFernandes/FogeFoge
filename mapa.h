#ifndef _MAPA_H_
#define _MAPA_H_

#define HERO '@'
#define GHOST 'F'
#define VAZIO '.'
#define PAREDEVERTICAL '|'
#define PAREDEHORIZONTAL '-'
#define PILULA 'P'
#define BOMBA 'b'

struct mapa {
    char** matriz;
    int linhas;
    int colunas; 
};
typedef struct mapa MAPA; 

struct position
{
    int x,y;
};

typedef struct position POSITION;
int podeAndar(MAPA* m,char personagem, int x, int y);
int ehvalida(MAPA* m, int proximox, int proximoy);
int ehVazia(MAPA*, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem,int xdestino, int ydestino);
void freeMap(MAPA* m);
void readsMap(MAPA* m);
void alocatesMap(MAPA* m);
int findMap(MAPA* m, POSITION* p, char c);
int ehParede(MAPA* m, int x, int y);
void copiaMapa(MAPA* destino, MAPA* origem);
int ehPersongagem(MAPA* m,char personagem, int x, int y);

#endif