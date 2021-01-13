//////////////////////////////////////////////////////////////////
///////     ATIVIDADE DE LISTAS DUPLAMENTE ENCADEADAS     ///////
//////     Disciplina: Estrutura de dados e programa��o  ///////
/////     		Aluno: Bruno Soares Vasques				///////							
//// 				Data: Outubro/2020				   ///////
/////////////////////////////////////////////////////////////

 
#include <stdio.h>                            // entrada e sa�da padr�o: printf, scanf
#include <stdlib.h>		                      // exit, malloc, system
#include <string.h>	  	                      // strcmp
#include <locale.h>                           // setlocale
#include <conio.h>                            // getch

#include "MODELODUPLA.h"                      // modelo de dados
#include "GERA_DADOSCIRCULAR.h"               // gera dados para povoar lista de forma autom�tica 


///////////////////////////////////////////////// 
/////////   Defini��o das Fun��es   ////////////
///////////////////////////////////////////////
void  entrada_dados  ( NODO* aux );         // l� dados de entrada
void  imprime_lista  ( NODO* l );          // visualiza lista em tela
void  cria_lista     ( NODO** l );        // inicializa lista com NULL
void  inclui_fim     ( NODO** l );       // inclui novo registro no final da lista
void  inclui_inicio  ( NODO** l );      // inclui novo registro no in�cio da lista
void  exclui_nodo    ( NODO** l );     // exclui regitro por c�digo
void  ordena_lista   ( NODO** l ); 	  // ordena lista por c�digo
void  altera_dados   ( NODO** l );	 // altera dados
void  consulta       ( NODO** l );	// consulta os registros
void  destroi_lista  ( NODO* *l ); // apaga lista e libera mem�ria
       
///////////////////////////////////////////////// 
/////////    Programa Principal     ////////////
/////////////////////////////////////////////// 
int main( void ){							//
    int op;                                // op��o do menu                               
    NODO* l;                              // declara��o da lista, vari�vel do tipo lista = lista de ponteiros
    setlocale(LC_ALL, "Portuguese");     // alterar idioma para portugu�s      

    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registro - Menu                          " );
         printf( "\n [1] Cria lista                                       " );
         printf( "\n [2] Inclui registro no final da lista                " );
         printf( "\n [3] Inclui registro no in�cio da lista               " );
         printf( "\n [4] Exclui registro pot c�digo                       " );
         printf( "\n [5] Consulta Registro por Nome                       " );
         printf( "\n [6] Altera Registro por c�digo                       " );
         printf( "\n [7] Ordena lista                                     " );                           
         printf( "\n [8] Gera dados                                       " );
		 printf( "\n [9] Imprime lista                                    " );
		 printf( "\n [10] Destr�i lista e libera mem�ria                   ");
         printf( "\n [0] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Op��o: " );
         fflush( stdin );         // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op );     // tecla de op��o do menu

         switch( op ) {
            case 1: // rotina cria lista       
                    cria_lista( &l );
                    break;
                                                    
            case 2: // rotina inclui registro no final da lista
                    inclui_fim( &l );    
                    break;
          
            case 3: // rotina inclui registro no in�cio da lista
                    inclui_inicio( &l );
                    break;                     
                
            case 4: // rotina exclui registro da lista
                    exclui_nodo( &l );
                    break;
                  
            case 5: //rotina consulta registro
            		consulta ( &l );
            		break;
			
			case 6: //rotina para alterar dados
					altera_dados( &l);
					break;
					
			case 7: // rotina ordena lista
                    ordena_lista( &l ); 
                    break;
                                                                                                                   
            case 8: // rotina imprime lista                 
                    gera_dados( &l ); 
                    break;

            case 9: // rotina imprime lista                 
                    imprime_lista( l ); 
                    break;
					                                
            case 10: // rotina destr�i lista
            		destroi_lista( &l );
            		break;
            		
			case 0: // t�rmino do programa                                                 
                    exit( 1 ); 
                    break;
                
            default : 
                    printf( "\n Digite uma op��o!" );
                    break;
        } // fim switch( op )
        
        printf("\n");
        getchar();       // parada da tela
        system( "cls" ); // limpar tela
     } // fim do while( 1 )     
 return 0;
} // fim do programa principal


