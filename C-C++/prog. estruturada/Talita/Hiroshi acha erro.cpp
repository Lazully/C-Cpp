/* Grupo 9 - Nome e RA dos integrantes:
Daniel Hiroshi Fugikawa - 200209 
Let�cia Lopes Foga�a - 200670 
Breno Capelupo Angelotti - 200069
*/
#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#define MAX 100

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

typedef struct t_livro tabela [4];

struct livro{
	char 	titulo[80];
	char 	autor[80];
	char	status [3];
	int id;
	int codigo;
	int raAluno;
}t_livro;

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

void obter_livro(FILE *arq_livros, int id_livro);

int str_somente_numeros(char str[]);
int existe_cliente(FILE *arq_clientes, int raAluno);
//t_livro *obter_livro(FILE *arq_livros, int id_livro);
void atualizar_livros(FILE *arq_livros, int t_livro, int *livro_alugado);

main()
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
		printf("\n[1]Inserir um novo cadastro\n[2]Mostrar status dos livros\n[3]Sair\n\nDigite a op��o desejada: ");
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
					printf("\nDesculpe, o sistema n�o pode receber novos cadastros.\n\n");
					system("pause");
					system("cls");
					break;
				}
				system("cls");
				registra(lg+cont);
				cnt++;
				printf("\nCadastrar outro? Se escolher 'N', voltar� ao menu principal. <S/N>");
				scanf("%c", &opcao);
				fflush(stdin);
			}while(opcao == 'S' ||opcao == 's' );
			system("cls");
			break;
			
		case 2:
			/*if(l==0)
			{
				printf("\n\nOpa! Parece que voc� ainda n�o cadastrou nenhum livro.\n\n");
				system("pause");
				system("cls");
			}
			else
			{*/
			system("cls");
			mlivros(lg,cnt);
			break;
	}
			
	

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



//op��o 3:

void r_livro(livro **l,int tama)
{
if((*l=(livro*)realloc(*l,tama*sizeof(livro)))==NULL)
  exit(1);
}



//registrar livro:
void registra(livro *l)
{
	static int x = 1;
	
	l->id = x;
	x++;
	printf("%i",x);
	printf("\nQual o autor do livro? ");
	gets(l->autor);
	fflush(stdin);
	
	printf("Qual o t�tulo do livro? ");
	gets(l->titulo);
	fflush(stdin);
	
	printf("Qual o status do livro? \n[L] - Livre\n[E] - Emprestado\n[R] - Reservado\n\nResposta: ");
	gets(l->status);
	fflush(stdin);
	
	gv_l (l);
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

void obter_livro(FILE *arq_livros, int id_livro) {

	rewind(arq_livros);
 
	t_livro, *livro;
 
	livro = (t_livro *)malloc(sizeof(t_livro));
	while(1)
	{

		size_t result = fread(livro, sizeof(t_livro), 1, arq_livros);
 
		if(result == 0)
			break;
 
		if(livro->id == id_livro)
			return livro;
	}
	free(livro);
	return NULL;
}

int str_somente_numeros(char str[]) {
	int i = 0;
	int len_str = strlen(str);
 
	for(i = 0; i < len_str; i++)
	{
		if(str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}

void atualizar_livros(FILE *arq_livros, t_livro *livro_alugado)
{
	
	rewind(arq_livros);
 
	t_livro livro;
	while(1) 
	{
 
		
		size_t result = fread(&livro, sizeof(t_livro), 1, arq_livros);
 
		
		if(result == 0)
			break;
 
		
		if(livro.id == livro_alugado->id) {
			fseek(arq_livros, - sizeof(t_livro), SEEK_CUR);
			
			fwrite(livro_alugado, sizeof(t_livro), 1, arq_livros);
			break;
		}
	}
}

void emprestarLivro(){
	char str_raAluno[7];
	int raAluno;
 
	FILE *arq_livros = fopen("livros.bin", "rb+");
	FILE *arq_alunos = fopen("alunos.bin", "rb+");
 
	if(arq_livros == NULL)	{
		arq_livros = fopen("livros.bin", "wb+");
		if(arq_livros == NULL)
		{
			printf("\nFalha ao criar arquivo(s)!\n");
			exit(1);
		}
	}
 
	if(arq_alunos == NULL)	{
		arq_alunos = fopen("alunos.bin", "wb+");
		if(arq_alunos == NULL)
		{
			printf("\nFalha ao criar arquivo(s)!\n");
			exit(1);
		}
	}
 
	printf("\nDigite o RA do aluno: ");
	scanf("%7s%*c", str_raAluno);
 
	fseek(stdin, 0, SEEK_END);
 
	if(str_somente_numeros(str_raAluno) == 1)	{
	
		sscanf(str_raAluno, "%d", &raAluno);
	
			char str_livro[10];
			int id_livro;
 
			printf("\nDigite o ID do livro: ");
			scanf("%10s%*c", str_livro);
 
			if(str_somente_numeros(str_livro) == 1) {
			
				sscanf(str_livro, "%d", &id_livro);
 
				t_livro *livro = obter_livro(arq_livros, id_livro);
 
				if(livro != NULL)	{
		
					if(livro->raAluno != -1)
						printf("\nO livro \"%s\" ja esta alugado!\n", livro->titulo);
					else
					{
						
						livro->raAluno = raAluno;
						atualizar_livros(arq_livros, livro); 
						printf("\nLivro \"%s\" alugado com sucesso!\n", livro->titulo);
					}
					free(filme);
				}
				else
					printf("\nNao existe livro com o ID \"%d\".\n", id_livro);
			}
			else
				printf("\nO ID so pode conter numeros!\n");
		
	}
	else
		printf("\nO ID so pode conter numeros!\n");
 
	// fecha os arquivos
	fclose(arq_alunos);
	fclose(arq_livros);
 
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
 
	fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}
}

