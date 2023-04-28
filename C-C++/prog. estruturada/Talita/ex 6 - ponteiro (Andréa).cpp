#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void leitura(float *p, int q);
float media(float *p, int q);
void mostra(float *p,int q, float med);

main()
{
	int qtde, pos;
	float vet[10], med;
		do{
			printf("\nQtde - max.10: ");
			scanf("%i",qtde);
			fflush(stdin);
		}while(qtde<1 || qtde>10);
	leitura(vet, qtde);
	med=media(vet,qtde);
	mostra(vet,qtde,med);
	
}



void leitura(float *p, int q)
{
	int i;
	for(i=0;i<q;i++)
	{
		printf("\nvet[%i]= ",i);
		scanf("%f",p++);
		fflush(stdin);
	}//for
}//leitura

float media(float *p, int q)
{
	int i;
	float soma=0;
	for(i=0;i<q;i++,p++)
		soma+=*p; //soma=soma+*p
	return (soma/q);
}//media

void mostra(float *p,int q, float med)
{
	int i;
	for(i=0;i<q;i++,p++)
		printf("\nvet[%i]= %.2f",i,*p);
	printf("\n\nA media=%.2f\n\n\n",med);
	system("pause");
}//mostra
