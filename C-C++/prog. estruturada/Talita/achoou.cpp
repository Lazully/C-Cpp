#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int procura(char *p, int tam, char *proc);

int main()
{
	char frase[80], letra;
	
	printf("Digite uma frase: ");
	gets(frase);
	fflush(stdin);
	printf("Digite uma letra: ");
	scanf("%c",&letra);
	
	if(procura(frase,strlen(frase),&letra)==1)
	{
		printf("O caractere \"%c\" foi encontrado."), letra;
	}
	else
	{
		printf("O caractere \"%c\" nao foi encontrado",letra);
	}
	
	getch();
	return 0;
}

int procura(char *p, int tam, char *proc)
{
	int i=0, achou=0;
	
	while(i<tam && achou==0)
	{
		if(*(p+i)==*proc)
		{
			achou=1;
		}
		else
		{
			i++;
		}
	}
	return achou;
}
