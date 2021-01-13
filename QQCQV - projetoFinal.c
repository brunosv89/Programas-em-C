//////////////////////////////////////////////////////  Trabalho Estrutua de Dados e Programação   /////
/////////////////////////////////////////////////////  Árvore Binária de decisão                  //////
////////////////////////////////////////////////////  Alunos: Bruno Soares Vasques e Lucas Zatt  ///////
///////////////////////////////////////////////////	Data: Dezembro de 2020                      ////////

///////////////////////////////////////////////// FUNÇÃO DO PROGRAMA: SUGERIR FILMES/SERIES  ///////////
//////////////////////////////////////////////// AO USUÁRIO DE ACORDO COM A INTERAÇÃO,      ////////////
/////////////////////////////////////////////// ATRAVÉS DE UMA ÁRVORE DE DECISÃO           /////////////


////////////////////////////////////////////////////  BIBLIOTECAS  /////////////////////////////////////                               

#include <stdio.h>     
#include <conio.h>     
#include <stdlib.h>   
#include <string.h>    
#include <locale.h>    

////////////////////////////////////////////////////  ESTRUTURA DOS REGISTROS  /////////////////////////

typedef struct {          
    int  codigo;        // valor inteiro para manipulação e montagem da árvore
} INFORMACAO;
       
typedef struct arv {
       INFORMACAO info;   
       struct arv *subd;  // ponteiro para a subarvore da direita
       struct arv *sube;  // ponteiro para a subarvore da esquerda
} ARVORE; 


////////////////////////////////////////////////////  DEFINIÇÕES DAS FUNÇÕES  //////////////////////////


void   cria_ARVORE ( ARVORE **r );           // inicializa árvore
void   attCatalogo ( ARVORE **r );			 // função que monta a árvore
void   insereNodos ( ARVORE **r, int cod );  // função auxiliar para montar a árvore
void   entrada_dados ( ARVORE *aux ); 		 // função auxiliar
void   loading ();							 // estética para o menu
void   percorreArvore( ARVORE **r );		 // função principal que desce na árvore até encontrar a lista de filme e séries a ser indicada
void   listaFilmes ( ARVORE *r );			 // função auxiliar que guarda as listas de filmes e séries
void   perguntas   ( ARVORE *r );       	 // função auxiliar que faz as perguntas da árvore de decisão
void   imprime_ARVORE  ( ARVORE *aux );      // função inativa, apenas para controle



/////////////////////////////////////////////////////                      /////////////////////////////
////////////////////////////////////////////////////  PROGRAMA PRINCIPAL  //////////////////////////////
///////////////////////////////////////////////////                      ///////////////////////////////

int main( void )
{
    char op;       // opção do menu                               
    ARVORE *r, *p; // declaração da ARVORE, variável do tipo ARVORE = ARVORE de ponteiros
  
    
    setlocale(LC_ALL, "Portuguese");   //idioma e caracteres
    
	cria_ARVORE( &r );        // planta a mudinha
    
    
    while( 1 ){
    	printf( "\n ---------------------------------------- "); 
    	printf( "\n ----------------QQCQV------------------- "); 
        printf( "\n ---------------------------------------- ");
		printf( "\n --- Instruções: Carregue o catálogo  --- ");
		printf( "\n -------- para atualizá-lo antes -------- ");
		printf( "\n -------- de iniciar o programa. -------- "); 
		printf( "\n ---------------------------------------- ");
        printf( "\n ---  [1] Carregar Catalogo           --- ");
		printf( "\n ---  [2] Me indique um filme/serie   --- ");	
		printf( "\n ---  [0] Para sair do programa       --- ");         
        printf( "\n ---------------------------------------- ");      
        printf( "\n Opcao: " );
        op = getche(); // tecla de opção do menu

        switch( op ) {
            case '1':      
                attCatalogo( &r );
                //imprime_ARVORE( r );
				loading();
				break;
				
			case '2':  // término do programa                                                 
                percorreArvore ( &r ); 
                break;
                
           case '0':  // término do programa                                                 
                exit( 1 ); 
                break;                
                   
           default : 
                printf( "\n Digite uma opcao!" );
                break;
        }
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        system( "cls" ); // limpa o menu
        printf( "\n" );
     }
     
 return 0;
} // fim do programa principal


////////////////////////////////////////////////////  Função para criar a raiz da árvore  /////////////


void cria_ARVORE( ARVORE **r ){
	
    *r = NULL; 
}


////////////////////////////////////////////////////  Função para montar a árvore  ////////////////////

