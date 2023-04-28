#include<conio.h>
#include<stdio.h>

int main ()
{
	float vet[10], *pont;
	int i, quant;
	
	pont=vet;

	do
	{
	printf("Digite a quantidade de números: ");
	scanf("%i", &quant);
	}while(quant<0 || quant>10);
	
	for(i-0;i<quant;i++)
	{
		printf("Digite um numero: ");
		scanf("%f",pont++);
	}
	
	pont=vet;
	for(i=0;i<quant;i++)
	{
		printf("\nValor=%2g", *(pont++));
	}

	
	getch();
	return 0;
}
