#define UNICODE
#include <stdio.h>
#include <stdlib.h>
enum COLORS{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define bg(c) (c+10)
enum LETTERS{LA=0, LB, LC, LD, LE, LF, LG, LH, LI, LJ, LK, LL, LM, LN, LO, LP, LQ, LR, LS, LT, LU, LV, LW, LX, LY, LZ};
char fileintoarray(int i);
void barchart(int , int, int);
void clearScreen(void);
void setColors(short, short);
void resetColors(void);
#define COL 26
#define BAR "\u2590"
