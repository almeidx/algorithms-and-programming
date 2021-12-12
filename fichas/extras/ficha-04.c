#include <locale.h>
#include <stdio.h>
#include <string.h>

#define MAX_V 20

typedef struct caract {
  float percAlc;  // % de alcool
  short cor;      // 1-tinto; 2-branco, 3-rosé; 4-ruby;
  char tpVinho;   // M-mesa, G-generoso, E-Espumante, C-Champanhe
  char nome[50];
} CARACT;

typedef struct garrafa {
  int ano;
  CARACT def;
  float preco;
} GARRAFA;

typedef struct Movie {
  char title[51], actors[51], producer[51];
  short year;
  float price;
  // (A-Acção; E-Espionagem; F-Ficção Científica; R-Romance;P-Policial;
  // T-Terror; W-Western; O-Outro)
  char genre;
} FILME;

void readStr(char *str, char *msg) {
  printf("%s", msg);
  gets(str);
}

void printStr(char *msg) {
  char currentChar;
  while ((currentChar = *msg++) != '\0') {
    printf("%c", currentChar);
  }

  printf("\n");

  msg -= 2;

  while ((currentChar = *msg--) != '\0') {
    printf("%c", currentChar);
  }
}

int strLen(char *str) {
  int len = 0;
  while (*str++ != '\0') {
    len++;
  }
  return len;
}

void strConcat(char *str1, char *str2) {
  int len1 = strLen(str1);
  int len2 = strLen(str2);
  int i;
  for (i = 0; i < len2; i++) {
    *(str1 + len1 + i) = *(str2 + i);
  }
  *(str1 + len1 + i) = '\0';
}

//#region Funções de leitura

// read garrafa
void leGarr(GARRAFA *garrafa) {
  fflush(stdin);

  printf("Introduza o nome da garrafa: ");
  gets(garrafa->def.nome);

  printf("Introduza o ano da garrafa: ");
  scanf("%d", &garrafa->ano);

  printf("Introduza o preco da garrafa: ");
  scanf("%f", &garrafa->preco);

  printf("Introduza a percentagem de alcool: ");
  scanf("%f", &garrafa->def.percAlc);

  printf("Introduza a cor (1-tinto; 2-branco, 3-rosé; 4-ruby): ");
  scanf("%d", &garrafa->def.cor);

  fflush(stdin);

  printf(
      "Introduza o tipo de vinho (M-mesa, G-generoso, E-Espumante, "
      "C-Champanhe): ");
  scanf("%c", &garrafa->def.tpVinho);
}

void minMaxGarrafeira(GARRAFA *garrafeira, int n, float *min, float *max) {
  *min = garrafeira->preco;
  *max = garrafeira->preco;
  for (int i = 0; i < n; i++) {
    if ((garrafeira + i)->preco < *min) {
      *min = (garrafeira + i)->preco;
    }
    if ((garrafeira + i)->preco > *max) {
      *max = (garrafeira + i)->preco;
    }
  }
}

void precMarcaGVelha(GARRAFA *garrafeira, int n, float *prec, char *marca) {
  *prec = garrafeira->preco;
  strcpy(marca, garrafeira->def.nome);
  for (int i = 0; i < n; i++) {
    if ((garrafeira + i)->preco < *prec) {
      *prec = (garrafeira + i)->preco;
      strcpy(marca, (garrafeira + i)->def.nome);
    }
  }
}

//#endregion

void readInt(int *n, char *msg) {
  printf("%s", msg);
  scanf("%d", n);
}

void nFilmePTipo(FILME prateleiras[10][100], int *quantidades, char *tipos,
                 int anoSuperior, int anoInferior, int *nFilmes) {
  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < quantidades[i]; j++) {
      if (prateleiras[i][j].year >= anoInferior &&
          prateleiras[i][j].year <= anoSuperior &&
          tipos[i] == prateleiras[i][j].genre) {
        nFilmes[i]++;
      }
    }
  }
}

void main() {
  setlocale(LC_ALL, "Portuguese");

  // char msg[41];
  // readStr(msg, "Introduza uma mensagem: ");

  // Exercício 1

  // printStr(msg);

  // Exercício 2

  // printf("O tamanho da string é %d\n", strLen(msg));

  // Exercício 3

  // char msg2[41];
  // readStr(msg2, "Introduza outra mensagem: ");

  // strConcat(msg, msg2);
  // printStr(msg);

  // Exercício 4

  // GARRAFA garrafeira[MAX_V];

  // // a
  // int n;

  // do {
  //   printf("Introduza o número de garrafas ([1, %d]): ", MAX_V);
  //   scanf("%d", &n);
  // } while (n < 1 || n > MAX_V);

  // for (int i = 0; i < n; i++) {
  //   leGarr(garrafeira + i);
  // }

  // // b
  // float min, max;

  // minMaxGarrafeira(garrafeira, n, &min, &max);
  // printf("O preço mínimo é %.2f e o preço máximo é %.2f\n", min, max);

  // // c
  // float prec;
  // char marca[50];

  // precMarcaGVelha(garrafeira, n, &prec, marca);
  // printf("O preço mínimo é %.2f e a marca é %s\n", prec, marca);

  // Exercício 5

  // conjunto de DVDs, arquivados em 10 prateleiras com capacidade máxima de
  // 100 DVDs
  FILME prateleiras[10][100];

  // quantos filmes existem em cada prateleira
  int quantidades[10];

  // tipos dos filmes em cada prateleira
  char tipos[10];

  int anoInferior, anoSuperior, nFilmes[10];
  readInt(&anoInferior, "Introduza o limite de anos inferior: ");
  readInt(&anoSuperior, "Introduza o limite de anos superior: ");

  nFilmePTipo(prateleiras, quantidades, tipos, anoInferior, anoSuperior,
              nFilmes);
}
