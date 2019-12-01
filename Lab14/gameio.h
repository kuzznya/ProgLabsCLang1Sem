#ifndef PROGLABSCLANG_GAMEIO_H
#define PROGLABSCLANG_GAMEIO_H

#include "bmp.h"

typedef struct {
    char** data;
    unsigned width;
    unsigned height;
} GameField;

GameField getGameField(BMP* image);
void editImage(BMP* image, GameField field);

#endif //PROGLABSCLANG_GAMEIO_H
