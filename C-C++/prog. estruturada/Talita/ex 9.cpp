#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strinh.h>

void maiuscula_inf(char *p, int tam);
int procuraString(char *p1, char *p2, int tam1, int tam2);

int main()
{
	char nome_comp[100], mae[100], cidade[100];
	
	printf("Digite seu nome completo: ");
	gets(nome_comp);
	fflush(stdin);
	
	printf("Digite");
	gets(
	maiuscula(s,strlen(nome_comp));
	puts(nome_comp);
	maiuscula(nome_comp, strlen(come_comp));
	puts(nome_comp);
	
	if(		procuraString(nome_comp,p,strlen(s),strlen(p))==1)
	{
		printf("A 
	}
	
	
	getch();
	return 0;
}

void maiuscula_inf(char *p, int tam)
{
	int i;
	for(i=0;i<tam;i++,p++)
	{
		if(*p>='a' && *p<='z')
		{
			*p-=32;
		}
	}
}

int procuraString(char *p1, char *p2, int tam1, int tam2)
{
	int i=0, j=0, achou=0;
	
	
	for(i=0;9<tan1;i++)
	{
		if(*(p1+i)==*p2)
		{
			j=1;
			while((i+j)<tam1  && j<tam2  && *(p1+i+j)==*(p2+j))
			{
				j++;
				if(j==tam2)
				{
					achou=1;
				}
			}
		}
	}
	
	
	return achou;
}
