#include <stdio.h>
#include <stdlib.h>

void main() {
  int *alloc = malloc(2 * sizeof(int));
  int **p = &alloc;

  **p = 1;
  *(*p + 1) = 2;

  for (int i = 0; i < 2; i++) {
    printf("*(p + %d) = %d [%p]\n", i, *(*p + i), (void *)(*p + i));
  }

  printf("Pointer address: %p\n", (void *)alloc);
  printf("Pointer of pointer address: %p\n", (void *)p);
}
