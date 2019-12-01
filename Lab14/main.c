#include <stdio.h>
#include "bmp.h"

int main(int argc, char* argv[]) {
    //printPixelData(readBMP("testsmile.bmp"));
    BMP* image = readBMP("testsmile.bmp");
    //imageInv(image);
    char** pixelData = getPixelData(image);
    for (int i = 0; i < image->bmpInfo->biWidth; i++) {
        pixelData[image->bmpInfo->biHeight - 1][i] = 0;
    }
    setPixelData(image, pixelData);
    printPixelData(image);

    printPixelData(image);
    writeBMP(image, "testsmileout.bmp");
    return 0;
}
