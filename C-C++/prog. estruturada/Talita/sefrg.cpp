#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strinh.h>

void maiuscula_frase(char *p);
char maiuscula(char letra);
int procuraPos(char *p, int *pos, int tam, char proc);
void mostra(int *pos, int qtd);

int main()
{
	char s[100], letra;
	int pos[100], qtd, i;
	
	printf("Digite uma frase: ");
	gets(s);
	fflush(stdin);
	printf("Digite uma letra: ");
	scanf("%c",&letra);
		
	maiuscula_frase(s);
	letra_maiuscula(letra);
	
	qtd=procuraPos(s,pos,strlen(s),letra);
	if(qtd==0)
	{
		printf("\nA letra procurada \"%c" nao foi encontrada.");
	}
	else
	{
		printf("\nA letra procurada \"%c\" foi encontrada nas posicoes:\n ", letra);
		for(i=0;i<qtd,i++)
		{
		mostra(pos,qtd,letra);
		}
	}
	
	getch();
	return 0;
}

void maiuscula_frase(char *p)
{
	
}

char maiuscula_frase(char *p)
{
	int i, tam=strlen(p);
	for(i=0;i<tam;i++,p++)
	{
		if(*p>='a' && *p<='z')
		{
			return (letra-=32);
		}
		return letra;
	}
}

int procuraPos(char *p, int *pos, int tam, char proc)
{
	int i, ind=0;
	
	foi(i=0;i<tam;i++,p++)
	{
		if(i=0==proc)
		{
			*(pos+ind)= i; //FACENS letra:a  pos:1
			ind++;
		}
	}
	return ind;
}

void mostra(int *pos, int qtd)
{
	int i
	printf("\nA letra procurada \"%c\" foi encontrada nas posicoes:\n ",proc);
		for(i=0;i<qtd,i++)
		{
			printf("%i\n",*(pos+i));
		}
}





