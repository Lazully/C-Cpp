#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void inverte(char *p, int tam);

int main()
{
	char frase[80];
	int total;
	
	printf("Digite a frase: ");
	gets(frase);
	fflush(stdin);
	total=strlen(frase);
	//chamada
	inverte(frase,total);
	printf("\nA frase invertida: %s\n",frase);
	
	
	getch();
	return 0;
}

void inverte(char *p, int tam)
{
	int i, j;
	char aux;
	
	i=tam-1;
	j=0;
	
	while(j<i)
	{
		aux=*(p+j);
		*(p+j)=*(p+i);
		*(p+i)=aux;
		j++;
		i--;
	}
}




