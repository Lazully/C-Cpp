#include <stdio.h>
#include <string.h>


int main ()
{
	char txt[60], aux[50];
	int i, j;
	
	printf("Digite algo");
	gets(txt);
	
	printf("O que você digitou foi: %s\n\n", txt);
	
	for(i=strlen(txt)-1; j=0; i>=0; i--; j++)
    {
    	aux[j]=txt[i];
	}	

  aux[j]='\0';

  	printf("Faremos como a Zatanna, inverteremos o que você digitou. Ela ficaria então %s", aux);

	getch();
	return 0;
}

