#include <stdio.h>

#define VECTOR_SIZE 20

int isDigit(char c) { return c >= '0' && c <= '9'; }

int isAlpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

int isAlphanumeric(char c) { return isAlpha(c) || isDigit(c); }

char toLower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  }
  return c;
}

char toUpper(char c) {
  if (c >= 'a' && c <= 'z') {
    return c + 'A' - 'a';
  }
  return c;
}

int resto(int a, int b) { return a % b; }

int impar(int a) { return a % 2; }

int perfeito(int n) {
  int i, soma = 0;
  for (i = 1; i < n; i++) {
    if (resto(n, i) == 0) {
      soma += i;
    }
  }
  return soma == n;
}

int primo(int n) {
  int i;
  for (i = 2; i < n; i++) {
    if (resto(n, i) == 0) {
      return 0;
    }
  }
  return 1;
}

int abundante(int a) {
  int i, soma = 0;
  for (i = 1; i < a; i++) {
    if (resto(a, i) == 0) {
      soma += i;
    }
  }
  return soma > a;
}

void askForInt(int *n, char msg[]) {
  printf(msg);
  scanf("%d", n);
}

int calculateVolume(int l) { return l * l * l; }

void biggerNumber(int n1, int n2) {
  if (n1 > n2) {
    printf("%d é maior que %d\n", n1, n2);
  } else if (n1 < n2) {
    printf("%d é maior que %d\n", n2, n1);
  } else {
    printf("%d é igual a %d\n", n1, n2);
  }
}

void askForVector(int v[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Digite o %dº elemento: ", i + 1);
    scanf("%d", &v[i]);
  }
}

void displayVector(int v[], int size) {
  printf("{ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", v[i]);
  }
  printf("}\n");
}

void getBiggestVectorComponentPosition(int v[], int size,
                                       int *biggestComponentPosition) {
  int biggestComponent = v[0];
  for (int i = 1; i < size; i++) {
    if (v[i] > biggestComponent) {
      *biggestComponentPosition = i;
    }
  }
}

int calculateInternalProductOfVectors(int v1[], int v2[], int size) {
  int product = 0;
  for (int i = 0; i < size; i++) {
    product += v1[i] * v2[i];
  }
  return product;
}

int factorial(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

void circularPermutation(int v[], int size) {
  int i, aux;
  for (i = 0; i < size; i++) {
    v[i] = factorial(v[i] - 1);
  }
}

void switchPlaces(int v[], int p, int q) {
  int aux = v[p];
  v[p] = v[q];
  v[q] = aux;
}

void askForMatrix(int m[][VECTOR_SIZE], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Digite o %dº elemento da %dª linha: ", j + 1, i + 1);
      scanf("%d", &m[i][j]);
    }
  }
}

void displayMatrix(int m[][VECTOR_SIZE], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

int getSmallestMatrixEntry(int m[][VECTOR_SIZE], int size, int *outerPosition,
                           int *innerPosition, int *smallestValue) {
  *smallestValue = m[0][0];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (m[i][j] < *smallestValue) {
        *smallestValue = m[i][j];
        *outerPosition = i;
        *innerPosition = j;
      }
    }
  }
}

int matrixIsSymmetric(int m[][VECTOR_SIZE], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (m[i][j] != m[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

void displayTransposedMatrix(int m[][VECTOR_SIZE], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", m[j][i]);
    }
    printf("\n");
  }
}

void displaySumOfTwoMatrix(int m1[][VECTOR_SIZE], int m2[][VECTOR_SIZE],
                           int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", m1[i][j] + m2[i][j]);
    }
    printf("\n");
  }
}

