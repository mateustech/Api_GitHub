#include <stdio.h>	/*printf*/
#include <stdlib.h>	/*system*/

/**
* Fun��o: menuPrincipal
* Descri��o: apresenta o menu principal do sistema
*            ao usu�rio
* Par�metros: nada
* Retorno: nada
**/
void menuPrincipal(){
	printf("\n ---------- MENU PRINCIPAL ----------");
    printf("\n|                                    |");
    printf("\n|   1. CADASTRAR PACIENTE            |");	//Cadastra na fila
    printf("\n|   2. BUSCAR PACIENTE               |"); //Busca na fila 
    printf("\n|   3. PR�XIMO PACIENTE              |");	//Recebe um limite de tempo 
														//e retorna o proximo paciente 
														//com tempo menor que o limite
    printf("\n|   4. ATENDER FILA HOSPITAL         |");	//Pega 
    printf("\n|   5. IMPRIMIR DADOS                |");	//Abre o menu de impressao
    printf("\n|   6. GERAR RELAT�RIO               |");	//Salva os dados da lista
    													//num arquivo
    printf("\n|   7. AJUDA                         |");	
    printf("\n|   8. SAIR                          |");//default
    printf("\n|                                    |");
    printf("\n ------------------------------------\n>>> ");
}

/**
* Fun��o: submenuImpressao
* Descri��o: apresenta o submenu de impressao das
*            estruturas de dados do sistema
*			 ao usu�rio
* Par�metros: nada
* Retorno: nada
**/
void submenuImpressao(){
	
	printf("\n --- MENU DE IMPRESS�O ---");
	printf("\n|                         |");
	printf("\n|   1. FILA               |");
	printf("\n|   2. PILHA              |");
	printf("\n|   3. LISTA              |");
	printf("\n|   4. SAIR               |");
	printf("\n|                         |");
	printf("\n -------------------------\n >>> ");	
}

/**
* Fun��o: mensagemAjuda
* Descri��o: apresenta um tutorial explicando o fluxo normal
*            do sistema ao usu�rio, sem considerar casos
*		     excepcionais
* Par�metros: nada
* Retorno: nada
**/
void mensagemAjuda(){
	printf("\n -------------------------  AJUDA -------------------------");
    printf("\n|                                                          |");
	printf("\n| Para um funcionamento normal do sistema, siga estes      |");
	printf("\n| passos:                                                  |");
	printf("\n| (1) Cadastre os pacientes;                               |");
	printf("\n| (2) Busque um paciente por nome:                         |");
	printf("\n| (3) Pesquise o pr�ximo paciente pelo tempo de exame;     |");
	printf("\n| (4) Atenda a fila;                                       |");
	printf("\n| (5) Gere o relat�rio em um arquivo .txt;                 |");
    printf("\n| (6) Imprima a lista ou a fila ou a pilha quando desejar. |");
	printf("\n|                                                          |");		
	printf("\n ----------------------------------------------------------\n");
}

/**
* Fun��o:mensagemDespedida
* Descri��o: dado uma string, a fun��o
*            imprime na saida padr�o
* Par�metros: msg
* Retorno: nada
**/
void mensagemDespedida(char* msg){
    printf("\n%s\n\n",msg);
}

/**
* Fun��o:mensagemAbertura
* Descri��o: apresenta uma mensagem de abertura
*            do sistema ao usu�rio
* Par�metros: nada
* Retorno: nada
**/
void mensagemAbertura(){
	printf("------------------------------------------\n");
	printf("SISTEMA DE APOIO AO ATENDIMENTO HOSPITALAR\n");
	printf("------------------------------------------\n");
}

/**
* Fun��o: limpaTela
* Descri��o: fun��o repons�vel por
*            limpar a tela
* Par�metros: nada
* Retorno: nada
**/
void limpaTela(){
    system("cls");
}
