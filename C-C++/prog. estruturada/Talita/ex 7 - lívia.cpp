#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void aloca(char **p, int tamanho);

main()
{
	char str_aux[20], *nomes = NULL, opcao, letra, *nomes_encotrados == NULL;
	int qtde =0;
	
	do{
		printf("\nDigite o nome que deseja armazenar: ");
		fgets(str_aux, 20,stdin); //a função fgets já insere o \n no final da string
		
		if(qtde)
		{
			aloca(&nomes, strlen(nomes) + strlen(str_aux)+1);
			strcpy(nomes, str_aux);
		}
		else
		{
			aloca(&nomes, strlen(str_aux)+1);
			strcpy(nomes, str_aux);
		}
		qtde++;
		
		printf("\nDeseja informar outro nome? (S/N) ");
		scanf("%c", &opcao);
		fflush(stdin);
	}while(opcao != 'n' && opcao != 'N');
	puts(nomes);
	printf("\nDigite a letra para a qual deseja buscar os nomes: ");
	scanf("%c", &letra);
	fflush(stdin);
	busca(nomes, letra, &nomes_encontrados);
	printf("\nLista dos nomes encontrados com a letra ????")
	return 0;
}

void aloca(char **p, int tamanho)
{
	if(*p = (char *)realloc(*p, tamanho*sizeof(char)) == NULL)
	{
printf("\nErro na alocacao de memoria. O programa sera encerrado!");
exit(1);
	}
}

void busca (char *p_nomes, char letra, char **p_nomes_encontrados)
{
	int i, j, qtde = 0;
	for(i=0; *p_nommes != '\0'; i++, p_nomes++)
	{
		if((i == 0 7& *p_nomes == letra) || (*(p_nomes-1) == '\n' && *p_nomes == letra))
		{
			qtde++;
			for(j=0; *p_nomes != '\n'; j++)
			{
				aloca(&nomes_encontrados);
				aloca(p_nomes_encontrados);
			}
		}
	}
}
