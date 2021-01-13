
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Programa em C desenvolvido na cadeira de Programação para Resolução de Problemas - UNISC/2020   ////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////// Função:  Imprime caracteres em tamanho grande usando simbolos da tabela ASC II     /////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#include <stdio.h>
#define MAX 100 //tamanho máximo da matriz (fonte)
#define SIMB 178 //símbolo da caixinha toda preenchida

void fLetraA(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j==0)
				mat[i][j] = SIMB;//perna esquerda do A
				
			else if(i==0)
				mat[i][j] = SIMB;//parte de cima do A
			
			else if(j == t-1)
				mat[i][j] = SIMB;//perna direita do A
				
			else if(i == t/2)
				mat[i][j] = SIMB;//linha central do A
				
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}
void fLetraB(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j==0)
				mat[i][j] = SIMB;//perna esquerda do B
				
			else if(i==0 && j != t-1)
				mat[i][j] = SIMB;//parte de cima do B
			
			else if(i == t-1 && j != t-1)
				mat[i][j] = SIMB;//parte de baixo do B
				
			else if(i == t/2 && j!= t-1)
				mat[i][j] = SIMB;//linha central do B
			
			else if( j == t-1 && i != 0 && i != t-1 && i != t/2 ) //linha direita do B
				mat[i][j] = SIMB;
			
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}

void fLetraC(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j == 0 || j == 1 || i == 0 || i == t-1) // caso for a primeira ou segunda coluna, a primeira linha, ou a ultima linha-1 ele vai preencher com o caractere
				mat[i][j] = SIMB;
			else
				mat[i][j] = ' '; //espaços que não devem preenchidos
		}
	}	
}
void fLetraD(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j==0)
				mat[i][j] = SIMB;//perna esquerda do D
				
			else if(i==0 && j != t-1)
				mat[i][j] = SIMB;//parte de cima do D
			
			else if(i == t-1 && j != t-1)
				mat[i][j] = SIMB;//parte de baixo do D
				
			
			else if( j == t-1 && i != 0 && i != t-1)
				mat[i][j] = SIMB;
			
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}
void fLetraE(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j==0)
				mat[i][j] = SIMB;//perna esquerda do E
				
			else if(i==0)
				mat[i][j] = SIMB;//parte de cima do E
			
			else if(i == t-1)
				mat[i][j] = SIMB;//parte de baixo do E
				
			else if(i == t/2)
				mat[i][j] = SIMB;//linha central do E
				
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}
void fLetraF(char mat[][MAX], int t){
	int i, j;
	
	for(i = 0; i < t; i ++){
		for(j = 0; j < t; j ++){
			if(j == 0)
				mat[i][j] = SIMB;	//Perna esquerda
				
			else if(i == 0)	
				mat[i][j] = SIMB;	//Parte de cima
			
			else if(i == t / 2)
				mat[i][j] = SIMB;	//Linha do meio
			
			else
				mat[i][j] = ' ';	//Espaços em branco
		}
	}
}
void fLetraG(char mat[][MAX], int t){
	int i, j;
	
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			
			if(j == 0)//imprime |
				mat[i][j] = SIMB;
			
			else if(i==0)//imprime -
				mat[i][j] = SIMB;
					
			else if(i == t-1)//imprime - 
				mat[i][j] = SIMB;
			
			else if(j == t-1 && i > t/2)//imprime |
				mat[i][j] = SIMB;
				
			else if(i == t/2 && j > 1)//imprime -
				mat[i][j] = SIMB;
				
			else
				mat[i][j] = ' ';

		}
	}
	
}
void fLetraH(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j==0)
				mat[i][j] = SIMB;   //perna esquerda do H
			
			else if(j == t-1)
				mat[i][j] = SIMB;   //perna direita do H
				
			else if(i == t/2 )
				mat[i][j] = SIMB;   //linha central do H
				
			else
				mat[i][j] = ' ';   //espaços que não devem preenchidos
		}
	}	
}
void fLetraI(char mat[][MAX], int t){

	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j == t/2){
				mat[i][j] = SIMB;
			}
			else if(i==0){
				mat[i][j] = SIMB;
			}
			else if(i==t-1){
				mat[i][j] = SIMB;
			}
			else{
				mat[i][j] = ' ';
			}
		}
	}
}
void fLetraJ(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i==0)
				mat[i][j] = SIMB;//parte de cima do J
			
			else if(j == t/2)
				mat[i][j] = SIMB;//corpo do J
		
			else if(i==t-1 && j<=t/2)
				mat[i][j] = SIMB;//perna do J
			
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}
void fLetraK(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
				if(j==0)
				mat[i][j]=SIMB;	//esquerda
				
			else if(i == t - j - 2 && i < t+1/2)
			mat[i][j]=SIMB; // diagonal
			
			else if(j-1 == i/2 && i > t/2.2)
				mat[i][j]=SIMB;	//diagonal
							
			else
				mat[i][j] =' ';	//Espaços em branco
		}
	}	
}

