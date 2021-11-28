# Exercício 1

## Variáveis

- inteiros: `n1`, `n2`, `d1`, `d2`

## Código

```txt
Inicio
  Escrever('Introduza o início do intervalo.')
  Ler(n1)
  Escrever('Introduza o fim do intervalo.')
  Ler(n2)

  Escrever('Introduza o primeiro nº para servir de divisor.')
  Ler(d1)
  Escrever('Introduza o segundo nº para servir de divisor.')
  Ler(d2)

  Para i = n1 até n2
    Se i % d1 = 0
      Escrever(i, ' é divisível por ', d1)
    Ou Se i % d2 = 0
      Escrever(i, ' é divisível por ', d2)
    Fim Se
  Fim Para
Fim
```

# Exercício 2

## Variáveis

- inteiros: `age`, `max`, `min`, `sum`, `n`

## Código

```txt
Inicio
  max <- -1
  min <- 999
  sum <- 0

  Escrever('Introduza o nº de pessoas')
  Ler(n)

  Para i = 1 até n faz
    Escrever('Introduza a idade')
    Ler(age)
    Se age > max
      max = age
    Ou se age < min
      min = age
    Fim Se
    sum <- sum + age
  Fim Para

  Escrever('A média das idades é ', sum / n, '. A maior idade foi ', max, ' e a menor foi ', min)
Fim
```

# Exercício 3

## Variáveis

- inteiros: `even`, `uneven`, `n`, `num`

## Código

```txt
Inicio
  even <- 0
  uneven <- 0
  n <- 0
  Faz
    Escrever('Introduza um nº')
    Ler(num)
    Se n % 2 = 0
      even <- even + 1
    Ou
      uneven <- uneven + 1
    Fim Se
  Enquanto (IS_NUMBER(n))
  Escrever('Foram tratados ', n, ' números. ', even, ' eram pares e ', uneven, ' eram impares.')
Fim
```

# Exercício 5

## Variáveis

- inteiros: `n1`, `n2`, `d1`, `d2`

## Código

```txt
Inicio
  Escrever('Introduza o início do intervalo.')
  Ler(n1)
  Escrever('Introduza o fim do intervalo.')
  Ler(n2)

  Escrever('Introduza o primeiro nº para servir de divisor.')
  Ler(d1)
  Escrever('Introduza o segundo nº para servir de divisor.')
  Ler(d2)

  Para i = n2 até n1
    Se i % d1 = 0
      Escrever(i, ' é divisível por ', d1)
    Ou Se i % d2 = 0
      Escrever(i, ' é divisível por ', d2)
    Fim Se
  Fim Para
Fim
```
