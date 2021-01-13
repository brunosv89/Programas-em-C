/*************************************************************
Atividade de EDP - Árvores binárias
Aluno: Bruno Soares Vasques
Data: Novembro/2020

A tarefa é: Implementar as operações de uma árvore binária.
O exercício deve contemplar as seguintes funcionalidades:
    -insere novo registro
    -busca um registro por um campo de escolha
    -exclui um registro por um campo de escolha
    -percorre toda árvore
    -criar as próprias funções
**************************************************************/


#include <stdio.h>     // printf e scanf 
#include <conio.h>     // getch
#include <stdlib.h>    // exit
#include <string.h>    
#include <locale.h>    // setlocale


const char ORA_NIVEL_CHAR = '_';


/***********************************************/ 
/* Definição dos Registros                     */
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
/* Definição das Funções                       */
/***********************************************/
void    entrada_dados   ( ARVORE *aux );         // leitura dos dados de entrada
void    imprime_ARVORE  ( ARVORE *aux );         // visualização da árvore em tela, todos os registros
void    cria_ARVORE     ( ARVORE **r );          // inicializa árvore com NULL
void    insere_recursivo( ARVORE **r, int cod ); // inclui um novo registro na árvore
void    busca_recursivo ( ARVORE *p, int cod );  // procura na árvore um código
ARVORE *remove_recursivo( ARVORE *p, int cod );  // exclui um regitro por código
void    limpa_arvore    ( ARVORE *r );			 // limpa registros

void    calcula_altura  ( ARVORE **r );          // calcula e atualiza a altura e fator de balancemaento de um nodo
int     altura_arvore   ( ARVORE *p );           // atualiza a altura do nodo
void verifica_balanceamento( ARVORE **r );       // verifica balanceamento de cada nodo da árvore
void rotacao_direita ( ARVORE **p );             // rotação para balanceamento  
void rotacao_esquerda( ARVORE **p );             // rotação para balanceamento