void fLetraL(char mat[][MAX], int t){
	int i, j;								//definindo as variaveis
	for(i=0; i<t; i++){						//for da linha da matriz
		for(j=0; j<t; j++){					//for da coluna da matriz
			if(j==0)						//verifica se é a primeira coluna
				mat[i][j] = SIMB;			//atribui o valor 178 a matriz
			else if(i == t-1)				//verifica se é a ultima linha
				mat[i][j] = SIMB;			//atribui o valor 178 a matriz
			else
				mat[i][j] = ' ';			//espaço em branco
		}
	}	
}
void fLetraM(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j==0)
				mat[i][j] = SIMB;//perna esquerda do M
				
			else if(i == j - 1 && i < t/2)
				mat[i][j] = SIMB;//parte diagonal esquerda
			
			//else if(j - 1 == i/2 && i - 1 <= t/2)
			//	mat[i][j] = SIMB;//parte diagonal esquerda
				
			//else if(j - 1 == i/2 )
			//	mat[i][j] = SIMB;//parte diagonal esquerda
			
			//else if(i == j * (1) )
			//	mat[i][j] = SIMB;//parte diagonal esquerda
		
			else if(i == t - j - 2 && i < t/2)
				mat[i][j] = SIMB;//parte diagonal direita
				
			else if(j == t - 1)
				mat[i][j] = SIMB;//linha central do A
				
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}
void fLetraN(char mat[][MAX], int t){
    
	int i,j;
	for (i = 0; i < t; i++){
        for (j = 0; j < t; j++){
            if (j == 0 || i == j || j == t - 1) // Caso seja a primeira coluna, diagonal principal ou diagonal secundária
                mat[i][j] = 178;                // Nesta posição da matriz, é atribuido o caractere 178
            //printf("%c", 178);
            else                 // Caso não seja validado a condicional
                mat[i][j] = ' '; // Nesta posição da matriz, é atribuido espaço em branco ' '
 		}
	}
}
void fLetraO(char mat[][MAX], int t){
	
	int i, j;
	
	for (i=0; i<t; i++){
		for(j=0;j<t; j++){
			
			if(j==0)
				mat[i][j] = SIMB; 
				
			else if(i == 0)
				mat[i][j] = SIMB; 
				
			else if(i == t - 1)
				mat[i][j] = SIMB; 
			
			else if(j == t -1)
				mat[i][j] = SIMB;
			
			else
				mat[i][j] = ' ';
					
		}
}

}
void fLetraP(char mat[][MAX], int t){
	int i, j;
	
	for(i = 0; i < t; i ++)
	{
		for(j = 0; j < t; j ++)
		{
			if(j == 0)
				mat[i][j] = SIMB;	//Perna esquerda
				
			else if(i == 0)	
				mat[i][j] = SIMB;	//Parte de cima
			
			else if(i == t/2 - 1)
				mat[i][j] = SIMB;	//Linha do meio
			
			else if(j == t-1 && i < t/2)
				mat[i][j] = SIMB;	//linha da direita até o meio			
			else
				mat[i][j] = ' ';	//Espaços em branco
		}
	}
}
void fLetraQ(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j == 0)
				mat[i][j] = SIMB;				// PARTE DE ESQUERDA

			else if(i == 0)
				mat[i][j] = SIMB;				// PARTE DE CIMA	
				
			else if(i == (t-1))
				mat[i][j] = SIMB;				// PARTE DE BAIXO
				
			else if(j == (t-1))
				mat[i][j] = SIMB;				// PARTE DE DIREITA	
	
			else if(j > t/2 && i==j)
				mat[i][j] = SIMB;				// PONTA DIREITA INFERIOR	
		
			else
				mat[i][j] = ' ';

		}
	}	
}
void fLetraR(char mat[][MAX], int t){
	int i, j;
	
	for(i=0; i<t; i++)
	{
		for(j=0; j<t;j++)
		{
			if(j==0)
				mat[i][j] = SIMB; //esquerda
				
			else if(i==0 && j != t-1)
				mat[i][j] = SIMB;//cima
			
			
			else if(i == t/2 && j!= t-1)
				mat[i][j] = SIMB;//linha central do B
			
			else if( j == t-1 && i != 0 && i != t-1 && i != t/2 && i < t/2 ) //linha direita do B
				mat[i][j] = SIMB;
			else if(j-1 == i/2 && i > t/2.2)
				mat[i][j]=SIMB;	//diagonal
		}
	}
}
void fLetraS(char mat[][MAX], int t){
	
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i == 0)
				mat[i][j] = SIMB;				// CIMA

			else if(i == (t-1))
				mat[i][j] = SIMB;				// BAIXO
				
			else if(i == t/2)
				mat[i][j] = SIMB;				// MEIO	
	
			else if(j == t-1 && i > t/2)
				mat[i][j] = SIMB;				// DIREITA INFERIOR	
		
			else if (j == 0 && i < t/2)			// ESQUERDA SUPERIOR
				mat[i][j] = SIMB;
			
			else
				mat[i][j] = ' ';

		}
	}	
}
void fLetraT(char mat[][MAX], int t){
	int i, j;
	for (i = 0; i<t; i++){
		for (j=0; j<t; j++){
			if (i == 0)//primeira linha do T
				mat[i][j] = SIMB;
			else if (j == t/2)//perna do T
				mat[i][j] = SIMB;
			else if (t > 5 && j == t/2-1)//perna do T, se T for maior que 5 pra n ficar bugado
				mat[i][j] = SIMB;			
			else //espaçamento
				mat[i][j] = ' ';
		}
	}	
}
void fLetraU(char mat[][MAX], int t){
	
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(j==0)
				mat[i][j] = SIMB;//perna esquerda do U
				
			else if(i== t-1)
				mat[i][j] = SIMB;//parte de baixo do U
			
			else if(j == t-1)
				mat[i][j] = SIMB;//perna direita do U
				
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}
void fLetraX(char mat[][MAX], int t){
	int i, j;
	
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			
			if (i == t - j)
				mat[i][j] = SIMB;
			
			else if (j == t-1 && i == 0)
				mat[i][j] = SIMB; 	
			
			else if(i == j )
				mat[i][j] = SIMB;  //linha diagonal
				
			else
				mat[i][j] = ' ';  //espaços que não devem preenchidos
		}
	}	
}

