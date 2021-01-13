////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Programa em C desenvolvido na cadeira de Programação para Resolução de Problemas - UNISC/2020   ////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////  PROVA 1    ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Questão Prática: Uma   indústria   de implementos   agrícolas   convidou   você   para desenvolver  um  programa  para  gerenciar o  consumo  de  energia  elétrica  da  fábrica,
// sendo  que  a  mesma está  caminhando  para  o  conceito  de indústria  4.0  de  forma  que todos as  tomadas de  energia  que  alimentam  as  máquinasestão  sendo  monitoradas
// constantementepor meio de uma rede de sensores.Seu  programa recebe  um  vetor  referente aos 10 pontos  de  energiadisponíveis,  com cada posição indicando o consumo da máquina
// ligada naquele ponto.
// Por exemplo: int vet[] = {58, 44, 15, 0, 8, 0, 10, 20, 30, 0};  //unidades em MWh

/* 

Funcionalidades:
 • Ao abrir o programa o sistema imprimea atual potência instalada (soma de todas as tomadas);
 • Depois o usuário informa a potência da nova máquina a ser ligada;
 • O sistema busca uma tomada que não esteja em uso (potência igual a zero);
 	o Se encontrar, a nova máquina deve ser alocada nessa tomada;
 	o Caso contrário pedir para o usuário qual máquina deve ser substituída e alocar a nova máquina nessa posição;
 • Ao  final  o  programa imprime  a  nova  capacidade instalada e a  lista de todas  as tomadas (posição e potência)

*/



//::::::::::: inclusão das bibliotecas :::::::://

#include <stdio.h>
#include <locale.h>

//::::::::::: declaração das funções :::::::::://

int soma_potencias ( int vet[] );
int alocar_maquina ( int vet[], int potencia );

////::::::::::::::::::::::::::::::::::::::::::://
///:::::::::::: programa principal::::::::::::://
///:::::::::::::::::::::::::::::::::::::::::::://

int main () {
	
	setlocale(LC_ALL, "Portuguese");  //permite o uso de acentos através da biblioteca <locale.h>
	
	// VETORES PARA TESTE:
	// int vet[] = {15, 9, 89, 22, 10, 63, 0, 10, 32, 8};
	// int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int vet[] = {58, 44, 15, 0, 8, 0, 10, 20, 30, 0}; //caso de testes sugerido no enunciado
	
	int vet[] = {42, 13, 15, 70, 8, 4, 10, 20, 30, 50};  //caso de teste do exemplo
	int soma;
	
	soma = soma_potencias (vet);	//chamamento da função para somar a potência total
	printf("A potência instalada é: %d MWh", soma);
	
	int potencia;
	printf("\nInforme a potência (em MWh) da nova máquina a ser instalada: ");
	scanf("%d", &potencia);         //leitura da nova potência informada pelo usuário
	
	
	alocar_maquina ( vet, potencia );  //chamamento da função para alocar a nova potência no lugar vago ou no lugar a ser substituido
	
	
	soma = soma_potencias (vet);  //novamente o chamamento da função para somar as potências, agora atualizada
	printf("\nA nova potência instalada é: %d MWh", soma);
	
	return 0;
}

//:::: função para somar o total das potências::://

int soma_potencias ( int vet[] ) {
	
	int soma, i;    			//declaração das variáveis
	for (i=0; i < 10; i++) {	//varre a lista da posição 0 até a 9
		soma = soma + vet[i];   //a cada looping soma os valores do vetor à variavel soma
		
	}
	
	return soma;				//retorna o valor total
	
}

//::::::::: função para alocar potência  ::::::://

int alocar_maquina ( int vet[], int potencia ) {
	
	int verificador, i, posicao;  
	for (i=0; i < 10; i++){		   //através do verificador identifica se há alguma tomada livre
		if (vet[i] == 0)		   //isto é, se o vetor na posição do contador é igual a zero
			verificador += 1;	   //se sim, o verificador recebe um valor
		}
	
	if (verificador == 0) {		   //deste modo, se o verificador estiver com valor 0, é porquê não há nenhuma tomada livre
	
		printf("Nenhuma tomada livre, informe a posição (de 0 a 9) da tomada que deseja substituir: ");
		scanf("%d", &posicao);    //portanto é preciso escolher uma tomada para ser substituida
		vet[posicao] = potencia;  //atribuindo à posição escolhida pelo usuário a potencia anteriormente informada
	}
	else {
		int cont;				  //caso o verificador contenha algum valor diferente de zero, é pq há tomadas vazia
		for (cont=0; cont < 10; cont++){
			if (vet[cont] == 0){
				vet[cont] = potencia;		//neste caso é mais simples, basta atribuir a potência informada pelo usuário na posição que estiver vazia
				break;	 //o break impede que o programa continue preenchendo as outras tomada vazias com a potencia (se houver)
			}
		}	
	}
	
	printf("LISTAGEM DAS TOMADAS:");    //lista atualizada com as tomadas e seus respectivos valores
		for(i=0; i <10; i++){
			printf("\nPosição: %d  Carga: %d", i, vet[i]);
		}
	
	return 0;  //ja retorna a lista pronta pra main
		
	} 
	
	
