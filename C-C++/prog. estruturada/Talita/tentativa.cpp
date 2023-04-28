/* Grupo 9 - Nome e RA dos integrantes:
Daniel Hiroshi Fugikawa - 200209 
Letícia Lopes Fogaça - 200670 
Breno Capelupo Angelotti - 200069
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#include <iostream>

typedef struct aluno{
	int 	reg;
	char 	nome[80];
	char 	RA[7];
  int emprestado; //quantidade de livros emprestados max=3
  int reservado; //quantidade de livros reservados max=1
 	}aluno;
typedef struct cadastra_livro{
	 char 	sigla;// [L]ivre, [E]mprestado, [R]eservadointreg;// registro do livro};
	 int 	regist;
	 int 	cod=0;
	 int 	op_livro;
	 int 	l=0;
	 int 	i;
	}cadastra_livro;

struct livro{
	char 	titulo[80];
	char 	autor[80];
	char	status [3];
	int regist;
	int codigo;
};

struct cadastra_livro cad();

void aloca(aluno **p,int tam);
void cadastro(aluno *p);
void mostra(aluno *p,int tam);
void grava(aluno *p);
int verifica();
int op_livro;
int l=0;
int cod=0;
char opcao;
int i;
struct livro ficha[4];

void aloca_livro(livro **ptr, int tamanho);

void guardar_livro(livro *ptr, int qtd);

main()
{
	
	setlocale(LC_ALL,"Portuguese");
	
aluno *ag=NULL;
int cont=0 , co, cod=001, i;
char op, opcao ;
cont = verifica();

livro *lg=NULL;
int cnt=0, op_livro, l=0;
struct livro ficha[4];

FILE *flg = NULL;

do{
  aloca(&ag,cont+1);
printf("\n[1]Cadastro de aluno\n[2]Mostrar cadastro do aluno\n[3]Registrar ou mostrar Livro\n[4]Fim\nOpcao: ");
scanf("%i",&co);
fflush(stdin);
system("cls");
switch(co){
case 1 :
do{
	cadastro(ag+cont);
	cont++;
	printf("\nDeseja continuar <S/N>: ");
	scanf("%c",&op);
	fflush(stdin);
}while(op=='s' || op=='S');
mostra(ag,cont);
break;

case 2:
system("cls");
mostra(ag,cont);

case 3:

	(flg = fopen("livros.bin", "ab"))==NULL;

}
}while(co !=4); 

//arquivo em FILE de livros


}//main

void aloca(aluno **p,int tam)
{
if((*p=(aluno*)realloc(*p,tam*sizeof(aluno)))==NULL)
  exit(1);
}//aloca

void cadastro(aluno *p)
{
  static int n=1;

  p->reg=n;
  n++;
  printf("\nNome: ");
  gets(p->nome);
  fflush(stdin);

  printf("\nRA: ");
  gets(p->RA);
  fflush(stdin);
  grava(p);
}//cadastro

void grava(aluno *p){
  FILE *fptr=NULL;
if((fptr=fopen("alunos.bin","ab"))==NULL)
  printf("\nErro ao abrir o arquivo\n\n");
else
  fwrite(p,sizeof(aluno),1,fptr);
fclose(fptr);
}

int verifica() {
FILE *fptr=NULL;
long int cont=0;
if((fptr=fopen("alunos.bin","rb"))==NULL)
  return cont;
else
  {
  	fseek(fptr,0,2);  //posiciona fptr no fim
  	cont=ftell(fptr)/sizeof(aluno);  //qtde de elementos
  	fclose(fptr);    //dentro do else = rb
  	return cont;
  }//else
}//verifica

void mostra(aluno *p,int tam) {
FILE *fptr=NULL;
int i;
system("cls");
if((fptr=fopen("alunos.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo\n\n");
else
  {
  	for(i=0;i<tam;i++)
  	  {
  	  	fseek(fptr,i*sizeof(aluno),0);
  	  	fread(p,sizeof(aluno),1,fptr);
  	  	printf("\nNome: %s\nRa: %s\n\n",p->nome,p->RA);
  	  }//for
  	fclose(fptr);  //dentro do else = rb
  }//else
system("pause");
}//mostra

void aloca_livro(livro **ptr, int tamanho)
{
	if((*ptr = (livro *)realloc(*ptr, tamanho * sizeof(livro)))==NULL)
	{
		printf("Desculpe, ocorreu um erro. Terei que encerrar, mas tente de novo!");
		exit (1);
	}
}

struct cadastra_livro cad()
{
	do{
		
		printf("\n[1]Inserir um novo cadastro\n[2]Mostrar status dos livros\n[3]Sair\n\nDigite a opção desejada: ");
		scanf("%i",&op_livro);
		fflush(stdin);
		op_livro = getch()-48;
	}while(op_livro<1 || op_livro>2);
	system("cls");
	switch(op_livro){
		case 1:
			do{
				if(l>5)
				{
					printf("\nDesculpe, o sistema não pode receber novos cadastros.\n\n");
					system("pause");
					system("cls");
					break;
				}
				system("cls");
				cod = rand()%100+1;
				printf("\n------Dados do livro------ \n\n");
				printf("Código: %d\n",cod);
				
				ficha[0].codigo = cod;
				
				printf("\nQual o autor do livro? ");
				fflush(stdin);
				gets(ficha[0].autor);
				ficha[0].autor[strlen(ficha[0].autor)]='\0';
				
				printf("Qual o título do livro? ");
				fflush(stdin);
				gets(ficha[0].titulo);
				ficha[0].titulo[strlen(ficha[0].titulo)]='\0';
				
				printf("Qual o status do livro? \n[L] - Livre\n[E] - Emprestado\n[R] - Reservado\n\nResposta: ");
				fflush(stdin);
				gets(ficha[0].status);
				ficha[0].autor[strlen(ficha[0].status)]='\0';
				
				l = l+1;
				cod = cod+1;
				
				printf("\nCadastrar outro? Se escolher 'N', voltará ao menu principal. <S/N>");
				scanf("%c", &opcao);
				fflush(stdin);
			}while(opcao == 'S' ||opcao == 's' );
			system("cls");
			break;
			
		case 2:
			if(l==0)
			{
				printf("\n\nOpa! Parece que você ainda não cadastrou nenhum livro.\n\n");
				system("pause");
				system("cls");
			}
			else
			{
				printf("\nLivros registrados: ");
					for(i=0;i<l;i++)
					{
						FILE *arqLivros;
						
												
						printf("\nCódigo do livro: ", ficha[i].codigo);
						printf("\nAutor: ", ficha[i].autor);
						printf("\nTítulo: ", ficha[i].titulo);
						printf("\nStatus do livro ([L] - Livre, [E] - Emprestado, [R] - Reservado): ", ficha[i].status);
					}				
			}
		case 3:
			break;
	}
	
}

void guardar_livro(livro *ptr, int qtd)
{
	FILE *lg = NULL;
	if((lg = fopen("livros.bin", "ab"))== NULL)
	{
		printf("Não consegui cadastrar seu livro.");
	}
	else
	{
		fwrite(ptr, sizeof(guardar_livro), qtd, lg);
	}
	fclose(lg);
}

