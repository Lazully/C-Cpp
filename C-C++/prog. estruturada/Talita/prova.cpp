#include<stdio.h>
#include<stdlib.h>

void dinamico (int **p, int n);
void aloca(char **p, int tam);

typedef struct inteiro{
	int aux;
	
}inteiro;

//Alocar dinamicamente a seq��ncia de n�meros int digitados pelo usu�rio, at� que este escolha a op��o N�o.

int main()
{
	inteiro *ptr=NULL;
	int cont=0;
	char op;
	
	do{
		aloca(&ptr, cont+1);
		//aloca (&it, cont+1);
		//dinamico ();
		printf("Deseja continuar? <S/N>: ");
		scanf("%d", &it);
	}while(op == 'S' || op == 's');
	
	
	
	
	
	
	return 0;
}

//void dinamico (int **p, int n)
//{
	
//}

void aloca(char **p, int tam)
{
	if((*p=(int*)realloc(*p,tam*sizeof(int*)))== NULL)
		exit(1);
}
