#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Party {
  char name[51];
  int votes, places;
} party;

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

party *allocateParties(int n) { return (party *)malloc(n * sizeof(party)); }

void readAllParties(party *partyVector, int n) {
  for (int i = 0; i < n; i++) {
    printf("Introduza o nome do partido: ");
    gets(partyVector->name);
    fseek(stdin, 0, 2);
    printf("Introduza o número de votos: ");
    scanf("%d", &partyVector->votes);
    partyVector->places = 0;
    partyVector++;
  }
}

int getMaxPosition(int *q, party *L, int n) {
  int pos = 0;
  for (int i = 1; i < n; i++) {
    if (q[i] > q[pos] || (q[i] == q[pos] && L[i].places < L[pos].places)) {
      pos = i;
    }
  }
  return pos;
}

void assignPlaces(party *partyVector, int n, int numberOfMandates) {
  int i, currentPosition = 0, nextPartyPosition,
         *queue = (int *)malloc(n * sizeof(int));

  while (currentPosition < numberOfMandates) {
    for (i = 0; i < n; i++) {
      queue[i] = partyVector[i].votes / (1 + partyVector[i].places);
    }

    nextPartyPosition = getMaxPosition(queue, partyVector, n);

    partyVector[nextPartyPosition].places++;
    currentPosition++;
  }

  free(queue);
}

void main() {
  setlocale(LC_ALL, "Portuguese");

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
  // int rows, columns;
  // readInt(&rows, "Digite o numero de linhas: ");
  // readInt(&columns, "Digite o numero de colunas: ");

  // int *matrix1 = allocateMatrix(rows, columns);
  // int *matrix2 = allocateMatrix(rows, columns);
  // int *matrix3 = allocateMatrix(rows, columns);

  // readMatrixLineByLine(matrix1, rows, columns);
  // readMatrixLineByLine(matrix2, rows, columns);

  // calculateMatrixProduct(matrix1, matrix2, matrix3, rows, columns);

  // displayMatrix(matrix3, rows, columns);

  // Exercício 3

  // int n, mandatos;
  // party *partyVector = allocateParties(n);

  // readInt(&n, "Introduza o número de partidos: ");
  // readAllParties(partyVector, n);
  // readInt(&mandatos, "Introduza o número de lugares a atribuir: ");

  // assignPlaces(partyVector, n, mandatos);

  // for (int i = 0; i < n; i++) {
  //   printf("Partido %s recebe %d lugares\n", partyVector[i].name,
  //          partyVector[i].places);
  // }

  // free(partyVector);
}
