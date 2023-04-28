#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void imprime(char *p);

main ()
{
	char frase[80],op;	
	
	printf("\nInverte a frase ou palavras, assim você pode falar igual a Zatanna e fazer umas mágicas ;)");
	do{
		printf("\nDigite sua frase mágica: ");
		gets(frase);
		fflush(stdin);
		imprime(frase);
		printf("\nDeseja fazer outro feitiço? S/N: ");
		scanf("%c", &op);
		fflush(stdin);
	}while(op!='n' && op!='N');

}//main

void imprime(char *p)
{
	int  i, tam;
	tam=strlen(p);
	p+=tam-1; //p=p+tam-1   posiciona o ponteiro na última letra (ignora \0)
	for(i=0;i<tam;i++,p--)
	printf("%c",*p);
	printf("\n\n\n");
	system("pause");
}//imprime





