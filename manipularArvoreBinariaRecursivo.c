/*************************************************************
Atividade de EDP - �rvores bin�rias
Aluno: Bruno Soares Vasques
Data: Novembro/2020

A tarefa �: Implementar as opera��es de uma �rvore bin�ria.
O exerc�cio deve contemplar as seguintes funcionalidades:
    -insere novo registro
    -busca um registro por um campo de escolha
    -exclui um registro por um campo de escolha
    -percorre toda �rvore
    -criar as pr�prias fun��es
**************************************************************/


#include <stdio.h>     // printf e scanf 
#include <conio.h>     // getch
#include <stdlib.h>    // exit
#include <string.h>    
#include <locale.h>    // setlocale


const char ORA_NIVEL_CHAR = '_';


/***********************************************/ 
/* Defini��o dos Registros                     */
/***********************************************/ 
typedef struct {          // registro 
       int  codigo;       
	   int  altura;       // utilizado para balanceamento 
	   int  fatbal;       // utilizado para balanceamento
} INFORMACAO;
       
typedef struct arv {
       INFORMACAO info;   // dados do registro
       struct arv *subd;  // ponteiro para o nodo da direita
       struct arv *sube;  // ponteiro para o nodo da esquerda
} ARVORE; 



/***********************************************/ 
/* Defini��o das Fun��es                       */
/***********************************************/
void    entrada_dados   ( ARVORE *aux );         // leitura dos dados de entrada
void    imprime_ARVORE  ( ARVORE *aux );         // visualiza��o da �rvore em tela, todos os registros
void    cria_ARVORE     ( ARVORE **r );          // inicializa �rvore com NULL
void    insere_recursivo( ARVORE **r, int cod ); // inclui um novo registro na �rvore
void    busca_recursivo ( ARVORE *p, int cod );  // procura na �rvore um c�digo
ARVORE *remove_recursivo( ARVORE *p, int cod );  // exclui um regitro por c�digo
void    limpa_arvore    ( ARVORE *r );			 // limpa registros

void    calcula_altura  ( ARVORE **r );          // calcula e atualiza a altura e fator de balancemaento de um nodo
int     altura_arvore   ( ARVORE *p );           // atualiza a altura do nodo
void verifica_balanceamento( ARVORE **r );       // verifica balanceamento de cada nodo da �rvore
void rotacao_direita ( ARVORE **p );             // rota��o para balanceamento  
void rotacao_esquerda( ARVORE **p );             // rota��o para balanceamento



void salvaArvore( ARVORE * r );
void salvaRecursivo ( FILE *pont_arq, ARVORE* r, int pos );
void carregaArvore( ARVORE ** r);
int carregaRecursivo ( FILE *pont_arq, ARVORE** r, int pos );


       
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    char op;       // op��o do menu                               
    ARVORE *r, *p; // declara��o da ARVORE, vari�vel do tipo ARVORE = ARVORE de ponteiros
    int cod;
    
    setlocale(LC_ALL, "Portuguese");
    //cria_ARVORE( &r );
    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registros - Menu                         " );
         printf( "\n [1] Cria ARVORE                                      " );
         printf( "\n [2] Imprime                                          " );         
         printf( "\n [3] Insere recursivo                                 " );
         printf( "\n [4] Busca recursivo                                  " );         
         printf( "\n [5] Remove recursivo                                 " );          
         printf( "\n [6] Limpa Arvore                                     " );
		 printf( "\n [7] SALVA A �RVORE                                   " ); 
		 printf( "\n [8] CARREGA A �RVORE                                   " ); 
		 printf( "\n [0] Para sair do programa                            " );         
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche(); // tecla de op��o do menu

        switch( op ) {
           case '1':   // rotina cria ARVORE       
                   cria_ARVORE( &r );
                   break;
           
           case '2':   // rotina imprime nodos da ARVORE
                   imprime_ARVORE( r );
                   break;                   
                                                         
           case '3':   // rotina recursiva do inclui nodo da ARVORE
                    
					
					
                       	printf("\n Digite o novo codigo: ");
                    	scanf("%d", &cod);
                   	    insere_recursivo( &r, cod );
                   	    calcula_altura( &r );          // calcula e armazena a altura de cada n�
                   	    verifica_balanceamento( &r );  // verifica balanceamento da �rvore
               		
                   break; 
                   
           case '4':  // rotina recursiva que busca um registro da ARVORE                                                
                   printf("\n Buscar o codigo: ");
                   scanf("%d", &cod);
                   busca_recursivo( r, cod );  // busca c�digo na �rvore e retorno ponteiro do registro quando encontrado, caso n�o encontre retorna NULL
                   break; 

           case '5':  // rotina recursiva que remove um registro da ARVORE                                                
                    if (r == NULL) {
						printf("\nOps! Nada para remover, a lista j� est� vazia!");					
                		break;
                		}
				    else{
				   		printf("\n Digite qual c�digo deseja remover: ");
                   		scanf("%d", &cod);
                   		p = remove_recursivo( r, cod );  // remove registro que cont�m o c�digo e retorna a ra�z
				   		calcula_altura( &r );  // calcula e armazena a altura de cada n�
                   		break;
               		}
           case '6':  // rotina recursiva que limpa os registros                                              
                   limpa_arvore( r );
                   cria_ARVORE( &r );
                   break;
                   
            case '7':                                            
                	salvaArvore ( r );
             		break;
             		
            case '8':                                            
              		carregaArvore( &r );
	          		break;
				                      
           case '0':  // t�rmino do programa                                                 
                   exit( 1 ); 
                   break;                
                   
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        system( "cls" ); // limpa o menu
        
        printf( "\n" );
     } // fim do while( 1 )
     
 return 0;
} // fim do programa principal