void attCatalogo( ARVORE **r ) {
	
	int cod;														//vetor com os nodos em ordem de inserção:
    int array[63] = {32,16,48,8,24,40,56,4,12,20,28,36,44,52,60,2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63};  
    int i;										
	
	for (i=0;i<64;i++){          //laço para inserir na ordem pré definida no array, desta forma já está balanceada
		cod = array[i];				
        insereNodos( r, cod );   // função que insere os nodos recursivamente
        fflush(stdin);
    }
	
}

////////////////////////////////////////////////////  Função para povoar a árvore  ////////////////////

void insereNodos ( ARVORE **p, int cod ){
   if( *p == NULL ){                                     
        ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em memória
        no->info.codigo = cod;
        no->subd= NULL;                              // inicializa subárvore da direita
        no->sube= NULL;								 // inicializa subárvore da esquerda
        *p= no;                                      // anda com o ponteiro
        //printf( "\n Registro inserido!" );   
   }else{
         if( (*p)->info.codigo > cod )               // verifica se código a ser inserido é menor que o valor do registro para qual o p aponta
              insereNodos( &(*p)->sube, cod );       // anda com o ponteiro p para a esquerda, pois o código procurado é menor
         else
              if( (*p)->info.codigo < cod )          // verifica se código a ser inserido é maior que o valor do registro para qual o p aponta
                   insereNodos ( &(*p)->subd, cod ); // anda com o ponteiro p para a direita, pois o código procurado é maior 
              else
                 printf( "\nNULL");    
		}
} 

//  FUNÇÃO AUXILIAR 
void entrada_dados( ARVORE* aux )
{ 
 
    aux->subd = NULL;   
    aux->sube = NULL;    

}

////////////////////////////////////////////////////  Função para impressão  /////////////////////////
// Função de apoio durante a montagem da árvore

void imprime_ARVORE( ARVORE *aux ){    
     
    if( aux != NULL ){              // verifica se a raiz é diferente de vazio
        printf( "\n Código.....: %d", aux->info.codigo );     
		getchar();
        printf( "\n <<-- Esquerda" );
        imprime_ARVORE( aux->sube ); // recursivo, segue pelo caminho da esquerda
        printf( "\n Direita -->>" );
        imprime_ARVORE( aux->subd ); // recursivo, segue pelo caminho da direita
    }
    else
       printf("\nNULL!");
}

////////////////////////////////////////////////////  Função "Principal"  ///////////////////////////
// Percorre o caminho da árvore de acordo com as decisões do usuário até chegar no nodo folha


void percorreArvore( ARVORE **r ) {
	
	system("cls");
	
	printf("\nBEM VINDO AO QQCQV!\n");               
	int lado;
	ARVORE *p = *r;
	
	while ((*r)->subd != NULL) {    // o processo abaixo é realizado até chegar ao nodo folha
	
//	printf("\nCodigo: %d\n", (*r)->info.codigo);
	perguntas(*r);                                // chama a função onde estão as perguntasa para questionar a preferência do usuário
	printf("\nEscolha [1] ou [2]: ");			  // O usuário escolhe entre 2 opções
	fflush(stdin);
	scanf("%d", &lado);
		switch(lado){
			case 1:                               // a opção [1] leva para a subárvore da esquerda
				*r = (*r)->sube;
				break;
			case 2:                               // a opção [2] leva para a subárvore da direita
				*r = (*r)->subd;
				break;
			default:
				printf("\ndigite uma opção válida!");
		}
 	system("cls");
	 }

//	printf("\nCodigo: %d\n", (*r)->info.codigo);
	listaFilmes (*r);							  // chegando no nodo folha, é chamada a função onde contém a lista de filmes para aquele nodo (resultado das decisões)	

}

////////////////////////////////////////////////////  Função auxiliar que armazena as peguntas  ///////

