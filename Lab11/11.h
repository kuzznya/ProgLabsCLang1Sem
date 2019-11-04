#ifndef MAINPROJECT_11_H
#define MAINPROJECT_11_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Ring {
    struct Point center;
    float radius1;
    float radius2;
};

struct Ring makeRing(int, int, float, float);
float ringPerimeter(struct Ring);
float ringArea(struct Ring);

#endif //MAINPROJECT_11_H
