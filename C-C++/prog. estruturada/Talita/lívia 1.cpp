#include<stdio.h>
#include<stdlib.h>

void aloca(char **p, int tamanho);
void le_letras(char *l, int t);
void inverte_letras(char *l, int t);
void imprime(char *l, int t);

main()
{
	char *letras = NULL;
	int qtde = 10;
	letras = (char *)malloc(qtde*sizeof(char));
	aloca(&letras, qtde);
	printf("\nVoltando para a main e verificando o endereco apontado pelo ponteiro: %u", letras);
	le_letras(letras,qtde);
	inverte_letras(letras, qtde);
	printf("\n\nLetras armazenadas e invertidas entre minusculo e maiuscula:\n");
	imprime(letras, qtde);

	return 0;
}

void aloca(char **p, int tamanho)
{
	if((*p = (char *)malloc(tamanho*sizeof(char)))==NULL)
	{
		printf("Erro na alocacao de memoria. O programa será finalizado.");
		exit(1);
	}
	printf("memória alocada com sucesso! Endereco: %u", *p);
}

void le_letras(char *l, int t)
{
	int i;
	for(i=0;i<t;i++,l++)
	{
		printf("\nLetra[%d]: ", i);
		scanf("%c", l);
		fflush(stdin);
		printf("\nLetra alocada no endereco: %u: ", l);
	}
}

void inverte_letras(char *l, int t)
{
	int i;
	for(i=0;i<t;i++, l++)
	{
	if(*l >= 'A' && *l <= 'Z')
		*l+= 32;
		else if(*l >= 'a' && *l <= 'z')
			*l -= 32;	
	}
}

void imprime(char *l, int t)
{
	int i;
	for(i=1;i<=t;i++, l++)
	{
		printf("\nLetra[%d]: %c\tEndereco: %u.", i,*l, l);
	}
}

