#ifndef PROGLABSCLANG_MP3ID3V2_H
#define PROGLABSCLANG_MP3ID3V2_H

#pragma pack(push, 1)

//typedef union {
//    struct {
//        char        fileID[3];
//        char        version[2];
//        char        flags;
//        unsigned    size;
//    } data;
//
//    char buffer[10];
//} ID3v2Header;
//
//typedef union {
//    struct {
//        unsigned extHeaderSize;
//        unsigned short extFlags;
//        unsigned paddingSize;
//    } data;
//
//    char buffer[10];
//} ID3v2ExtendedHeader;
//
//typedef union {
//    struct {
//        char frameID[4];
//        unsigned size;
//        unsigned short flags;
//    } data;
//
//    char buffer[10];
//} FrameHeader;

typedef struct {
    char        fileID[3];
    char        version[2];
    char        flags;
    unsigned    sizeReversed;
} ID3v2Header;

typedef struct {
    unsigned extHeaderSizeReversed;
    unsigned short extFlags;
    unsigned paddingSize;
} ID3v2ExtendedHeader;

typedef struct {
    char            frameID[4];
    unsigned        sizeReversed;
    unsigned short  flags;
} FrameHeader;

typedef struct {
    FrameHeader* frameHeader;
    char* frameData;
} Frame;

typedef struct {
    char* fileName;
    ID3v2Header* tagHeader;
    ID3v2ExtendedHeader* extendedTagHeader;
    unsigned frameCount;
    Frame** frames;
    unsigned dataSize;
    char* data;
} MP3File;

unsigned int reverseBytes(unsigned n);

MP3File* readMP3(char* fileName);
char updateMP3(MP3File* mp3);
void freeMP3(MP3File* mp3);

#pragma pack(pop)

#endif //PROGLABSCLANG_MP3ID3V2_H