//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////// SALVA ARVORE .

void salvaArvore( ARVORE * r ) {
	
		
	FILE *pont_arq;
	pont_arq = fopen("arvore.txt", "w");
	
	if(pont_arq == NULL) {
		printf("\n Erro ao abrir o arquivo '%s'!\n");
		return;
	}
	
	
	salvaRecursivo (pont_arq, r, 0);
	
	fclose(pont_arq);
	
	printf("\n �rvore Salva com Sucesso!\n\n");
	getchar();
	system ("cls");
}

void salvaRecursivo ( FILE *pont_arq, ARVORE* r, int pos )
{
	pos ++; 
	int i;
	if (r != NULL) {
		for(i=0; i<pos; i++)
			fprintf(pont_arq, "%c", ORA_NIVEL_CHAR);
			
		fprintf(pont_arq, "%s\n", r->info);
	
    	salvaRecursivo(pont_arq, r->sube, pos);
    	salvaRecursivo(pont_arq, r->subd, pos);
	}
}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////// CARREGA ARVORE .


void carregaArvore( ARVORE ** r){
	
	
	FILE *pont_arq = fopen("arvore.txt", "r");

	if(pont_arq == NULL)
	{
		printf("\n Erro ao abrir o arquivo '%s'!\n", "arvore.txt");
		return;
	}

		
		cria_ARVORE ( r );
	  	if (carregaRecursivo(pont_arq, r, 0) == 0){
		  	printf("\n Arquivo carregado com sucesso!\n\n");
			system ("pause");
			system ("cls");
	
		}

	
	
	fclose(pont_arq);
}

int carregaRecursivo ( FILE *pont_arq, ARVORE** r, int pos ){
	
	fpos_t posArq;
	fgetpos(pont_arq, &posArq);
		
		
	if (carregaRecursivo(pont_arq, &((*r)->sube), pos+1) != 0)
		return 1;
		
	if(carregaRecursivo(pont_arq, &((*r)->subd), pos+1) != 0)
		return 1;
	
}

/************************************************* 
 * entrada_dados                                 *
 * objetivo: rotina para ler dados               *
 * entrada : nodo (ponteiro para o novo espaco)  *
 * sa�da   : nodo com dados                      *
 ************************************************/
void entrada_dados( ARVORE* aux )
{ 
/*  printf( "\n\n C�digo: %d", aux->info.codigo ); */  
    aux->subd = NULL;    // n�o aponta
    aux->sube = NULL;    // n�o aponta

}



/*************************************************
 * imprime_ARVORE                                *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                              *
 * sa�da   : dados em tela                       *
 *************************************************/ 