///////////////////////////////////////////////// 
/////////      entrada_dados ()     ////////////
///////////////////////////////////////////////

void entrada_dados( NODO* aux ){
	  
    printf( "\n\n Digite o c�digo: " ); 
    fflush( stdin );      			// limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.codigo);

    printf( "\n Digite o nome: " );
    fflush( stdin );      		// limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );
  
    aux->prox= aux;          // circular, registro aponta para ele mesmo 
    aux->ant = aux;         // circular, registro aponta para ele mesmo 
}


///////////////////////////////////////////////// 
/////////     imprime_lista()       ////////////
///////////////////////////////////////////////
 
void imprime_lista( NODO* aux ){
    
	int i= 0;                     			// indica n�mero de registro na lista
		 	 
    if( aux == NULL )	             	  // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
	     printf("\n Relat�rio Geral ----------------------------------------- ");
         NODO *inicio= aux;		       // ponteiro auxiliar para percorrer a lista
         do{                        
		 	    printf( "\n Registro[%d]", i );
                printf( "\t C�digo: %d", aux->info.codigo );
                printf( "\t Nome..: %s", aux->info.nome );
                aux = aux->prox;   // aponta para o pr�ximo registro da lista
                i++;
         }while( aux != inicio );// fim while( aux->prox != inicio )    
    } // fim if( aux == NULL )
 	getchar();                 // parada da tela
}

 

///////////////////////////////////////////////// 
///////// 		cria_lista          ////////////
/////////////////////////////////////////////// 

void cria_lista( NODO** l ){
	 
    *l = NULL ; 	// lista criada, in�cio nao aponta
}



///////////////////////////////////////////////// 
/////////        inclui_fim()       ////////////
///////////////////////////////////////////////

void inclui_fim( NODO** l ){

	NODO* no = (NODO *) malloc (sizeof(NODO));  		//aloca espa�o de mem�ria para um novo nodo
	if ( no != NULL) {								   //verifica se h� espa�o ou n�o
		entrada_dados ( no );						  //recebe os dados
		if ( *l == NULL ){							 //verifica se a lista est� vazia
			no->prox = no;							//faz o prox apontar para si mesmo
			no->ant = no;						   //faz o ant apontar para si mesmo
			*l = no;
		}
		else{
			no->ant = (*l)->ant;				//seta o nodo novo antes pra n�o perder informa��es
			no->prox = *l;
			(*l)->ant->prox = no;		      //depois seta os nodos j� existentes
			(*l)->ant = no;				     //a ironia � que, por ser circular, o funcionamento � o mesmo para inserir no inicio
		} 								    //a unica diferen�a � que n�o mexe no *l
		printf("\n Registro inclu�do com sucesso!");
	}
	else
		printf("\n Desculpe, lista cheia!!");
	getchar();
}


///////////////////////////////////////////////// 
/////////      inclui_inicio()      ////////////
///////////////////////////////////////////////

void inclui_inicio( NODO** l ){

    NODO* no = ( NODO * ) malloc ( sizeof( NODO ));   	// aloca novo espa�o em mem�ria
    if( no != NULL ){                              	   // verifica se conseguiu alocar mem�ria para o novo registro (no)
              entrada_dados( no );              	  // l� dados
              if( *l == NULL ){                 	 // verifica se lista vazia, caso sim o novo registro ser� o primeiro
                   no->prox = no;              		// lista circular, nodo aponta para ele mesmo
                   no->ant  = no;
              }else{                              // caso n�o seja o primeiro da lista...
                   no->ant = (*l)->ant;          // ant do novo registro (no) aponta para �ltimo da lista 
				   no->prox = *l;               // prox do novo registro (no) aponta para o primeiro registro da lista (*l) 
                   (*l)->ant->prox = no;       // prox do �ltimo registro da lista aponta para o novo registro (no)
				   (*l)->ant = no;            // ant do primeiro registro da lista aponta para o novo registro (no)
              } 							 // fim if ( *l == NULL ) 
			  *l = no;                      // insere o novo registro (no) como primeiro na lista
			  							   // compare os algoritmos de inclus�o no in�cio e no fim, qual � a l�gica que os diferencia?
              printf( "\n Registro inclu�do no in�cio!" );
    } 									 // if( no != NULL )   
    else
        printf( "\n Lista cheia!" );
    getchar();
}


