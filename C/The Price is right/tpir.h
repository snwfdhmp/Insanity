#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define LEVEL1 100
#define LEVEL2 200
#define LEVEL3 300
#define LEVEL4 400
#define LEVEL5 500
#define LEVEL6 600
#define LEVEL7 700
#define LEVEL8 800
#define LEVEL9 900
#define LEVEL10 1000


#define MIN 1

int level();
void registerScore(char *name, int score);
int getAletNumber(int MAX);
void putscore(int random);
int available(int random);
int bestScore(int max);
