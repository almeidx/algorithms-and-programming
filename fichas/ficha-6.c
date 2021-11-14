#include <stdio.h>
#include <string.h>

#define VECTOR_SIZE 20
#define DOUBLE_VECTOR_SIZE 40

void switchVariableValue(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void readString(char str[], char question[]) {
    printf("%s", question);
    scanf("%s", str);
}

void concatenateStrings(char str1[], char str2[]) {
    int str1Len = strlen(str1);
    for (int i = 0; i < strlen(str2); i++) {
        str1[str1Len + i] = str2[i];
    }
}

void readInt(int *number, char question[]) {
    printf("%s", question);
    scanf("%d", number);
}

void readVector(int vector[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Introduza o %dº elemento do vector: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

void intercalateVectors(int v1[], int v2[], int v3[], int size) {
    for (int i = 0; i <= size; i += 2) {
        v3[i] = v1[i];
        v3[i + 1] = v2[size - i - 1];
    }
}

void displayVector(int v[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
    printf("}\n");
}

void main() {
    // Exercicio 1
    // int a = 1, b = 2;
    // printf("a = %d, b = %d\n", a, b);
    // switchVariableValue(&a, &b);
    // printf("a = %d, b = %d\n", a, b);

    // Exercicio 2
    // char c[VECTOR_SIZE];
    // readString(c, "Introduza alguns caracteres: ");
    // printf("Os dois primeiros caracteres são: %c%c", c[0], c[1]);

    // Exercicio 3
    // char str1[VECTOR_SIZE], str2[VECTOR_SIZE];
    // readString(str1, "Introduza uma string: ");
    // readString(str2, "Introduza outra string: ");
    // concatenateStrings(str1, str2);
    // printf("%s", str1);

    // Exercicio 4
    int n, v1[VECTOR_SIZE], v2[VECTOR_SIZE], v3[DOUBLE_VECTOR_SIZE];
    readInt(&n, "Introduza o tamanho dos vectores: ");
    readVector(v1, n);
    readVector(v2, n);
    // broken
    intercalateVectors(v1, v2, v3, n);
    displayVector(v3, n * 2);
}
