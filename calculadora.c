#include <stdio.h>			// Vamos usar isso para input e output
#include <stdlib.h> 		// Vamos usar isso para alocação de memória
#define _USE_MATH_DEFINES 	// Isso é somente para usar o M_PI ao invés de definir o número de pi.
#include <math.h>			// Vamos usar isso para as funções matemáticas.
#include <string.h> 		// Vamos usar isso para ter as várias funções de manipulação de string.

#define MAX_HISTORICO 10 	// defini o tamanho máximo do histórico.


// Aqui é definido um struct para guardar o histórico, onde é criado um array com limite de 100 caracteres chamado entrada em HistoricoEntry
typedef struct {			
    char entrada[100];
} HistoricoEntry;

// Aqui onde é definido o tamanho em si do histórico e também e definido uma váriavel que serve de contador de intens no histórico e ele é definido como 0 inicialmente.
HistoricoEntry historico[MAX_HISTORICO];
		int historico_count = 0; 

// A função adicionrAohistorico recebe o buffer em entrada cataloga ela com limite de 100 caracteres e adiciona 1 em historico_count, passando para a "proxima página"
  void adicionarAoHistorico(const char* entrada) { 		
    if (historico_count < MAX_HISTORICO) {
        snprintf(historico[historico_count].entrada, 100, "%s", entrada);
        historico_count++;
    }
		printf("histórico cheio.\n");
}

  void mostrarHistorico(void) {
    printf("\n--- [26]Historico de Operacoes --\n");
    if (historico_count == 0) {
        printf("O historico esta vazio.\n");
        return;
    }
    // um laço "for" que momstra tudo que foi guardado em histórico.entrada usando o historico_count como controle.
    for (int i = 0; i < historico_count; i++) {		
        printf("%d: %s\n", i + 1, historico[i].entrada);
    }
}


  void funcaoAdicao(void) {
	  // As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
	// aqui o array e definido para o funcionamento da estrutura.
    double *array;
    double soma = 0.0;
    int tamanho;
    char buffer[100];

    printf("\n--- [1] Adicao ---\n");
    printf("Digite o total de números que vai querer somar: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("A quantidade devve ser maior que zero.\n");
        return;
    }

    array = (double *) malloc(tamanho * sizeof(double)); // É usado malloc para mudar o tamanho do array de acordo com o pedido do usuário.
    if (array == NULL) {
        printf("falha.\n");
        return;
    }

    printf("Digite %d elementos:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {  // É usado um laço "for" para pegar cada espaço de memória do array e somar em um total.
        printf("Elemento %d: ", i + 1);
        scanf("%lf", &array[i]);
        soma += array[i];
    }

    printf("\nResultado: %g\n", soma);
    
    snprintf(buffer, 200, "Adicao de %d numeros. Resultado = %g", tamanho, soma); // O resultado é passado para o array buffer para depois ser passado para adicionarAoHistorico
    adicionarAoHistorico(buffer);

    free(array); // Liberta o espaço de memória do array
}

  void funcaoSubtracao(void) {
	  // As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double valorInicial, subtracao, resultado;
    int tamanho;
    char buffer[100];

    printf("\n--- [2] Subtracao ---\n");
    printf("Digite o valor inicial: ");
    scanf("%lf", &valorInicial);
    resultado = valorInicial; 

    printf("Quantos números deseja subtrair desse valor?? ");
    scanf("%d", &tamanho);

    if (tamanho > 0) {
        printf("digite os %d numeros a serem subtraidos:\n", tamanho);
        for (int i = 0; i < tamanho; i++) {
            printf("Subtrair o valor %d: ", i + 1);
            scanf("%lf", &subtracao);
            resultado -= subtracao;
        }
    }

    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Subtracao partindo de %g resultado = %g", valorInicial, resultado);
    adicionarAoHistorico(buffer);
}


  void funcaoMultiplicacao(void) {
	  // As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double *array;
    double produto = 1.0;
    int tamanho;
    char buffer[100];

    printf("\n--- [3] Multiplicacao ---\n");
    printf("Digite o total de número a Multiplicar: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("a quantidade deve ser maior que zero.\n");
        return;
    }

    array = (double *) malloc(tamanho * sizeof(double));
    if (array == NULL) {
        printf("falha.\n");
        return;
    }

    printf("Digite %d elementos:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%lf", &array[i]);
        produto *= array[i];
    }

    printf("\nResultado: %g\n", produto);
    snprintf(buffer, 100, "multiplicacao de %d numeros, resultado = %g", tamanho, produto);
    adicionarAoHistorico(buffer);
    free(array);
}

  void funcaoDivisao(void) {
	  // As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, snumero, resultado;
    char buffer[100];
    
    printf("\n--- [4] Divisao ---\n");
    printf("Digite o dividendo, numero a ser dividido: ");
    scanf("%lf", &pnumero);
    printf("Digite o divisor: ");
    scanf("%lf", &snumero);

    if (snumero == 0) {
        printf("\nNao e possivel dividir por zero.\n");
        snprintf(buffer, 100, "Divisao: %g / 0. Tentativa Invalida.", pnumero);
    } else {
        resultado = pnumero / snumero;
        printf("\nResultado: %g\n", resultado);
        snprintf(buffer, 100, "Divisao: %g / %g = %g", pnumero, snumero, resultado);
    }
    adicionarAoHistorico(buffer);
}


  void funcaoExponenciacao(void) {
	  // As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double base, expoente, resultado;
    char buffer[100];

    printf("\n--- [5] Exponenciacao ---\n");
    printf("Digite a base: ");
    scanf("%lf", &base);
    printf("Digite o expoente: ");
    scanf("%lf", &expoente);

    resultado = pow(base, expoente);
    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Exponenciacao: %g ^ %g = %g", base, expoente, resultado);
    adicionarAoHistorico(buffer);
}


  void funcaoModulo(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, snumero, resultado;
    char buffer[100];

    printf("\n--- [6] Modullo (Resto) ---\n");
    printf("Digite o dividendo: ");
    scanf("%lf", &pnumero);
    printf("Digite o divisor: ");
    scanf("%lf", &snumero);

    if (snumero == 0) {
        printf("\nN]ao e possivel calcular modulo por zero.\n");
    } else {
        resultado = fmod(pnumero, snumero);
        printf("\nResultado: %g\n", resultado);
        snprintf(buffer, 100, "Modulo: %g %% %g = %g", pnumero, snumero, resultado); // o %% serve para aparecer um % sem problemas.
    }
    adicionarAoHistorico(buffer);
}


  void funcaoPorcentagem(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, snumero, resultado;
    char buffer[100];

    printf("\n--- [7]Porcentagem ---\n");
    printf("Digite a porcentagem: ");
    scanf("%lf", &pnumero);
    printf("Digite o valor total: ");
    scanf("%lf", &snumero);


    resultado = (pnumero / 100.0) * snumero;
    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Porcentagem: %g%% de %g = %g", pnumero, snumero, resultado);
    adicionarAoHistorico(buffer);
}

