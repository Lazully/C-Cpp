//Nome: RA:
//Nome: RA:
//Nome: RA:

//ENUNCIADO (1ª semana)
//1ª etapa -Fazer menu e rotina para:
Arquivo e Cadastro de ALUNOScontendo uma estrutura com:
/*nome
RA
quantidade de livros emprestados (máximo 3)
quantidade de livros reservados(máximo 1) 
tabela 0 (irá conter o status e o nº de registro do 1º livro, se for o caso)
tabela 1 (irá conter o status e o nº de registro do 2º livro, se for o caso)
tabela 2 (irá conter o status e o nº de registro do 3º livro, se for o caso)
tabela 3 (irá conter o status e o nº de registro do 4º livro, se for o caso)
as tabelas devem ser struct?as tabelas devem ser inicializadas com “L” –livre
Consulta da situação do aluno–2 
tipos de consulta:
Total?mostrar  o  nome,  RA  e  a  quantidade  de  livros  emprestados  e reservados 
(se for o caso –mostrar as tabelas)oParcial?o acesso deve ser feito através do RA
do aluno
mostrar   o   nome
e   a   
quantidade   de   livros   emprestados   e reservados(se for o caso –mostrar as tabelas)para aquele aluno
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

	
	printf("Olá! Digite:\nNome do aluno: ");
	gets(nome);
	printf("RA do aluno:", ra);
	scanf("%c", ra);
	printf("Quantidade de livros emprestados:", qtde_l);
	scanf("%i", qtde_l);
	system ("pause");

	return 0;
}

//Todo o projeto foi feito por autoria própria
