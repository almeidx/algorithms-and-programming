#include <math.h>
#include <stdio.h>

typedef struct Point {
    int x, y;
} point;

void readPoint(point *p) {
    printf("Introduza as cordenadas ponto: ");
    scanf("%d %d", &(*p).x, &(*p).y);
}

void displayPoint(point p) { printf("(%d, %d)\n", p.x, p.y); }

float getDistanceBetweenPoints(point p1, point p2) {
    int x = abs(p2.x - p1.x), y = abs(p2.y - p1.y);
    return sqrt(pow(x, 2) + pow(y, 2));
}

int getRectangleAreaUsingDiagonal(point p1, point p2) {
    return abs(p2.x - p1.x) * abs(p2.y - p1.y);
}

void main() {
    // Exercicio 1
    point p1, p2;
    readPoint(&p1);
    displayPoint(p1);
    readPoint(&p2);
    displayPoint(p2);
    float distance = getDistanceBetweenPoints(p1, p2);
    int area = getRectangleAreaUsingDiagonal(p1, p2);
    printf("O comprimento da diagonal é: %.2f\n", distance);
    printf("A área do retângulo é: %d\n", area);
}
