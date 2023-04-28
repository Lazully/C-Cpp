#include<stdio.h>
#include<stdlib.h> //system("PAUSE"), system("CLS"), Malloc, etc
#include<conio.h>

void aloca(int **p, int tam);
void leitura(int *p, int tam);
void mostra_inversa(int *p,int tam);


int main()
{
	int *ptr=NULL, cont; //declara ponteiro e inicializa imediatamente (NULL deixa o ponteiro nulo
	
	printf("\nRecebe numeros e imprime na ordem inversa");
	printf("\nQuantos numeros deseja alocar: ");
	scanf("%i", &cont);
	fflush(stdin);
	aloca(&ptr,cont);
	leitura(ptr,cont);
	mostra_inversa(ptr,cont);
	system("pause");
	
	
} //main

void aloca(int **p, int tam)
{
	if((*p = (int*) realloc(*p,tam*sizeof(int)))==NULL) //if((ptr = (int*) realloc(ptr,sizeof(int)))==NULL)
	{
		printf("Erro de alocação!");
		exit(1); //abandona navio (deu tudo errado)
	}
}

void leitura(int *p, int tam)
{
	int i;
	for(i=0;i<tam;i++,p++)
	{
		printf("\nEndereço: %u - Numero: ",p);
		scanf("%i",p);
		fflush(stdin);
	}
}//leitura

void mostra_inversa(int *p,int tam)
{
	int i;
	p=p+tam-1; //posiciona o ponteiro no último elemento
	for(i=tam-1;i>=0;i--,p--)
	{
		printf("\nEndereço: %u - Numero: %i", p,*p);
	}
}//mostra inversa