void perguntas(ARVORE *r){
	
	if (r->info.codigo == 2)
	printf("O que causa mais calafrios: [1] personagens assustadores ou coisas que você não pode ver? MUHAHAHAHA\n");
	
	if (r->info.codigo == 4)
	printf("Prefere [1] lidar com personagens assustadores, sangue e mutilações ou [2] você gosta do clima de tensão no ar, como se um espirito estivesse agora mesmo com a mão no seu ombro? (se eu fosse você não olharia para atrás agora.)\n ");
	
	if (r->info.codigo == 6)
	printf("O que mais lhe instiga suspense são [1] histórias de crime e mistério ou [2] algo mais profundo, quase psicótico? (não escute as vozes da sua cabeça, decida sozinho.)\n");
	
	if (r->info.codigo == 8)
	printf("Prefere algo [1] mais assustador e sombrio ou [2] aventuras com mais ação e cheiro de pólvora pelo ar?\n");
	
	if (r->info.codigo == 10)
	printf("Você é [1] daqueles que preferem manter os pés no chão ou [2] uma pitadinha de ficção não faz mal a ninguém?\n");
	
	if (r->info.codigo == 12)
	printf("Prefere [1] estar no meio do fogo cruzado entre mocinhos e vilões ou [2] você fantasia em viver aventuras perigosas que exigem muita coragem?\n");
	
	if (r->info.codigo == 14)
	printf("A sua é [1] explorar lugares inóspitos e lutar pela sobrevivência sozinho ou [2] posso chamar uns super-heróis para ajudar a defender a existência do nosso planeta?\n");
	
	if (r->info.codigo == 16)
	printf("Você [1] está energizado buscando explosões, assassinatos, tiro, porrada e bomba ou [2] prefere algo mais calmo e inspirador, para sentir-se confortável sozinho ou com a família?\n");
	
	if (r->info.codigo == 18)
	printf("Você [1] precisa de um esforço ou [2] é daqueles que ri de qualquer besteira?\n");
	
	if (r->info.codigo == 20)
	printf("É [1] pra rir ou [2] pra chorar? rsrs\n");
	
	if (r->info.codigo == 22)
	printf("Menu do dia: [1] Sempre tem uma comédia romântica fresquinha saindo do forno ou [2] talvez você precise de algo mais profundo?\n");
	
	if (r->info.codigo == 24)
	printf("Prefere [1] histórias de amor e diversão ou [2] algo mais dramático e inspirador?\n");
	
	if (r->info.codigo == 26)
	printf("[1] Histórias inspiradas em fatos reais ou [2] dramas que poderiam acontecer com qualquer um?\n");
	
	if (r->info.codigo == 28)
	printf("As histórias que te inspiram [1] são aquelas bem contadas e produzidas com ótimos atores ou [2] são aquelas histórias reais, os bastidores e a vivências, contadas de forma documental?\n");
	
	if (r->info.codigo == 30)
	printf("Prefere [1] acompanhar a vida e obra de pessoas relevantes ou [2] documentários em geral?\n");
	
	if (r->info.codigo == 32)
	printf("Vamos começar! Primeiro me diz: Quer ver [1] um FILME ou [2] uma SÉRIE? \n");
	
	if (r->info.codigo == 34)
	printf("Prefere [1] multiplas histórias e creepypastas ou [2] apeans uma história de tremer a espinha?\n");
	
	if (r->info.codigo == 36)
	printf("Prefere [1] ver sangue e multilação ou [2] sentir que algo está te observando? (o que é aquilo ali na janela?)\n");
	
	if (r->info.codigo == 38)
	printf("Prefere [1] uma série de assassinatos e perseguições ou [2] mistérios e dúvidas?\n");
	
	if (r->info.codigo == 40)
	printf("Prefere [1] perder o sono e dormir com a luz acesa ou [2] sentir a adrenalina nas veias?\n");
	
	if (r->info.codigo == 42)
	printf("Prefere [1] algo mais realista e possível ou [2] heróis com superpoderes insanos?\n");
	
	if (r->info.codigo == 44)
	printf("Prefere [1] tiro, soco e granada ou [2] aventuras de exploração e expêriencia?\n");
	
	if (r->info.codigo == 46)
	printf("Prefere [1] uma história que envolve monstros do djabo ou [2] algo mais envolvido com humanos?\n");
	
	if (r->info.codigo == 48)
	printf("Prefere [1] uma série sobre crime, investigação, ação e suspense ou [2] algo mais calmo que faça você pensar?\n");
	
	if (r->info.codigo == 50)
	printf("Prefere [1] um romance mais humorístico e sem noção ou [2] algo que toque seu coração?\n");
	
	if (r->info.codigo == 52)
	printf("Prefere [1] rir e se divertir ou [2] chorar e se apaixonar?\n");
	
	if (r->info.codigo == 54)
	printf("Prefere [1] uma comédia espalhafatosa e besta ou [2] algo mais trabalhado?\n");
	
	if (r->info.codigo == 56)
	printf("Prefere [1] o choro e o riso ou [2] o drama e a informação?\n");
	
	if (r->info.codigo == 58)
	printf("Prefere [1] algo que mostre o mal no mundo ou [2] algo sobre idéias e invenções?\n");
	
	if (r->info.codigo == 60)
	printf("Prefere [1] se informar ou [2]se enganchar em uma história?\n");
	
	if (r->info.codigo == 62)
	printf("Prefere [1] um drama romântico ou [2] algo que possa causar angústia e te prender na história?\n");
	
		
}

