#include "lista.h"
#include "paciente.h"

#include <stdio.h>	/*printf, fopen, fclose*/
#include <stdlib.h>	/*malloc, system*/

typedef struct lista{
	Paciente* p;
	struct lista* prox;
} Lista;

/**
* Fun��o: novaLista
* Descri��o: cria uma lista vazia
* Par�metros: nada
* Retorno: NULL
**/
Lista* novaLista(){
	return NULL;
}

/**
* Fun��o: listaVazia
* Descri��o: verifica se uma lista passada por parametro
*            estar vazia.
*			 Se sim, retorna 1, sen�o, retorna 0.
* Par�metros: lista
* Retorno: 0 ou 1
**/
int listaVazia(Lista* lista){
	if(lista == NULL){
		return 1;
	}else{
		return 0;
	}
}

/**
* Fun��o: exibirLista
* Descri��o: imprime os dados dos pacientes de uma lista
*            passada por parametro
* Par�metros: lista
* Retorno: nada
**/
void exibirLista(Lista* lista){
	printf("---------------- Pacientes ----------------\n");
	while(!listaVazia(lista)){
		pacDisplay(lista->p);
		lista = lista->prox;
	}
	printf("-------------------------------------------\n\n\n");
}

/**
* Fun��o: pushLista
* Descri��o: adiciona no ultimo no de uma lista
*            um novo no contendo um paciente
*			 passado por parametro.
*			 Esse novo no eh alocado dinamicamente.
* Par�metros: lista, p
* Retorno: lista atualizada
**/
Lista* pushLista(Lista* lista, Paciente* p){
	Lista* temp = lista;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->p = p;
	novo->prox = NULL;
	
	if(listaVazia(lista)){
		return novo;
	}
	
	while(temp->prox != NULL){
		temp = temp->prox;
	}
	temp->prox = novo;
	return lista;	
}

/**
* Fun��o: displayPrimeiroMenorTempo
* Descri��o: recebe uma lista e um valor de tempo e 
* 			 imprime os dados do primeiro paciente
*            da lista que tem o tempo de exame menor 
*			 do que o valor de tempo fornecido.
* Par�metros: lista, valor
* Retorno: nada
**/
void displayPrimeiroMenorTempo(Lista* lista, int valor){
	if(listaVazia(lista)){
		printf("\nNenhum paciente com tempo inferior!\n\n\n");		
		return;
	}
	if(menorTempo(lista->p,valor)){
		lista = lista->prox;
		return displayPrimeiroMenorTempo(lista,valor); 
	}
	system("color 02");
	printf("\nPaciente encontrado:\n");
	pacDisplay(lista->p);
}

/**
* Fun��o: gerarArquivo
* Descri��o: recebe uma lista com dados de pacientes 
* 			 e imprime esses dados em um arquivo .txt
*			 comecando a partir da cabeca da lista.
* Par�metros: lista
* Retorno: nada
**/
void gerarArquivo(Lista* lista){
	FILE* arq = fopen("relatorio.txt","w");
	while(!listaVazia(lista)){
		imprimeArquivo(arq,lista->p);
		lista = lista->prox;
	}
	fclose(arq);
}

/**
* Fun��o: liberarLista
* Descri��o: libera o espaco alocado de uma lista
*            passada por parametro
* Par�metros: lista
* Retorno: lista vazia
**/
Lista* liberarLista(Lista* lista){
	while(!listaVazia(lista)){
		Lista* temp = lista->prox;
		free(lista);
		lista = NULL;
		lista = temp;
	}
	return NULL;
}
