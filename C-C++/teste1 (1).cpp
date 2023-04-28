#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void recebeFuncao(int q,float *vC,float *vE);
void alocaFloat(float **p,int tam); //Sem a função aloca float, ele nao consegue trazer os valores de uma função pra main

int main ()
{
	int qtd;
	float *pCoeficiente=NULL,*pExpoente=NULL;
	
	printf("Digite a quantidade de termos: ");
	scanf("%i",&qtd);
	alocaFloat(&pCoeficiente,qtd);
	alocaFloat(&pExpoente,qtd);
	recebeFuncao(qtd,pCoeficiente,pExpoente);
}
void recebeFuncao(int q,float *vC,float *vE)
{
	int i;
	for(i=0;i<q;i++)
	{
		printf("Digite o coeficiente e o expoente do %i termo: ", i+1);
		scanf("%f %f",vC+i,vE+i); //usando os ponteiros
		
		printf("\n\n%i",q);
	}
}
void alocaFloat(float **p,int tam)
{
	if( (*p=(float *)realloc(*p, tam*sizeof(float)) )==NULL)
	{
		printf("Erro na alocacao!");
		exit(1);
	}
}
