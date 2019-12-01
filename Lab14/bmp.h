#ifndef PROGLABSCLANG_BMP_H
#define PROGLABSCLANG_BMP_H

#pragma pack(push, 1)

typedef struct {
    unsigned short  bfType;
    unsigned        bfSize;
    unsigned short  bfReserved1;
    unsigned short  bfReserved2;
    unsigned        bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned        biSize;
    long            biWidth;
    long            biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned        biCompression;
    unsigned        biSizeImage;
    long            biXPelsPerMeter;
    long            biYPelsPerMeter;
    unsigned        biClrUsed;
    unsigned        biClrImportant;
} BITMAPINFO;

typedef struct {
    BITMAPFILEHEADER*   bmpFileHeader;
    BITMAPINFO*         bmpInfo;
    char*               gap1;
    unsigned char*      pixelData;
} BMP;


BMP* readBMP(char* filepath);

void writeBMP(BMP* image, char* filepath);
void printPixelData(BMP* image);
char** getPixelData(BMP* image);
void setPixelData(BMP* image, char** pixelData);

#pragma pack(pop)

#endif //PROGLABSCLANG_BMP_H
