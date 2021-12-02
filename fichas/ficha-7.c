#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define STRING_LIMIT 50
#define VECTOR_LIMIT 30

typedef struct Point {
  int x, y;
} point;

typedef struct Fraction {
  int numerator, denominator;
} fraction;

typedef struct Student {
  char name[STRING_LIMIT];
  int number, grade;
} student;

typedef struct Book {
  char title[31], author[31], area[21];
  int year, occupied;
} book;

void readPoint(point *p) {
  printf("Introduza as cordenadas ponto: ");
  scanf("%d %d", &(*p).x, &(*p).y);
}

void displayPoint(point p) { printf("(%d, %d)\n", p.x, p.y); }

float getDistanceBetweenPoints(point p1, point p2) {
  return sqrt(pow(abs(p2.x - p1.x), 2) + pow(abs(p2.y - p1.y), 2));
}

int getRectangleAreaUsingDiagonal(point p1, point p2) {
  return abs(p2.x - p1.x) * abs(p2.y - p1.y);
}

void readFraction(fraction *f) {
  printf("Introduza o numerador e denominador da fração: ");
  scanf("%d %d", &(*f).numerator, &(*f).denominator);
}

void readString(char *str, char msg[]) {
  printf(msg);
  scanf("%s", str);
}

void multiplyFractions(fraction f1, fraction f2, fraction *f3) {
  (*f3).numerator = f1.numerator * f2.numerator;
  (*f3).denominator = f1.denominator * f2.denominator;
}

void displayFraction(fraction f) {
  printf("%d/%d\n", f.numerator, f.denominator);
}

void addFractions(fraction f1, fraction f2, fraction *f3) {
  (*f3).numerator =
      f1.numerator * f2.denominator + f2.numerator * f1.denominator;
  (*f3).denominator = f1.denominator * f2.denominator;
}

void subtractFractions(fraction f1, fraction f2, fraction *f3) {
  (*f3).numerator =
      f1.numerator * f2.denominator - f2.numerator * f1.denominator;
  (*f3).denominator = f1.denominator * f2.denominator;
}

void divideFractions(fraction f1, fraction f2, fraction *f3) {
  (*f3).numerator = f1.numerator * f2.denominator;
  (*f3).denominator = f1.denominator * f2.numerator;
}

void readInt(int *n, char msg[]) {
  printf(msg);
  scanf("%d", n);
}

void readStudent(student *s) {
  readString(s->name, "Introduza o nome do aluno: ");
  readInt(&s->number, "Introduza o número do aluno: ");
  readInt(&s->grade, "Introduza a nota do aluno: ");
}

void readBook(book *b) {
  readString(b->title, "Introduza o título do livro: ");
  readString(b->author, "Introduza o autor do livro: ");
  readString(b->area, "Introduza a área do livro: ");
  readInt(&b->year, "Introduza o ano de publicação: ");
  b->occupied = 1;
}

void displayBook(book b) {
  printf("Título: %s\n", b.title);
  printf("Autor: %s\n", b.author);
  printf("Área: %s\n", b.area);
  printf("Ano: %d\n", b.year);
}

void removeBookByName(book *b, int n, char name[]) {
  int i = 0;
  while (strcmp(b[i].title, name) != 0) {
    i++;
  }
  b[i].occupied = 0;
}

void main() {
  setlocale(LC_ALL, "Portuguese");

  // Exercício 1
  // point p1, p2;
  // readPoint(&p1);
  // displayPoint(p1);
  // readPoint(&p2);
  // displayPoint(p2);
  // printf("O comprimento da diagonal é: %.2f\n",
  //        getDistanceBetweenPoints(p1, p2));
  // printf("A área do retângulo é: %d\n",
  //        getRectangleAreaUsingDiagonal(p1, p2));

  // Exercício 2
  // fraction f1, f2, f3;
  // short cont = 1;
  // char op;
  // printf(
  //     "Introduza a operação (Valores válidos: a [add], m [multiply], s "
  //     "[subtract], d [divide]): ");
  // scanf("%c", &op);

  // readFraction(&f1);
  // readFraction(&f2);

  // switch (op) {
  //     case 'a':
  //         addFractions(f1, f2, &f3);
  //         break;
  //     case 'm':
  //         multiplyFractions(f1, f2, &f3);
  //         break;
  //     case 's':
  //         subtractFractions(f1, f2, &f3);
  //         break;
  //     case 'd':
  //         divideFractions(f1, f2, &f3);
  //         break;
  //     default:
  //         cont = 0;
  //         break;
  // }

  // if (cont == 1) {
  //     displayFraction(f3);
  // } else {
  //     puts("Operação inválida!");
  // }

  // Exercício 3
  // student students[VECTOR_LIMIT];
  // short n, studentNumber;
  // readInt(&n, "Introduza o número de estudantes: ");

  // for (int i = 0; i < n; i++) {
  //     readStudent(&students[i]);
  // }

  // readInt(&studentNumber, "Introduza o número do aluno que quer aceder: ");
  // for (int i = 0; i < n; i++) {
  //     if (students[i].number == studentNumber) {
  //         printf("Nome: %s\n", students[i].name);
  //         printf("Nota: %d\n", students[i].grade);
  //         break;
  //     }
  // }

  // Exercício 4
  book books[VECTOR_LIMIT];
  int n;
  readInt(&n, "Introduza o número de livros que deseja introduzir: ");

  for (int i = 0; i < n; i++) {
    readBook(&books[i]);
  }

  for (int i = 0; i < n; i++) {
    displayBook(books[i]);
  }

  char name[31];
  readString(name, "Introduza o título do livro que deseja remover: ");
  removeBookByName(books, n, name);

  for (int i = 0; i < n; i++) {
    displayBook(books[i]);
  }
}
