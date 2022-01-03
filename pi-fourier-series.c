#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define ITERATIONS 1000000000

void main() {
  double pi;
  double sum = 0;
  double piOver2 = M_PI / 2;

  for (int n = 1; n < ITERATIONS; n++) {
    sum += (((double)-1.0 / n) * pow((double)-1, n) + (double)1.0 / n) *
           sin(n * piOver2);
  }

  pi = 2 * sum;

  printf("pi = %.50f\n", pi);
}
