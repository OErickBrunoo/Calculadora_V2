# Calculadora Científica em C

Este repositório contém o código-fonte de uma calculadora científica de console, implementada integralmente na linguagem C. O projeto foi desenvolvido de forma modular, com um menu interativo que dá acesso a 25 operações matemáticas distintas e um sistema de histórico.

## Funcionalidades

O programa oferece um conjunto de 25 funções de cálculo, além de um visualizador de histórico.

### Operações Básicas

  * **Adição**: Permite a soma de N números.
  * **Subtração**: Permite a subtração de N números a partir de um valor inicial.
  * **Multiplicação**: Permite a multiplicação de N números.
  * **Divisão**: Inclui verificação para divisão por zero.

### Potência, Raízes e Logaritmos

  * Exponenciação ($base^{expoente}$)
  * Raiz Quadrada (com verificação de números negativos)
  * Raiz Cúbica
  * Logaritmo (Base 10) (com verificação de domínio)
  * Logaritmo Natural (Base e) (com verificação de domínio)

### Trigonometria

  * Seno (entrada em graus)
  * Cosseno (entrada em graus)
  * Tangente (entrada em graus)
  * Arcseno (saída em graus, com verificação de domínio)
  * Arccosseno (saída em graus, com verificação de domínio)
  * Arctangente (saída em graus)
  * Conversão de Graus para Radianos
  * Conversão de Radianos para Graus

### Operações Algébricas e Geométricas

  * Módulo (Resto da divisão, com verificação de divisão por zero)
  * Porcentagem
  * Cálculo de Hipotenusa (Teorema de Pitágoras)
  * Cálculo de Cateto (Teorema de Pitágoras, com verificação de entradas)
  * Equação de 2º Grau (Bhaskara) (com verificação de `a=0` e delta)

### Outras Funções

  * Arredondar para Baixo (Floor)
  * Arredondar para Cima (Ceil)
  * Fatorial (definido no menu como opção 19)

### Sistema de Histórico

  * **Mostrar Histórico**: Exibe uma lista das últimas operações realizadas.
  * O histórico armazena uma string formatada de cada operação, incluindo entradas e resultados.

## Compilação e Execução

O código foi escrito em C padrão e pode ser compilado com qualquer compilador C, como o GCC. Como o projeto utiliza funções da biblioteca `math.h`, é necessário linkar a biblioteca matemática durante a compilação.

**Compilando com GCC:**

```bash
gcc Calculadora_final.c -o calculadora -lm
```

**Executando o programa:**

```bash
./calculadora
```

## Utilização

Ao executar o programa, um menu principal é exibido no console, listando todas as operações disponíveis (de 1 a 25) e a opção de histórico (26).

1.  Digite o número da operação desejada e pressione `Enter`.
2.  Siga as instruções no console para inserir os valores numéricos necessários para o cálculo.
3.  O resultado será exibido, e a operação será registrada no histórico.
4.  Após a conclusão, o programa perguntará se deseja realizar um novo cálculo:
      * Digite `1` para retornar ao menu principal.
      * Digite `2` para encerrar o programa.

## Detalhes da Implementação

### Estrutura do Código

  * **Modularidade**: Cada operação matemática é encapsulada em sua própria função `void` (ex: `funcaoRaizQuadrada()`, `funcaoBhaskara()`).
  * **Menu Principal**: O fluxo do programa é controlado por um loop `while` e uma estrutura `switch` na função `main()`.

### Gerenciamento de Memória

  * **Alocação Dinâmica**: As funções `funcaoAdicao` e `funcaoMultiplicacao` utilizam `malloc()` para alocar dinamicamente um array de `double`, permitindo ao usuário definir quantos números deseja operar.
  * **Liberação de Memória**: `free()` é chamado ao final dessas funções para prevenir vazamento de memória.

### Sistema de Histórico

  * O histórico é implementado através de um array global de `structs`:
    ```c
    #define MAX_HISTORICO 10

    typedef struct {
        char entrada[100];
    } HistoricoEntry;

    HistoricoEntry historico[MAX_HISTORICO];
    int historico_count = 0;
    ```
  * A função `adicionarAoHistorico` é chamada ao final de cada cálculo, formatando o resultado em uma string (via `snprintf`) e armazenando-o na `struct`.
  * A função `mostrarHistorico` itera sobre o array `historico` até o limite de `historico_count` para exibir as entradas.

### Tratamento de Erros

O programa inclui validações de entrada para diversas operações críticas:

  * Divisão por zero (`funcaoDivisao`, `funcaoModulo`).
  * Domínio de funções (`funcaoRaizQuadrada`, `funcaoLog10`, `funcaoArcseno`, etc.).
  * Validação de coeficientes (`funcaoBhaskara`).
  * Validação de cateto vs. hipotenusa (`funcaoPitagoras`).

## Observações

  * A função `funcaoFatorial()` (opção 19) está definida no menu, mas sua lógica de cálculo não foi implementada na versão atual do arquivo `Calculadora_final.c`.
  * O limite do histórico (`MAX_HISTORICO`) está atualmente definido como 10 entradas.
  * Existe um bug conhecido na função `adicionarAoHistorico` onde a mensagem "histórico cheio." é impressa a cada operação, independentemente do estado do histórico, devido ao seu posicionamento fora de um bloco `else`.