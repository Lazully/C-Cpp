/* Grupo 9 - Nome e RA dos integrantes:
Daniel Hiroshi Fugikawa - 200209 
Letícia Lopes Fogaça - 200670 
Breno Capelupo Angelotti - 200069
*/
#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif


#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#define MAX 100

typedef struct info_livro{
	char sigla; // [L]ivre, [E]mprestado, [R]eservado
	int reg; // registro do livro
}info_livro;

typedef struct aluno{
	int reg;
	char nome[80];
	char RA[7];
	int emprestado; // qtde de livros emprestados - Max=3
	int reservado; // qtde de livros reservados - Max =1
	info_livro tabela[4];
}aluno;

typedef struct info_aluno{
	char sigla;
	char RA[7];
	int dia_ret; // dia – máx=31
	int mes_ret; // mes: fev=28 dias
	int dia_dev; // mes: abril=jun=set=nov=30 dias
	int mes_dev; // os demais = 31 dias
}info_aluno;

typedef struct livro{
	int reg; // gerado automaticamente
	char titulo[80];
	char autor[80];
	int id;
	int codigo;
	int raAluno;
	info_aluno status[2];
}livro;

char menu();

void aloca(aluno **p,int tam);
void cadastro(aluno *p);
void mostra(aluno *p,int tam);
void grava(aluno *p);
int verifica();


void registra(livro *l);
void r_livro(livro **l,int tama);
void mlivros(livro *l,int tama);
void regist(livro *l);
void gv_l(livro *l);
int ver_l();
int reg_livro();
void ler (aluno *p, livro *l);

int str_somente_numeros(char str[]);
int existe_cliente(FILE *arq_clientes, int raAluno);
int ver_RA(char *RA);
int ver_aluno();
void data(livro *d, int n, int opc);
void t_mostraat (aluno *p, livro *l, int pos_a);
//t_livro *obter_livro(FILE *arq_livros, int id_livro);
//void atualizar_livros(FILE *arq_livros, t_livro *livro_alugado);

int main()
{
	
	setlocale(LC_ALL,"Portuguese");
	
aluno *ag=NULL;
int cont=0 , co, cod=001, i;
char op, opcao ;
cont = verifica();

livro *lg=NULL;
int cnt=0, op_livro, l=0;
//char sn ;
//cnt = ver_l();
cnt =ver_l();

do{
  aloca(&ag,cont+1);
printf("\n[1]Cadastro de aluno\n[2]Mostrar\n[3]Registrar ou mostrar Livro\n[4]Fim\nOpcao: ");
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
		r_livro(&lg,cnt+1);
		printf("\n[1]Inserir um novo cadastro\n[2]Mostrar status dos livros\n[3]Sair\n\nDigite a opção desejada: ");
		scanf("%i",&op_livro);
		fflush(stdin);
		op = getch()-48;
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
				registra(lg+cont);
				cnt++;
				printf("\nCadastrar outro? Se escolher 'N', voltará ao menu principal. <S/N>");
				scanf("%c", &opcao);
				fflush(stdin);
			}while(opcao == 'S' ||opcao == 's' );
			system("cls");
			break;
			
		case 2:
			system("cls");
			mlivros(lg,cnt);
			break;
	}
			
	

}
}while(co !=4); 


}//main


void data(livro *d, int n, int opc)
{
	int mes1, mes2;
	
}


void aloca(aluno **p,int tam)
{
if((*p=(aluno*)realloc(*p,tam*sizeof(aluno)))==NULL)
  exit(1);
}//aloca

