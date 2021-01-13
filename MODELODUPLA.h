/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::::::::::::::::::::::::: DESAFIO EDP :::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::              EQUIPE: ADA LOVELACE           :::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::     Alunos: Bruno Vasques && Maria Grasieli     :::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::            Data: Outubro/2020               :::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:::::::::::::::::::::::::::::::::    REGRAS DA GINGANA:    ::::::::::::::::::::::::::::::::::::::::::::::::::

1) A atividades consiste em agrupar as crian�as em um c�rculo (organizado no sentido anti-hor�rio)
do qual seriam retiradas uma a uma at� que sobrasse apenas uma crian�a, que seria a vencedora.

2) No momento em que entra no c�rculo, cada crian�a recebe uma pequena ficha que cont�m um valor de 1 a 500.

3) Depois que o c�rculo � formado, conta-se, iniciando na crian�a que est� ao lado da primeira que entrou no
 c�rculo, o n�mero correspondente � ficha que a primeira det�m.
 
4) A crian�a onde o n�mero contado cair, deve ser retirada do grupo.

5) A contagem inicia novamente segundo a ficha da crian�a que acabou de ser eliminada. 
       POR�M:
       a) quando o valor que consta na ficha � par, a contagem � feita no sentido hor�rio
	   b) quando o valor que consta na ficha � �mpar, a contagem � feita no sentido anti-hor�rio. 

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

 
typedef struct{             // registro pessoa
       int  codigo;
       char nome[30];
}INFORMACAO;
       
typedef struct nodo {
       INFORMACAO info;     // dados do registro
       struct nodo* prox;   // ponteiro para o pr�ximo registro
       struct nodo* ant;    // ponteiro para o registro anterior
}NODO; 
