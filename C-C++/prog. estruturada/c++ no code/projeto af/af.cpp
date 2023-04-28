/* Grupo 9 - Nome e RA dos integrantes:
Daniel Hiroshi Fugikawa - 200209 
Letícia Lopes Fogaça - 200670 
Breno Capelupo Angelotti - 200069
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

typedef struct aluno{
	int 	reg;
	char 	nome[80];
	char 	RA[7];
  int emprestado; //quantidade de livros emprestados max=3
  int reservado; //quantidade de livros reservados max=1
 	}aluno;
struct livro_status{
	 char 	sigla;// [L]ivre, [E]mprestado, [R]eservadointreg;// registro do livro};
	 int 	regist;
	};

struct livro{
	char 	titulo[80];
	char 	autor[80];
	int regist;
};

void aloca(aluno **p,int tam);
void cadastro(aluno *p);
void mostra(aluno *p,int tam);
void grava(aluno *p);
int verifica();

void registra(livro *l);
void r_livro(livro **l,int tama);
void regist(livro *l);
void gv_l(livro *l);
int ver_l();
int reg_livro();

main()
{
aluno *ag=NULL;
int cont=0 , co;
char op ;
cont = verifica();

livro *lg=NULL;
int cnt=0;
char sn ;
cnt = ver_l();


do{
  aloca(&ag,cont+1);
printf("\n[1]Cadastro de aluno\n[2]Mostrar\n[3]Registrar livro\n[4]Fim\nOpcao: ");
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
	do{
		registra(lg+cnt);
		cnt++;
		printf("\nDeseja cadastrar outro livro? <S/N>: ");
		scanf("%c",&sn);
		fflush(stdin);
	}while(sn=='s' || sn=='S');
	gv_l(lg+cnt);
	break;
}
}while(co !=4); 


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

//opção 3:

void r_livro(livro **l,int tama)
{
if((*l=(livro*)realloc(*l,tama*sizeof(livro)))==NULL)
  exit(1);
}

//registrar livro:
void registra(livro *l)
{
	static int x = 1;
	
	l->regist = x;
	x++;
	printf("\nTítulo: ");
	gets(l->titulo);
	fflush(stdin);
	
	printf("\nAutor: ");
	gets(l->autor);
	fflush(stdin);
	gv_l (l);
}

void gv_l(livro *p)
{
	FILE *lptr=NULL;
if((lptr=fopen("livros.bin","lb"))==NULL)
  printf("\nErro ao abrir o arquivo\n\n");
else
  fwrite(p,sizeof(livro),1,lptr);
fclose(lptr);
}

int ver_l() {
FILE *lptr=NULL;
long int cnt=0;
if((lptr=fopen("livros.bin","lb"))==NULL)
  return cnt;
else
  {
  	fseek(lptr,0,2);  
  	cnt=ftell(lptr)/sizeof(livro);  
  	fclose(lptr);    
  	return cnt;
  }
}
//int reg_livro()
