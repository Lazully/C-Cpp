#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void inverte_frase(char *pf, char *pi);
char letra_minuscula(char letra);
char letra_maiuscula(char letra);

main ()
{
	char frase[80], inv[80];	
	
	printf("\nInverte a frase ou palavras, assim você pode falar igual a Zatanna e fazer umas mágicas ;)");

		printf("\nDigite sua frase mágica: ");
		gets(frase);
		fflush(stdin);
		inverte_frase(frase,inv);
		printf("\nA frase invertida: %s\n\n\n",inv);
		system("pause");

}//main

void inverte_frase(char *pf, char *pi)
{
	int i, tam;
	tam-strlen(pf);
	pf+=tam-1; //pf=pf+tam-1 posiciona para a última letra da frase
	for(i=0;i<tam;i++,pf--,pi++)
	{
		*pi=letra_minuscula(*pf);
		if(i==0)
			*pi=letra_maiuscula(*pf);
	if(*pf==' ')
		{
			i++;
			pi++;
			pf--;
			*pi=letra_maiuscula(*pf);
		}
     }
	*pi='\0';
	
}//inverte frase

char letra_minuscula(char letra)
{
	if(letra>='A' && letra<='Z')
		return(letra+=32);
	return letra;
}//letra_minuscula

char letra_maiuscula(char letra)
{
	if(letra>='a' && letra<'z')
		return(letra-=32);
	return letra;
}//letra_maiuscula