void cadastro(aluno *p)
{
	int cont=0;
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

int ver_RA(char *RA)
{
	FILE *fptr;
	aluno *p=NULL;
	aloca(&p,1);
	
	int i,quant=ver_aluno();
	
	if((fptr=fopen("alunos.bin","rb"))==NULL){
		return 0;
	}
	else{
		for(i=0;i<quant;i++){
			fseek(fptr,i*sizeof(aluno),0);
			fread(p,sizeof(aluno),1,fptr);
			if(strcmp(RA,p->RA)==0){
				fclose(fptr);
				return 1;
			}
		}
		fclose(fptr);
		return 0;
	}
}

int ver_aluno(){
	FILE *fptr;
	int cont=0;
	if((fptr=fopen("alunos.bin","rb"))==NULL){
		return cont;
	}
	else{
		fseek(fptr,0,2);
		cont=ftell(fptr)/sizeof(aluno);
		fclose(fptr);
		return cont;
	}
}

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
	int num_reg,i;
	l->reg=ver_l()+1;
	
	system("cls");
	printf("Cadastro de Livro\n\n");
	printf("Título: ");
	gets(l->titulo);
	fflush(stdin);
	printf("Autor: ");
	gets(l->autor);
	fflush(stdin);
	
	for(i=0;i<2;i++){
		(l->status+i)->sigla='L';
	}
	
	gv_l(l);
	
	printf("\nLivro cadastrado com sucesso\n\n");
}

void gv_l(livro *l)
{
	FILE *fltr=NULL;
if((fltr=fopen("livros.bin","ab"))==NULL)
  printf("\nErro ao abrir o arquivo\n\n");
else
  fwrite(l,sizeof(livro),1,fltr);
fclose(fltr);
}

