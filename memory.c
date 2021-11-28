#include <stdio.h>
#include <stdlib.h>

void main() {
  char *str = malloc(6 * sizeof(char));

  str[0] = 'h';
  str[1] = 'e';
  str[2] = 'l';
  str[3] = 'l';
  str[4] = 'o';
  str[5] = '\0';

  puts(str);
  printf("Address: %p", str);

  free(str);
}
