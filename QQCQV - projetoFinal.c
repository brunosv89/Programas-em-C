//////////////////////////////////////////////////////  Trabalho Estrutua de Dados e Programa��o   /////
/////////////////////////////////////////////////////  �rvore Bin�ria de decis�o                  //////
////////////////////////////////////////////////////  Alunos: Bruno Soares Vasques e Lucas Zatt  ///////
///////////////////////////////////////////////////	Data: Dezembro de 2020                      ////////

///////////////////////////////////////////////// FUN��O DO PROGRAMA: SUGERIR FILMES/SERIES  ///////////
//////////////////////////////////////////////// AO USU�RIO DE ACORDO COM A INTERA��O,      ////////////
/////////////////////////////////////////////// ATRAV�S DE UMA �RVORE DE DECIS�O           /////////////


////////////////////////////////////////////////////  BIBLIOTECAS  /////////////////////////////////////                               

#include <stdio.h>     
#include <conio.h>     
#include <stdlib.h>   
#include <string.h>    
#include <locale.h>    

////////////////////////////////////////////////////  ESTRUTURA DOS REGISTROS  /////////////////////////

typedef struct {          
    int  codigo;        // valor inteiro para manipula��o e montagem da �rvore
} INFORMACAO;
       
typedef struct arv {
       INFORMACAO info;   
       struct arv *subd;  // ponteiro para a subarvore da direita
       struct arv *sube;  // ponteiro para a subarvore da esquerda
} ARVORE; 


////////////////////////////////////////////////////  DEFINI��ES DAS FUN��ES  //////////////////////////


void   cria_ARVORE ( ARVORE **r );           // inicializa �rvore
void   attCatalogo ( ARVORE **r );			 // fun��o que monta a �rvore
void   insereNodos ( ARVORE **r, int cod );  // fun��o auxiliar para montar a �rvore
void   entrada_dados ( ARVORE *aux ); 		 // fun��o auxiliar
void   loading ();							 // est�tica para o menu
void   percorreArvore( ARVORE **r );		 // fun��o principal que desce na �rvore at� encontrar a lista de filme e s�ries a ser indicada
void   listaFilmes ( ARVORE *r );			 // fun��o auxiliar que guarda as listas de filmes e s�ries
void   perguntas   ( ARVORE *r );       	 // fun��o auxiliar que faz as perguntas da �rvore de decis�o
void   imprime_ARVORE  ( ARVORE *aux );      // fun��o inativa, apenas para controle



/////////////////////////////////////////////////////                      /////////////////////////////
////////////////////////////////////////////////////  PROGRAMA PRINCIPAL  //////////////////////////////
///////////////////////////////////////////////////                      ///////////////////////////////

