#include<stdio.h>
#include<stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p, int tam);
void mostra(int *p, int tam);
void media(int *p, int tam;);

main()
{
	int *ptr=NULL, cont=0;
	char op;
	
	do{
		alloc(&ptr,cont+1);
		leitura(ptr,cont);
		cont++;
		printf("\nDeseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
	}while(op=='s' || op=='S');
	mostra(ptr,cont);
	media(ptr,cont);
	
	system("pause");
}

void aloca(int **p, int tam)
{
	if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL)
		exit(1);
}

void leitura(int *p, int tam)
{
	printf("\nNumero: ");
	scanf("%i",p+tam);
	fflush(stdin);
}

void mostra(int *p, int tam)
{
	int i;
	for(i=0;i<tam;i++)
		printf("\nNumero: %i", *p);
}//mostra

void media(int *p, int tam;)
{
	int i, qtde=0;
	float soma=0;
	for(i=0;i<tam;i++,p++)
	if(*p!=0)
	{
		soma=soma+*p;
	}
	
	soma=soma/qtde;
	printf("\nMedia = %.2f\n", soma);
}