void imprime_ARVORE( ARVORE *aux ){    
     
    if( aux != NULL ){              // verifica se a raiz � diferente de vazio
        printf( "\n C�digo.....: %d", aux->info.codigo );
        printf( "\n Altura.....: %d", aux->info.altura );
        printf( "\n Fatbal.....: %d", aux->info.fatbal );        
		getchar();
        printf( "\n <<-- Esquerda" );
        imprime_ARVORE( aux->sube ); // recursivo, segue pelo caminho da esquerda
        printf( "\n Direita -->>" );
        imprime_ARVORE( aux->subd ); // recursivo, segue pelo caminho da direita
    }
    else
       printf("\nNULL!");
}



/*************************************************
 * cria_ARVORE                                   *
 * objetivo: rotina para inicializar a ARVORE    *
 * entrada : nenhuma                             *
 * sa�da   : NULL (inicializa ARVORE)            *
 ************************************************/ 
void cria_ARVORE( ARVORE **r ){
    *r = NULL; // arvore criada, raiz nao aponta
}



/************************************************* 
 * insere_recursivo                              *
 * objetivo: rotina para inserir no fim da ARVORE*
 * entrada : ARVORE e cod                        *
 * sa�da   : ARVORE com mais um registro         *
 *************************************************/ 
void insere_recursivo( ARVORE **p, int cod ){
   if( *p == NULL ){                                     // se n�o achou o c�digo, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
         no->info.codigo = cod;  
         no->subd= NULL;                                 // inicializa sub�rvore da direita
         no->sube= NULL;								 // inicializa sub�rvore da esquerda
         *p= no;                                         // anterior aponta para novo registro
         printf( "\n Registro inserido!" );   
   }else{
         if( (*p)->info.codigo > cod )                   // verifica se c�digo a ser inserido � menor que o valor do registro para qual o p aponta
              insere_recursivo( &(*p)->sube, cod );      // anda com o ponteiro p para a esquerda, pois o c�digo procurado � menor
         else
              if( (*p)->info.codigo < cod )              // verifica se c�digo a ser inserido � maior que o valor do registro para qual o p aponta
                   insere_recursivo( &(*p)->subd, cod ); // anda com o ponteiro p para a direita, pois o c�digo procurado � maior 
              else
                 printf( "\n Registro j� existe!" );    
		 }			  
} // desempilha


/* INSERE N�O RECURSIVO
void insere( ARVORE** r ){
    ARVORE* p;      // ponteiro auxiliar
    ARVORE* a;      // ponteiro auxiliar para anterior de p (nodo pai)
    int cod, achou; // cod = dado de entrada; achou = informa se c�digo j� existe na estrutura

    printf("\n Digite o novo c�digo: ");
    scanf("%d", &cod);
    
    p = *r;                            // posiciona ponteiro auxiliar
    achou = busca( cod, &a, &p );      // verifica se c�digo a ser inserido j� existe na �rvore, "a" � o nodo pai
    if( !achou ){                      // se n�o achou o c�digo, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria

         if( no != NULL ){             // se conseguiu alocar mem�ria, insere
                 no->info.codigo = cod;// preenche o novo registro com o c�digo j� informado
                 entrada_dados( no );  // entrada do usu�rio
                 if( *r == NULL )      // verifica se a �rvore esta vazia
                     *r = no;          // o registro sera o primeiro, atualiza a raiz
                 else 
                      if ( no->info.codigo > a->info.codigo )
                           a->subd = no; // insere a direita do registro folha
                      else
                           a->sube = no; // insere a esquerda do registro folha
         } // fim if( no != NULL )
    } // fim if( !achou )
    else
        printf( "\n Registro j� existe!" );
*/


/***************************************************
 * busca_recursivo                                 *
 * objetivo: rotina para buscar registro por c�digo*
 * entrada : ARVORE e cod                          *
 * sa�da   : ARVORE com mais um registro           *
 ***************************************************/ 
void busca_recursivo( ARVORE *p, int cod ){
	
	
	
	if (p == NULL){
		printf("Registro n�o encontrado!");
	}
	else{
		if (p->info.codigo == cod){
			printf("\nO registro %d est� na altura: %d\n", p->info.codigo, p->info.altura);
			printf("E seu fator de balanceamento �: %d\n", p->info.fatbal);	
		}	
		else {    // recursividade para varrer a �rvore
			if(cod < p->info.codigo)  
				busca_recursivo( p->sube, cod );
			else
				busca_recursivo( p->subd, cod );
		}	
	}

	 

} // desempilha


