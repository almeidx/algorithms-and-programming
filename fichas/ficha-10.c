#include <locale.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define FIBONACCI_CACHE_SIZE 100

struct timeval t1, t2;

void readInt(int *n, char *msg) {
  printf("%s", msg);
  scanf("%d", n);
}

int recursiveSum(int n) {
  if (n == 0) {
    return 0;
  }
  return n + recursiveSum(n - 1);
}

int recursiveFactorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * recursiveFactorial(n - 1);
}

int recursivePower(int n, int p) {
  if (p == 0) {
    return 1;
  }
  return n * recursivePower(n, p - 1);
}

float recursiveSumOfDivision(int n, int numerator) {
  if (n == 0) {
    return 0;
  }
  return (float)recursivePower(numerator, n) / (float)recursiveFactorial(n) +
         recursiveSumOfDivision(n - 1, numerator);
}

// Exercício 5 - a
int recursiveSumOfFactorialPower(int n) {
  if (n == 0) {
    return 0;
  }
  return recursivePower(recursiveFactorial(n), n) +
         recursiveSumOfFactorialPower(n - 1);
}

// Exercício 5 - b
int recursiveSumOfProductFactorial(int n) {
  if (n == 0) {
    return 0;
  }
  return n * recursiveFactorial(n + 1) + recursiveSumOfProductFactorial(n - 1);
}

// Exercício 5 - c
int recursiveSumOfDivisionOfFactorial(int n) {
  if (n == 0) {
    return 0;
  }
  return recursiveFactorial(n) / n + recursiveSumOfDivisionOfFactorial(n - 1);
}

// Exercício 5 - d
int recursiveSumOfDivisionOfFactorials(int n) {
  // i = 2
  if (n <= 1) {
    return 0;
  }
  return recursiveFactorial(n) / recursiveFactorial(n - 1) +
         recursiveSumOfDivisionOfFactorials(n - 1);
}

// Exercício 5 - e
int recursiveSumOfDivisionOfFactorialPower(int n) {
  if (n == 0) {
    return 0;
  }
  return recursivePower(recursiveFactorial(n), 2) / (n + 1) +
         recursiveSumOfDivisionOfFactorialPower(n - 1);
}

int recursiveFibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int iterativeFibonacci(int n) {
  int a = 0, b = 1, c = 0;
  for (int i = 0; i < n - 1; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int recursiveFibonacciWithCache(int n, int *cache) {
  if (n == 0 || n == 1) {
    return n;
  }
  if (cache[n] != 0) {
    return cache[n];
  }
  cache[n] = recursiveFibonacciWithCache(n - 1, cache) +
             recursiveFibonacciWithCache(n - 2, cache);
  return cache[n];
}

void main() {
  setlocale(LC_ALL, "Portuguese");

  // Exercício 1

  // int n;
  // readInt(&n, "Introduza um número: ");

  // printf("A soma dos números até %d é %d\n", n, recursiveSum(n));

  // Exercício 2

  // int n;
  // readInt(&n, "Introduza um número: ");

  // printf("%d! = %d\n", n, recursiveFactorial(n));

  // Exercício 3

  // int n, p;
  // readInt(&n, "Introduza uma base: ");
  // readInt(&p, "Introduza um expoente: ");

  // printf("O somatório de i = %d de %d^%d = %d\n", n, n, p,
  //        recursivePower(n, p));

  // Exercício 4

  // int n, numerator, power;
  // readInt(&n, "Introduza o número de iterações: ");
  // readInt(&numerator, "Introduza o numerador: ");

  // printf("O somatório de i = %d de %d^i/i = %.3f", n, numerator,
  //        recursiveSumOfDivision(n, numerator));

  // Exercício 5

  // int i;
  // readInt(&i, "Introduza o número de iterações: ");

  // // a
  // printf("O somatório de i = %d de (i!)^i = %d\n", i,
  //        recursiveSumOfFactorialPower(i));

  // // b
  // printf("O somatório de i = %d de i * (i + 1)! = %d\n", i,
  //        recursiveSumOfProductFactorial(i));

  // // c
  // printf("O somatório de i = %d de i!/i = %d\n", i,
  //        recursiveSumOfDivisionOfFactorial(i));

  // // d
  // printf("O somatório de i = 2 até %d de i!/(i - 1)! = %d\n", i,
  //        recursiveSumOfDivisionOfFactorials(i));

  // // e
  // printf("O somatório de i = %d de (i!)^2/(i + 1) = %d\n", i,
  //        recursiveSumOfDivisionOfFactorialPower(i));

  // Exercício 6

  int n, res;
  double elapsedTime;
  readInt(&n, "Introduza um número: ");

  // a
  gettimeofday(&t1, NULL);
  res = recursiveFibonacci(n);
  gettimeofday(&t2, NULL);

  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

  printf("[recursive: %.9f] O fibonacci de %d é %d\n", elapsedTime, n, res);

  // b
  gettimeofday(&t1, NULL);
  res = iterativeFibonacci(n);
  gettimeofday(&t2, NULL);

  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

  printf("[iterative: %.9f] O fibonacci de %d é %d\n", elapsedTime, n, res);

  // c
  int cache[FIBONACCI_CACHE_SIZE] = {0};

  gettimeofday(&t1, NULL);
  res = recursiveFibonacciWithCache(n, cache);
  gettimeofday(&t2, NULL);

  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

  printf("[recursive w/ cache: %.9f] O fibonacci de %d é %d\n", elapsedTime, n,
         res);
}
