#include "gameio.h"
#include <stdlib.h>

GameField getGameField(BMP* image) {
    GameField field;
    char** pixelData = getPixelData(image);
    field.height = image->bmpInfo->biHeight;
    field.width = image->bmpInfo->biWidth;
    field.data = malloc(field.height * sizeof(char*));
    for (int i = 0; i < field.height; i++)
        field.data[i] = malloc(field.width * sizeof(char));

    for (int i = 0; i < field.height; i++) {
        for (int j = 0; j < field.width; j++) {
            if (pixelData[i][j])
                field.data[field.height - i - 1][j] = 0;
            else
                field.data[field.height - i - 1][j] = 1;
        }
    }
    return field;
}

void editImage(BMP* image, GameField field) {
    char** pixelData = malloc(image->bmpInfo->biHeight * sizeof(char*));
    for (int i = 0; i < image->bmpInfo->biHeight; i++)
        pixelData[i] = malloc(image->bmpInfo->biWidth * sizeof(char));

    for (int i = 0; i < field.height; i++) {
        for (int j = 0; j < field.width; j++) {
            if (field.data[i][j])
                pixelData[field.height - i - 1][j] = 0;
            else
                pixelData[field.height - i - 1][j] = -1;
        }
    }
}
