// Aluno: Bruno Soares Vasques
// Ex 10.5
/* Faça um algoritmo que escreve a tabuada até 10 dos dez primeiros números inteiros positivos permitindo a repetição do
cálculo para novo número após ler “S” ou “N” como resposta para: Escrever nova tabuada(S/N)? */

#include <stdio.h>
#include <locale.h>
#include <string.h>

int tabuada(int n) {
	
	int i;
	for (i = 0; i <= 10; i++){
		printf("%d x %d = %d\n", n, i, n*i);
	}
		
}

int main (){
	
	setlocale(LC_ALL, "Portuguese");
	int n;
	char resposta;
	
	do {
	
		printf("Digite um número inteiro: ");
		scanf("%d", &n);
		tabuada(n);	
		
		printf("Escrever nova tabuada? [S/N]: ");
		fflush(stdin);
		scanf("%c", &resposta);
		
	} while (resposta == 'S' || resposta == 's');	 
		
	return 0;
}
