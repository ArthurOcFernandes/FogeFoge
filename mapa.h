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

void freeMap(MAPA* m);
void readsMap(MAPA* m);
void printsMap(MAPA* m);
void alocatesMap(MAPA* m);
void findMap(MAPA* m, POSITION* p, char c);