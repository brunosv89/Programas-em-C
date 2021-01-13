/*///////////////////////////////////////// 
//////  Aluno: Bruno Soares Vasques  //////
///////////////////////////////////////////
//////   Calculadora de matrizes  /////////
///////////////////////////////////////////

Exercício 13.1 - Elaborar uma calculadora de matrizes.
Deve ser exibido um menu com as opções:

0 - Sair;
1 - Informar matriz A: usuário informa o número de linhas e de colunas e em seguida informa todos os l x c valores que devem ser salvos na matriz A, ou informa um comando e o sistema gera valores aleatoriamente com a função rand();
2 - Informar matriz B: idem anterior mas com a matriz B;
3 - Imprimir matriz A: percorre todos as linhas e colunas da matriz A e imprime os valores;
4 - Imprimir matriz B: idem com a matriz B
5 - Imprimir matriz C: idem com a matriz C (serve para receber os resultados das operações);
6 - Somar matrizes: faz C = A + B (validar se linhas de A = linhas de B e colunas de A = colunas de B)
7 - Multiplicar matrizes: faz C = A * B (validar se colunas de A = linhas de B)
8 - Matriz oposta: faz C = oposta de A;
9 - Matriz transposta: C = transposta de A;

Todas as operações devem ser feitas em funções que são chamadas na main;
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h> //função rand() e srand()
#include <time.h>   //função time()

// declaração de constantes com tamanho máximo das matrizes

#define MAX_L 50
#define MAX_C 50

// declaração das funções:
int informa_matriz ( int matriz[MAX_L][MAX_C], int linhas, int colunas );
void imprime_matriz (int matriz[MAX_L][MAX_C], int linhas, int colunas);
//int matriz_rand (int matriz[MAX_L][MAX_C], int linhas, int colunas);
int soma( int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc);
int multiplica( int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc);
int oposta (int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc);
int transposta( int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc);


/////////////////////////////////////////////////////////
/////////////////// PROGRAMA PRINCIPAL //////////////////
/////////////////////////////////////////////////////////

int main () {
	
	setlocale (LC_ALL, "Portuguese");
	
	int matriz_a[MAX_L][MAX_C]; // = {matriz_rand( matriz_a, 3, 3)};
	int matriz_b[MAX_L][MAX_C]; // = {matriz_rand( matriz_b, 3, 3)};
	int matriz_c[MAX_L][MAX_C];
	int opcao;
	int la, ca, lb, cb, lc, cc;
	
	while (1){
		printf("------------------------------------\n");
		printf("[1] - Informar matriz A             \n");
		printf("[2] - Informar matriz B             \n");
		printf("[3] - Imprimir matriz A             \n");
		printf("[4] - Imprimir matriz B             \n");
		printf("[5] - Imprimir Resultado            \n");
		printf("[6] - Somar matrizes                \n");
		printf("[7] - Multiplicar matrizes          \n");
		printf("[8] - Matriz oposta                 \n");
		printf("[9] - Matriz transposta             \n");
		printf("[0] - Sair                          \n");
		printf("------------------------------------\n");
		printf("Opção: \n");
		scanf("%d", &opcao);
		switch (opcao){
			case 1:
				fflush(stdin);
				printf("\nInforme o número de linhas: ");
				scanf("%d", &la);
				fflush(stdin);
				printf("\nInforme o número de colunas: ");
				scanf("%d", &ca);
				informa_matriz ( matriz_a, la, ca );
				break;
			case 2:
				fflush(stdin);
				printf("\nInforme o número de linhas: ");
				scanf("%d", &lb);
				fflush(stdin);
				printf("\nInforme o número de colunas: ");
				scanf("%d", &cb);
				informa_matriz ( matriz_b, lb ,cb );
				break;
			case 3:
				imprime_matriz( matriz_a, la, ca );
				break;
			case 4:
				imprime_matriz( matriz_b, lb, cb );
				break;
			case 5:
				imprime_matriz( matriz_c, lc, cc );
				break;
			case 6:
				matriz_c[MAX_L][MAX_C] = soma (matriz_a, matriz_b, matriz_c, la, ca, lb, cb, lc, cc);
				lc = la;
				cc = ca;
				break;
			case 7:
				matriz_c[MAX_L][MAX_C] = multiplica (matriz_a, matriz_b, matriz_c, la, ca, lb, cb, lc, cc);
				lc = la;
				cc = ca;
				break;
			case 8:
				matriz_c[MAX_L][MAX_C] = oposta (matriz_a, matriz_b, matriz_c, la, ca, lb, cb, lc, cc);
				lc = la;
				cc = ca;
				break;
			case 9:
				matriz_c[MAX_L][MAX_C] = transposta (matriz_a, matriz_b, matriz_c, la, ca, lb, cb, lc, cc);
				lc = la;
				cc = ca;
				break;
			case 0:
				exit(1);
			default:
				printf("Digite uma opção válida.\n");
				break;
		}
	
	fflush( stdin ); 
    getchar();
    system("cls");
	printf("\n");
	}
		
	return 0;
}


int informa_matriz ( int matriz[MAX_L][MAX_C], int linhas, int colunas ) {

	int i,j;
	
	for (i=0; i<linhas; i++){
		for (j=0; j<colunas; j++){
			printf("[%d x %d]: ", i+1, j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
		
}


void imprime_matriz(int matriz[MAX_L][MAX_C], int linhas, int colunas){
	
	int i, j;
	for (i=0; i<linhas; i++){
		printf("\n");
		for (j=0; j<colunas; j++){
			printf("\t%d", matriz[i][j]);
		}
	}
	printf("\n");
	
}

int soma( int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc) {
	
	
	if (la == lb && ca == cb) {
		
		int i, j;
		for (i=0; i<la; i++){
			printf("\n");
			for (j=0; j<ca; j++){
				c[i][j] = a[i][j] + b[i][j];
				printf("%d\t", c[i][j]);
			}
		}
	printf("Matrizes somadas com sucesso!");
	}
	else
		printf("Desculpe, só é possível realizar a soma com matrizes de mesma ordem.");
}


int multiplica( int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc){
	
	int i, j;
	if (la == cb){
		
		for (i=0; i<la; i++){
			printf("\n");
			for (j=0; j<ca; j++){
				c[i][j] = a[i][j] * b[j][i];
				printf("%d\t", c[i][j]);
			}
		}
	printf("Matrizes multiplicadas com sucesso!");
	}
	else {
		printf("------------------------- ERRO !! --------------------------\n");
		printf("Desculpa, você só pode multiplicar matrizes se o número de  \n");
		printf("linhas da primeira for igual ao numero de colunas da segunda\n");
		printf("------------------------------------------------------------\n");
	}
}

int oposta (int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc) {
	
	int i,j;

	
	for (i=0; i<la; i++){
		printf("\n");
		for (j=0; j<ca; j++){
			c[i][j] = a[i][j] * -1;
			printf("\t%d", c[i][j]);
		}
	}
	
	printf("Matriz oposta criada com sucesso!");
}


int transposta( int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int la, int ca, int lb, int cb, int lc, int cc) {

	int i,j;
	char op;
	printf("Você deseja ver a transposta da matriz A ou da Matriz B? ");
	fflush(stdin);
	scanf("%c", &op);
	if ( op == 'A' || op == 'a'){
		for (i=0; i<la; i++){
			for (j=0; j<ca ; j++){
				c[i][j] = a[j][i];
			}
		}
		imprime_matriz( c, 3, 3 );
	}
	else if ( op == 'B' || op == 'b'){
		for (i=0; i<lb; i++){
			for (j=0; j<cb ; j++){
				c[i][j] = b[j][i];
			}
		}
		imprime_matriz( c, 3, 3 );
	}
	else
		printf("\nErro! Digite apenas A ou B.\n");

	
}


/*
int matriz_rand (int matriz[MAX_L][MAX_C], int linhas, int colunas) {
	
	int i,j;
	srand(time(NULL));
	
	for (i=0; i<linhas; i++){
		printf("\n");
		for (j=0; j<colunas; j++){
			matriz[i][j] = rand() % 1000;
			printf("%d", matriz[i][j]);
		}
	}
		
	
}
*/

 
