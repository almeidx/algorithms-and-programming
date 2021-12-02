#include <locale.h>
#include <stdio.h>
#include <string.h>

#define STRING_LIMIT 100
#define INPUT_FILENAME "input.txt"

void readString(char *string) {
  printf("Introduza uma string: ");
  scanf("%20s", string);
}

void main() {
  // Exercicio 1

  // char str[STRING_LIMIT];
  // FILE *f = fopen(INPUT_FILENAME, "a+");

  // if (f == NULL) {
  //   printf("Ocorreu um erro ao abrir o ficheiro.\n");
  //   return;
  // }

  // do {
  //   readString(str);
  //   strcat(str, "\n");
  //   if (str[0] != '.') {
  //     fputs(str, f);
  //   }
  // } while (str[0] != '.');

  // fclose(f);

  // Exercício 2

  FILE *f = fopen(INPUT_FILENAME, "r");
  char str;

  while ((str = fgetc(f)) != EOF) {
    printf("%c", str);
  }

  fclose(f);
}