void funcaoHipotenusa(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double catetoA, catetoB, resultado;
    char buffer[100];

    printf("\n--- [8] Hipotenusa ---\n");
    printf("Digite o cateto A: ");
    scanf("%lf", &catetoA);
    printf("Digite o cateto B: ");
    scanf("%lf", &catetoB);

    resultado = hypot(catetoA, catetoB);
    printf("\nResultado (Hipotenusa): %g\n", resultado);
    snprintf(buffer, 100, "Hipotenusa: catetos %g e %g = %g", catetoA, catetoB, resultado);
    adicionarAoHistorico(buffer);
}

void funcaoRaizQuadrada(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];

    printf("\n [9] Raiz Quadrada ---\n");
    printf("Digite o numero: ");
    scanf("%lf", &pnumero);


    if (pnumero < 0) {
        printf("\nNão existe raiz quadrada real de némero negativo.\n");
        snprintf(buffer, 100, "Raiz Quad: sqrt(%g). Invalido.", pnumero);
    } else {
        resultado = sqrt(pnumero);
        printf("\nResultado: %g\n", resultado);
        snprintf(buffer, 100, "Raiz Quad: sqrt(%g) = %g", pnumero, resultado);
    }
    adicionarAoHistorico(buffer);
}

void funcaoRaizCubica(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];

    printf("\n--- [10] Raiz Cubica ---\n");
    printf("Digite o numero: ");
    scanf("%lf", &pnumero);

    resultado = cbrt(pnumero);
    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Raiz Cubica: cbrt(%g) = %g", pnumero, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoSeno(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double anguloGraus, anguloRadianos, resultado;
    char buffer[100];

    printf("\n--- [11] Seno ---\n");
    printf("Digite o angulo em GRAUS: ");
    scanf("%lf", &anguloGraus);

    anguloRadianos = anguloGraus * (M_PI / 180.0);
    resultado = sin(anguloRadianos);

    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Seno: sin(%g graus) = %g", anguloGraus, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoCosseno(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double anguloGraus, anguloRadianos, resultado;
    char buffer[100];

    printf("\n--- [12] Cosseno ---\n");
    printf("Digite o angulo em GRAUS: ");
    scanf("%lf", &anguloGraus);

    anguloRadianos = anguloGraus * (M_PI / 180.0);
    resultado = cos(anguloRadianos);

    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Cosseno: cos(%g graus) = %g", anguloGraus, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoTangente(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double anguloGraus, anguloRadianos, resultado;
    char buffer[100];

    printf("\n--- Tangente ---\n");
    printf("Digite o angulo em GRAUS: ");
    scanf("%lf", &anguloGraus);

    anguloRadianos = anguloGraus * (M_PI / 180.0);
    resultado = tan(anguloRadianos);

    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Tangente: tan(%g graus) = %g", anguloGraus, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoArcseno(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];

    printf("\n--- [14] Arcseno ---\n");
    printf("Digite o valor deve estar entre -1 e 1: ");
    scanf("%lf", &pnumero);

    if (pnumero < -1.0 || pnumero > 1.0) {
        printf("\nValor invalido.\n");
        snprintf(buffer, 100, "Arcseno: asin(%g) Invalido.", pnumero);
    } else {
        resultado = asin(pnumero) * (180.0 / M_PI); 
        printf("\nResultado (em graus): %g\n", resultado);
        snprintf(buffer, 100, "Arcseno: asin(%g) = %g graus", pnumero, resultado);
    }
    adicionarAoHistorico(buffer);
}


