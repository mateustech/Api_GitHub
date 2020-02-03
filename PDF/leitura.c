#include <stdio.h>	/*getchar, printf*/
#include <stdlib.h>	/*atoi*/
#include <string.h>	/*strlen, strcpy*/
#include <ctype.h>	/*isalpha*/

/**
* Fun��o: limpaBuffer
* Descri��o: fun��o que limpa o buffer
*            evitando que alguns bugs ocorram
* Par�metros: nada
* Retorno: nada
**/
void limpaBuffer(){
	int valorLido;
    do{
        valorLido = getchar();
    }while ((valorLido != '\n') && (valorLido != EOF));
}

/**
* Fun��o: leOpcao
* Descri��o: l� uma op��o digitada pelo
*            usu�rio e valida conforme
*            as condi��es dadas
* Par�metros: menor_valor, maior_valor
* Retorno: o valor lido e validado
**/
int leOpcao(int menor_valor, int maior_valor){
    int op;
        while(1){
            printf("Digite sua opcao: ");
            op=getchar();
            if(op>=menor_valor && op<=maior_valor){
                limpaBuffer();
                break;
            }else{
                printf("\nOpcao Invalida. Tente Novamente");
                printf("\nA opcao deve estar entre %c e %c. \n",menor_valor, maior_valor);
                limpaBuffer();
            }
        }
	return op;
}


/**
* Fun��o: validaNome
* Descri��o: recebe um caracter e verifica se
*            n�o � um n�mero, se for retorna 0
* Par�metros: caracter
* Retorno: 0 ou 1
**/
int validaNome(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z') || c == ' ');
}

/**
* Fun��o: leString
* Descri��o: l� uma string, calcula seu tamanho,
*            aloca uma string do tamanho da
*            string lida e transfere a string
*            lida para aquela que foi alocada
* Par�metros: nada
* Retorno: a string lida
**/
char* leString(){
    char aux[101];
    scanf(" %100[^\n]", aux);
	int n = strlen(aux); //calcula a quantidade de caracteres inseridos na string
    char* string = (char*) malloc((n+1)*sizeof(char));
    strcpy(string, aux);
    return string;
}

/**
* Fun��o: leNome
* Descri��o: le um nome, usando as fun��es:
*            le_string e fun��o valida_nome
* Par�metros: nada
* Retorno: nome lido e validado
**/
char* leNome(){
    char* nome;
    int t_nome;
    printf("Digite o nome do paciente: ");
    nome = leString();
    t_nome = strlen(nome);

    int i = 0;
    int r = 0;
    while(nome[i] != '\0'){
        r += validaNome(nome[i]);
        i++;
    }

    while(r != t_nome){
        i = 0;
        r = 0;
        limpaBuffer();
        printf("Entrada incorreta.Digite um nome do paciente: ");
        nome = leString();
        t_nome = strlen(nome);
        while(nome[i] != '\0'){
            r += validaNome(nome[i]);
            i++;
        }
    }
    limpaBuffer();
    return nome;
}


/**
* Fun��o: leInt
* Descri��o: le uma string usando a funcao leString,
*            verifica se tem letra na string,
*            converte a string para um numero inteiro,
*            armazena esse valor em uma var do tipo inteiro
* Par�metros: nada
* Retorno: valor inteiro lido
**/
int leInt(){
    int v;
    char* str = leString();
	int i = 0;
	while(str[i] != '\0'){
        if(isalpha(str[i]) != 0) //retorna 0 se caracter � numero
            return -1;
        i++;
	}
	v = atoi(str); //Converte string pra inteiro
	return v;
}

/**
* Fun��o: leTempo
* Descri��o: le um tempo em minutos e faz a sua,
*            validacao, obrigando o us�rio digitar
*            um tempo cujo valor � sempre um numero
*			 inteiro
* Par�metros: nada
* Retorno: tempo lido e validado
**/
int leTempo(){
    int tempo;
    printf("Digite o tempo em minutos: ");
    tempo = leInt();
    while(tempo == -1){
        limpaBuffer();
        printf("Entrada incorreta. Digite o tempo em minutos:");
        tempo = leInt();
    }
    limpaBuffer();
    return tempo;
}
