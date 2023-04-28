#include<stdio.h>
#include<stdlib.h>

void aloca(float **p, int tam);
void leitura(float *p, int tam);
void maior_temp(float *p, int tam, float *pmaior, int *pdia);

main()
{
	float *ptr=NULL, maior;
	int cont=0, dia;
	char op;
	
	do{
		aloca(&ptr, cont+1);
		leitura(ptr, cont);
		maior_temp(ptr,cont,&maior,&dia);
		cont++;
		printf("\nMaior temperatura = %.2f - dia = %i", maior,dia);
		printf("\nDeseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
	}while(op!='n' && op!='N');
	
}

void aloca(float **p, int tam)
{
	if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL);
	exit(1);
}//função aloca

void leitura(float *p, int tam)
{
	printf("\nTemperatura - %i dia: ",tam+1);
	scanf("%f",p+tam);
	fflush(stdin);
}//leitura

void maior_temp(float *p, int tam, float *pmaior, int *pdia)
{
	if(tam==0)
	{
		*pmaior=*p; //1 elemento
		*pdia=tam+1; //*pdia=1
	}
	else
	
		if(*(p+tam)>pmaior)
		{
			*pmaior=*(p+tam);
			*pdia=tam+1;
		}
}