/****************************************************
 * remove_recursivo                                 *
 * objetivo: rotina para remover registro por c�digo*
 * entrada : ARVORE e cod                           *
 * sa�da   : ARVORE com registro removido           *
 ****************************************************/ 
ARVORE *remove_recursivo( ARVORE *p, int cod ){
	
	if (p == NULL) {
		printf("Ops! O c�digo digitado n�o foi encontrado! Tente novamente.");	
		return NULL;
	}
	else {
		if (p->info.codigo == cod){ // CONDI��O DE PARADA
			// verifica se trata-se de um NODO FOLHA
			if( p->sube == NULL && p->subd == NULL){
				printf("\nRegistro exclu�do com sucesso!");
				free(p);
				return NULL;
			}
			//verifica se h� PELO MENOS 1 filho
			else if (p->sube == NULL || p->subd == NULL){ 
				ARVORE *aux;   		 // variavel que guardar� o filho
				if (p->sube !=NULL)  //caso esteja na esquerda:
					aux = p->sube;
				else                 //caso esteja na direita:
					aux = p->subd;
				printf("\nRegistro exclu�do com sucesso!");
				free(p);
				return aux;  		 //retorna a auxiliar que guardou o endere�o de mem�ria do filho
			}
			//por exclus�o, ter� 2 FILHOS [INCLUSIVE SE FOR  A RAIZ]
			else {
				//estrat�gia: pegar o elemento mais a direita da sub-arvore � esquerda
				ARVORE *aux = p->sube;     // coloca o ponteiro auxiliar na sub-arvore da esquerda
				while (aux->subd != NULL){ // e faz ele caminhar at� o nodo mais a direita
					aux = aux->subd;
				}                                  // ao inv�s da manipula��o de ponteiro, � mais f�cil manipular o conte�do:
				p->info.codigo = aux->info.codigo; // ent�o o nodo a ser excluido recebe o conte�do do nodo que vai substituir ele
				aux->info.codigo = cod;			   // e o nodo que vai substituir, recebe o c�digo a ser deletado
				p->sube = remove_recursivo(p->sube, cod); //ent�o, enfim, posso remover o nodo sem perder refer�ncias
				return p;
			}
			
		}
		else {                      // CONDI��O DE RECURSIVIDADE
			if (cod < p->info.codigo)			// se o valor for menor, desce � esquerda
				// a recurs�o retornar� um endere�o, portanto algu�m deve receber ele. Neste caso, deve retornar NULL para o ponteiro da esquerda
				p->sube = remove_recursivo( p->sube, cod );  
			else								// se for maior, desce � direita
				p->subd = remove_recursivo(p->subd, cod );
			
			return p;
		}
	}	
}	
		

/****************************************************
 * libera �rvore                                    *
 * objetivo: limpar a �rvore						*
 * entrada : ARVORE                                 *
 * sa�da   : RAIZ NULL						        *
 ****************************************************/
 
 
 void limpa_arvore( ARVORE *r ){

	if (r != NULL){    				 // verifica se o nodo possui conte�do
		limpa_arvore ( r->sube );    // desce at� embaixo primeiro
		limpa_arvore ( r->subd );
		free(r);					 // depois libera mem�ria, para n�o perder as refer�ncias
	}	
	
}



/****************************************************
 * calcula_altura                                   *
 * objetivo: rotina para calcular a altura da �rvore*
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE com campo altura atualizado     *
 ****************************************************/ 
void calcula_altura( ARVORE **r ){
	ARVORE *aux= *r;                            // ponteiro auxiliar para percorrer a �rvore
    
    if( aux != NULL ){                          // verifica se a raiz � diferente de NULL
        aux->info.altura= altura_arvore( aux ); // verifica a altura do n�
        aux->info.fatbal= ( altura_arvore( aux->subd ) + 1 ) - ( altura_arvore( aux->sube ) + 1 ); // calcula fator de balanceamento (fatbal) do n�
        //printf("\n Cod:%i  A:%i  Fatbal:%i  \n", aux->info.codigo, aux->info.altura, fatbal);
   	    calcula_altura( &aux->subd );          // recursivo, segue pelo caminho da direita do n�
        calcula_altura( &aux->sube );          // recursivo, segue pelo caminho da esquerda do n�
    }
}