void funcaoArccosseno(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];

    printf("\n--- Arccosseno ---\n");
    printf("Digite o valor entre -1 e 1: ");
    scanf("%lf", &pnumero);

    if (pnumero < -1.0 || pnumero > 1.0) {
        printf("\nValor invalido.\n");
        snprintf(buffer, 100, "Arccosseno: acos(%g). Invalido.", pnumero);
    } else {
        resultado = acos(pnumero) * (180.0 / M_PI); 
        printf("\nResultado (em graus): %g\n", resultado);
        snprintf(buffer, 100, "Arccosseno: acos(%g) = %g graus", pnumero, resultado);
    }
    adicionarAoHistorico(buffer);
}


void funcaoArctangente(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];

    printf("\n--- [16] Arctangente ---\n");
    printf("Digite o valor: ");
    scanf("%lf", &pnumero);

    resultado = atan(pnumero) * (180.0 / M_PI); 
    printf("\nResultado (em graus): %g\n", resultado);
    snprintf(buffer, 100, "Arctangente: atan(%g) = %g graus", pnumero, resultado);
    adicionarAoHistorico(buffer);
}

void funcaoLog10(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];

    printf("\n--- Logaritmo de base 10 ---\n");
    printf("Digite o numero (deve ser > 0): ");
    scanf("%lf", &pnumero);


    if (pnumero <= 0) {
        printf("\nLogaritmo so e definido para numeros positivos.\n");
        snprintf(buffer, 100, "Log10: log10(%g). Invalido.", pnumero);
    } else {
        resultado = log10(pnumero);
        printf("\nResultado: %g\n", resultado);
        snprintf(buffer, 100, "Log10: log10(%g) = %g", pnumero, resultado);
    }
    adicionarAoHistorico(buffer);
}


