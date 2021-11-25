#include <math.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  // Exercicio 1

  // int n;

  // printf("Introduza a base.");
  // scanf("%d", &n);

  // for (int i = 1; i <= 10; i++) {
  //     printf("%d x %d = %d\n", n, i, n * i);
  // }

  // Exercicio 2

  // for (int n = 2; n <= 10; n++) {
  //     for (int i = 1; i <= 10; i++) {
  //         printf("%d x %d = %d\n", n, i, n * i);
  //     }

  //     sleep(2);
  // }

  // Exercicio 3

  // int n;

  // printf("Introduza a base.");
  // scanf("%d", &n);

  // for (int i = 10; i >= 1; i--) {
  //     printf("%d / %d = %d\n", n, i, n / i);
  // }

  // Exercicio 4

  // int sum = 0;

  // for (int s = 1; s <= 5; s++) {
  //     unsigned long factorial = 1;

  //     for (int i = s; i >= 1; i--) {
  //         factorial *= i;
  //     }

  //     sum += factorial;
  // }

  // printf("Σ: %d", sum);

  // Exercicio 5

  // int sum = 0, n;

  // printf("Introduza o numero de iterações.\n");
  // scanf("%d", &n);

  // for (int s = 1; s <= 5; s++) {
  //     unsigned long factorial = 1;

  //     for (int i = s; i >= 1; i--) {
  //         factorial *= i;
  //     }

  //     sum += pow(s, 2) / factorial;
  // }

  // printf("Σ: %d", sum);

  // Exercicio 6

  // int sum = 0, n;

  // printf("Introduza o numero numeros.\n");
  // scanf("%d", &n);

  // for (int i = n; i >= 1; i--) {
  //     sum += i;
  //     printf("Soma: %d\n", sum);
  // }

  // printf("Σ: %d\n", sum);

  // Exercicio 7

  // double sum = 1.0;
  // short mult = -1.0;
  // int n;

  // printf("Introduza o numero de termos.\n");
  // scanf("%d", &n);

  // for (float i = 2.0; i <= n; i += 2.0) {
  //     sum += mult * (1.0 / i);
  //     mult = mult == -1.0 ? 1.0 : -1.0;
  // }

  // printf("Σ: %.4f\n", sum);

  // Exercicio 8

  // int branches;

  // printf("Introduza o nº de ramos.\n");
  // scanf("%d", &branches);

  // for (int i = 0; i < branches; i++) {
  //     for (int c = branches; c >= 1; c--) {
  //         printf(c <= i ? "*" : " ");
  //     }

  //     printf("\n");
  // }

  // Exercicio 9 - unfinished

  // int branches;

  // printf("Introduza o nº de ramos.\n");
  // scanf("%d", &branches);

  // for (int i = 1; i <= branches; i++) {
  //     for (int c = 1; c <= i; c++) {
  //         printf("b: %d - i: %d - c: %d\n", branches, i, c);
  //         if (c < branches - i * 2 + 1) {
  //             printf(" ");
  //         } else {
  //             printf("%d", c == i ? i : i - c);
  //         }
  //     }

  //     printf("\n");
  // }

  // Exercicio 10

  // float initialCapital, interest;
  // int years;

  // printf("Introduza o capital inicial.\n");
  // scanf("%f", &initialCapital);
  // printf("Introduza o juro.\n");
  // scanf("%f", &interest);
  // interest /= 100;
  // printf("Introduza o nº de anos.\n");
  // scanf("%f", &years);

  // // n = years => CI(1+J)^(n-1) + J*CI(1+J)^(n-1)
  // printf("Capital acumulado: %.2f",
  //        initialCapital * pow(1 + interest, years - 1) +
  //            interest * initialCapital * pow(1 + interest, years - 1));

  // Exercicio 11

  // float n;
  // int p;

  // printf("Introduza a base.\n");
  // scanf("%f", &n);
  // printf("Introduza o expoente.\n");
  // scanf("%d", &p);

  // printf("%.2g^%d = %.2g\n", n, p, pow(n, p));

  // Exercicio 12 - a

  // int n, num, sum = 0;
  // do {
  //     printf("Introduza o nº de parcelas: ");
  //     scanf("%d", &n);
  // } while (n <= 0);

  // for (int i = 1; i <= n; i++) {
  //     printf("Introduza um valor: ");
  //     scanf("%d", &num);
  //     sum += num;
  // }

  // printf("A média dos %d valores introduzidos é %d", n, (int)(sum / n));

  // Exercicio 12 - b

  // int n = 0;
  // float num, sum = 0.0f;

  // do {
  //     printf("Introduza um valor: ");
  //     scanf("%f", &num);
  //     if (num >= 0) {
  //         sum += num;
  //         n++;
  //     }
  // } while (num >= 0.0f);

  // printf("A média dos %d valores introduzidos é %.2f", n, sum / n);

  // Exercicio 13

  // int n, guess;

  // do {
  //     printf("Introduza um nº inteiro entre 0 e 100: ");
  //     scanf("%d", &n);
  // } while (n < 0 || n > 100);

  // system("cls");

  // do {
  //     printf("Introduza o seu palpite: ");
  //     scanf("%d", &guess);
  //     if (guess > n) {
  //         printf("O seu palpite é maior que o nº a adivinhar.\n");
  //     } else if (guess < n) {
  //         printf("O seu palpite é menor que o nº secreto.\n");
  //     }
  // } while (guess != n);

  // printf("ESTÁ CERTA!!!");

  // Exercicio 14

  // int n, guess, attempts = 0;

  // do {
  //     printf("Introduza um nº inteiro entre 0 e 100: ");
  //     scanf("%d", &n);
  // } while (n < 0 || n > 100);

  // system("cls");

  // do {
  //     printf("Introduza o seu palpite: ");
  //     scanf("%d", &guess);
  //     attempts++;
  //     if (guess > n) {
  //         printf(
  //             "Tentativas: %d. O seu palpite é maior que o nº a
  //             adivinhar.\n", attempts);
  //     } else if (guess < n) {
  //         printf("Tentativas: %d. O seu palpite é menor que o nº
  //         secreto.\n",
  //                attempts);
  //     }
  // } while (guess != n);

  // printf("ESTÁ CERTA!!! Nº de tentativas: ", attempts);

  // Exercicio 15

  /*
      a = ANO MOD 19
      b = ANO \ 100
      c = ANO MOD 100
      d = b \ 4
      e = b MOD 4
      f = (b + 8) \ 25
      g = (b - f + 1) \ 3
      h = (19 × a + b - d - g + 15) MOD 30
      i = c \ 4
      k = c MOD 4
      L = (32 + 2 × e + 2 × i - h - k) MOD 7
      m = (a + 11 × h + 22 × L) \ 451
      MÊS = (h + L - 7 × m + 114) \ 31
      DIA = 1+ (h + L - 7 × m + 114)MOD 31
  */

  int year;
  printf("Introduza o ano: ");
  scanf("%d", &year);

  int a = year % 19;
  int b = year / 100;
  int c = year % 100;
  int d = b / 4;
  int e = b % 4;
  int f = (b + 8) / 25;
  int g = (b - f + 1) / 3;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int l = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 22 * l) / 451;
  int month = (h + l - 7 * m + 114) / 31;
  int day = 1 + (h + l - 7 * m + 114) % 31;

  printf("%d/%d", day, month);
}
