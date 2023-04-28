#include<conio.h>
#include<stdio.h>

int main ()
{
	float vet[10], *pont;
	int i, quant=0;
	char resp='S';
	
	pont=vet;
	
	while(toupper(resp)=='S' && quant<10)
	{
	scanf("%f",ptr++);
	quant++;
	printf("deseja continuar (S/N)? ");
	scanf(" %c",&resp);
	}
	
	pont=ver;
	
	for(i=0;i<quant;i++)
	{
		printf("\nValor = %.2f",*(pont++));
	}

	getch();
	return 0;
}
