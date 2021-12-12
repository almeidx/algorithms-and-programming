#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/*
  Elabore um programa que permita armazenar em memória a informação relativa a
  um novo livro que chega a uma biblioteca. Considere que para cada livro deve
  ser guardada a seguinte informação:
    - ISBN (máximo 25 caracteres);
    - titulo (máximo 30 caracteres);
    - autor (máximo 30 caracteres);
    - area (máximo 20 caracteres);
    - ano de publicação.

  O programa deve:

  a) Usar uma estrutura de dados que contenha a informação relativa aos dados
  contidos no vector que deve ser alocado dinâmicamente. Esta estrutura deverá
  incluir a informação relativa ao número de elementos existentes na lista de
  livros; o tamanho actual da lista (número actual dos elementos alocados para o
  vector; o endereço inicial do bloco de memória alocado para guardar a lista
  dos livros (vector); e, obviamente, o ponteiro para o bloco de dados que
  conterá o vector onde serão guardados os livros.

  b) O tamanho do vector deverá ser incrementado, sempre que se pretenda
  registar um novo registo e já não haja um elemento disponível, devendo este
  incremento ser definido na aplicação;

  c) a inserção de novos livros, efetuando a inserção de forma a que fiquem
  ordenados no vector por ordem crescente de ISBN;

  d) Eliminar um livro, especificando o respectivo ISBN, devendo usar para a
  pesquisa do livro especificado, a pesquisa binária. Ao eliminar um livro, numa
  determinada posição, essa posição deve ser ocupada pelo livro existente na
  posição seguinte e assim sucessivamente;

  e) Eliminar um livro, especificando o nome respectivo título, devendo a
  posição do livro  eliminado ter um tratamento idêntico ao especificado na
  alínea d);

  f) Listar os livros por ordem do respectivo ISBN;

  g) Listar os livros por ordem do respectivo título;

  h) Gravar os dados existentes na lista num ficheiro binário;

  i) Ler os dados do ficheiro binário para uma lista auxiliar, mostrando no
  final os livros existentes nessa lista. Não esquecer de eliminar essa nova
  lista no final;

  j) Ler os dados do ficheiro binário para a lista já existente (lista
  principal), devendo ser inseridos pela ordem já existente (ordenação crescente
  por ISBN);

  k) Gravar os dados na lista para um ficheiro texto;

  l) Exportar e importar ficheiros texto de forma a permitir transferir dados
  entre sistemas diferentes.
*/

typedef struct Book {
  char isbn[26], title[31], author[31], area[21];
  short year;
} BOOK;

void main() {}
