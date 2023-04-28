#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void maiuscula(char *p, int tam);
int conta(char *p, int tam, char *proc);

int main()
{
	char frase[80], letra;
	
	printf("Digite uma frase: ");
	gets(frase);
	fflush(stdin)
	printf("Digite uma letra: ");
	scanf("%c",&letra);
	
	maiuscula(frase,strlen(frase));
	maiuscula(letra,1);
	
	printf("A Letra = %c ocorre %i vez(es).", letra, conta(frase, strlen(frase), &letra))
	
	getch();
	return 0;
}

void maiuscula(char *p, int tam)
{
	int i;
	
	
	for(i=0;i<tam;i++)
	{
		if(*(p+i)>='a' && *(p+i)<='z')
		{
			*(p+i)-=32;
		}
	}
}
int conta(char *p, int tam, char *proc)
{
	int i, cont=0;
	for(i=0;i<tam;i++;p++)
	{
		if(*p==*proc)
		{
			cont++;
		}
	}
	return cont;
}
