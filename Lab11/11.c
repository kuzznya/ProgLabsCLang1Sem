#include <math.h>

struct Ring makeRing(int x, int y, float radius1, float radius2) {
    return (struct Ring) {(struct Point) {x, y}, radius1, radius2};
}

float ringPerimeter(struct Ring ring) {
    float p1 = 2.0 * M_PI * ring.radius1;
    float p2 = 2.0 * M_PI * ring.radius2;
    return p1 + p2;
}

float ringArea(struct Ring ring) {
    float S1 = M_PI * ring.radius1;
    float S2 = M_PI * ring.radius2;
    return abs(S2 - S1);
}

