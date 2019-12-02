#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>

size_t getGap1Size(BMP* image) {
    return image->bmpFileHeader->bfOffBits - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFO);
}

size_t getPadding(BMP* image) {
    return ((4 - image->bmpInfo->biWidth % 4) % 4);
}

size_t getPixelDataSize(BMP* image) {
    return image->bmpInfo->biHeight * (image->bmpInfo->biWidth + getPadding(image));
}

BMP* readBMP(char* filepath) {
    FILE* BMPFile = fopen(filepath, "rb");
    if (BMPFile == NULL)
        return NULL;

    BMP* image = malloc(sizeof(BMP));
    image->bmpFileHeader = malloc(sizeof(BITMAPFILEHEADER));
    image->bmpInfo = malloc(sizeof(BITMAPINFO));

    fread(image->bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, BMPFile);
    fread(image->bmpInfo, sizeof(BITMAPINFO), 1, BMPFile);

    image->gap1 = malloc(getGap1Size(image));
    fread(image->gap1, getGap1Size(image), 1, BMPFile);

    image->pixelData = malloc(sizeof(char) * getPixelDataSize(image));
    fread(image->pixelData, sizeof(char) * getPixelDataSize(image), 1, BMPFile);

    fclose(BMPFile);

    return image;
}

void writeBMP(BMP* image, char* filepath) {
    FILE* BMPFile = fopen(filepath, "wb");
    if (BMPFile == NULL)
        return;

    fwrite(image->bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, BMPFile);
    fwrite(image->bmpInfo, sizeof(BITMAPINFO), 1, BMPFile);
    fwrite(image->gap1, getGap1Size(image), 1, BMPFile);
    fwrite(image->pixelData, sizeof(char), getPixelDataSize(image), BMPFile);

    fclose(BMPFile);
}

char** getPixelData(BMP* image) {
    char** pixelData = malloc(image->bmpInfo->biHeight * sizeof(char*));
    for (int i = image->bmpInfo->biHeight - 1; i >= 0; i--) {
        pixelData[i] = malloc(image->bmpInfo->biWidth * sizeof(char*));
        for (int j = 0; j < image->bmpInfo->biWidth; j++) {
            pixelData[i][j] = image->pixelData[i * (image->bmpInfo->biWidth + getPadding(image)) + j];
        }
    }
    return pixelData;
}

void setPixelData(BMP* image, char** pixelData) {
    for (int i = image->bmpInfo->biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < image->bmpInfo->biWidth; j++) {
            image->pixelData[i * (image->bmpInfo->biWidth + getPadding(image)) + j] = pixelData[i][j];
        }
    }
}
