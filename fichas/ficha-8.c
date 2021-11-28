#include <stdio.h>
#include <stdlib.h>

void readInt(int *number, char msg[]) {
  printf("%s", msg);
  scanf("%d", number);
}

int *allocateMatrix(int rows, int cols) {
  // return (int *)malloc(rows * cols * sizeof(int));
  return (int *)calloc(rows * cols, sizeof(int));
}

void displayMatrix(int *matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i * cols + j]);
    }
    printf("\n");
  }
}

void readMatrixLineByLine(int *matrix, int rows, int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("Introduza um inteiro para a posição (%d, %d): ", r, c);
      scanf("%d", &matrix[r * cols + c]);
    }
  }
}

int isMatrixSymmetric(int *matrix, int rows, int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (matrix[r * cols + c] != matrix[c * cols + r]) {
        return 0;
      }
    }
  }
  return 1;
}

int sumMainDiagonal(int *matrix, int rows, int cols) {
  int sum = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (r == c) {
        sum += matrix[r * cols + c];
      }
    }
  }
  return sum;
}

void calculateMatrixProduct(int *matrix1, int *matrix2, int *matrix3, int rows,
                            int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int sum = 0;
      for (int i = 0; i < rows; i++) {
        sum += matrix1[r * cols + i] * matrix2[i * cols + c];
      }
      matrix3[r * cols + c] = sum;
    }
  }
}

void main() {
  // Exercício 1

  // int rows, columns;
  // readInt(&rows, "Digite o numero de linhas: ");
  // readInt(&columns, "Digite o numero de colunas: ");

  // // a
  // int *matrix = allocateMatrix(rows, columns);

  // // b
  // readMatrixLineByLine(matrix, rows, columns);

  // // c
  // displayMatrix(matrix, rows, columns);

  // // d
  // if (isMatrixSymmetric(matrix, rows, columns)) {
  //   printf("A matriz é simétrica.\n");
  // } else {
  //   printf("A matriz não é simétrica.\n");
  // }

  // // e
  // printf("A soma da diagonal principal é %d.\n",
  //        sumMainDiagonal(matrix, rows, columns));

  // Exercício 2
  int rows, columns;
  readInt(&rows, "Digite o numero de linhas: ");
  readInt(&columns, "Digite o numero de colunas: ");

  int *matrix1 = allocateMatrix(rows, columns);
  int *matrix2 = allocateMatrix(rows, columns);
  int *matrix3 = allocateMatrix(rows, columns);

  readMatrixLineByLine(matrix1, rows, columns);
  readMatrixLineByLine(matrix2, rows, columns);

  calculateMatrixProduct(matrix1, matrix2, matrix3, rows, columns);

  displayMatrix(matrix3, rows, columns);
}