///////////////////////////////////////////////// 
/////////       exclui_nodo()       ////////////
///////////////////////////////////////////////
 
void exclui_nodo( NODO** l ){
		
	int cod;
	if ( *l == NULL){ 						  //verifica se a lista est� vazia (se h� algo para excluir)
		printf("\n Ops. A lista est� vazia.\n");
	}
	else {	
		NODO *p = *l;					   //cria um ponteiro para percorrer a lista (n�o ser� necess�rio 2 pois h� a informa��o do anterior no nodo)
											
		printf("\nDigite o c�digo do registro que deseja excluir: ");
		scanf("%d", &cod);				 //l� o c�digo a ser exclu�do
		
					
		if (cod == (*l)->info.codigo) {   	  //verifica se � o primeiro da lista
			if ((*l)->prox == *l) { 	  	 //al�m de verificar se � o primeiro da lista, tem que verificar se � o �NICO da lista
				*l = NULL;					//nesse caso n�o basta realocar os ponteiros ant/prox
				printf("Registro exclu�do com sucesso!");
			}
			else{
				(*l)->prox->ant = (*l)->ant;    //realoca��o dos ponteiros, para que n�o se apontem mais para o nodo exclu�do
				(*l)->ant->prox = p->prox;	  
				*l = p->prox;			      //por ser o primeimro da lista, h� um cuidado especial, j� que deve-se modificar o *l
				free(p);				     //limpa a mem�ria
				printf("Registro excluido com sucesso.");
			}
		}
		else {  //n�o sendo o primeiro da lista:

			p = p->prox;			        //o ponteiro p vai sair da primeira posi��o e percorrer a lista
			NODO *inicio = *l;		       //enquanto isso, outro ponteiro marcar� o inicio para o P n�o rodar eternamente, por ser uma lista circular
			do {
				p = p->prox;		  	 //enquanto isso P passeia at� que chegue ao in�cio ou at� que encontre o c�digo do elemento procurado
			} while (p != inicio && p->info.codigo != cod);
			
			if (p->info.codigo == cod) {     //tendo o P localizado o c�digo:
				p->ant->prox = p->prox;	    //o prox do anterior recebe o prox de P
				p->prox->ant = p->ant;	   //o ant do posterior recebe o ant de P
				free(p);				  //mem�ria esta livre, leve e solta
				printf("Registro excluido com sucesso!");
			}
			else {
				printf("\nDesculpe, o c�digo que procura n�o est� registrado.\n");
			}
		}
	}	
	getchar();
}


///////////////////////////////////////////////// 
/////////      ordena_lista()       ////////////
///////////////////////////////////////////////
 
void ordena_lista( NODO** l ){
	
	/*usando o bublesort n�o muda praticamente nada, j� que n�o trocam os nodos de lugares, ou seja, n�o h� altera��es nos ponteiros,
	apenas uma troca em seus conte�dos.
	Todavia, por ser uma lista circular e nenhum ponteiro apontar para NULL, posicionei um ponteiro FIM para determinar o final da lista
	evitando o looping eterno. */
	   
	INFORMACAO aux;
    NODO *x = *l;			 //vai percorrer a lista para comparar os valores
    NODO *y = *l;			//vai auxiliar a troca de valores e no looping
	
	if (*l == NULL)
		printf("\nDesculpe, a lista est� vazia. Adicione registros para poder orden�-la!");
	else {
		NODO *fim = (*l)->ant; 				     //marca o final da lista	
	   	for(x=*l; x!=fim; x=x->prox) { 			//movimento do x pelos nodos
		    for(y=x->prox; y!=*l; y=y->prox)   //movimento do y pelos nodos ~~ OBS: como o Y vai na frente do x varrendo a lista,  ~~
		        { 							  //                            ~~ o y precisa parar em um nodo posterior (no in�cio). ~~
		            if(y->info.codigo < x->info.codigo) 
		            {						//troca a posicao das variaveis
		                aux = x->info;       
		                x->info = y->info;
		                y->info = aux;
		            }
		        }
		    }
		    printf("\n\n Lista ordenada em ordem crescente com sucesso! \n\n");
	}
	getchar();
}

