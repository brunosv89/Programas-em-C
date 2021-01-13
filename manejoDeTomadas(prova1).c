////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Programa em C desenvolvido na cadeira de Programa��o para Resolu��o de Problemas - UNISC/2020   ////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////  PROVA 1    ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Quest�o Pr�tica: Uma   ind�stria   de implementos   agr�colas   convidou   voc�   para desenvolver  um  programa  para  gerenciar o  consumo  de  energia  el�trica  da  f�brica,
// sendo  que  a  mesma est�  caminhando  para  o  conceito  de ind�stria  4.0  de  forma  que todos as  tomadas de  energia  que  alimentam  as  m�quinasest�o  sendo  monitoradas
// constantementepor meio de uma rede de sensores.Seu  programa recebe  um  vetor  referente aos 10 pontos  de  energiadispon�veis,  com cada posi��o indicando o consumo da m�quina
// ligada naquele ponto.
// Por exemplo: int vet[] = {58, 44, 15, 0, 8, 0, 10, 20, 30, 0};  //unidades em MWh

/* 

Funcionalidades:
 � Ao abrir o programa o sistema imprimea atual pot�ncia instalada (soma de todas as tomadas);
 � Depois o usu�rio informa a pot�ncia da nova m�quina a ser ligada;
 � O sistema busca uma tomada que n�o esteja em uso (pot�ncia igual a zero);
 	o Se encontrar, a nova m�quina deve ser alocada nessa tomada;
 	o Caso contr�rio pedir para o usu�rio qual m�quina deve ser substitu�da e alocar a nova m�quina nessa posi��o;
 � Ao  final  o  programa imprime  a  nova  capacidade instalada e a  lista de todas  as tomadas (posi��o e pot�ncia)

*/



//::::::::::: inclus�o das bibliotecas :::::::://

#include <stdio.h>
#include <locale.h>

//::::::::::: declara��o das fun��es :::::::::://

int soma_potencias ( int vet[] );
int alocar_maquina ( int vet[], int potencia );

////::::::::::::::::::::::::::::::::::::::::::://
///:::::::::::: programa principal::::::::::::://
///:::::::::::::::::::::::::::::::::::::::::::://

int main () {
	
	setlocale(LC_ALL, "Portuguese");  //permite o uso de acentos atrav�s da biblioteca <locale.h>
	
	// VETORES PARA TESTE:
	// int vet[] = {15, 9, 89, 22, 10, 63, 0, 10, 32, 8};
	// int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int vet[] = {58, 44, 15, 0, 8, 0, 10, 20, 30, 0}; //caso de testes sugerido no enunciado
	
	int vet[] = {42, 13, 15, 70, 8, 4, 10, 20, 30, 50};  //caso de teste do exemplo
	int soma;
	
	soma = soma_potencias (vet);	//chamamento da fun��o para somar a pot�ncia total
	printf("A pot�ncia instalada �: %d MWh", soma);
	
	int potencia;
	printf("\nInforme a pot�ncia (em MWh) da nova m�quina a ser instalada: ");
	scanf("%d", &potencia);         //leitura da nova pot�ncia informada pelo usu�rio
	
	
	alocar_maquina ( vet, potencia );  //chamamento da fun��o para alocar a nova pot�ncia no lugar vago ou no lugar a ser substituido
	
	
	soma = soma_potencias (vet);  //novamente o chamamento da fun��o para somar as pot�ncias, agora atualizada
	printf("\nA nova pot�ncia instalada �: %d MWh", soma);
	
	return 0;
}

//:::: fun��o para somar o total das pot�ncias::://

int soma_potencias ( int vet[] ) {
	
	int soma, i;    			//declara��o das vari�veis
	for (i=0; i < 10; i++) {	//varre a lista da posi��o 0 at� a 9
		soma = soma + vet[i];   //a cada looping soma os valores do vetor � variavel soma
		
	}
	
	return soma;				//retorna o valor total
	
}

//::::::::: fun��o para alocar pot�ncia  ::::::://

int alocar_maquina ( int vet[], int potencia ) {
	
	int verificador, i, posicao;  
	for (i=0; i < 10; i++){		   //atrav�s do verificador identifica se h� alguma tomada livre
		if (vet[i] == 0)		   //isto �, se o vetor na posi��o do contador � igual a zero
			verificador += 1;	   //se sim, o verificador recebe um valor
		}
	
	if (verificador == 0) {		   //deste modo, se o verificador estiver com valor 0, � porqu� n�o h� nenhuma tomada livre
	
		printf("Nenhuma tomada livre, informe a posi��o (de 0 a 9) da tomada que deseja substituir: ");
		scanf("%d", &posicao);    //portanto � preciso escolher uma tomada para ser substituida
		vet[posicao] = potencia;  //atribuindo � posi��o escolhida pelo usu�rio a potencia anteriormente informada
	}
	else {
		int cont;				  //caso o verificador contenha algum valor diferente de zero, � pq h� tomadas vazia
		for (cont=0; cont < 10; cont++){
			if (vet[cont] == 0){
				vet[cont] = potencia;		//neste caso � mais simples, basta atribuir a pot�ncia informada pelo usu�rio na posi��o que estiver vazia
				break;	 //o break impede que o programa continue preenchendo as outras tomada vazias com a potencia (se houver)
			}
		}	
	}
	
	printf("LISTAGEM DAS TOMADAS:");    //lista atualizada com as tomadas e seus respectivos valores
		for(i=0; i <10; i++){
			printf("\nPosi��o: %d  Carga: %d", i, vet[i]);
		}
	
	return 0;  //ja retorna a lista pronta pra main
		
	} 
	
	
