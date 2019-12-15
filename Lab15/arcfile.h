#ifndef PROGLABSCLANG_ARCFILE_H
#define PROGLABSCLANG_ARCFILE_H

typedef struct {
    unsigned short fileNameSize;
    char* fileName;
    char flags;
    unsigned dataSize;
    char* data;
} ArcFile;

ArcFile* readFile(char* fileName);
void writeFile(ArcFile* arcFile);

#endif //PROGLABSCLANG_ARCFILE_H
