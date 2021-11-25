#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  // short _1;  // -2^16 / 2, 2^16 / 2 - 1
  // int _2;    // -2^32 / 2, 2^32 / 2 - 1
  // long _3;   // -2^64 / 2, 2^64 / 2 - 1

  // unsigned short _4;  // 0, 2^16
  // unsigned int _5;    // 0, 2^32
  // unsigned long _6;   // 0, 2^64

  // float _7;
  // double _8;

  // char _9;
  // char _10[80];

  // int _11[8];

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

  // getchar();
}