void fLetraZ(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i==0)
					mat[i][j]=SIMB;	//parte de cima
			
			else if(i == t - j - 1 && i < t )
				mat[i][j]=SIMB;	//diagonal
				
			else if (i==t-1)
				mat[i][j]=SIMB;	// parte de baixo
							
			else
				mat[i][j] ='  ';//espaços que não devem ser preenchidos
		}
	}	
}

void fNum1(char mat[][MAX], int t){

    int i, j; //Variáveis para percorrer a matriz

    for(i = 0; i < t; i++){ //Percorre as linhas
        for(j = 0; j < t; j++){ //Percorre as colunas
            mat[i][j] = ' '; //Por padrão a matriz recebe espaço
            if(!(t % 2)){ //Se for ímpar
                if((i == t - 1 && j != t - 1) || j == t / 2 - 1 || ((j < t / 2 && j >= t / 4 - 1) && i == 1)){ //Faz as comparações para o desenho
                    mat[i][j] = SIMB; //Atribui um caractere especial
                }
            }
            else{ //Se for par
                if(j == t / 2 || (i == t - 1 && j != 0 && j != t - 1) || ((j < t / 2 && j > t / 4 - 1) && i == 1)){ //Faz as comparações para o desenho
                    mat[i][j] = SIMB; //Atribui um caractere especial
                }
            }
        }
    }
}
void fNum2(char mat[][MAX], int t){
	
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i == 0)
				mat[i][j] = SIMB;				// CIMA

			else if(i == (t-1))
				mat[i][j] = SIMB;				// BAIXO
				
			else if(i == t/2)
				mat[i][j] = SIMB;				// MEIO	
	
			else if(j == t-1 && i < t/2)
				mat[i][j] = SIMB;				// DIREITA SUPERIOR	
		
			else if (j == 0 && i > t/2)			// ESQUERDA INFERIOR
				mat[i][j] = SIMB;
			
			else
				mat[i][j] = ' ';

		}
	}	
}
void fNum3(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i == 0)
				mat[i][j] = SIMB;// linha superior 3
			
			else if( i == t-1)
				mat[i][j] = SIMB;// linha inferior 3
				
			else if(i == t/2 )
				mat[i][j] = SIMB;// linha central do 3
			
			else if ( j == t-1)
				mat[i][j] = SIMB; // perna direita do 3	
			else
				mat[i][j] = ' '; // espaços que não devem preenchidos
		}
	}	
}
void fNum4(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i == t/2 )
				mat[i][j] = SIMB;// linha central 
			
			else if ( j == t-1)
				mat[i][j] = SIMB; // perna direita
			
			else if ( j == 0 && i < t/2)
				mat[i][j] = SIMB; // perna esquerda 
			else
				mat[i][j] = ' '; // espaços que não devem preenchidos
		}
	}	
}
void fNum5(char mat[][MAX], int t){
	
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i == 0)
				mat[i][j] = SIMB;				// CIMA

			else if(i == (t-1))
				mat[i][j] = SIMB;				// BAIXO
				
			else if(i == t/2)
				mat[i][j] = SIMB;				// MEIO	
	
			else if(j == t-1 && i > t/2)
				mat[i][j] = SIMB;				// DIREITA INFERIOR	
		
			else if (j == 0 && i < t/2)			// ESQUERDA SUPERIOR
				mat[i][j] = SIMB;
			
			else
				mat[i][j] = ' ';

		}
	}	
}
void fNum6(char mat[][MAX], int t){
	int i, j;
	
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			
			if(j == 0)  
				mat[i][j] = SIMB;  //esquerda
								
			else if(i == t-1) 
				mat[i][j] = SIMB;  //baixo
			
			else if(j == t-1 && i > t/2)  //direita
				mat[i][j] = SIMB;
				
			else if(i == t/2)  
				mat[i][j] = SIMB;
				
			else
				mat[i][j] = ' ';

		}
	}
	
}
void fNum7(char mat[][MAX], int t){
	
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			
			if(i==0)
				mat[i][j] = SIMB ;//parte de cima do 7
				
			else if(j == t-1 )
				mat[i][j] = SIMB; //perna direita do 7
			else
				mat[i][j] = ' ';
				
		}
	}
}
void fNum8(char mat[][MAX], int t){
	int i, j;
	
	for(i=0; i<t; i++){
		for(j=0; j<t; j++)
		{
			if(j==0)
				mat[i][j] = SIMB;
				
			else if(i==0)
				mat[i][j] = SIMB;
			
			else if(j==t-1)
				mat[i][j] = SIMB;
				
			else if(i==t-1)
				mat[i][j] = SIMB;
				
			else if(i == t/2)
				mat[i][j] = SIMB;
				
			else
				mat[i][j] = ' ';
		}
	}	
}
void fNum9(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			if(i == 0)
				mat[i][j] = SIMB;// linha superior 9
						
			else if(i == t/2 )
				mat[i][j] = SIMB;// linha central do 9
			
			else if ( j == t-1)
				mat[i][j] = SIMB; // perna direita do 9
			
			else if ( j == 0 && i < t/2)
				mat[i][j] = SIMB; // perna esquerda do 9
			else
				mat[i][j] = ' '; // espaços que não devem preenchidos
		}
	}	
}
void fNum0(char mat[][MAX], int t){
	int i, j;
	
	for(i=0; i<t; i++){
		for(j=0; j<t; j++){
			
			if(j==0)
				mat[i][j] = SIMB;//linha esquerda do 0
				
			else if(i==0)
				mat[i][j] = SIMB;//parte de cima do 0
			
			else if(j == t - 1)
				mat[i][j] = SIMB;//linha direita do 0
				
			else if(i == t - 1 )
				mat[i][j] = SIMB;//linha inferior do 0
				
			else if(i == j )
				mat[i][j] = SIMB;//linha central (diagonal) do 0
				
			else
				mat[i][j] = ' ';//espaços que não devem preenchidos
		}
	}	
}


