#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mp3id3v2.h"


void printFrameData(Frame* frame) {
    for (int i = 0; i < reverseBytes(frame->frameHeader->sizeReversed); i++) {
        if (frame->frameData[i] >= 32 && frame->frameData[i] <= 126)
            printf("%c", frame->frameData[i]);
    }
    printf("\n");
}

void showFrames(MP3File* mp3) {
    for (int i = 0; i < mp3->frameCount; i++) {
        printf("[%s]:\t", mp3->frames[i]->frameHeader->frameID);
        if (reverseBytes(mp3->frames[i]->frameHeader->sizeReversed) > 100)
            continue;
        printFrameData(mp3->frames[i]);
    }
}

void getFrame(MP3File* mp3, char propName[4]) {
    for (int i = 0; i < mp3->frameCount; i++) {
        if (strcmp(mp3->frames[i]->frameHeader->frameID, propName) == 0) {
            printFrameData(mp3->frames[i]);
            return;
        }
    }
}

char setFrame(MP3File* mp3, char propName[4], char* value) {
    for (int i = 0; i < mp3->frameCount; i++) {
        if (strcmp(mp3->frames[i]->frameHeader->frameID, propName) == 0) {
            mp3->frames[i]->frameHeader->sizeReversed = reverseBytes(strlen(value));
            realloc(mp3->frames[i]->frameData, reverseBytes(mp3->frames[i]->frameHeader->sizeReversed));
            mp3->frames[i]->frameData = value;
            return updateMP3(mp3);
        }
    }
    mp3->frames = realloc(mp3->frames, ++mp3->frameCount * sizeof(Frame));
    mp3->frames[mp3->frameCount - 1] = malloc(sizeof(Frame));
    mp3->frames[mp3->frameCount - 1]->frameHeader = malloc(sizeof(FrameHeader));
    mp3->frames[mp3->frameCount - 1]->frameHeader->frameID[0] = propName[0];
    mp3->frames[mp3->frameCount - 1]->frameHeader->frameID[1] = propName[1];
    mp3->frames[mp3->frameCount - 1]->frameHeader->frameID[2] = propName[2];
    mp3->frames[mp3->frameCount - 1]->frameHeader->frameID[3] = propName[3];
    mp3->frames[mp3->frameCount - 1]->frameHeader->sizeReversed = reverseBytes(strlen(value));
    mp3->frames[mp3->frameCount - 1]->frameHeader->flags = 0;
    mp3->frames[mp3->frameCount - 1]->frameData = value;
    return updateMP3(mp3);
}

char deleteFrame(MP3File* mp3, char propName[4]) {
    for (int i = 0; i < mp3->frameCount; i++) {
        if (strcmp(mp3->frames[i]->frameHeader->frameID, propName) == 0) {
            free(mp3->frames[i]->frameHeader);
            free(mp3->frames[i]->frameData);
            free(mp3->frames[i]);
            for (int j = i + 1; j < mp3->frameCount; j++)
                mp3->frames[j - 1] = mp3->frames[j];
            mp3->frames = realloc(mp3->frames, --mp3->frameCount * sizeof(Frame));
            return updateMP3(mp3);
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    char* fileName = malloc(200 * sizeof(char));
    char* frameName = malloc(10 * sizeof(char));
    char* value = malloc(100 * sizeof(char));
    char showFlag = 0;
    char setFlag = 0;
    char getFlag = 0;
    for (int i = 1;i < argc; i++){
        if (strcmp(argv[i], "--show") == 0) {
            showFlag = 1;
            continue;
        }
        if (argv[i][2] == 'f') {
            fileName = strpbrk(argv[i], "=") + 1;
        }
        if (argv[i][2] == 'g') {
            getFlag = 1;
            frameName = strpbrk(argv[i], "=") + 1;
            continue;
        }
        if (argv[i][2] == 's') {
            setFlag = 1;
            frameName = strpbrk(argv[i], "=") + 1;
            continue;
        }
        if (argv[i][2] == 'v') {
            value = strpbrk(argv[i], "=") + 1;
            continue;
        }
    }

    MP3File* mp3 = readMP3(fileName);

    if (mp3 == NULL) {
        printf("Error while opening file\n");
        return 0xF;
    }

    if (getFlag)
        getFrame(mp3, frameName);
    if (setFlag) {
        if (strlen(frameName) == 4)
            setFrame(mp3, frameName, value);
        else
            printf("Error: incorrect prop name\n");
    }
    if (showFlag)
        showFrames(mp3);
    return 0;

}