void salvaArvore( ARVORE * r );
void salvaRecursivo ( FILE *pont_arq, ARVORE* r, int pos );
void carregaArvore( ARVORE ** r);
int carregaRecursivo ( FILE *pont_arq, ARVORE** r, int pos );


       
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    char op;       // opção do menu                               
    ARVORE *r, *p; // declaração da ARVORE, variável do tipo ARVORE = ARVORE de ponteiros
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
		 printf( "\n [7] SALVA A ÁRVORE                                   " ); 
		 printf( "\n [8] CARREGA A ÁRVORE                                   " ); 
		 printf( "\n [0] Para sair do programa                            " );         
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche(); // tecla de opção do menu

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
                   	    calcula_altura( &r );          // calcula e armazena a altura de cada nó
                   	    verifica_balanceamento( &r );  // verifica balanceamento da árvore
               		
                   break; 
                   
           case '4':  // rotina recursiva que busca um registro da ARVORE                                                
                   printf("\n Buscar o codigo: ");
                   scanf("%d", &cod);
                   busca_recursivo( r, cod );  // busca código na árvore e retorno ponteiro do registro quando encontrado, caso não encontre retorna NULL
                   break; 

           case '5':  // rotina recursiva que remove um registro da ARVORE                                                
                    if (r == NULL) {
						printf("\nOps! Nada para remover, a lista já está vazia!");					
                		break;
                		}
				    else{
				   		printf("\n Digite qual código deseja remover: ");
                   		scanf("%d", &cod);
                   		p = remove_recursivo( r, cod );  // remove registro que contém o código e retorna a raíz
				   		calcula_altura( &r );  // calcula e armazena a altura de cada nó
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
				                      
           case '0':  // término do programa                                                 
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
	
	printf("\n Árvore Salva com Sucesso!\n\n");
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
 * saída   : nodo com dados                      *
 ************************************************/
void entrada_dados( ARVORE* aux )
{ 
/*  printf( "\n\n Código: %d", aux->info.codigo ); */  
    aux->subd = NULL;    // não aponta
    aux->sube = NULL;    // não aponta

}



/*************************************************
 * imprime_ARVORE                                *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                              *
 * saída   : dados em tela                       *
 *************************************************/ 
void imprime_ARVORE( ARVORE *aux ){    
     
    if( aux != NULL ){              // verifica se a raiz é diferente de vazio
        printf( "\n Código.....: %d", aux->info.codigo );
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
 * saída   : NULL (inicializa ARVORE)            *
 ************************************************/ 
void cria_ARVORE( ARVORE **r ){
    *r = NULL; // arvore criada, raiz nao aponta
}



/************************************************* 
 * insere_recursivo                              *
 * objetivo: rotina para inserir no fim da ARVORE*
 * entrada : ARVORE e cod                        *
 * saída   : ARVORE com mais um registro         *
 *************************************************/ 
void insere_recursivo( ARVORE **p, int cod ){
   if( *p == NULL ){                                     // se não achou o código, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em memória
         no->info.codigo = cod;  
         no->subd= NULL;                                 // inicializa subárvore da direita
         no->sube= NULL;								 // inicializa subárvore da esquerda
         *p= no;                                         // anterior aponta para novo registro
         printf( "\n Registro inserido!" );   
   }else{
         if( (*p)->info.codigo > cod )                   // verifica se código a ser inserido é menor que o valor do registro para qual o p aponta
              insere_recursivo( &(*p)->sube, cod );      // anda com o ponteiro p para a esquerda, pois o código procurado é menor
         else
              if( (*p)->info.codigo < cod )              // verifica se código a ser inserido é maior que o valor do registro para qual o p aponta
                   insere_recursivo( &(*p)->subd, cod ); // anda com o ponteiro p para a direita, pois o código procurado é maior 
              else
                 printf( "\n Registro já existe!" );    
		 }			  
} // desempilha


/* INSERE NÃO RECURSIVO
void insere( ARVORE** r ){
    ARVORE* p;      // ponteiro auxiliar
    ARVORE* a;      // ponteiro auxiliar para anterior de p (nodo pai)
    int cod, achou; // cod = dado de entrada; achou = informa se código já existe na estrutura

    printf("\n Digite o novo código: ");
    scanf("%d", &cod);
    
    p = *r;                            // posiciona ponteiro auxiliar
    achou = busca( cod, &a, &p );      // verifica se código a ser inserido já existe na árvore, "a" é o nodo pai
    if( !achou ){                      // se não achou o código, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em memória

         if( no != NULL ){             // se conseguiu alocar memória, insere
                 no->info.codigo = cod;// preenche o novo registro com o código já informado
                 entrada_dados( no );  // entrada do usuário
                 if( *r == NULL )      // verifica se a árvore esta vazia
                     *r = no;          // o registro sera o primeiro, atualiza a raiz
                 else 
                      if ( no->info.codigo > a->info.codigo )
                           a->subd = no; // insere a direita do registro folha
                      else
                           a->sube = no; // insere a esquerda do registro folha
         } // fim if( no != NULL )
    } // fim if( !achou )
    else
        printf( "\n Registro já existe!" );
*/


/***************************************************
 * busca_recursivo                                 *
 * objetivo: rotina para buscar registro por código*
 * entrada : ARVORE e cod                          *
 * saída   : ARVORE com mais um registro           *
 ***************************************************/ 
void busca_recursivo( ARVORE *p, int cod ){
	
	
	
	if (p == NULL){
		printf("Registro não encontrado!");
	}
	else{
		if (p->info.codigo == cod){
			printf("\nO registro %d está na altura: %d\n", p->info.codigo, p->info.altura);
			printf("E seu fator de balanceamento é: %d\n", p->info.fatbal);	
		}	
		else {    // recursividade para varrer a árvore
			if(cod < p->info.codigo)  
				busca_recursivo( p->sube, cod );
			else
				busca_recursivo( p->subd, cod );
		}	
	}

	 

} // desempilha


/****************************************************
 * remove_recursivo                                 *
 * objetivo: rotina para remover registro por código*
 * entrada : ARVORE e cod                           *
 * saída   : ARVORE com registro removido           *
 ****************************************************/ 
ARVORE *remove_recursivo( ARVORE *p, int cod ){
	
	if (p == NULL) {
		printf("Ops! O código digitado não foi encontrado! Tente novamente.");	
		return NULL;
	}
	else {
		if (p->info.codigo == cod){ // CONDIÇÃO DE PARADA
			// verifica se trata-se de um NODO FOLHA
			if( p->sube == NULL && p->subd == NULL){
				printf("\nRegistro excluído com sucesso!");
				free(p);
				return NULL;
			}
			//verifica se há PELO MENOS 1 filho
			else if (p->sube == NULL || p->subd == NULL){ 
				ARVORE *aux;   		 // variavel que guardará o filho
				if (p->sube !=NULL)  //caso esteja na esquerda:
					aux = p->sube;
				else                 //caso esteja na direita:
					aux = p->subd;
				printf("\nRegistro excluído com sucesso!");
				free(p);
				return aux;  		 //retorna a auxiliar que guardou o endereço de memória do filho
			}
			//por exclusão, terá 2 FILHOS [INCLUSIVE SE FOR  A RAIZ]
			else {
				//estratégia: pegar o elemento mais a direita da sub-arvore à esquerda
				ARVORE *aux = p->sube;     // coloca o ponteiro auxiliar na sub-arvore da esquerda
				while (aux->subd != NULL){ // e faz ele caminhar até o nodo mais a direita
					aux = aux->subd;
				}                                  // ao invés da manipulação de ponteiro, é mais fácil manipular o conteúdo:
				p->info.codigo = aux->info.codigo; // então o nodo a ser excluido recebe o conteúdo do nodo que vai substituir ele
				aux->info.codigo = cod;			   // e o nodo que vai substituir, recebe o código a ser deletado
				p->sube = remove_recursivo(p->sube, cod); //então, enfim, posso remover o nodo sem perder referências
				return p;
			}
			
		}
		else {                      // CONDIÇÃO DE RECURSIVIDADE
			if (cod < p->info.codigo)			// se o valor for menor, desce à esquerda
				// a recursão retornará um endereço, portanto alguém deve receber ele. Neste caso, deve retornar NULL para o ponteiro da esquerda
				p->sube = remove_recursivo( p->sube, cod );  
			else								// se for maior, desce à direita
				p->subd = remove_recursivo(p->subd, cod );
			
			return p;
		}
	}	
}	
		

/****************************************************
 * libera árvore                                    *
 * objetivo: limpar a árvore						*
 * entrada : ARVORE                                 *
 * saída   : RAIZ NULL						        *
 ****************************************************/
 
 
 void limpa_arvore( ARVORE *r ){

	if (r != NULL){    				 // verifica se o nodo possui conteúdo
		limpa_arvore ( r->sube );    // desce até embaixo primeiro
		limpa_arvore ( r->subd );
		free(r);					 // depois libera memória, para não perder as referências
	}	
	
}



/****************************************************
 * calcula_altura                                   *
 * objetivo: rotina para calcular a altura da árvore*
 * entrada : ARVORE                                 *
 * saída   : ARVORE com campo altura atualizado     *
 ****************************************************/ 
void calcula_altura( ARVORE **r ){
	ARVORE *aux= *r;                            // ponteiro auxiliar para percorrer a árvore
    
    if( aux != NULL ){                          // verifica se a raiz é diferente de NULL
        aux->info.altura= altura_arvore( aux ); // verifica a altura do nó
        aux->info.fatbal= ( altura_arvore( aux->subd ) + 1 ) - ( altura_arvore( aux->sube ) + 1 ); // calcula fator de balanceamento (fatbal) do nó
        //printf("\n Cod:%i  A:%i  Fatbal:%i  \n", aux->info.codigo, aux->info.altura, fatbal);
   	    calcula_altura( &aux->subd );          // recursivo, segue pelo caminho da direita do nó
        calcula_altura( &aux->sube );          // recursivo, segue pelo caminho da esquerda do nó
    }
}


/****************************************************
 * verifica_balanceamento                           *
 * objetivo: rotina para calcular o balancemaneto   *
 * entrada : ARVORE                                 *
 * saída   : ARVORE balanceada                      *
 ****************************************************/ 
void verifica_balanceamento( ARVORE **r ){
	ARVORE *aux= *r;                                // cria ponteiro auxiliar para percorrer a árvore
    
    if( aux != NULL ){                              // verifica se ponteiro é diferente de NULL
		if( aux->info.fatbal >= 2 && ( aux->subd->info.fatbal != 2 && aux->subd->info.fatbal != -2 ) ){ // verifica fator de balanceamento no nó pai e filho, se nó pai for maior do que 1, a rotação será à esquerda 
	        if( aux->subd->info.fatbal < 0 ){       // se sinal do fatbal do nó filho for negativo, realiza rotação dupla				
	            rotacao_direita( &aux->subd );	    // rotação esquerda - dupla
		        rotacao_esquerda( &aux );
			}else                                   // se sinal do fatbal do nó filho for positivo, realiza rotação simples
    			rotacao_esquerda( &aux );
	    }else
            if( aux->info.fatbal <= -2 && ( aux->sube->info.fatbal != 2 && aux->sube->info.fatbal != -2 ) ){ // verifica fator de balanceamento no nó pai e filho, se nó pai for menor do que 1, a rotação será à direita
		        if( aux->sube->info.fatbal > 0 ){   // se sinal do fatbal do nó filho for positvo, realiza rotação dupla  
		            rotacao_esquerda( &aux->sube ); // rotação direita - dupla	  
			        rotacao_direita( &aux );
				}else 
	    			rotacao_direita( &aux );        // se sinal do fatbal do nó filho for positivo, realiza rotação simples
			}else{
					verifica_balanceamento( &aux->sube ); // continua verificando balanceamento à esquerda
					verifica_balanceamento( &aux->subd ); // continua verificando balanceamento à direita 	
			}
		calcula_altura( &aux );	                    // atualiza a altura dos nós da árvore após rotação
   }
   *r= aux;                                         // atualiza a raiz após rotação
}

/****************************************************
 * altura_arvore                                    *
 * objetivo: rotina para atualizar a altura do nodo *
 * entrada : ARVORE                                 *
 * saída   : altura                                 *
 ****************************************************/ 
int altura_arvore( ARVORE *p ){
	 int altura_esq, altura_dir;
	 if( p == NULL  )                           // finaliza o percurso
	     return -1;
     else{
          altura_dir= altura_arvore( p->subd ); // percorre à direita
	 	  altura_esq= altura_arvore( p->sube ); // percorre à esquerda
          if( altura_dir > altura_esq )         // se altura da direita maior, soma mais um nível à direita
              return altura_dir + 1;
          else                                  // se altura da esquerda maior, soma mais um nível à esquerda
              return altura_esq + 1;		      
     }
}


/****************************************************
 * rotacao_direita                                  *
 * objetivo: rotina para rotacionar árvore          *
 * entrada : ARVORE                                 *
 * saída   : ARVORE rotacionada                     *
 ****************************************************/ 
void rotacao_direita( ARVORE **p ){
	 ARVORE *aux;
	 if( *p != NULL ){                            // percurso até NULL
	 	  aux= (*p)->sube;                        // aponta à esquerda
		  (*p)->sube= aux->subd;                  // nó filho à direita  
		  aux->subd= *p;                          // raiz passa a ser nó filho
		  *p= aux;                                // aux passa ser a nova raiz
     }
}


/****************************************************
 * rotacao_esquerda                                 *
 * objetivo: rotina para rotacionar árvore          *
 * entrada : ARVORE                                 *
 * saída   : ARVORE rotacionada                     *
 ****************************************************/ 
void rotacao_esquerda( ARVORE **p ){
	 ARVORE *aux;
	 if( *p != NULL ){                            // percurso até NULL
	 	  aux= (*p)->subd;                        // ponteiro auxiliar é posicionado no nó filho da direita
		  (*p)->subd= aux->sube;                  // ajusta apontamento, ponteiro direito pai aponta para ponteiro esquerdo do filho
		  aux->sube= *p;                          // ponteiro à esquerda no filho aponta para nó pai
		  *p= aux;                                // reposiciona p
     }
}
