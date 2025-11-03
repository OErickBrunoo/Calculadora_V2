#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



//Variaveis Globais, Constantes ------------------Leo!!!
int tamanho;
double pnumero, snumero, tnumero;
double resultado, resultado2;
double acao;
double delta, pcima1, pcima2, pbaixo;
const double pi = 3.1415926535897;
//--------------------------------------------------------Leo!!!

typedef struct {
	char tipo[50];
    double a, b;
    double resultado;
    int id;

}historico;

#define MAXHISTORICO 100
historico historicoArray[MAXHISTORICO];
int numeroDeOperacoes = 0;

void salvarHistoricoEmArquivo(){
    FILE *arquivo = fopen("historico.csv", "w");
    
    if(arquivo == NULL){
        printf("Erro ao salvar arquivo.\n");
        return;
    }
    
    fprintf(arquivo, "ID, Tipo, Numero1, Numero2, Resultado\n");
    
    for(int i = 0; i < numeroDeOperacoes;i++){
        char tipoSemEspacos[50];
        strcpy(tipoSemEspacos, historicoArray[i].tipo);
        for(int j = 0; tipoSemEspacos[j] != '\0'; j++){
            if(tipoSemEspacos[j] == ' '){
                tipoSemEspacos[j] = '-';
            }
        }
        
        fprintf(arquivo, "%d, %s, %g, %g, %g \n",
        historicoArray[i].id,
        tipoSemEspacos,
        historicoArray[i].a,
        historicoArray[i].b,
        historicoArray[i].resultado);
    }
    fclose(arquivo);
}

void adicionarAoHistorico(const char* tipo, double n1, double n2, double res){

if (numeroDeOperacoes<100){
    strcpy(historicoArray[numeroDeOperacoes].tipo, tipo);
    historicoArray[numeroDeOperacoes].a = n1;
    historicoArray[numeroDeOperacoes].b = n2;
    historicoArray[numeroDeOperacoes].resultado = res;
    historicoArray[numeroDeOperacoes].id = numeroDeOperacoes;
    numeroDeOperacoes++;
    
    salvarHistoricoEmArquivo();
}else{
    printf("Eu estou completamente impressionado que você realizou 101 operações. Parabéns?");
}

}

void mostrarHistorico(){
    printf("\n--- Histórico de Cálculos---\n");

    if(numeroDeOperacoes == 0){
        printf("Nenhum registro.");
    }else{
        for(int i = 0; i < numeroDeOperacoes; i++){
            printf("ID: %d | Operação: %s | Inputs: %g - %g | Resultado: %g. \n", historicoArray[i].id, historicoArray[i].tipo, historicoArray[i].a, historicoArray[i].b, historicoArray[i].resultado);
        }
    }
    printf("\n Entrada ou saída representados por 0 indicam valores multiplos, variados, imprecisos ou complexos.\n");
}


