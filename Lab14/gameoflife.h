#ifndef PROGLABSCLANG_GAMEOFLIFE_H
#define PROGLABSCLANG_GAMEOFLIFE_H

#include "bmp.h"

typedef struct {
    char**      data;
    unsigned    width;
    unsigned    height;
} GameField;

typedef struct {
    GameField   field;
    GameField   prevField;
    BMP*        image;
    char*       outputDir;
    unsigned    maxGenCount;
    unsigned    currentGen;
    unsigned    outputFreq;
} GAME;

GameField getGameField(BMP* image);
void editImage(BMP* image, GameField field);

GAME newGame(BMP* image, unsigned maxGenCount, unsigned outputFreq, char* outputDir);
void start(GAME game);

#endif //PROGLABSCLANG_GAMEOFLIFE_H
