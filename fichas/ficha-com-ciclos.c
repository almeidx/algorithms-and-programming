#include <stdio.h>

void main() {
    // Exercicio 4

    // int n;
    // printf("Introduza o número.");
    // scanf("%d", &n);
    // for (int i = 2; i <= 100; i++) {
    //     printf("%d x %d = %d\n", n, i, n * i);
    // }

    // Exercicio 6

    int max, min, p, sum = 0;
    printf("Introduza o minimo e o maximo.");
    scanf("%d%d", &min, &max);
    do {
        p += min;
        sum += p;
    } while (sum + p + min < max);

    printf("Somatorio = %d | P = %d", sum, p);
}
