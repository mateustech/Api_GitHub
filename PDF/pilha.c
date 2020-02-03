#include "pilha.h"
#include "paciente.h"

#include <stdio.h>	/*printf*/
#include <stdlib.h>	/*malloc*/

typedef struct pilha{
	Paciente * p;
	struct pilha * prox;
}Pilha;

/**
* Fun��o: novaPilha
* Descri��o: cria uma pilha vazia
* Par�metros: nada
* Retorno: NULL
**/
Pilha* novaPilha(){
	return NULL;
}

/**
* Fun��o: pilhaVazia
* Descri��o: verifica se uma pilha passada por parametro
*            estar vazia.
*			 Se sim, retorna 1, sen�o, retorna 0.
* Par�metros: pilha
* Retorno: 0 ou 1
**/
int pilhaVazia(Pilha* pilha){
	if(pilha == NULL){
		return 1;
	}else{
		return 0;
	}
}

/**
* Fun��o: exibirPilha
* Descri��o: imprime os dados dos pacientes de uma pilha
*            passada por parametro
* Par�metros: pilha
* Retorno: nada
**/
void exibirPilha(Pilha* pilha){
	printf("---------------- Pacientes ----------------\n");
	while(!pilhaVazia(pilha)){
		pacDisplay(pilha->p);
		pilha = pilha->prox;
	}
	printf("-------------------------------------------\n\n\n");
}

/**
* Fun��o: pushPilha
* Descri��o: adiciona no topo de uma pilha
*            um novo no contendo um pacente
*			 passado por parametro.
* Par�metros: pilha, p
* Retorno: pilha atualizada
**/
Pilha* pushPilha(Pilha* pilha, Paciente* p){
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
	novo->p = p;
	novo->prox = pilha;
	pilha = novo;
	return pilha;
}

/**
* Fun��o: movePilhaPraLista
* Descri��o: copia na mesma ordem os pacientes armazenados
*            em uma pilha passada por parametro para uma lista
*			 tambem passada por parametro. 
*			 A funcao pushLista eh usada para ir montando
*			 a lista desejada.
* Par�metros: pilha, lista
* Retorno: lista
**/
Lista* movePilhaPraLista(Pilha* pilha, Lista* lista){
	while(!pilhaVazia(pilha)){
		lista = pushLista(lista, pilha->p);
		pilha = pilha->prox;
	}
	return lista;
}

/**
* Fun��o: liberarPilha
* Descri��o: libera o espaco alocado de uma pilha
*            passada por parametro
* Par�metros: pilha
* Retorno: pilha vazia
**/
Pilha* liberarPilha(Pilha* pilha){
	while(!pilhaVazia(pilha)){
		Pilha* temp = pilha->prox;
		free(pilha);
		pilha = NULL;
		pilha = temp;
	}
	return NULL;
}