///////////////////////////////////////////////// 
/////////         consulta()        ////////////
///////////////////////////////////////////////

void  consulta ( NODO** l ) {
	
	if (*l == NULL)						//verifica se a lista est� vazia
		printf("\nA lista est� vazia!\n");  
	else {
		NODO *p = *l;				// nodo para percorrer a lista
		NODO *fim = (*l)->ant;	   // nodo para marcar o final da lista
		char name[30];			  
		fflush(stdin);           // limpa o buffer
		printf("Digite o nome que deseja consultar: ");
		gets(name);    	       // o scanf n�o l� espa�os, ent�o utiliza-se o gets para pegar toda a string 
							  // � necess�rio usar strcmp = false (1) para fazer a compara��o:
		while (p != fim && strcmp(p->info.nome, name) == 1) {
			p = p->prox;	// P varre a lista, indo at� o final ou ficando localizado no NODO consultado
		} 
						  //tendo o P localizado o nodo:
		if (strcmp(p->info.nome, name) == 0) {   	  
			printf("\n-- Cadastro: --\n-- Nome: %s \n-- C�digo %d\n", p->info.nome, p->info.codigo);
		}								
		else {		 // caso n�o encontre o nodo:
			printf("\nDesculpe, o nome que procura n�o est� registrado.\n");
		}
	}
	getchar();
}

///////////////////////////////////////////////// 
/////////       altera_dados()      ////////////
///////////////////////////////////////////////
 
 void  altera_dados ( NODO** l ) {
 	
 	if (*l == NULL)					     // verifica se a lista est� vazia
		printf("\nA lista est� vazia!\n"); 
	else {
		int cod;
		printf("Digite o c�digo do registro que deseja alterar: ");
		scanf("%d", &cod);			 // l� o c�digo do nodo a ser alterado
		NODO *p = *l;				// ponteiro que varre a lista
		NODO *fim = (*l)->ant;	   // ponteiro que marca o fim
		while (p != fim && p->info.codigo != cod) {
			p = p->prox;		 // P caminha pela lista at� o final ou at� achar o c�digo
		}
		if (p->info.codigo == cod){
			
			NODO* aux = ( NODO * ) malloc ( sizeof( NODO ));   // cria um nodo auxiliar para guardar informa��es
			printf("\n**  Insira os novos dados  **\n");	  
			entrada_dados ( aux );							 // alimenta o nodo auxiliar com os novos dados
			p->info = aux->info;							// faz a transfer�ncia dos novos dados pro nodo a ser modificado
			printf("\nDados alterados com sucesso!\n");
			free(aux);									  // libera a mem�ria do nodo auxiliar
		}
		else {
			printf("C�digo n�o encontrado!");
		}
	}
	getchar();
  }
  
///////////////////////////////////////////////// 
/////////      destroi_lista()      ////////////
///////////////////////////////////////////////
  
void destroi_lista  ( NODO* *l ){
	  
	int i= 0;                      			   // indica n?mero de registro na lista
	if( *l == NULL )              	   	      // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
		NODO *aux = *l;        	 	   // ponteiro auxiliar para percorrer a lista
		NODO *inicio = aux;
        do{                        
		    printf( "\n Destroi Registro[%d]", i );
            printf( "\t C�digo: %d", aux->info.codigo );
			printf( "\t Nome..: %s", aux->info.nome );
            *l = aux->prox;   	 // aponta para o pr?ximo registro da lista
		    free( aux );     	// libera mem?ria
		    aux = *l;          // reposiciona ponteiro auxiliar no in?cio  
            i++;
        } while( inicio != *l ); // fim while ( aux->prox != aux )
		free( inicio ); 
		*l= NULL;          
    } // fim if( aux == NULL )
 	
	getchar();              // parada da tela
}