void fImprime(char mat[][MAX], int t){
	int i, j;
	for(i=0; i<t; i++){
		printf("\n");
		for(j=0; j<t; j++){
			printf("%c", mat[i][j]);
		}
	}
}

int main(){
	int t, ok;
	char letra, mat[MAX][MAX];
	
	printf("Informe o tamanho da fonte: ");
	scanf("%d", &t);
	
	printf("Agora informe as letras ou numeros: ");
	while(letra != 27){
		letra = getch();
		letra = toupper(letra);//passa para maiúscula
		ok = 0;//controle para ver se passou por uma função
		
		switch(letra){
			case 'A':
				fLetraA(mat, t);
				ok=1;
				break;
			case 'B':
				fLetraB(mat, t);
				ok=1;
				break;
			case 'C':
				fLetraC(mat, t);
				ok=1;
				break;
			case 'D':
				fLetraD(mat, t);
				ok=1;
				break;
			case 'E':
				fLetraE(mat, t);
				ok=1;
				break;
			case 'F':
				fLetraF(mat, t);
				ok=1;
				break;
			case 'G':
				fLetraG(mat, t);
				ok=1;
				break;
			
			case 'H':
				fLetraH(mat, t);
				ok=1;
				break;
			case 'I':
				fLetraI(mat, t);
				ok=1;
				break;
			case 'J':
				fLetraJ(mat, t);
				ok=1;
				break;
			case 'K':
				fLetraK(mat, t);
				ok=1;
				break;
			case 'L':
				fLetraL(mat, t);
				ok=1;
				break;
			case 'M':
				fLetraM(mat, t);
				ok=1;
				break;
			case 'N':
				fLetraN(mat, t);
				ok=1;
				break;
			case 'O':
				fLetraO(mat, t);
				ok=1;
				break;
			case 'P':
				fLetraP(mat, t);
				ok=1;
				break;
			case 'Q':
				fLetraQ(mat, t);
				ok=1;
				break;
			case 'R':
				fLetraR(mat, t);
				ok=1;
				break;
			case 'S':
				fLetraS(mat, t);
				ok=1;
				break;
			case 'T':
				fLetraT(mat, t);
				ok=1;
				break;
			case 'U':
				fLetraU(mat, t);
				ok=1;
				break;
			case 'X':
				fLetraX(mat, t);
				ok=1;
				break;
			case 'Z':
				fLetraZ(mat, t);
				ok=1;
				break;
			case '1':
				fNum1(mat, t);
				ok=1;
				break;
			case '2':
				fNum2(mat, t);
				ok=1;
				break;
			case '3':
				fNum3(mat, t);
				ok=1;
				break;
			case '4':
				fNum4(mat, t);
				ok=1;
				break;
			case '5':
				fNum5(mat, t);
				ok=1;
				break;
			case '6':
				fNum6(mat, t);
				ok=1;
				break;
			case '7':
				fNum7(mat, t);
				ok=1;
				break;
			case '8':
				fNum8(mat, t);
				ok=1;
				break;
			case '9':
				fNum9(mat, t);
				ok=1;
				break;
			case '0':
				fNum0(mat, t);
				ok=1;
				break;

				
		}
		printf("\n");
		if(ok)
			fImprime(mat, t);
		
	}
	
}
