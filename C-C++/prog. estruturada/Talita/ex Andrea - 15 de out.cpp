#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>



//estrutura, novo tipo de dado feito pelo programador
struct cliente{
	char nome[30];
	int conta;
	float saldo;
};

struct cliente cadastro();
struct cliente movimento(struct cliente x, int op);


//main
main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	//declarar uma matriz de estrutura para a estrutura acima ser dada como verdadeira
	struct cliente cli[10]; //chamei a estrutura declarada antes da main e defini uma quant de dados
	int op, cont=0;
	
	do{
		system("cls"); //limpa a tela
		printf("\n[1]Cadastro\n[2]Depósito\n[3]Retirada\n[4]Fim\nOpção: ");
		scanf("%i", &op);
		fflush(stdin); //limpa o buffer do teclado
		switch(op)//verifica a opção
		{
			case 1: if(cont<10)
				{
					cli[cont]=cadastro();
					cont++;
				}//if de case
			else
				printf("\nCadastro lotado\n\n");
			break;
		case 2:
		case 3: printf("\nConta: ");
				scanf("%i", &num_conta);
				fflush(stdin);
				achou=0;
				for(i=0; i<cont; i++)
				
					if(cli[i].conta==num_conta)
					{
						cli[i]=movimento(cli[i], op);
						achou=1
					}
					if(achou==0)
					
						printf("\nConta Inválida\n\n");
					break;
		
		}//fim do switch
	
	}while(op!=4);//fim do Do
	
	return 0;
}//fim da main

struct cliente cadastro()
{
	struct cliente aux;
	static int n_conta=1000; //variável estática não perde o valor quando sai da função :)
	
	printf("\nNome: ");
	gets(aux.nome);
	fflush(stdin);
	aux.conta=n_conta;
	aux.saldo=0;
	n_conta++;
	printf("\nConta: %i\n\n", aux.conta);
	system("pause");
	return aux;
}//função cadastro após a main

struct cliente movimento(struct cliente x, int op)
{
	float valor;
	printf("\nNome: %s\nSaldo: %.2f", x.nome, x.saldo);
	printf("\nValor a ser depositado/retirado: ");
	scanf("%f", &valor);
	fflush(stdin);
		if(op==2)  //depósito
			x.saldo+=valor;
		else //retirada
			{
				if(valor<=x.saldo)
					x.saldo-=valor;
				else
					printf("\nSaldo Insuficiente\n\n");
			}//else
	printf("\nSaldo Atualizado: %.2f\n\n", x.saldo);
	system("pause");
	return x;
}//movimento