void funcaoLogNatural(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];

    printf("\n--- Logaritmo Natural ---\n");
    printf("Digite o numero (deve ser > 0): ");
    scanf("%lf", &pnumero);


    if (pnumero <= 0) {
        printf("\nLogaritmo so e definido para numeros positivos.\n");
        snprintf(buffer, 100, "LogNatural: ln(%g). Invalido.", pnumero);
    } else {
        resultado = log(pnumero);
        printf("\nResultado: %g\n", resultado);
        snprintf(buffer, 100, "LogNatural: ln(%g) = %g", pnumero, resultado);
    }
    adicionarAoHistorico(buffer);
}



void funcaoFatorial(void) {
	
}	

void funcaoRadParaGraus(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double radianos, resultado;
    char buffer[100];
    
    printf("\n--- Radianos para Graus ---\n");
    printf("Digite o valor em radianos: ");
    scanf("%lf", &radianos);

    resultado = radianos * (180.0 / M_PI);
    printf("\nResultado (em graus): %g\n", resultado);
    snprintf(buffer, 100, "Conversao: %g rad = %g graus", radianos, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoArredondarBaixo(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];
    
    printf("\n--- Arredondar para Baixo (floor) ---\n");
    printf("Digite o numero: ");
    scanf("%lf", &pnumero);

    resultado = floor(pnumero);
    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Arredondar Baixo: floor(%g) = %g", pnumero, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoArredondarCima(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double pnumero, resultado;
    char buffer[100];
    
    printf("\n--- Arredondar para Cima ---\n");
    printf("Digite o numero: ");
    scanf("%lf", &pnumero);

    resultado = ceil(pnumero);
    printf("\nResultado: %g\n", resultado);
    snprintf(buffer, 100, "Arredondar Cima: ceil(%g) = %g", pnumero, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoGrausParaRad(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double graus, resultado;
    char buffer[100];
    
    printf("\n--- Graus para Radianos ---\n");
    printf("Digite o valor em graus: ");
    scanf("%lf", &graus);

    resultado = graus * (M_PI / 180.0);
    printf("\nResultado (em radianos): %g\n", resultado);
    snprintf(buffer, 100, "Conversao: %g graus = %g rad", graus, resultado);
    adicionarAoHistorico(buffer);
}


void funcaoPitagoras(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double hipotenusa, cateto, resultado;
    char buffer[100];
    
    printf("\n--- Achar Cateto com Pitagoras ---\n");
    printf("Digite o valor da Hipotenusa: ");
    scanf("%lf", &hipotenusa);
    printf("Digite o valor do Cateto conhecido (a ou b): ");
    scanf("%lf", &cateto);


    if (hipotenusa <= cateto) {
        printf("\nA hipotenusa deve ser maior que o cateto.\n");
        snprintf(buffer, 100, "Pitagoras: Hipotenusa %g <= Cateto %g. Invalido.", hipotenusa, cateto); // guardando a informação que deu erro no histórico.
    } else {
        resultado = sqrt(pow(hipotenusa, 2) - pow(cateto, 2));
        printf("\nResultado (outro cateto): %g\n", resultado);
        snprintf(buffer, 100, "Pitagoras: sqrt(%g^2 - %g^2) = %g", hipotenusa, cateto, resultado);
    }
    adicionarAoHistorico(buffer);
}


void funcaoBhaskara(void) {
	// As variáveis de construção da formula são definidas aqui.
	// o Buffer que será usado para guardar o resultado temporáriamente para depois ser passado para a função adicionarAoHistorico é definido aqui.
    double a, b, c, delta, x1, x2;  
    char buffer[100];				

    printf("\n--- Equacão de 2º Grau Bhaskara ---\n");
    printf("Formato: ax^2 + bx + c = 0\n");
    printf("Digite o coeficiente 'a': ");
    scanf("%lf", &a);
    printf("Digite o coeficiente 'b': ");
    scanf("%lf", &b);
    printf("Digite o coeficiente 'c': ");
    scanf("%lf", &c);

    if (a == 0) {
        printf("\n'a' nao pode ser zero, isso nao e uma equacao de 2º grau.\n");
        snprintf(buffer, 100, "Bhaskara Tentativa com a=0. Invalido.");
    } else {
        delta = pow(b, 2) - 4 * a * c;
        printf("Delta = %g\n", delta);

        if (delta < 0) {
            printf("Delta negativo. nao existem raizes reais.\n");
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Delta e zero existe uma raiz real:\n");
            printf("x = %g\n", x1);
            snprintf(buffer, 100, "Bhaskara: Delta = 0. x = %g", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Delta positivo existem duas raizes reais:\n");
            printf("x1 = %g\n", x1);
            printf("x2 = %g\n", x2);
            snprintf(buffer, 100, "Bhaskara: x1 = %g, x2 = %g", x1, x2);
        }
    }
    adicionarAoHistorico(buffer);
}


int main() {
    int escolha;			// A variável escolha que será usada no Switch case é definida aqui.
    int continuar = 1;		// A variável continuar que é usada no loop while é definida aqui.

    while (continuar == 1) {
		// Menu principal mostrando todas as funções e o histórico
        printf("\n===========================================================================\n");
        printf("                          CALCULADORA CIENTIFICA\n");
        printf("===========================================================================\n\n");
        printf("  [ 1] Adicao            [ 2] Subtracao            [ 3] Multiplicacao\n");
        printf("  [ 4] Divisao           [ 5] Exponenciacao        [ 6] Modulo (Resto)\n");
        printf("  [ 7] Porcentagem       [ 8] Hipotenusa           [ 9] Raiz Quadrada\n");
        printf("  [10] Raiz Cubica       [11] Seno                 [12] Cosseno\n");
        printf("  [13] Tangente          [14] Arcseno              [15] Arccosseno\n");
        printf("  [16] Arctangente       [17] Logaritmo base 10    [18] Logaritmo Natural\n");
        printf("  [19] Fatorial          [20] Radianos para Graus  [21] Arredondar p Baixo\n");
        printf("  [22] Arredondar p Cima [23] Graus para Radianos  [24] Teorema de Pitagoras (Achar Cateto)\n");
        printf("  [25] Bhaskara\n\n");
        printf("===========================================================================\n");
        printf("  [26] Mostrar Historico\n");
        printf("===========================================================================\n\n");

		// Entrada do pedido do usuário da função na qual ele deseja usar.
        printf("Digite o numero da operacao desejada: ");
        scanf("%d", &escolha);
        
		
		// Switch case feito de forma bem compacta para deixar o código menor.
        switch (escolha) {
            case 1:  funcaoAdicao(); break;
            case 2:  funcaoSubtracao(); break;
            case 3:  funcaoMultiplicacao(); break;
            case 4:  funcaoDivisao(); break;
            case 5:  funcaoExponenciacao(); break;
            case 6:  funcaoModulo(); break;
            case 7:  funcaoPorcentagem(); break;
            case 8:  funcaoHipotenusa(); break;
            case 9:  funcaoRaizQuadrada(); break;
            case 10: funcaoRaizCubica(); break;
            case 11: funcaoSeno(); break;
            case 12: funcaoCosseno(); break;
            case 13: funcaoTangente(); break;
            case 14: funcaoArcseno(); break;
            case 15: funcaoArccosseno(); break;
            case 16: funcaoArctangente(); break;
            case 17: funcaoLog10(); break;
            case 18: funcaoLogNatural(); break;
            case 19: funcaoFatorial(); break;
            case 20: funcaoRadParaGraus(); break;
            case 21: funcaoArredondarBaixo(); break;
            case 22: funcaoArredondarCima(); break;
            case 23: funcaoGrausParaRad(); break;
            case 24: funcaoPitagoras(); break;
            case 25: funcaoBhaskara(); break;
            case 26: mostrarHistorico(); break;
            default:
                printf("\nOperação invalida. Tente novamente.\n");
                break;
        } 
		// Aqui onde a váriavel continua recebe o valor que fará o loop continuar ou parar.
        printf("\n---------------------------------------------------------------------------\n");
        printf(" Continuar Calculando?\n [1] para Sim \n [2] para Nao \n Resposta: ");
        scanf("%d", &continuar);
    
    } 
    
    printf("\nPrograma encerrado, obrigado por usar a minha calculadora\n");  // Aviso de desepedida.
    
    return 0;
}