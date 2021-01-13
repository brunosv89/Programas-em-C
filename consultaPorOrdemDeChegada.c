//::::::::::::::::::::::::::::::::::://
//:::::::::: ATIVIDADE EDP :::::::::://
//:::::::: Pilhas Encadeadas ::::::::// 
//::: Aluno: Bruno Soares Vasques ::://
//:::::: Data: Outubro de 2020 :::::://
//::::::::::::::::::::::::::::::::::://

// Função: Cria uma fila de pacientes para consulta, por ordem de chegada, utilizando pilhas.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


/*********************************************** 
/* Definição dos Registros                     *
/***********************************************/ 
typedef struct {           // registro para uma pessoa
       int  conv;
       char nome[30];
} INFORMACAO;
       
typedef struct reg {
       INFORMACAO info;    // dados do registro
       struct reg* prox;   // ponteiro para o próximo registro
} REGISTRO; 



/***********************************************/ 
/* Definição das Funções                       */
/***********************************************/ 
void    entrada_dados ( REGISTRO* aux );
void    imprime_dados ( REGISTRO* aux );
void    cria_fila     ( REGISTRO** f  );
void    entra_fila    ( REGISTRO** f  );
void    sai_fila      ( REGISTRO** f  );

/***********************************************/ 
/* Programa Principal                          */
/***********************************************/ 
int main( void )
{
    char op;     // opcao do menu                               
    REGISTRO* f; // declaracao da fila 
	setlocale(LC_ALL, "Portuguese");

    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Registro de Consulta Médica		                  " );
         printf( "\n [1] Cria Fila                                        " );
         printf( "\n [2] Entra na fila                                    " );
         printf( "\n [3] Atendimento Realizado                            " );
         printf( "\n [4] Visualizar fila                                  " );
         printf( "\n [5] Sair                                             " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche();// tecla de opcao do menu

         switch( op ) {
           case '1':  // rotina cria pilha
                   cria_fila( &f );
                   break;
                                
           case '2':  // rotina empilha
                   entra_fila( &f );    
                   break;
           
           case '3':   // rotina desempilha
                   sai_fila ( &f );
                   break;
                                                                            
           case '4':   // rotina imprime pilha                 
                   imprime_dados( f ); 
                   break;
                                
           case '5':  // término do programa                                                 
                   exit( 1 ); 
                   break; 
                
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )

       
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        system( "cls" ); // limpar tela
        printf( "\n" );
     } // fim do while( 1 )
     
 return 0;
} // fim do programa principal



/************************************************ 
 * entrada_dados                                *
 ************************************************/
void entrada_dados( REGISTRO* aux )
{ 
    printf( "\n\n Digite o número do Convêncio: " ); 
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.conv);

    printf( "\n Digite o nome do Paciente: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );
  
    aux->prox= NULL;     // não aponta
}

/*************************************************
 * imprime_fila                                  *
 *************************************************/ 
void imprime_dados( REGISTRO* aux )
{
    if( aux == NULL )
        printf( "\n Cadastro vazio!" );
    else {
         printf("\n\n ---- Lista Geral ---- ");    
         while( aux != NULL ){  // ponteiro auxiliar para a lista
                printf( "\n Nome.....: %s", aux->info.nome );
                printf( "\n Convênio : %d\n", aux->info.conv );
                aux = aux->prox;// aponta para o proximo registro da lista
         } // fim while( aux != NULL )
    } // fim if( aux == NULL )  
}

/************************************************
 * cria_fila                                    *
 ************************************************/ 
void cria_fila( REGISTRO** inicio )
{
    *inicio = NULL; // pilha criada, topo nao aponta
    printf("Cadastro de consultas aberto!");
}

/************************************************ 
 * entra na fila                                *
 ************************************************/ 
void entra_fila ( REGISTRO** f ){
     
    REGISTRO* no = ( REGISTRO * ) malloc ( sizeof( REGISTRO ) ); // aloca novo espaco em memoria
    REGISTRO* fim = *f;
	if( no != NULL ) {                            // verifica se conseguiu alocar memoria para o novo registro
		entrada_dados( no );                      // le dados
    	
		if (*f == NULL){
			*f = no;
			printf("Paciente incluído.");
		}
		else {
			while (fim->prox != NULL) {
				fim = fim->prox;
			}
			fim->prox = no;
			no->prox = NULL;
			fim = no;
			printf("Paciente incluído no final da fila.");
		}
    } // fim if( no != NULL )
    else
        printf( "\n Cadastro lotado!" );

}

/************************************************ 
 * sai da fila                                  *
 ************************************************/ 

void    sai_fila      ( REGISTRO** f  ){
	
	REGISTRO* aux;

    if( *f != NULL ){       // verifica se a pilha esta vazia 
        aux = *f;
        *f = aux->prox;
        free(aux);
		printf( "\n Consulta realizada! " );
    } // fim if( *p != NULL )
    else
        printf( "\n Nenhum paciente na fila! " );
	
}