////////////////////////////////////////////////////  Função auxiliar que armazena as listas  /////////


void listaFilmes (ARVORE *r){

	char f1[30],f2[30],f3[30];

		//lista 1:
	if (r->info.codigo == 1){
		strcpy(f1, "It - A coisa");
		strcpy(f2, "Anabelle 2");
		strcpy(f3, "Anaconda");
	}

		//lista 2:
	if (r->info.codigo == 3){
		strcpy(f1, "Vozes");
		strcpy(f2, "Invocação do Mal 2");
		strcpy(f3, "O Sono da Morte");
	}
	
	
		//lista 3:
	if (r->info.codigo == 5){
		strcpy(f1, "Seven - Os 7 crimes capitais");
		strcpy(f2, "Crime de Mestre");
		strcpy(f3, "Dossiê Pelicano");
	}
	
	
		//lista 4:
	if (r->info.codigo == 7){
		strcpy(f1, "Ilha do medo");
		strcpy(f2, "O poço");
		strcpy(f3, "Campo do medo");
	}
	
	
		//lista 5:
	if (r->info.codigo == 9){
		strcpy(f1, "Velozes e Furiosos");
		strcpy(f2, "Tropa de Elite");
		strcpy(f3, "Troco em dobro");
	}
	
	
		//lista 6:
	if (r->info.codigo == 11){
		strcpy(f1, "Matrix");
		strcpy(f2, "Mad Max - A estrada da fúria");
		strcpy(f3, "A origem");
	}
	
	
		//lista 7:
	if (r->info.codigo == 13){
		strcpy(f1, "Bastardos Inglórios");
		strcpy(f2, "Jack Reacher - O Último Tiro");
		strcpy(f3, "Enola Holmes");
	}
	
	
		//lista 8:
	if (r->info.codigo == 15){
		strcpy(f1, "Liga da Justiça");
		strcpy(f2, "Batman - O cavaleiro das Trevas");
		strcpy(f3, "Indiana Jones");
 	}
	
	
		//lista 9:
	if (r->info.codigo == 17){
	
		strcpy(f1, "Forrest Gump");
		strcpy(f2, "De volta para o futuro");
		strcpy(f3, "Meu nome é Dolemite");
	}
	
	
		//lista 10:
	if (r->info.codigo == 19){
		strcpy(f1, "Loucademia de Polícia");
		strcpy(f2, "Gente Grande 2");
		strcpy(f3, "Superbad - É hoje!");
	}
	
	
		//lista 11:
	if (r->info.codigo == 21){
		strcpy(f1, "O amor não tira férias");
		strcpy(f2, "A barraca do Beijo");
		strcpy(f3, "Até que a sorte nos separe");
	}
	
	
		//lista 12:
	if (r->info.codigo == 23){
		strcpy(f1, "Questão de tempo");
		strcpy(f2, "Orgulho e preconceito");
		strcpy(f3, "Ela dança, eu danço");
	}
	
	
		//lista 13:
	if (r->info.codigo == 25){
		strcpy(f1, "Marshal - Igualdade e Justiça");
		strcpy(f2, "O menino que descobriu o vento");
		strcpy(f3, "Homens de coragem");
	}
	
	
		//lista 14:
	if (r->info.codigo == 27){
		strcpy(f1, "Django Livre");
		strcpy(f2, "Os 7 de chicago");
		strcpy(f3, "Coach Carter - Treino para a vida");
	}
	
	
		//lista 15:
	if (r->info.codigo == 29){
		strcpy(f1, "O dilema das rede");
		strcpy(f2, "Democracia em vertigem");
		strcpy(f3, "Dieta de gladiadores");
	}
	
	
		//lista 16:
	if (r->info.codigo == 31){
		strcpy(f1, "Emicida - AmarElo");
		strcpy(f2, "Travis Scott - Voando alto");
		strcpy(f3, "Senna - O Brasileiro, o herói, o campeão");
	}

		//lista 17:
	if (r->info.codigo == 33){
		strcpy(f1, "American Horror Story");
		strcpy(f2, "Diario de Horrores");
		strcpy(f3, "Channel Zero");
	}
	
		//lista 18:
	if (r->info.codigo == 35){
		strcpy(f1, "Marianne");
		strcpy(f2, "A Maldição da Mansão Bly");
		strcpy(f3, "Eu Vi");
	}
	
		//lista 19:
	if (r->info.codigo == 37){
		strcpy(f1, "Blacklist");
		strcpy(f2, "The Feed");
		strcpy(f3, "Curon");
	}
	
		//lista 20:
	if (r->info.codigo == 39){
		strcpy(f1, "Ratched");
		strcpy(f2, "Scream");
		strcpy(f3, "Curon");
	}
	
		//lista 21 assao:
	if (r->info.codigo == 41){
		strcpy(f1, "O Atirador");
		strcpy(f2, "Irmandade");
		strcpy(f3, "Damnation");
	}
	
		//lista 22 assao:
	if (r->info.codigo == 43){
		strcpy(f1, "Demolidor");
		strcpy(f2, "Bloodshot");
		strcpy(f3, "Secret Origins");
	}
	
		//lista 23 aventura:
	if (r->info.codigo == 45){
		strcpy(f1, "The Witcher");
		strcpy(f2, "Cursed");
		strcpy(f3, "The Magicians");
	}
	
		//lista 24:
	if (r->info.codigo == 47){
		strcpy(f1, "Spartacus");
		strcpy(f2, "Vikings");
		strcpy(f3, "Jack Ryan");
	}
	
		//lista 25:
	if (r->info.codigo == 49){
		strcpy(f1, "Gumball");
		strcpy(f2, "Rick and Morty");
		strcpy(f3, "Os Simpsons");
	}
	
		//lista 26:
	if (r->info.codigo == 51){
		strcpy(f1, "The Office");
		strcpy(f2, "Brooklyn Nine-Nine");
		strcpy(f3, "Lucifer");
	}
	
		//lista 27:
	if (r->info.codigo == 53){
		strcpy(f1, "As Telefonistas");
		strcpy(f1, "Easy");
		strcpy(f3, "Younger");
	}
	
		//lista 28:
	if (r->info.codigo == 55){
		strcpy(f1, "Find Yourself");
		strcpy(f2, "Pousando no Amor");
		strcpy(f3, "Love 101");
	}
	
		//lista 29:
	if (r->info.codigo == 57){
		strcpy(f1, "Behind Bars");
		strcpy(f2, "Quilos Mortais");
		strcpy(f3, "O Monstro ao Lado");
	}
		//lista 30:
	if (r->info.codigo == 59){
		strcpy(f1, "O Codigo Bill Gates");
		strcpy(f2, "Cosmos");
		strcpy(f3, "High Score");
	}
	
		//lista 31:
	if (r->info.codigo == 61){
		strcpy(f1, "Locke & Key");
		strcpy(f2, "Pose");
		strcpy(f3, "Dilema");
	}
	
		//lista 32:
	if (r->info.codigo == 63){
		strcpy(f1, "3%");
		strcpy(f2, "The Sinner");
		strcpy(f3, "13 Reasons Why");
	}

                          //// Além de armazenar as listas, a função printa o filme/serie recomendado.
                         											
int op;
	printf("O título sugerido para você é: %s\n", f1);
	printf("\nVocê deseja: \n");
	printf("[1] - Sugerir outro título semelhante.\n");				 //// Caso o usuário queira outra  sugestão, ela passa a recomendar outro, em um total de 3 opções.
	printf("[2] - Encerrar Programa.\n");
	printf("Opção: ");
	fflush(stdin);
	scanf("%d", &op);
	system("cls");
	switch(op) {
		case 1:
			printf("\nEntão que tal: %s\n", f2);
			break;
		case 2: 
			exit(0);
	}
		
	printf("\nVocê deseja: \n");
	printf("[1] - Sugerir outro título semelhante.\n");
	printf("[2] - Encerrar Programa.\n");
	printf("Opção: ");
	scanf("%d", &op);
	system("cls");
	switch(op) {
		case 1:
			printf("\nHmmm, ainda posso sugerir: %s\n", f3);
			break;
		case 2: 
			exit(0);
	}
	
	printf("\nVocê deseja: \n");
	printf("[1] - Sugerir outro título semelhante.\n");
	printf("[2] - Encerrar Programa.\n");
	printf("Opção: ");
	scanf("%d", &op);
	system("cls");
	switch(op) {
		case 1:
			printf("\nDesculpa, não temos mais títulos semelhantes para indicar.");
			getchar();
			break;
		case 2: 
			exit(0);
    }
    
}

 //// FUNÇÃO APENAS PARA ESTÉTICA DO MENU 

void loading (){
	
	system("cls");
	printf("\nAguarde!\nCarregando Catálogo: 10%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 13%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 17%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 25%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 31%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 44%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 59%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 66%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 72%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 88%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 92%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Catálogo: 100%%");
	Sleep(700);
	system ("cls");
	printf("\n\nCARREGAMENTO CONCLUÍDO.");
	Sleep(700);
	
}
