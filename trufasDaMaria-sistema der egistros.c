//////////////////////////////////////////////////////////////////////////
///////     TRABALHO PROGRAMA��O PARA RESOLU��O DE PROBLEMAS      ///////
//////             ALUNOS:   Bruno Soares Vasques				 ///////
/////     		           Lucas Zatt							///////	
////			          Maria Grasieli                       ///////
///															  ///////
// 			          DATA: Dezembro/2020				     ///////
///////////////////////////////////////////////////////////////////

// Fun�� do programa: Sistema de registro de clientes e pedidos para loja de trufas



 //bibliotecas
 
#include <stdio.h>                            
#include <stdlib.h>		                   
#include <string.h>	  	                    
#include <locale.h>                        
#include <conio.h> 
                         

///////////////////////////////////////////////////
//////////   Estrutura dos NODOS   ///////////////              
/////////////////////////////////////////////////

//registro dos sabores das trufas
typedef struct{
	int morango;
	int chocolate;
	int maracuja;
	int nutella;
}SABORES;

 // registro cliente
typedef struct{                             
       char nome[30];						// nome do cliente	(string)						
       int codigo;	         			   // codigo do registro (int)
}INFORMACAO;
       
typedef struct nodo {
	   SABORES sabores;
       INFORMACAO info;     		  // dados do registro
       struct nodo* prox;   		 // ponteiro para o pr�ximo registro
       struct nodo* ant;    	    // ponteiro para o registro anterior
}NODO;


///////////////////////////////////////////////// 
/////////   Defini��o das Fun��es   ////////////
///////////////////////////////////////////////

void  entrada_cliente( NODO* aux );         // l� dados de entrada
void  cria_lista     ( NODO** l );         // inicializa lista com NULL
void  inclui_cliente ( NODO** l );        // inclui novo cliente no final da lista
void  exclui_cliente ( NODO** l );       // exclui regitro por c�digo
void  altera_pedido  ( NODO** l );	    // altera dados
void  imprime_pedidos  ( NODO* aux  ); // visualiza lista em tela
void  limpa_lista  ( NODO** l );      // apaga lista e libera mem�ria

int fCabecalho();
int fLinha();
int fRodape(); 

///////////////////////////////////////////////// 
/////////    Programa Principal     ////////////
///////////////////////////////////////////////

int main(void ){							//
    int op;                                // op��o do menu                               
    NODO* l;                              // declara��o da lista, vari�vel do tipo lista = lista de ponteiros
       
    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n            **** TRUFAS DA MARIA  ****                " );
         printf( "\n /---------------------------------------------------/" );
		 printf( "\n               <Sistema de Registro>                  " );
		 printf( "\n /---------------------------------------------------/" );
         printf( "\n [1] Cria lista                                       " );
         printf( "\n [2] Inclui cliente 				                  " );
         printf( "\n [3] Pedido entregue (exclui cliente da lista)        " );
         printf( "\n [4] Altera pedido                                    " );
         printf( "\n [5] Imprime pedidos                                  " );
         printf(" \n [6] Limpa Lista                                      " );
         printf( "\n [0] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         fflush( stdin );         // limpa buffer do teclado
         scanf( "%i", &op );      // guarda a op��o do menu
        
         switch( op ) {
            case 1: // rotina cria lista       
                    cria_lista( &l );
                    break;
                                                    
            case 2: // inclui cliente no final da lista
                    inclui_cliente( &l );
                    break;
          
            case 3: // exclui cliente ap�s o pedido ser entregue
                    exclui_cliente( &l );
                    break;
                
            case 4: // altera pedido do cliente
                    altera_pedido( &l );
                    break;
                  
            case 5: // imprime a lista de todos os pedidos registrados
            		imprime_pedidos ( l );
            		break;
			
			case 6: // limpa a lista e libera mem�ria
                    limpa_lista( &l );
                    break;
                                                                                                                   
			case 0: // t�rmino do programa                                                 
                    exit( 1 );
                    break;
                
            default : 
                    printf( "\n Digite uma op��o!" );
                    break;
        }
        
        printf("\n");
        getchar();       // parada da tela
        system( "cls" ); // limpar tela
     }      
 return 0;
} // fim do programa principal


  ////////////////////////////////////////////////// 
///////////      entrada_cliente ()     ////////////
  ////////////////////////////////////////////////

