#define HERO '@'
#define GHOST 'F'
#define VAZIO '.'
#define PAREDEVERTICAL '|'
#define PAREDEHORIZONTAL '-'

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
int ehvalida(MAPA* m, int proximox, int proximoy);
int ehVazia(MAPA*, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem,int xdestino, int ydestino);
void freeMap(MAPA* m);
void readsMap(MAPA* m);
void printsMap(MAPA* m);
void alocatesMap(MAPA* m);
void findMap(MAPA* m, POSITION* p, char c);
void copiaMapa(MAPA* destino, MAPA* origem);