// Adição
double funcaoAdicao (double valores[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        resultado += valores[i];
    }
    adicionarAoHistorico("Soma (Múltiplos Números)", 0, 0, resultado);
    return resultado;
}
// Multiplicação
double funcaoMultiplicacao1(double valores[], int tamanho){
    double res = 1;
     for (int i = 0; i < tamanho; i++) {
        res *= valores[i];
    }
    adicionarAoHistorico("Multiplicação (Múltiplos Números)", 0, 0, resultado);
    return res;
    
}
double funcaoSubtracao (double valorInicial, double valores[], int tamanho){
// Subtração
    resultado = valorInicial;
    for(int i = 0; i < tamanho; i++){
        resultado -= valores[i];
    }
    adicionarAoHistorico("Subtração (Multiplos Valores.)", 0, 0, resultado);
    return resultado;
}
// Divisão
double funcaoDivisao (double pn, double sn) {
            
                resultado = pn / sn;

				adicionarAoHistorico("Divisão.", pn, sn, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
				
            
            return resultado;
}
// Exponenciação
double funcaoExponenciacao (double pn, double sn) {
            resultado = pow(pn, sn);

			adicionarAoHistorico("Exponenciação.", pn, sn, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;
			
}
// Modulo resto da divisão
double funcaoResto (double pn, double sn) {
            resultado = fmod(pn, sn);

			adicionarAoHistorico("Modulo resto da divisão.", pn, sn, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!

            return resultado;

}
// Porcentagem
double funcaoPorcentagem (double pn, double sn) {
            resultado = (pn / 100.0) * sn;

			adicionarAoHistorico("Porcentagem.", pn, sn, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!

            return resultado;

}
// Hipotenusa
double funcaoHip (double pn, double sn) {
            resultado = hypot(pn, sn);

			adicionarAoHistorico("Hipotenusa.", pn, sn, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!

            return resultado;

}
// Raiz quadrada
double funcaoSQRT (double pn) {
            resultado = sqrt(pn);

			adicionarAoHistorico("Raiz quadrada.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!

            return resultado;

}
// Raiz cubica
double funcaoCBRT (double pn) {
            resultado = cbrt(pn);

			adicionarAoHistorico("Raiz cubica.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!

            return resultado;

}
// Seno
double funcaoSin (double pn) {
            double radianos = pn * (pi / 180.0);	                 //Equação para transformar graus em radianos, já que ele só aceita radianos.
            resultado = sin(radianos);

			adicionarAoHistorico("Seno.", pn, 0, resultado);        //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;
			
		}
// Cosseno
double funcaoCos (double pn) {
            double radianos = pn * (pi / 180.0);
            resultado = cos(radianos);

			adicionarAoHistorico("Cosseno.", pn, 0, resultado);    //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;
			
		}

// Tangente
double funcaoRad (double pn) {
            double radianos = pn * (pi / 180.0);
            resultado = tan(radianos);

			adicionarAoHistorico("Tangente.", pn, 0, resultado);   //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;
			
		}

// Arcseno
double funcaoASin (double pn) {
            resultado = asin(pn) * (180.0 / pi);

			adicionarAoHistorico("Arcseno.", pn, 0, resultado);   //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;
	
}
// Arccosseno
double funcaoACos (double pn) {
            resultado = acos(pn) * (180.0 / pi);

			adicionarAoHistorico("Arccosseno.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;

}
// Arctangente
double funcaoATan (double pn) {
            resultado = atan(pn) * (180.0 / pi);

			adicionarAoHistorico("Arctangente.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;
			
}
// Logaritmo na base 10
double funcaoLog10 (double pn) {
            resultado = log10(pn);

			adicionarAoHistorico("Logaritmo na base 10.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;
	
}
// Logaritmo natural
double funcaoLog (double pn) {
            resultado = log(pn);

			adicionarAoHistorico("Logaritmo natural.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;

}
// Fatorial
double funcaoFat (double pn) {
            resultado = 1;
                for (int i = 1; i <= (int)pn; i++) {
                    resultado *= i;
                }

				adicionarAoHistorico("funcaoFat.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
				
				return resultado;

}
// Radianos para Graus
double funcaoRTD (double pn) {
            resultado = pn * (180.0 / pi);

			adicionarAoHistorico("Radianos para Graus.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;

}
// Arredondar para baixo
double funcaoArrPB (double pn) {
            resultado = floor(pn);

			adicionarAoHistorico("Arredondar para baixo.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;

}
// Arredondar 
double funcaoArrPC (double pn) {
            resultado = ceil(pn);

			adicionarAoHistorico("Arredondar.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;

}
// Graus para radianos
double funcaoDTR (double pn) {
            resultado = pn * (pi / 180.0);
            

			adicionarAoHistorico("Graus para radianos.", pn, 0, resultado);  //---------------------------------------Leo!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
			return resultado;

}
// Teorema de Pitagoras ;; Cada passo da equação foi feito para cada possível icognita.
double funcaoPit (double pn, double sn, double tn) {
			    if (pn == 0) {
				pn = (sn * sn) + (tn * tn);		
				resultado = sqrt(pn);
				printf("\nResultado: %g\n", resultado);
				return resultado;
			} else if (sn == 0) {
				pcima1 = (tn * tn);
				pbaixo = (pn * pn);
				pcima2 = pbaixo - pcima1;
				resultado = sqrt(pcima2);
				printf("\nResultado: %g\n", resultado);
				return resultado;
			} else if (tn == 0) {
			double *array; // O array para as funções, soma, subtração e multiplicação.
		int tamanho;  // variavel auxiliar para as funções que usam array. 
		
			printf("Digite o total de números que vai querer somar: ");		// O tamanho do array é pedido
			scanf("%d", &tamanho);
			{
			acao = 0;
			}
			array = (double *) malloc(tamanho * sizeof(double));		// O tamanho do array e passado para o array em si.
			
			printf("Digite %d elementos:\n", tamanho);		// Um aviso é dado dizendo para digitar os valores.
			for (int i = 0; i < tamanho; i++) {				//laço "for" é feito para para a conta acontecer. 
			printf("Elemento %d: ", i + 1);					// O pedido dos números é feito.
			scanf("%d", &array[i]);							// O número é colocado no espaço da vez do array.
			acao += array[i]; 								// acha é somando com o valor do espaço do array da vez e o resultado é passado para acao.
			}
			
			printf("\nResultado: %g\n", acao);				// O resultado é dado, sendo ele o valor de achao.
			adicionarAoHistorico("Pitagoras (Multiplos Números)", 0, 0, resultado);
			free(array);	pcima1 = (sn * sn);
				pbaixo = (pn * pn);
				pcima2 = pbaixo - pcima1;
				resultado = sqrt(pcima2);
				printf("\nResultado: %g\n", resultado);
				return resultado;
			}
}
// Equação de segundo grau usando baskara, tem tratamento de erro para cada possível delta.
double funcaoBhaskara (double pn, double sn, double tn) {
			delta = pow(sn, 2) - (4 * (pn * tn));
			if (delta > 0) {
				pcima1 = -sn + sqrt(delta);
				pcima2 = -sn - sqrt(delta);
				pbaixo = 2 * pn;
				resultado = pcima1 / pbaixo;
				resultado2 = pcima2 / pbaixo;
				printf("\nPrimeiro Resultado %.2lf \n", resultado);
				printf("Segundo Resultado %.2lf\n", resultado2);
				adicionarAoHistorico("Bhaskara (Multiplos Números)", 0, 0, resultado2);
			} else if (delta == 0) {
			resultado = -sn / (2 * pn);
        
			printf("A equacao possui uma unica raiz real:\n");
			printf("x = %.2lf\n", resultado);
			adicionarAoHistorico("Bhaskara (Multiplos Números)", 0, 0, resultado);	
			} else if (delta < 0) {
			printf("Delta negativo.\n");
			printf("A raiz não está nos números reais.\n");
			adicionarAoHistorico("Bhaskara (Multiplos Números)", 0, 0, resultado);	
			}
			return resultado;
}

void lerMatriz3x3(double matriz[3][3]) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }
}

void imprimirMatriz3x3(const double matriz[3][3]) {
    printf("\n--- Matriz Resultado ---\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            // "%8.2lf" formata o número para ter 8 caracteres de largura
            // com 2 casas decimais, alinhando a matriz visualmente.
            printf("%8.2lf ", matriz[i][j]);
        }
        printf("|\n");
    }
}

void somarMatrizes3x3(const double a[3][3], const double b[3][3], double resultado[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = a[i][j] + b[i][j];
        }
        adicionarAoHistorico("Soma de Matrizes 3x3", 0, 0, 0);
    }
}
    
void multiplicarMatrizes3x3(const double a[3][3], const double b[3][3], double resultado[3][3]) {
   
    for (int i = 0; i < 3; i++) {       
        for (int j = 0; j < 3; j++) {    
            resultado[i][j] = 0; 
            for (int k = 0; k < 3; k++) { 
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    adicionarAoHistorico("Multiplicação de Matrizes 3x3 (Multiplos valores)", 0, 0, 0);
}



void carregarHistoricoDoArquivo(){
    FILE *arquivo = fopen("historico.csv", "r");
    
    if (arquivo == NULL){
        return;
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), arquivo);
    
    while(fgets(buffer, sizeof(buffer), arquivo)){
        sscanf(buffer, "%d, %[^,], %lg, %lg, %lg",
        &historicoArray[numeroDeOperacoes].id,
        historicoArray[numeroDeOperacoes].tipo,
        &historicoArray[numeroDeOperacoes].a,
        &historicoArray[numeroDeOperacoes].b,
        &historicoArray[numeroDeOperacoes].resultado);
        
        for(int j = 0; historicoArray[numeroDeOperacoes].tipo[j] != '\0'; j++)
            if(historicoArray[numeroDeOperacoes].tipo[j]=='-'){
                historicoArray[numeroDeOperacoes].tipo[j]=' ';
            }
    
    
    numeroDeOperacoes++;
    if(numeroDeOperacoes>=MAXHISTORICO){
        break;
    }
    
    }
    fclose(arquivo);
}

int main() {
    int escolha, t;
	int continuar = 1;
	
	double pnumero, snumero, tnumero;
	double resultado, resultado2;

    carregarHistoricoDoArquivo();

    do{  // inicio do loop, se continuar igual 1 ele reinicia.
    
        printf("\n===========================================================================\n");
        printf("                          CALCULADORA CIENTIFICA\n");
        printf("===========================================================================\n\n");
        printf("  [ 1] Adicao            [ 2] Subtracao            [ 3] Multiplicacao\n");
        printf("  [ 4] Divisao           [ 5] Exponenciacao        [ 6] Resto\n");
        printf("  [ 7] Porcentagem       [ 8] Hipotenusa           [ 9] Raiz Quadrada\n");
        printf("  [10] Raiz Cubica       [11] Seno                 [12] Cosseno\n");
        printf("  [13] Tangente          [14] Arcseno              [15] Arccosseno\n");
        printf("  [16] Arctangente       [17] Logaritmo base 10    [18] Logaritmo Natural\n");
        printf("  [19] Fatorial          [20] Radianos para Graus  [21] Arredondar p Baixo\n");
        printf("  [22] Arredondar p Cima [23] Graus para Radianos  [24] Teorema de Pitagoras\n");
        printf("  [25] Bhaskara          [26] Soma de Matrizes(3x3)[27] Mult. de Matrizes(3x3) \n\n");
        printf("===========================================================================\n\n");
		printf("  [0] Histórico\n\n");
		printf("===========================================================================\n\n");


        printf("Digite o numero da operacao desejada: ");
        scanf("%d", &escolha);
        
        if(escolha >=4 && escolha <= 8|| escolha == 24){
            printf("Digite o 1° numero: \n");
            scanf("%lf", &pnumero);
            printf("Digite o 2° número: \n");
            scanf("%lf", &snumero);
            if (escolha == 24 || escolha == 25){
                printf("Digite o 3° número: \n");
                scanf("%lf", &tnumero);
            }
        }else if((escolha >= 9 && escolha <= 23) && escolha != 24){
            printf("Digite o número: \n");
            scanf("%lf", &pnumero);
        }
        
        switch (escolha) {// Switch case usado para escolha das funções.
            case 0:
            mostrarHistorico();
            break;
            case 1:// Adição
            printf("Digite o total de números a somar: \n");
            scanf("%d", &t);
            
            double *meusNumeros = (double *) malloc(t * sizeof(double));
            
            if(meusNumeros == NULL){
                printf("Erro de alocação.");
                break;
            }
            printf("Digite os %d elementos:\n", t);
            for (int i = 0; i < t; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%lf", &meusNumeros[i]);
            }
            
            resultado = funcaoAdicao(meusNumeros, t);
            printf("Resultado: %g \n", resultado);
            
            free(meusNumeros);
                break;
            case 2: //subtração
            double valorInicial;
            printf("Digite o valor inicial: ");
            scanf("%lf", &valorInicial);
            
            int quantidade;
            printf("Quantos numeros deseja subtrair desse valor? ");  
            scanf("%d", &quantidade);
            
            if(quantidade > 0){
                double *numeros = (double *) malloc(quantidade * sizeof(double));
                
                 if (numeros == NULL) {
            printf("Falha ao alocar memória!\n");
            break; // Sai do case 2
                }
                
            printf("Digite os %d numeros a serem subtraidos:\n", quantidade);
            for (int i = 0; i < quantidade; i++) {
                printf("Subtrair o valor %d: ", i + 1);
                scanf("%lf", &numeros[i]);
            }
            resultado = funcaoSubtracao(valorInicial, numeros, quantidade);
            free(numeros);
            }else{
            resultado = valorInicial;
            }
            printf("\nResultado: %g\n", resultado);
                break;
            case 3:  
            printf("Digite o total de números a multiplicar: \n");
            scanf("%d", &t);
            double *meusNumerosM = (double *) malloc(t * sizeof(double));
            
            if(meusNumerosM == NULL){
                printf("Erro de alocação.");
                break;
            }
            printf("Digite os %d elementos:\n", t);
            for (int i = 0; i < t; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%lf", &meusNumerosM[i]);
            }
            
            resultado = funcaoMultiplicacao1(meusNumerosM, t);
            printf("Resultado: %g \n", resultado);
                break;
            case 4:
            if (snumero != 0){
                resultado = funcaoDivisao(pnumero, snumero);
                printf("\n Resultado: %g \n", resultado);
            }else{
                printf("\nNão é possível dividir por 0!\n");
            }
                break;
            case 5:
			resultado = funcaoExponenciacao(pnumero, snumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 6:
			resultado = funcaoResto(pnumero, snumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 7:
			resultado = funcaoPorcentagem(pnumero, snumero);
            printf("\nResultado: %g \n", resultado);    
                break;
            case 8:
			resultado = funcaoHip(pnumero, snumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 9:
			resultado = funcaoSQRT(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 10:
			resultado = funcaoCBRT(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 11:
			resultado = funcaoSin(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 12:
			resultado = funcaoCos(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 13:
			resultado = funcaoRad(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 14:
			resultado = funcaoASin(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 15:
			resultado = funcaoACos(pnumero);
            printf("\nResultado: %g \n", resultado);    
                break;
            case 16:
			resultado = funcaoATan(pnumero);
            printf("\nResultado: %g \n", resultado);    
                break;
            case 17:
			resultado = funcaoLog10(pnumero);
            printf("\nResultado: %g \n", resultado);    
                break;
            case 18:
			resultado = funcaoLog(pnumero);
            printf("\nResultado: %g \n", resultado);    
                break;
            case 19:
			resultado = funcaoFat(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 20:
			resultado = funcaoDTR(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 21:
			resultado = funcaoArrPB(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 22:
			resultado = funcaoArrPC(pnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 23:
			resultado = funcaoRTD(pnumero);
            printf("\nResultado: %g \n", resultado);    
                break;
            case 24:
			resultado = funcaoPit(pnumero, snumero, tnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 25:
			resultado = funcaoBhaskara(pnumero, snumero, tnumero);
			printf("\nResultado: %g \n", resultado);
                break;
            case 26:{
            double matrizA[3][3];
            double matrizB[3][3];
            double matrizResultado[3][3];
        
            printf("\n--- Lendo a Primeira Matriz ---\n");
            lerMatriz3x3(matrizA);
        
            printf("\n--- Lendo a Segunda Matriz ---\n");
            lerMatriz3x3(matrizB);
        
            somarMatrizes3x3(matrizA, matrizB, matrizResultado);
        
            imprimirMatriz3x3(matrizResultado);
            }
            break;
            case 27:{
            double matrizA[3][3];
            double matrizB[3][3];
            double matrizResultado[3][3];
        
            printf("\n--- Lendo a Primeira Matriz (A) ---\n");
            lerMatriz3x3(matrizA);
        
            printf("\n--- Lendo a Segunda Matriz (B) ---\n");
            lerMatriz3x3(matrizB);
        
            multiplicarMatrizes3x3(matrizA, matrizB, matrizResultado);
        
            printf("\nResultado de A * B:");
            imprimirMatriz3x3(matrizResultado);
            }
            break;
            default:
                printf("\nOperação invalida.\n");
                break; 
        } // Fim do switch
    
        printf("\n Continuar Calculando?\n 1 para sim \n 2 para não \n Resposta: ");  // parte do loop while, onde o valor de continuar e dado.
        scanf("%d", &continuar);
    
    }while(continuar <= 1); // Fim do while
    

}