void entrada_cliente( NODO* aux ){
	  
    
	printf( "\n Digite o nome: " );       // l� nome do cliente como string
    fflush( stdin );      			
    gets(aux->info.nome);

	//declara��o e inicializa��o de vari�veis
	int quant_morango = 0, quant_chocolate = 0, quant_maracuja = 0, quant_nutella = 0;
	aux->sabores.morango = 0;
	aux->sabores.maracuja = 0;
	aux->sabores.nutella = 0;
	aux->sabores.chocolate = 0;

	int op;
	int saida = 0;
	while(saida == 0){
		
		//menu dos sabores
	    printf("\nEscolha o sabor da trufa:\n");
	    printf("[1] - Morango              \n");
	    printf("[2] - Chocolate            \n");
	    printf("[3] - Maracuja             \n");
		printf("[4] - Nutella              \n");
		printf("[5] - Sair                 \n");
		printf("---------------------------\n");
		printf("Opcao: ");
		fflush( stdin );      		
	  	scanf("%d", &op);
		switch(op) 
		{
			case 1:
				printf("\nQuantidade: ");
				fflush(stdin);
				scanf("%d", &quant_morango);		
				aux->sabores.morango = quant_morango;
				printf("\nSabor incluido com sucesso!\n");
				break;
			case 2:
				printf("\nQuantidade: ");
				fflush(stdin);
				scanf("%d", &quant_chocolate);		
				aux->sabores.chocolate = quant_chocolate;
				printf("\nSabor incluido com sucesso!\n");
				break;
			case 3:
				printf("\nQuantidade: ");
				fflush(stdin);
				scanf("%d", &quant_maracuja);		
				aux->sabores.maracuja = quant_maracuja;
				printf("\nSabor incluido com sucesso!\n");
				break;
			case 4:
				printf("\nQuantidade: ");
				fflush(stdin);
				scanf("%d", &quant_nutella);		
				aux->sabores.nutella = quant_nutella;
				printf("\nSabor incluido com sucesso!\n");
				break;
			case 5:
				saida =+ 1;
				break;
			default:
				printf("Digite uma op��o valida.");
				break;			
		}
	fflush( stdin );    
   	}
    
	aux->prox= aux;          // circular, registro aponta para ele mesmo 
    aux->ant = aux;          // circular, registro aponta para ele mesmo 
}



  /////////////////////////////////////////////// 
/////////// 		cria_lista          ////////////
  ///////////////////////////////////////////// 

void cria_lista( NODO** l ){
	 
    *l = NULL ; 	// lista criada, in�cio nao aponta
    printf("\nLista criada com sucesso!");
    Sleep(1000);   // timer para o printf
}


  /////////////////////////////////////////////////// 
///////////        inclui_cliente()       ////////////
  /////////////////////////////////////////////////

void inclui_cliente( NODO** l ){
	int quant_morango = 0, quant_chocolate = 0, quant_maracuja = 0, quant_nutella = 0;
	NODO* no = (NODO *) malloc (sizeof(NODO));  	     	//aloca espa�o de mem�ria para um novo nodo
		if ( no != NULL) {								   //verifica se h� espa�o ou n�o
			entrada_cliente ( no );						  //recebe os dados
			if ( *l == NULL ){							 //verifica se a lista est� vazia
				no->prox = no;							//faz o prox apontar para si mesmo
				no->ant = no;						   //faz o ant apontar para si mesmo
				*l = no;
			}
			else{
				no->ant = (*l)->ant;				//seta o nodo novo antes pra n�o perder informa��es
				no->prox = *l;
				(*l)->ant->prox = no;		      //depois seta os nodos j� existentes
				(*l)->ant = no;				     
			} 								    
		printf("\n <><> Pedido registrado! <><>");
		}
}

  //////////////////////////////////////////////// 
/////////       exclui_cliente()       ////////////
  //////////////////////////////////////////////