/****************************************************
 * verifica_balanceamento                           *
 * objetivo: rotina para calcular o balancemaneto   *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE balanceada                      *
 ****************************************************/ 
void verifica_balanceamento( ARVORE **r ){
	ARVORE *aux= *r;                                // cria ponteiro auxiliar para percorrer a �rvore
    
    if( aux != NULL ){                              // verifica se ponteiro � diferente de NULL
		if( aux->info.fatbal >= 2 && ( aux->subd->info.fatbal != 2 && aux->subd->info.fatbal != -2 ) ){ // verifica fator de balanceamento no n� pai e filho, se n� pai for maior do que 1, a rota��o ser� � esquerda 
	        if( aux->subd->info.fatbal < 0 ){       // se sinal do fatbal do n� filho for negativo, realiza rota��o dupla				
	            rotacao_direita( &aux->subd );	    // rota��o esquerda - dupla
		        rotacao_esquerda( &aux );
			}else                                   // se sinal do fatbal do n� filho for positivo, realiza rota��o simples
    			rotacao_esquerda( &aux );
	    }else
            if( aux->info.fatbal <= -2 && ( aux->sube->info.fatbal != 2 && aux->sube->info.fatbal != -2 ) ){ // verifica fator de balanceamento no n� pai e filho, se n� pai for menor do que 1, a rota��o ser� � direita
		        if( aux->sube->info.fatbal > 0 ){   // se sinal do fatbal do n� filho for positvo, realiza rota��o dupla  
		            rotacao_esquerda( &aux->sube ); // rota��o direita - dupla	  
			        rotacao_direita( &aux );
				}else 
	    			rotacao_direita( &aux );        // se sinal do fatbal do n� filho for positivo, realiza rota��o simples
			}else{
					verifica_balanceamento( &aux->sube ); // continua verificando balanceamento � esquerda
					verifica_balanceamento( &aux->subd ); // continua verificando balanceamento � direita 	
			}
		calcula_altura( &aux );	                    // atualiza a altura dos n�s da �rvore ap�s rota��o
   }
   *r= aux;                                         // atualiza a raiz ap�s rota��o
}

/****************************************************
 * altura_arvore                                    *
 * objetivo: rotina para atualizar a altura do nodo *
 * entrada : ARVORE                                 *
 * sa�da   : altura                                 *
 ****************************************************/ 
int altura_arvore( ARVORE *p ){
	 int altura_esq, altura_dir;
	 if( p == NULL  )                           // finaliza o percurso
	     return -1;
     else{
          altura_dir= altura_arvore( p->subd ); // percorre � direita
	 	  altura_esq= altura_arvore( p->sube ); // percorre � esquerda
          if( altura_dir > altura_esq )         // se altura da direita maior, soma mais um n�vel � direita
              return altura_dir + 1;
          else                                  // se altura da esquerda maior, soma mais um n�vel � esquerda
              return altura_esq + 1;		      
     }
}


/****************************************************
 * rotacao_direita                                  *
 * objetivo: rotina para rotacionar �rvore          *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE rotacionada                     *
 ****************************************************/ 
void rotacao_direita( ARVORE **p ){
	 ARVORE *aux;
	 if( *p != NULL ){                            // percurso at� NULL
	 	  aux= (*p)->sube;                        // aponta � esquerda
		  (*p)->sube= aux->subd;                  // n� filho � direita  
		  aux->subd= *p;                          // raiz passa a ser n� filho
		  *p= aux;                                // aux passa ser a nova raiz
     }
}


/****************************************************
 * rotacao_esquerda                                 *
 * objetivo: rotina para rotacionar �rvore          *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE rotacionada                     *
 ****************************************************/ 
void rotacao_esquerda( ARVORE **p ){
	 ARVORE *aux;
	 if( *p != NULL ){                            // percurso at� NULL
	 	  aux= (*p)->subd;                        // ponteiro auxiliar � posicionado no n� filho da direita
		  (*p)->subd= aux->sube;                  // ajusta apontamento, ponteiro direito pai aponta para ponteiro esquerdo do filho
		  aux->sube= *p;                          // ponteiro � esquerda no filho aponta para n� pai
		  *p= aux;                                // reposiciona p
     }
}
