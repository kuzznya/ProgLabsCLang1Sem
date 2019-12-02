#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "bmp.h"
#include "gameoflife.h"

int main(int argc, char* argv[]) {
    char* inputBMPName = NULL;
    char* outputDirName = NULL;
    unsigned maxIter = 100;
    unsigned dumpFreq = 1;

    if (argc < 3) {
        printf("Error: not enough args\n");
        return -1;
    }
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--input") == 0) {
            if (i + 1 < argc)
                inputBMPName = argv[i + 1];
            else
                printf("Error in argument --input\n");
        }
        else if (strcmp(argv[i], "--output") == 0) {
            if (i + 1 < argc)
                outputDirName = argv[i + 1];
            else
                printf("Error in argument --output\n");
        }
        else if (strcmp(argv[i], "--max_iter") == 0) {
            if (i + 1 < argc)
                maxIter = atoi(argv[i + 1]);
            else
                printf("Error in argument --max_iter\n");
        }
        else if (strcmp(argv[i], "--dump_freq") == 0) {
            if (i + 1 < argc)
                dumpFreq = atoi(argv[i + 1]);
            else
                printf("Error in argument --dump_freq\n");
        }
    }
    if (inputBMPName == NULL || outputDirName == NULL) {
        printf("Not enough args\n");
        return -1;
    }

    BMP* image = readBMP(inputBMPName);
    mkdir(outputDirName);
    GAME* game = newGame(image, maxIter, dumpFreq, outputDirName);
    start(game);
    return 0;
}
