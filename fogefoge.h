#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

void ghosts();
int praondeofantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
int ehdirecao(char direction);
void move(char direction);
int acabou();
void explodePilula();
void explodePilula2(int x, int y, int somax, int somay, int qtd);