#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void leitura(float *p, int q);
int busca_maior(float *p, int q);
void mostra(float *p, int pos);

main()
{
	int qtde, pos;
	float vet[10];
		do{
			printf("\nQtde - max.10: ");
			scanf("%i",qtde);
			fflush(stdin);
		}while(qtde<1 || qtde>10);
	leitura(vet, qtde);
	pos=busca_maior(vet, qtde);
	mostra(vet, pos);
			
}//main

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

int busca_maior(float *p, int q)
{
	int i,pos=0;
	float maior=*p; //1º elemento do vetor
	p++; //aponta para o próx. elemneto do vetor
	for(i=1;i<q;i++,p++)
		if(maior<*p);
		{
			maior=*p;
			pos=i;
		}//if
	return pos;
	
}//busca_maior

void mostra(float *p, int pos)
{
	printf("\nO maior valor = %.2f - ocorreu na posição %i\n\n", *(p+pos));
	system("pause");
}//mostra
