#include <locale.h>
#include <stdio.h>
#include <string.h>

#define STRING_LIMIT 100
#define INPUT_FILENAME "ficha_09.txt"

void readString(char *string, char *msg) {
  printf(msg);
  gets(string);
}

void main() {
  // Exercicio 1

  // char str[STRING_LIMIT];
  // FILE *f = fopen(INPUT_FILENAME, "w");

  // if (f == NULL) {
  //   printf("Ocorreu um erro ao abrir o ficheiro.\n");
  //   return;
  // }

  // do {
  //   readString(str, "Introduza uma frase: ");
  //   if (strcmp(str, ".") != 0) {
  //     fputs(str, f);
  //     fputs("\n", f);
  //   }
  // } while (strcmp(str, ".") != 0);

  // fclose(f);

  // Exercício 2

  // FILE *f = fopen(INPUT_FILENAME, "r");
  // char str[STRING_LIMIT];

  // while (!feof(f)) {
  //   fgets(str, STRING_LIMIT, f);
  //   printf("%s", str);
  // }

  // fclose(f);

  // Exercício 3

  char fileName[STRING_LIMIT];

  readString(fileName, "Introduza o nome do ficheiro: ");

  FILE *f = fopen(fileName, "r");

  if (f == NULL) {
    printf("Ocorreu um erro ao abrir o ficheiro.\n");
    return;
  }

  fseek(f, 0, SEEK_END);

  printf("O ficheiro tem %ld bytes.\n", ftell(f));
}