void exclui_cliente( NODO** l ){
	int cod; //c�digo informado pelo usu�rio
	if ( *l == NULL){ 						  //verifica se a lista est� vazia (se h� algo para excluir)
		printf("\n Ops. A lista esta vazia.\n");
	}
	else {	
		NODO *p = *l;					   //cria um ponteiro para percorrer a lista 
											
		printf("\nDigite o codigo do cliente que deseja excluir: ");
		fflush(stdin);
		scanf("%d", &cod);				 //l� o c�digo a ser exclu�do
		
					
		if (cod == (*l)->info.codigo) {   	  //verifica se � o primeiro da lista
			if ((*l)->prox == *l) { 	  	 //al�m de verificar se � o primeiro da lista, tem que verificar se � o �NICO da lista
				*l = NULL;					//nesse caso n�o basta realocar os ponteiros ant/prox
				printf("Pedido entregue!");
			}
			else{
				(*l)->prox->ant = (*l)->ant;    //realoca��o dos ponteiros, para que n�o se apontem mais para o nodo exclu�do
				(*l)->ant->prox = p->prox;	  
				*l = p->prox;			      //por ser o primeimro da lista, h� um cuidado especial, j� que deve-se modificar o *l
				free(p);				     //limpa a mem�ria
				printf("Pedido entregue!");
			}
		}
		else {  //n�o sendo o primeiro da lista:

			p = p->prox;			        //o ponteiro p vai sair da primeira posi��o e percorrer a lista
			NODO *inicio = *l;		       //enquanto isso, outro ponteiro marcar� o inicio para o P n�o rodar eternamente, por ser uma lista circular
			while (p != inicio && p->info.codigo != cod) {			
				p = p->prox;		  	 //enquanto isso P passeia at� que chegue ao in�cio ou at� que encontre o c�digo do elemento procurado
			}
			if (p->info.codigo == cod) {     //tendo o P localizado o c�digo:
				p->ant->prox = p->prox;	    //o prox do anterior recebe o prox de P
				p->prox->ant = p->ant;	   //o ant do posterior recebe o ant de P
				free(p);				  //mem�ria esta livre, leve e solta
				printf("Pedido entregue!");
			}
			else {
				printf("\nDesculpe, o codigo que procura nao esta registrado.\n");
			}
		}
	}	
	getchar();
} 

  ////////////////////////////////////////////// 
//////////       altera_pedido()     ////////////
  ////////////////////////////////////////////
 
 void  altera_pedido ( NODO** l ) {
 	if (*l == NULL)					     // verifica se a lista est� vazia
		printf("\nA lista esta vazia!\n"); 
	else {
		int cod;
		printf("Digite o codigo do registro que deseja alterar: ");
		fflush(stdin);
		scanf("%d", &cod);			 // l� o c�digo do nodo a ser alterado
		NODO *p = *l;				// ponteiro que varre a lista
		NODO *fim = (*l)->ant;	   // ponteiro que marca o fim
		while (p != fim && p->info.codigo != cod) {
			p = p->prox;		 // P caminha pela lista at� o final ou at� achar o c�digo
		}
		if (p->info.codigo == cod){
			
			NODO* aux = ( NODO * ) malloc ( sizeof( NODO ));   // cria um nodo auxiliar para guardar informa��es
			printf("\n**  Insira os novos dados  **\n");	  
			entrada_cliente ( aux );							 // alimenta o nodo auxiliar com os novos dados
			p->info = aux->info;							// faz a transfer�ncia dos novos dados pro nodo a ser modificado
			printf("\nDados alterados com sucesso!\n");
			free(aux);									  // libera a mem�ria do nodo auxiliar
		}
		else {
			printf("Codigo nao encontrado!");
		}
	}
	  
  }
  
  ///////////////////////////////////////////////// 
///////////     imprime_pedidos()       ////////////
  ///////////////////////////////////////////////
 
void imprime_pedidos( NODO* aux ){
 
	int i=1;                     			// indica n�mero de registro na lista
    if( aux == NULL )	             	   // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
		
		 fCabecalho ();
		
		 NODO *inicio = aux;		  // ponteiro auxiliar para percorrer a lista
         do{                        
		 		fLinha();
		 		
		 		printf( "%c", 186);
		 	    aux->info.codigo = i;
				printf( "%5d", aux->info.codigo);
		 	    printf( "%c", 186);
		 	    printf( "%-30s", aux->info.nome );
                printf( "%c", 186);                
				printf( "%9d", aux->sabores.morango);
				printf( "%c", 186);
				printf( "%9d", aux->sabores.chocolate);
				printf( "%c", 186);
				printf( "%9d", aux->sabores.maracuja);
                printf( "%c", 186);
                printf( "%9d", aux->sabores.nutella);
                printf( "%c\n", 186);
				aux = aux->prox;   // aponta para o pr�ximo registro da lista
                i++;
         }while( aux != inicio );   
		 
		 fRodape();
    } 
 	getchar();  
}


   /////////////////////////////////////////////// 
