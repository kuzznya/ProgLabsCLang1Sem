#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "11.h"

int main(int argc, char *argv[]) {
    struct Ring a = makeRing(0, 0, 1, 2);
    printf("Ring perimeter is %f\n", ringPerimeter(a));
    printf("Ring area is %f\n", ringArea(a));
    return 0;
}

