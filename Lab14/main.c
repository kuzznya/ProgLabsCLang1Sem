#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "gameoflife.h"

int main(int argc, char* argv[]) {
    //printPixelData(readBMP("testsmile.bmp"));
//    BMP* image = readBMP("testsmile.bmp");
//    //imageInv(image);
//    char** pixelData = getPixelData(image);
//    for (int i = 0; i < image->bmpInfo->biWidth; i++) {
//        pixelData[image->bmpInfo->biHeight - 1][i] = 0;
//    }
//    setPixelData(image, pixelData);
//    printPixelData(image);
//
//    printPixelData(image);
//    writeBMP(image, "testsmileout.bmp");

    BMP* image = readBMP("itmo.bmp");
    GAME* game = newGame(image, 20, 2, "testitmo");
    start(game);
    return 0;
}
