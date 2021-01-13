// Aluno: Bruno Soares Vasques
// Ex 10.6
/* Fa�a um algoritmo que calcule o imposto de renda de um grupo de contribuintes considerando os dados de cada contribuinte:
n�mero do CPF, n�mero de dependentes e renda mensal (valores fornecidos pelo usu�rio). Para cada contribuinte ser� feito um desconto
de 5% de sal�rio m�nimo por dependente. Os valores da al�quota para calculo do imposto s�o:
- at� 2 sal min(exclusive) = isento
- 2..3(inclusive,inclusive) = 5%
- 3..5(exclusive,inclusive) = 10%
- 5..7(exclusive,inclusive) = 15%
- acima de 7 = 20%
O �ltimo valor( para encerrar o programa e que n�o ser� considerado) ter� CPF igual a zero. 
Deve ser lido o valor atual do sal�rio m�nimo. (13/11/2020 = R$ 1.045,00) */

#include <stdio.h>
#include <locale.h>
#include <string.h>

float imposto(float salario) {
	
	float imposto;
	
	if (salario >= 0 && salario < 2090)
		printf("Isento!\n");
	else if (salario >= 2090 && salario <= 3135){
		imposto = (salario - 2090) * 0.05;
		printf("Total a pagar de imposto de renda: R$ %.2f\n", imposto); 
	}
	else if (salario > 3135 && salario <= 5225){
		imposto = ((salario - 3135) * 0.10) + 156.75;
		printf("Total a pagar de imposto de renda: R$ %.2f\n", imposto);
	}
	else if (salario > 5225 && salario <= 7315){
		imposto = ((salario - 5225) * 0.15) + 522.50;
		printf("Total a pagar de imposto de renda: R$ %.2f\n", imposto);
	}
	else {
		imposto = ((salario - 7315) * 0.20) + 1097.25;
		printf("Total a pagar de imposto de renda: R$ %.2f\n", imposto);
	}
	
	
}
float desconto (int dep, float renda) {
	
	float totaldesconto, desconto;
	
	totaldesconto = dep * 0.05;
	desconto = renda * totaldesconto;
	
	return desconto;
}

int main (){
	
	int cpf, dependentes;
	float novosalario, renda, desc;
	setlocale(LC_ALL, "Portuguese");
	
	
	printf("::::::: Para sair: digite 0\n:::Para continuar: digite o CPF (apenas os n�meros):\n");
	scanf("%d", &cpf);
	printf("Digite o n�mero de dependentes: ");
	scanf("%d", &dependentes);
	printf("Digite sua renda mensal: R$ ");
	scanf("%f", &renda);
	
	desc = desconto(dependentes, renda);
	novosalario = renda - desc;
	printf("Total de desconto por dependetes: R$ %.2f\n", desc);
	printf("Sal�rio atualizado com os descontos: R$ %.2f\n", novosalario);
	
	imposto(novosalario);
	
	return 0;
		
}
