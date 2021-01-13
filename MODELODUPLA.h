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

1) A atividades consiste em agrupar as crianças em um círculo (organizado no sentido anti-horário)
do qual seriam retiradas uma a uma até que sobrasse apenas uma criança, que seria a vencedora.

2) No momento em que entra no círculo, cada criança recebe uma pequena ficha que contém um valor de 1 a 500.

3) Depois que o círculo é formado, conta-se, iniciando na criança que está ao lado da primeira que entrou no
 círculo, o número correspondente à ficha que a primeira detém.
 
4) A criança onde o número contado cair, deve ser retirada do grupo.

5) A contagem inicia novamente segundo a ficha da criança que acabou de ser eliminada. 
       PORÉM:
       a) quando o valor que consta na ficha é par, a contagem é feita no sentido horário
	   b) quando o valor que consta na ficha é ímpar, a contagem é feita no sentido anti-horário. 

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

 
typedef struct{             // registro pessoa
       int  codigo;
       char nome[30];
}INFORMACAO;
       
typedef struct nodo {
       INFORMACAO info;     // dados do registro
       struct nodo* prox;   // ponteiro para o próximo registro
       struct nodo* ant;    // ponteiro para o registro anterior
}NODO; 
