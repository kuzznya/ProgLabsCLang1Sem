#ifndef PROGLABSCLANG_ARCH_H
#define PROGLABSCLANG_ARCH_H

#include "arcfile.h"

typedef struct {
    unsigned filesCount;
    ArcFile** files;
} Archive;

Archive* readArchive(char* fileName);
void writeArchive(char* fileName, Archive* arch);
Archive* packArchive(unsigned filesCount, char** fileNames);
void extractArchive(Archive* arch);

#endif //PROGLABSCLANG_ARCH_H