void main() {
  // Exercício 1

  // printf("isDigit('1'): %d\n", isDigit('1'));
  // printf("isAlpha('a'): %d\n", isAlpha('a'));
  // printf("isAlphanumeric('a'): %d\n", isAlphanumeric('a'));
  // printf("toLower('E'): %c\n", toLower('E'));
  // printf("toUpper('a'): %c\n", toUpper('a'));

  // Exercício 2

  // printf("resto(10, 3): %d\n", resto(10, 3));
  // printf("impar(10): %d\n", impar(10));
  // printf("perfeito(6): %d\n", perfeito(6));
  // printf("primo(7): %d\n", primo(7));

  // Exercício 3

  // int a, b, reduzidos = 0, abundantes = 0, perfeitos = 0;

  // do {
  //     printf("Digite o nº mínimo o nº máximo: ");
  //     scanf("%d%d", &a, &b);
  // } while (a < 0);

  // for (; a <= b; a++) {
  //     if (perfeito(a)) {
  //         printf("%d é perfeito\n", a);
  //         perfeitos++;
  //     } else if (abundante(a)) {
  //         printf("%d é abundante\n", a);
  //         abundantes++;
  //     } else {
  //         printf("%d é reduzido\n", a);
  //         reduzidos++;
  //     }
  // }

  // printf(
  //     "Quantidadades:\n - perfeitos: %d\n - abundantes: %d\n - reduzidos:
  //     %d", perfeitos, abundantes, reduzidos);

  // Exercício 4

  // int lado;
  // askForInt(&lado, "Introduza o lado: ");
  // printf("O volume é: %d\n", calculateVolume(lado));

  // Exercício 5

  // int n1, n2;
  // askForInt(&n1, "Introduza o primeiro nº: ");
  // askForInt(&n2, "Introduza o segundo nº: ");

  // biggerNumber(n1, n2);

  // Exercício 6

  // // a
  // int v[VECTOR_SIZE], size;
  // askForInt(&size, "Introduza o tamanho do vetor (1-20): ");
  // askForVector(v, size);

  // // b
  // displayVector(v, size);

  // // c
  // int biggestComponentPosition;
  // getBiggestVectorComponentPosition(v, size, &biggestComponentPosition);
  // printf("A maior componente do vetor é v[%d] = %d",
  // biggestComponentPosition,
  //        v[biggestComponentPosition]);

  // Exercício 7

  // int v1[VECTOR_SIZE], v2[VECTOR_SIZE], size;
  // askForInt(&size, "Introduza o tamanho dos vetores (1-20): ");
  // askForVector(v1, size);
  // askForVector(v2, size);

  // printf("O produto interno dos vectores introduzidos é %d",
  //        calculateInternalProductOfVectors(v1, v2, size));

  // Exercício 8
  // int v1[VECTOR_SIZE], size;
  // askForInt(&size, "Introduza o tamanho do vetor (1-20): ");
  // askForVector(v1, size);

  // // a
  // circularPermutation(v1, size);
  // displayVector(v1, size);

  // // b
  // int p, q;
  // askForInt(&p, "Introduza o indique que deseja alterar: ");
  // askForInt(&q, "Introduza o novo indice: ");
  // switchPlaces(v1, p, q);
  // displayVector(v1, size);

  // Exercício 9
  // int m[VECTOR_SIZE][VECTOR_SIZE], size;
  // askForInt(&size, "Introduza o tamanho da matriz (1-20): ");

  // // 1
  // askForMatrix(m, size);

  // // 2
  // displayMatrix(m, size);

  // // 3
  // int outerPosition, innerPosition, smallestValue;
  // getSmallestMatrixEntry(m, size, &outerPosition, &innerPosition,
  //                        &smallestValue);
  // printf("O menor valor da matriz é m[%d][%d] = %d\n", outerPosition,
  //        innerPosition, smallestValue);

  // // 4
  // if (matrixIsSymmetric(m, size)) {
  //     puts("A matriz é simétrica");
  // } else {
  //     puts("A matriz não é simétrica");
  // }

  // // 5
  // displayTransposedMatrix(m, size);

  // // 6
  // int m2[VECTOR_SIZE][VECTOR_SIZE];
  // askForMatrix(m2, size);
  // displayMatrix(m2, size);
  // displaySumOfTwoMatrix(m, m2, size);
}
