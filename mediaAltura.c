// Aluno: Bruno Soares Vasques
// Ex 10.7
/* Considerando a altura dos N alunos de uma turma faça um algoritmo para calcular a média das alturas e determinar
a quantidade de alunos com altura > 1.60 e < 1.75m. Encerrar leitura com altura menor ou igual a zero */

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main (){
	
	setlocale(LC_ALL, "Portuguese");
	
	float soma=0, altura=0, media=0;
	int contalunos=0, h=0;
	
	while (1){
	
		printf("Informe a altura do aluno: ");
		fflush(stdin);
		scanf("%f", &altura);
		
		if (altura <= 0)
			break;
		else{
			soma = soma + altura;
			contalunos++;
			if (altura >= 1.60 && altura <= 1.75)
				h += 1;
			}	
		
	}
	
	media = soma / contalunos;
	
	printf("Media de altura: %.2f\n", media);
	printf("Quantidade de alunos com altura entre 1,60m e 1,75m: %d\n", h);
	
	return 0;
}
