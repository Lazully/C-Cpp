//Nome: RA:
//Nome: RA:
//Nome: RA:

//ENUNCIADO (1� semana)
//1� etapa -Fazer menu e rotina para:
Arquivo e Cadastro de ALUNOScontendo uma estrutura com:
/*nome
RA
quantidade de livros emprestados (m�ximo 3)
quantidade de livros reservados(m�ximo 1) 
tabela 0 (ir� conter o status e o n� de registro do 1� livro, se for o caso)
tabela 1 (ir� conter o status e o n� de registro do 2� livro, se for o caso)
tabela 2 (ir� conter o status e o n� de registro do 3� livro, se for o caso)
tabela 3 (ir� conter o status e o n� de registro do 4� livro, se for o caso)
as tabelas devem ser struct?as tabelas devem ser inicializadas com �L� �livre
Consulta da situa��o do aluno�2 
tipos de consulta:
Total?mostrar  o  nome,  RA  e  a  quantidade  de  livros  emprestados  e reservados 
(se for o caso �mostrar as tabelas)oParcial?o acesso deve ser feito atrav�s do RA
do aluno
mostrar   o   nome
e   a   
quantidade   de   livros   emprestados   e reservados(se for o caso �mostrar as tabelas)para aquele aluno
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>


int main()
{
	
	setlocale(LC_ALL, "Portuguese"); //permite acentuar as palavras
	
	
	char nome[50], ra;
	int qtde_l;

	
	printf("Ol�! Digite:\nNome do aluno: ");
	gets(nome);
	printf("RA do aluno:", ra);
	scanf("%c", ra);
	printf("Quantidade de livros emprestados:", qtde_l);
	scanf("%i", qtde_l);
	system ("pause");

	return 0;
}

//Todo o projeto foi feito por autoria pr�pria