///////////      limpa_lista()         ////////////
  //////////////////////////////////////////////
  
void limpa_lista ( NODO* *l ){
	  
	int i = 0;                      		   // indica n�mero de registro na lista
	if( *l == NULL )              	   	      // verifica se lista vazia
        printf( "\n Lista n�o contem dados registrados!" );
	else{
		NODO *aux = *l;        	 	       // ponteiro auxiliar para percorrer a lista
		NODO *inicio = aux;
        do{
		   	*l = aux->prox;   	 // aponta para o pr�ximo registro da lista
		    free( aux );     	// libera mem�ria
		    aux = *l;          // reposiciona ponteiro auxiliar no in�cio  
            i++;
        }while(inicio != *l);
       
    	printf( "\nAguarde. Apagando Registros...", aux->info.codigo);
		Sleep(2000);
		printf("\nPronto!");
        printf("\n\nLista sem registros.");
        *l=NULL;
    } 
	getchar();          
}


   /////////////////////////////////////////////////
///////////// Tabela ASC II - Impress�o /////////////
  ////////////////////////////////////////////////

int fCabecalho () {
	
////  primeira linha	
	
	printf("%c", 201 );  //borda esquerda
	
	int j;
	for(j=0; j<5; j++) //espa�o c�digo  
		printf("%c", 205);
		
	printf("%c", 203);
	
	int i;
	for(i=0; i<30; i++)  // espa�o do nome
		printf("%c", 205);
	
	printf("%c", 203);  
	
	int k;
	for(k=0; k<9; k++)  //espa�o morango  
		printf("%c", 205);
		
	printf("%c", 203);
	
	int l;
	for(l=0; l<9; l++)  //espa�o chocolate  
		printf("%c", 205);
	
	printf("%c", 203);
	
	int m;
	for(m=0; m<9; m++) //espa�o maracuj�  
		printf("%c", 205);
	
	printf("%c", 203);
	
	int n;
	for(n=0; n<9; n++) //espa�o nutella  
		printf("%c", 205);
	
		
	printf("%c\n", 187); //borda direita
	
//// segunda linha
	
	
	printf("%c", 186);
	printf(" Cod ");
	printf("%c", 186);
	printf("             NOME             ");
	printf("%c", 186);
	printf(" Morango ");
	printf("%c", 186);
	printf("Chocolate");
	printf("%c", 186);
	printf("Maracuja ");
	printf("%c", 186);
	printf(" Nutella ");
	printf("%c\n", 186);
	
		
	return 0;
}

int fLinha () {

	
	printf("%c", 204 );  //borda esquerda
	
	int p;
	for(p=0; p<5; p++) //espa�o telefone  
		printf("%c", 205);
	
	printf("%c", 206); 
	
	int o;
	for(o=0; o<30; o++)  // espa�o do nome
		printf("%c", 205);
	
	printf("%c", 206);  
	
	int q;
	for(q=0; q<9; q++)  //espa�o morango  
		printf("%c", 205);
		
	printf("%c", 206);
	
	int r;
	for(r=0; r<9; r++)  //espa�o chocolate  
		printf("%c", 205);
	
	printf("%c", 206);
	
	int s;
	for(s=0; s<9; s++) //espa�o maracuj�  
		printf("%c", 205);
	
	printf("%c", 206);
	
	int t;
	for(t=0; t<9; t++) //espa�o nutella  
		printf("%c", 205);
	
		
	printf("%c\n", 185); //borda direita
	
	
	return 0;
	
}

int fRodape () {
	
	printf("%c", 200 );  //borda esquerda
	
	
	int j;
	for(j=0; j<5; j++)  //espa�o codigo
		printf("%c", 205);
	
	printf("%c", 202);
	
	
	int i;
	for(i=0; i<30; i++)  // espa�o do nome
		printf("%c", 205);
	
	printf("%c", 202);  
	
	int k;
	for(k=0; k<9; k++)  //espa�o morango  
		printf("%c", 205);
		
	printf("%c", 202);
	
	int l;
	for(l=0; l<9; l++)  //espa�o chocolate  
		printf("%c", 205);
	
	printf("%c", 202);
	
	int m;
	for(m=0; m<9; m++) //espa�o maracuj�  
		printf("%c", 205);
	
	printf("%c", 202);
	
	int n;
	for(n=0; n<9; n++) //espa�o nutella  
		printf("%c", 205);
	
		
	printf("%c\n", 188); //borda direita
	
	return 0;
}
