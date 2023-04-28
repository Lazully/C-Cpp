#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p);

int main()
{
	char op;
	int *ptr=NULL, cont=0;
	
	do
	{
		aloca(&ptr,cont+1);
		leitura(ptr+cont);
		cont++;		
		
		printf("\nDeseja continuar? <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
	}while(op!='n' && op!='N');
	
	
	getch();
	return 0;
}

void aloca(int **p, int tam)
{
		if((*p=(int*)realloc(*p,tam*sizeof(int))) == NULL)
	{
		printf("Erro de alocacao!");
		exit(1);
	}
		
}

void leitura(int *p)
{
	printf("\nEndereco: %u - Numero: ",p);
	scanf("%i", p);
	fflush(stdin);
}

// void mostra0(int *p, int tam)
//{
//	int i;
//	for(i=0;i<tam;i++)
//	{
//		printf("\nEndereco: %u - Numero: %i",p,*p);
//	}
//}


