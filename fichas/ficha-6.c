#include <stdio.h>
#include <string.h>

#define VECTOR_LIMIT 20
#define DOUBLE_VECTOR_LIMIT 40

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
  while (*str1 != '\0') {
    str1++;
  }
  while (*str2 != '\0') {
    *str1 = *str2;
    str1++;
    str2++;
  }
}

void readInt(int *number, char question[]) {
  printf("%s", question);
  scanf("%d", number);
}

void readVector(int vector[], int size) {
  for (int i = 0; i < size; i++) {
    printf("Introduza o %dº elemento do vector: ", i + 1);
    scanf("%d", vector + i);
  }
}

void intercalateVectors(int v1[], int v2[], int v3[], int size) {
  int j = 0;
  for (int i = 0; i < size; i++) {
    *(v3 + j) = *(v1 + i);
    j++;
    *(v3 + j) = *(v2 + size - i - 1);
    j++;
  }
}

void displayVector(int v[], int size) {
  printf("{ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", *(v + i));
  }
  printf("}\n");
}

void displayVectorReverse(int v[], int size) {
  printf("{ ");
  for (int i = size - 1; i >= 0; i--) {
    printf("%d ", v[i]);
  }
  printf("}\n");
}

void getMaxValue(int v[], int size, int *max) {
  *max = *v;
  for (int i = 1; i < size; i++) {
    if (v[i] > *max) {
      *max = *(v + i);
    }
  }
}

void getMinValue(int v[], int size, int *min) {
  *min = v[0];
  for (int i = 1; i < size; i++) {
    if (*(v + i) < *min) {
      *min = *(v + i);
    }
  }
}

void getSum(int v[], int size, int *sum) {
  *sum = 0;
  for (int i = 0; i < size; i++) {
    *sum += *(v + i);
  }
}

void getMedian(int v[], int size, int *median) {
  int sum = 0;
  getSum(v, size, &sum);
  *median = sum / size;
}

void getMedianBounds(int v[], int size, int *smaller, int *bigger) {
  int median = 0;
  getMedian(v, size, &median);
  *smaller = 0;
  *bigger = 0;
  for (int i = 0; i < size; i++) {
    if (*(v + i) > median) {
      *bigger += 1;
    } else if (*(v + i) < median) {
      *smaller += 1;
    }
  }
}

void duplicateVector(int v1[], int v2[], int size) {
  for (int i = 0; i < size; i++) {
    v2[i] = v1[i];
  }
}

void main() {
  // Exercicio 1
  // int a = 1, b = 2;
  // printf("a = %d, b = %d\n", a, b);
  // switchVariableValue(&a, &b);
  // printf("a = %d, b = %d\n", a, b);

  // Exercicio 2
  // char c[VECTOR_LIMIT];
  // readString(c, "Introduza alguns caracteres: ");
  // printf("Os dois primeiros caracteres são: %c%c", c[0], c[1]);

  // Exercicio 3
  // char str1[VECTOR_LIMIT], str2[VECTOR_LIMIT];
  // readString(str1, "Introduza uma string: ");
  // readString(str2, "Introduza outra string: ");
  // concatenateStrings(str1, str2);
  // puts(str1);

  // Exercicio 4
  // int n, v1[VECTOR_LIMIT], v2[VECTOR_LIMIT], v3[DOUBLE_VECTOR_LIMIT];
  // readInt(&n, "Introduza o tamanho dos vectores: ");
  // readVector(v1, n);
  // readVector(v2, n);
  // intercalateVectors(v1, v2, v3, n);
  // displayVector(v3, n * 2);

  // Exercicio 5
  int v1[VECTOR_LIMIT], n;
  readInt(&n, "Introduza o tamanho do vector: ");

  // a
  readVector(v1, n);

  // b
  displayVector(v1, n);

  // c
  displayVectorReverse(v1, n);

  // d
  int max;
  getMaxValue(v1, n, &max);
  printf("O valor máximo é %d\n", max);

  // e
  int min;
  getMinValue(v1, n, &min);
  printf("O valor mínimo é %d\n", min);

  // f
  int sum;
  getSum(v1, n, &sum);
  printf("A soma das componentes é %d\n", sum);

  // g
  int media;
  getMedian(v1, n, &media);
  printf("A média das componentes é %d\n", media);

  // h
  int bigger, smaller;
  getMedianBounds(v1, n, &bigger, &smaller);
  printf(
      "Componentes maiores que a média: %d\nComponentes menores que a média: "
      "%d\n",
      bigger, smaller);

  // i
  int v2[VECTOR_LIMIT];
  duplicateVector(v1, v2, n);

  // j
  int v3[VECTOR_LIMIT];
  intercalateVectors(v1, v2, v3, n);
  displayVector(v3, n * 2);
}
