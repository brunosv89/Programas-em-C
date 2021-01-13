/*
Exercício 7.1: Deselvolver as funções necessárias para o funcionamento do programa.
Observe que estão declarados somente os protótipos
Deve ser desenhado um retângulo usando os caracteres de contorno da tabela ASCII Extendida
https://theasciicode.com.ar/

Dica: a funçao strlen() retorna o comprimento de uma string
*/

#include <stdio.h>
#include <string.h>

void linha_cima(int tam);	//protótipos
void linha_meio(int tam, char conteudo[]);
void linha_baixo(int tam);

int main(){
	
	char nome[35];
	printf("Digite seu nome: ");
	gets(nome);
	int t;	
	t = strlen(nome);
	
	linha_cima(t);
	linha_meio(t, nome);
	linha_baixo(t);
	return 0;
}

//implementação da função
void linha_cima(int tam){
	printf("%c", 201);  //canto superior esquerdo
	
	//repetição para imprimir todos os caracteres de linha
	int i;
	for(i<0; i<tam; i++)
		printf("%c", 205);
	
	printf("%c\n", 187);  //canto superior direito
}

void linha_meio(int tam, char nome[]) {
	printf("%c", 186);
	printf("%s", nome);
	printf("%c\n", 186);
	
}


void linha_baixo(int tam){
	printf("%c", 200);  //canto superior esquerdo
	
	//repetição para imprimir todos os caracteres de linha
	int i;
	for(i<0; i<tam; i++)
		printf("%c", 205);
	
	printf("%c\n", 188);  //canto superior direito
}
