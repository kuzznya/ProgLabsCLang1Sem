#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    int x;
    int y;
};

float dist(struct point pointA, struct point pointB) {
    return sqrtf(pow(pointB.x - pointA.x, 2) + pow(pointB.y - pointA.y, 2));
}

float** distances(unsigned n, struct point points[]) {

    float** distances = (float**)malloc(n * sizeof(float*));

    for (int i = 0; i < n; i++) {
        int lineIter = 0;
        distances[i] = malloc((n - 1) * sizeof(float));
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            distances[i][lineIter++] = dist(points[i], points[j]);
        }
    }
    return distances;
}

void deleteSymbol(char* p) {
    while (*p != '\0') {
        *p = *(p + 1);
    }
}

void deleteSpaces(char* p) {
    while (*p != '\0') {
        if (*p == ' ' && *(p + 1) == ' ') {
            deleteSymbol(p);
        }

    }
}

int main(int argc, char *argv[]) {
    //Task 2
    printf("=== Task 2 ===\n");

    int n;
    printf("Enter the count of points: ");
    scanf("%u", &n);
    struct point* points = (struct point*) malloc(n * sizeof(struct point));
    int x, y;
    for (int i = 0; i < n; i++) {
        printf("Point %d\n", i);
        printf("Enter x: ");
        scanf("%d", &x);
        printf("Enter y: ");
        scanf("%d", &y);
        points[i].x = x;
        points[i].y = y;
    }

    float** dist = distances(n, points);

    for (int i = 0; i < n; i++) {
        printf("Point %d:\n", i);
        for (int j = 0; j < n - 1; j++) {
            printf("%f\t", dist[i][j]);
        }
        printf("\n");
    }

    //Task 5
    printf("=== Task 5 ===");


    return 0;
}

