//Nome: Ana Julia da Silva Moraes RA:200716
//Nome: Leticia Lopes Fogaça RA:200670
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
O programa irá receber uma frase
 e na sequencia deverá mostrar na tela a frase apenas com as letras que compõem a palavra V-E-T-O-R,
  ou seja, caso a letra da palavra não tiver as letras de V-E-T-O-R, apenas mostre um asterisco no lugar da letra da palavra.

Exemplo:

Palavra: algoritmos

Limpar a tela e mostrar:

**or*t*o

O usuário terá uma quantidade determinada de chances para descobrir as letras que faltam. A quantidade será correspondente as letras "escondidas" da palavra.
Se o usuário descobrir a frase mostre uma mensagem informando que ele acertou a frase, caso contrário finalize o programa mostrando a frase inicial na tela.
Diferenciar letras maiúsculas e minúsculas, ou seja, se a frase possuir a letra ‘M’ e for digitado ‘m’ o acerto não deverá ser considerado.

- Receber uma palavra; ok
- Limpar a tela; ok
- Mostrar apenas com as letras de VETOR; ok
- criar numero de chances igual a de letras; ok
- se descobrir mostrar mensagem; ok
- se não mensagem e palavra correta; ok

*/





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>              //Bibliotecas
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>


int main()
{
	int i,z, cont=0, num=0;
	char palavra[50],salva[50], teste=0;          //Variáveis
	
	setlocale(LC_ALL,"Portuguese");      //Correção
	
	
	printf("\nOie! O objetivo deste programinha é que você acerte a palavra escondida.");
    printf("\nEssas são as regras:\n\n1.Você escolherá uma palavra e a mesma terá suas letras ocultas por (*),\n a menos que elas sejam pertencentes a palavra V E T O R.");
    printf("\n2. Seu oponente terá um número de chances igual ao número de (*) que aparecerem em sua palavra.\n\n----------------Vamos Começar!------------------\n\n");
	
	
	
	
	printf("Digite uma palavra:");
	       gets(palavra);
	            puts(palavra);                                              //entrada
	        printf("Digite ENTER para começar o jogo!");
	    getch();
	system("cls");
	
             strcpy(salva,palavra);   //Salvar a palavra em uma nova variável
	
	
	for(i=0;i<=strlen(palavra);i++)
	{
		if(palavra[i]=='v'|| palavra[i]== 'V'|| palavra[i]== 'V'||palavra[i]== 'E'|| palavra[i]== 'e'||palavra[i]== 'T'|| palavra[i]== 't'||palavra[i]== 'O'|| palavra[i]== 'o'||palavra[i]== 'R'|| palavra[i]== 'r')
		{
		printf("%c",palavra[i]);
		}
		else
		{
		if(palavra[i]==' ')
		{
		printf(" ");                              //resposta com *
		}
		else
		{
			if(palavra[i]== '\0')
			{
				
			}
			else
			{
				palavra[i]='*';
			printf("*");
			cont++;
			
			}
		
	
		
		
     	}
		}
		
	}
	
	//	puts(palavra);
	//	puts(salva);
	//printf("\n\n%i", cont);  teste de cont

	num=cont;
	
	
	for(z=0;z<cont;z++)
	{ 
		printf("\n\nVocê tem %i chances!", num);
		printf("\nDigite uma letra:");
		scanf(" %c",&teste);        //entrada da letra
		
		
		
		for(i=0;i<=strlen(palavra);i++)
		{
			if(palavra[i]=='*')
			{
				palavra[i]=teste;
				
		                 	strcmp(palavra, salva);
		                    if( palavra[i]== salva[i])
		                          	{ 
									  
			                        }
			                        else
									{
			                    		palavra[i]='*';
									}
			}
			
			
			
		}
		
		puts(palavra);
		
		num=num-1;
		
	}
	
////////////////////////////////////////////Resposta////////////////////////////////////////////////////////////

    if(strcmp(palavra,salva)==0)
	{
		printf("\nVocê ganhou!\n");
		

		printf("       _____      \n");
		printf("      '.=====.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         .' '.        \n");
		printf("        '-------'       \n\n");
	}
	else
	{
		printf("\nNão foi dessa vez!\n");
		printf("A palavra era %s\n\n", salva);

		printf("    _____         \n");
		printf("   /               \\       \n"); 
		printf("  /                 \\      \n");
		printf("//                   \\/\\  \n");
		printf("\\|   XXXX     XXXX   | /   \n");
		printf(" |   XXXX     XXXX   |/     \n");
		printf(" |   XXX       XXX   |      \n");
		printf(" |                   |      \n");
		printf(" \\_      XXX      _/     \n");
		printf("   |\\     XXX     /|       \n");
		printf("   | |           | |        \n");
		printf("   | I I I I I I I |        \n");
		printf("   |  I I I I I I  |        \n");
		printf("   \\             /       \n");
		printf("     \\         /         \n");
		printf("       \\_____/           \n");
	}
	


	
	getch();
	return 0;
}