int main( void )
{
    char op;       // op��o do menu                               
    ARVORE *r, *p; // declara��o da ARVORE, vari�vel do tipo ARVORE = ARVORE de ponteiros
  
    
    setlocale(LC_ALL, "Portuguese");   //idioma e caracteres
    
	cria_ARVORE( &r );        // planta a mudinha
    
    
    while( 1 ){
    	printf( "\n ---------------------------------------- "); 
    	printf( "\n ----------------QQCQV------------------- "); 
        printf( "\n ---------------------------------------- ");
		printf( "\n --- Instru��es: Carregue o cat�logo  --- ");
		printf( "\n -------- para atualiz�-lo antes -------- ");
		printf( "\n -------- de iniciar o programa. -------- "); 
		printf( "\n ---------------------------------------- ");
        printf( "\n ---  [1] Carregar Catalogo           --- ");
		printf( "\n ---  [2] Me indique um filme/serie   --- ");	
		printf( "\n ---  [0] Para sair do programa       --- ");         
        printf( "\n ---------------------------------------- ");      
        printf( "\n Opcao: " );
        op = getche(); // tecla de op��o do menu

        switch( op ) {
            case '1':      
                attCatalogo( &r );
                //imprime_ARVORE( r );
				loading();
				break;
				
			case '2':  // t�rmino do programa                                                 
                percorreArvore ( &r ); 
                break;
                
           case '0':  // t�rmino do programa                                                 
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


////////////////////////////////////////////////////  Fun��o para criar a raiz da �rvore  /////////////


void cria_ARVORE( ARVORE **r ){
	
    *r = NULL; 
}


////////////////////////////////////////////////////  Fun��o para montar a �rvore  ////////////////////

void attCatalogo( ARVORE **r ) {
	
	int cod;														//vetor com os nodos em ordem de inser��o:
    int array[63] = {32,16,48,8,24,40,56,4,12,20,28,36,44,52,60,2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63};  
    int i;										
	
	for (i=0;i<64;i++){          //la�o para inserir na ordem pr� definida no array, desta forma j� est� balanceada
		cod = array[i];				
        insereNodos( r, cod );   // fun��o que insere os nodos recursivamente
        fflush(stdin);
    }
	
}

////////////////////////////////////////////////////  Fun��o para povoar a �rvore  ////////////////////

void insereNodos ( ARVORE **p, int cod ){
   if( *p == NULL ){                                     
        ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
        no->info.codigo = cod;
        no->subd= NULL;                              // inicializa sub�rvore da direita
        no->sube= NULL;								 // inicializa sub�rvore da esquerda
        *p= no;                                      // anda com o ponteiro
        //printf( "\n Registro inserido!" );   
   }else{
         if( (*p)->info.codigo > cod )               // verifica se c�digo a ser inserido � menor que o valor do registro para qual o p aponta
              insereNodos( &(*p)->sube, cod );       // anda com o ponteiro p para a esquerda, pois o c�digo procurado � menor
         else
              if( (*p)->info.codigo < cod )          // verifica se c�digo a ser inserido � maior que o valor do registro para qual o p aponta
                   insereNodos ( &(*p)->subd, cod ); // anda com o ponteiro p para a direita, pois o c�digo procurado � maior 
              else
                 printf( "\nNULL");    
		}
} 

//  FUN��O AUXILIAR 
void entrada_dados( ARVORE* aux )
{ 
 
    aux->subd = NULL;   
    aux->sube = NULL;    

}

////////////////////////////////////////////////////  Fun��o para impress�o  /////////////////////////
// Fun��o de apoio durante a montagem da �rvore

void imprime_ARVORE( ARVORE *aux ){    
     
    if( aux != NULL ){              // verifica se a raiz � diferente de vazio
        printf( "\n C�digo.....: %d", aux->info.codigo );     
		getchar();
        printf( "\n <<-- Esquerda" );
        imprime_ARVORE( aux->sube ); // recursivo, segue pelo caminho da esquerda
        printf( "\n Direita -->>" );
        imprime_ARVORE( aux->subd ); // recursivo, segue pelo caminho da direita
    }
    else
       printf("\nNULL!");
}

////////////////////////////////////////////////////  Fun��o "Principal"  ///////////////////////////
// Percorre o caminho da �rvore de acordo com as decis�es do usu�rio at� chegar no nodo folha


void percorreArvore( ARVORE **r ) {
	
	system("cls");
	
	printf("\nBEM VINDO AO QQCQV!\n");               
	int lado;
	ARVORE *p = *r;
	
	while ((*r)->subd != NULL) {    // o processo abaixo � realizado at� chegar ao nodo folha
	
//	printf("\nCodigo: %d\n", (*r)->info.codigo);
	perguntas(*r);                                // chama a fun��o onde est�o as perguntasa para questionar a prefer�ncia do usu�rio
	printf("\nEscolha [1] ou [2]: ");			  // O usu�rio escolhe entre 2 op��es
	fflush(stdin);
	scanf("%d", &lado);
		switch(lado){
			case 1:                               // a op��o [1] leva para a sub�rvore da esquerda
				*r = (*r)->sube;
				break;
			case 2:                               // a op��o [2] leva para a sub�rvore da direita
				*r = (*r)->subd;
				break;
			default:
				printf("\ndigite uma op��o v�lida!");
		}
 	system("cls");
	 }

//	printf("\nCodigo: %d\n", (*r)->info.codigo);
	listaFilmes (*r);							  // chegando no nodo folha, � chamada a fun��o onde cont�m a lista de filmes para aquele nodo (resultado das decis�es)	

}

////////////////////////////////////////////////////  Fun��o auxiliar que armazena as peguntas  ///////

void perguntas(ARVORE *r){
	
	if (r->info.codigo == 2)
	printf("O que causa mais calafrios: [1] personagens assustadores ou coisas que voc� n�o pode ver? MUHAHAHAHA\n");
	
	if (r->info.codigo == 4)
	printf("Prefere [1] lidar com personagens assustadores, sangue e mutila��es ou [2] voc� gosta do clima de tens�o no ar, como se um espirito estivesse agora mesmo com a m�o no seu ombro? (se eu fosse voc� n�o olharia para atr�s agora.)\n ");
	
	if (r->info.codigo == 6)
	printf("O que mais lhe instiga suspense s�o [1] hist�rias de crime e mist�rio ou [2] algo mais profundo, quase psic�tico? (n�o escute as vozes da sua cabe�a, decida sozinho.)\n");
	
	if (r->info.codigo == 8)
	printf("Prefere algo [1] mais assustador e sombrio ou [2] aventuras com mais a��o e cheiro de p�lvora pelo ar?\n");
	
	if (r->info.codigo == 10)
	printf("Voc� � [1] daqueles que preferem manter os p�s no ch�o ou [2] uma pitadinha de fic��o n�o faz mal a ningu�m?\n");
	
	if (r->info.codigo == 12)
	printf("Prefere [1] estar no meio do fogo cruzado entre mocinhos e vil�es ou [2] voc� fantasia em viver aventuras perigosas que exigem muita coragem?\n");
	
	if (r->info.codigo == 14)
	printf("A sua � [1] explorar lugares in�spitos e lutar pela sobreviv�ncia sozinho ou [2] posso chamar uns super-her�is para ajudar a defender a exist�ncia do nosso planeta?\n");
	
	if (r->info.codigo == 16)
	printf("Voc� [1] est� energizado buscando explos�es, assassinatos, tiro, porrada e bomba ou [2] prefere algo mais calmo e inspirador, para sentir-se confort�vel sozinho ou com a fam�lia?\n");
	
	if (r->info.codigo == 18)
	printf("Voc� [1] precisa de um esfor�o ou [2] � daqueles que ri de qualquer besteira?\n");
	
	if (r->info.codigo == 20)
	printf("� [1] pra rir ou [2] pra chorar? rsrs\n");
	
	if (r->info.codigo == 22)
	printf("Menu do dia: [1] Sempre tem uma com�dia rom�ntica fresquinha saindo do forno ou [2] talvez voc� precise de algo mais profundo?\n");
	
	if (r->info.codigo == 24)
	printf("Prefere [1] hist�rias de amor e divers�o ou [2] algo mais dram�tico e inspirador?\n");
	
	if (r->info.codigo == 26)
	printf("[1] Hist�rias inspiradas em fatos reais ou [2] dramas que poderiam acontecer com qualquer um?\n");
	
	if (r->info.codigo == 28)
	printf("As hist�rias que te inspiram [1] s�o aquelas bem contadas e produzidas com �timos atores ou [2] s�o aquelas hist�rias reais, os bastidores e a viv�ncias, contadas de forma documental?\n");
	
	if (r->info.codigo == 30)
	printf("Prefere [1] acompanhar a vida e obra de pessoas relevantes ou [2] document�rios em geral?\n");
	
	if (r->info.codigo == 32)
	printf("Vamos come�ar! Primeiro me diz: Quer ver [1] um FILME ou [2] uma S�RIE? \n");
	
	if (r->info.codigo == 34)
	printf("Prefere [1] multiplas hist�rias e creepypastas ou [2] apeans uma hist�ria de tremer a espinha?\n");
	
	if (r->info.codigo == 36)
	printf("Prefere [1] ver sangue e multila��o ou [2] sentir que algo est� te observando? (o que � aquilo ali na janela?)\n");
	
	if (r->info.codigo == 38)
	printf("Prefere [1] uma s�rie de assassinatos e persegui��es ou [2] mist�rios e d�vidas?\n");
	
	if (r->info.codigo == 40)
	printf("Prefere [1] perder o sono e dormir com a luz acesa ou [2] sentir a adrenalina nas veias?\n");
	
	if (r->info.codigo == 42)
	printf("Prefere [1] algo mais realista e poss�vel ou [2] her�is com superpoderes insanos?\n");
	
	if (r->info.codigo == 44)
	printf("Prefere [1] tiro, soco e granada ou [2] aventuras de explora��o e exp�riencia?\n");
	
	if (r->info.codigo == 46)
	printf("Prefere [1] uma hist�ria que envolve monstros do djabo ou [2] algo mais envolvido com humanos?\n");
	
	if (r->info.codigo == 48)
	printf("Prefere [1] uma s�rie sobre crime, investiga��o, a��o e suspense ou [2] algo mais calmo que fa�a voc� pensar?\n");
	
	if (r->info.codigo == 50)
	printf("Prefere [1] um romance mais humor�stico e sem no��o ou [2] algo que toque seu cora��o?\n");
	
	if (r->info.codigo == 52)
	printf("Prefere [1] rir e se divertir ou [2] chorar e se apaixonar?\n");
	
	if (r->info.codigo == 54)
	printf("Prefere [1] uma com�dia espalhafatosa e besta ou [2] algo mais trabalhado?\n");
	
	if (r->info.codigo == 56)
	printf("Prefere [1] o choro e o riso ou [2] o drama e a informa��o?\n");
	
	if (r->info.codigo == 58)
	printf("Prefere [1] algo que mostre o mal no mundo ou [2] algo sobre id�ias e inven��es?\n");
	
	if (r->info.codigo == 60)
	printf("Prefere [1] se informar ou [2]se enganchar em uma hist�ria?\n");
	
	if (r->info.codigo == 62)
	printf("Prefere [1] um drama rom�ntico ou [2] algo que possa causar ang�stia e te prender na hist�ria?\n");
	
		
}

////////////////////////////////////////////////////  Fun��o auxiliar que armazena as listas  /////////


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
		strcpy(f2, "Invoca��o do Mal 2");
		strcpy(f3, "O Sono da Morte");
	}
	
	
		//lista 3:
	if (r->info.codigo == 5){
		strcpy(f1, "Seven - Os 7 crimes capitais");
		strcpy(f2, "Crime de Mestre");
		strcpy(f3, "Dossi� Pelicano");
	}
	
	
		//lista 4:
	if (r->info.codigo == 7){
		strcpy(f1, "Ilha do medo");
		strcpy(f2, "O po�o");
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
		strcpy(f2, "Mad Max - A estrada da f�ria");
		strcpy(f3, "A origem");
	}
	
	
		//lista 7:
	if (r->info.codigo == 13){
		strcpy(f1, "Bastardos Ingl�rios");
		strcpy(f2, "Jack Reacher - O �ltimo Tiro");
		strcpy(f3, "Enola Holmes");
	}
	
	
		//lista 8:
	if (r->info.codigo == 15){
		strcpy(f1, "Liga da Justi�a");
		strcpy(f2, "Batman - O cavaleiro das Trevas");
		strcpy(f3, "Indiana Jones");
 	}
	
	
		//lista 9:
	if (r->info.codigo == 17){
	
		strcpy(f1, "Forrest Gump");
		strcpy(f2, "De volta para o futuro");
		strcpy(f3, "Meu nome � Dolemite");
	}
	
	
		//lista 10:
	if (r->info.codigo == 19){
		strcpy(f1, "Loucademia de Pol�cia");
		strcpy(f2, "Gente Grande 2");
		strcpy(f3, "Superbad - � hoje!");
	}
	
	
		//lista 11:
	if (r->info.codigo == 21){
		strcpy(f1, "O amor n�o tira f�rias");
		strcpy(f2, "A barraca do Beijo");
		strcpy(f3, "At� que a sorte nos separe");
	}
	
	
		//lista 12:
	if (r->info.codigo == 23){
		strcpy(f1, "Quest�o de tempo");
		strcpy(f2, "Orgulho e preconceito");
		strcpy(f3, "Ela dan�a, eu dan�o");
	}
	
	
		//lista 13:
	if (r->info.codigo == 25){
		strcpy(f1, "Marshal - Igualdade e Justi�a");
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
		strcpy(f3, "Senna - O Brasileiro, o her�i, o campe�o");
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
		strcpy(f2, "A Maldi��o da Mans�o Bly");
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

                          //// Al�m de armazenar as listas, a fun��o printa o filme/serie recomendado.
                         											
int op;
	printf("O t�tulo sugerido para voc� �: %s\n", f1);
	printf("\nVoc� deseja: \n");
	printf("[1] - Sugerir outro t�tulo semelhante.\n");				 //// Caso o usu�rio queira outra  sugest�o, ela passa a recomendar outro, em um total de 3 op��es.
	printf("[2] - Encerrar Programa.\n");
	printf("Op��o: ");
	fflush(stdin);
	scanf("%d", &op);
	system("cls");
	switch(op) {
		case 1:
			printf("\nEnt�o que tal: %s\n", f2);
			break;
		case 2: 
			exit(0);
	}
		
	printf("\nVoc� deseja: \n");
	printf("[1] - Sugerir outro t�tulo semelhante.\n");
	printf("[2] - Encerrar Programa.\n");
	printf("Op��o: ");
	scanf("%d", &op);
	system("cls");
	switch(op) {
		case 1:
			printf("\nHmmm, ainda posso sugerir: %s\n", f3);
			break;
		case 2: 
			exit(0);
	}
	
	printf("\nVoc� deseja: \n");
	printf("[1] - Sugerir outro t�tulo semelhante.\n");
	printf("[2] - Encerrar Programa.\n");
	printf("Op��o: ");
	scanf("%d", &op);
	system("cls");
	switch(op) {
		case 1:
			printf("\nDesculpa, n�o temos mais t�tulos semelhantes para indicar.");
			getchar();
			break;
		case 2: 
			exit(0);
    }
    
}

 //// FUN��O APENAS PARA EST�TICA DO MENU 

void loading (){
	
	system("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 10%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 13%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 17%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 25%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 31%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 44%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 59%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 66%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 72%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 88%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 92%%");
	Sleep(700);
	system ("cls");
	printf("\nAguarde!\nCarregando Cat�logo: 100%%");
	Sleep(700);
	system ("cls");
	printf("\n\nCARREGAMENTO CONCLU�DO.");
	Sleep(700);
	
}