int ver_l() {
FILE *fltr=NULL;
long int cnt=0;
if((fltr=fopen("livros.bin","rb"))==NULL)
  return cnt;
else
  {
  	fseek(fltr,0,2);  
  	cnt=ftell(fltr)/sizeof(livro);  
  	fclose(fltr);    
  	return cnt;
  }
}
//int reg_livro()
void mlivros(livro *l,int tama) {
FILE *fltr=NULL;
int i;
system("cls");
if((fltr=fopen("livros.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo\n\n");
else
  {
  	for(i=0;i<tama;i++)
  	  {
  	  	fseek(fltr,i*sizeof(livro),0);
  	  	fread(l,sizeof(livro),1,fltr);
  	  	printf("\nTitulo %s\nAutor: %s\nStatus: %s\n\n",l->titulo,l->autor,l->status);
  	  }//for
  	fclose(fltr);  //dentro do else = rb
  }//else
system("pause");
}//mostra

void ler (aluno *p, livro *l)
{
	FILE *fptr;
	char RA [7], titulo[80], cont;
	int ck, c_aluno, c_livro, posi, i;
	c_aluno=ver_aluno();
	c_livro=ver_l();
		
	printf("Por favor, informe o RA do aluno: ");
	do
	{
		gets(RA);
		fflush(stdin);
		ck=ver_RA(RA);
		if (ck==0)
		{
			printf("\nDesculpe, não temos registro deste RA. Cadastre-o ou insira um RA válido.");
		}
	}while (ck==0);
	
	if((fptr=fopen("alunos.bin","rb"))==NULL)
	{
		printf("\nOpa! Não consegui abrir o arquivo :( \nFeche o programa e tente de novo, por favor!");
	}
	else
	{
		for(i=0;i<c_aluno;i++)
		{
			fseek(fptr, i*sizeof(aluno),0);
			fread(p, sizeof(aluno),1,fptr);
				if(strcmp(RA,p->RA)==0)
				{
					posi=i;
					break;
				}
		}
		fclose(fptr);
	}
	
	if(p->emprestado<3 || p->reservado<1)
	{
		printf("\n\nOba! Mais um querendo um pouquinho mais de conhecimento! Por favor, qual o título do livro desejado?: ");
		gets(titulo);
		fflush(stdin);
		
		if((fptr=fopen("livros.bin","rb"))==NULL)
		{
			printf("\nOpa! Não consegui abrir o arquivo :( \nFeche o programa e tente de novo, por favor!");
		}
		
		else
		{
			for(i=0;i<c_livro;i++)
			{
				fseek(fptr,i*sizeof(livro),0);
				fread(l,sizeof(livro),1,fptr);
				if(strcmp(titulo, l->titulo)==0)
				{
					break;
				}
			}
		fclose(fptr);
		if(i==cont)
		{
			printf("Não consegui encontrar o livro :( \nTente outro título!");
			system("pause");
			main();
		}
		
		if((l->status+0)->sigla=='L' && p->emprestado<3)
		{
			(l->status+0)->sigla='E';
				strcpy((l->status+0)->RA,RA);
				data(l,0,0);
				for(i=0;i<3;i++)
				{
					if((p->tabela+i)->sigla=='L')
					{
						p->emprestado++;
						(p->tabela+i)->sigla = 'E';
						(p->tabela+i)->reg = l->reg;
						break;
					}
				}
		}
	if(i==3)
	{
		printf("Desculpe, este livro não está disponível.");
	}
		
	else
	{
		if((l->status+0)->sigla=='E'&&p->emprestado<1)
		{
				if((l->status+1)->sigla=='R')
				{
					printf("Livro não disponível para reserva\n");
					printf("Emprestado para o RA: %s\n",(l->status+0)->RA);
					printf("Data de devolução: %d/%d\n",(l->status+1)->dia_dev,(l->status+1)->mes_dev);
				}
		}
	}
}
}
}

void t_mostraat (aluno *p, livro *l, int pos_a)
	{
	FILE *fptr;
	aluno *a;
	int cont, j;
	cont = ver_aluno();
	
	system("cls");
	printf("\n\nOba! Operação concluída! Aproveite o livro.\n\n\n");
	
	printf("\nRegistro: %.3d\nTítulo: %s\nAutor: %s\n",l->reg,l->titulo,l->autor);
	printf("Status 0 - %c",(l->status+0)->sigla);
	
	if((l->status+0)->sigla!='L')
	{
		printf("\tRA: %s\tRet: %d/%d\tDev: %d/%d\n",(l->status+0)->RA,(l->status+0)-> dia_ret,(l->status+0)->mes_ret,(l->status+0)->dia_dev,(l->status+0)->mes_dev);
	}
	else
	{
	printf("\n");
	printf("Status 1 - %c",(l->status+1)->sigla);
	}
	if((l->status+1)->sigla!='L')
	{
		printf("\tRA: %s\tRet: %d/%d\tDev: %d/%d\n",(l->status+1)->RA,(l->status+1)->dia_ret,(l->status+1)->mes_ret,(l->status+1)->dia_dev,(l->status+1)->mes_dev);
	}
	else
	{
	printf("\nNome: %s\nRA: %s\nLivros emprestados: %d\nLivros reservados: %d\n",p->nome,p->RA,p->emprestado,p->reservado);
	}
	for(j=0;j<4;j++)
	{
		if((p->tabela+j)->sigla=='L')
		{
			printf("Tabela %d: L - ----\n",j);
		}
		else
		{
			printf("Tabela %d: %c – %d\n",j,(p->tabela+j)->sigla,(p->tabela+j)->reg);
		}
	}
	
	if((fptr=fopen("livros.bin","rb+"))==NULL)
	{
		printf("Desculpe, não consegui abrir o arquivo de livros :(\n\n\n");
	}
	else
	{
		fseek(fptr,(l->reg-1)*sizeof(livro),0);
		fwrite(l,sizeof(livro),1,fptr);
		fclose(fptr);
	}
	
    if((fptr=fopen("alunos.bin","rb+"))==NULL)
	{
		printf("Desculpe, não consegui abrir o arquivo de alunos :(\n\n\n");
	}
	else
	{
		fseek(fptr,pos_a*sizeof(aluno),0);
		fwrite(p,sizeof(aluno),1,fptr);
		fclose(fptr);
	}
}
