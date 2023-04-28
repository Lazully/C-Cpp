/*
4. Fazer um programa para Controle de Hotel - este programa se destina a controlar o check-in (cadastro de hóspedes) de um hotel. O hotel possui 15 quartos. Utilizar alocação dinâmica e ponteiros para a estrutura.
 
[1] Check-in - alocar dinamicamente espaço, receber os valores digitados pelo usuário, se o hóspede não tiver acompanhantes atribuir categoria Solteiro, caso contrário Familiar, buscar o número do quarto disponível, de acordo com a categoria na estrutura quartos. Apenas um hóspede é cadastrado por vez. Não esquecer de atualizar o quarto da estrutura quartos para Ocupado.
[2] Check-out – encerra a estadia e apresenta o relatório, de acordo com o quarto. Apenas um registro é acessado por vez, buscar e mostrar o número do quarto, o nome do hóspede, quantidade de acompanhantes, a categoria (Solteiro ou Familiar,o tempo de permanência em dias e o valor a ser pago.
[3] Relatorio - Mostra todos os hóspedes ativos.
[4] Fim
 
Dica:
• No check-in - não esquecer de verificar se na estrutura hospede há um espaço vago (cujo quarto = -1), se houver o novo hóspede deverá ser ali armazenado, caso contrário, acrescentar no final da estrutura.
 
struct hospede{
int quarto; // número do quarto
char nome[80];
int acompanhante; // quantidade de acompanhantes
char categoria; // [S]olteiro / [F]amiliar
int dias; // tempo de permanência – em dias
};
 
struct quarto{
int num; // número do quarto
char categoria; // [S]olteiro / [F]amiliar
char status; // [L]ivre / [O]cupado
};
 
Categoria de quarto:
[S]olteiro – diária R$ 85,00 por pessoa
[F]amiliar – diária R$ 45,00 por pessoa
*/

#include<stdio.h>
#include<stdlib.h>

struct hospede{
int quarto; // número do quarto
char nome[80];
int acompanhante; // quantidade de acompanhantes
char categoria; // [S]olteiro / [F]amiliar
int dias; // tempo de permanência – em dias
};
 
struct quarto{
int num; // número do quarto
char categoria; // [S]olteiro / [F]amiliar
char status; // [L]ivre / [O]cupado
};

void aloca_quarto(quartos **p, tam);
void aloca_hospede(hospede **p, int tam);
void cadastra_quarto(quartos *p, int tam);
void cadastra_hospede(hospede *p_hospede, quarto *p_quarto, int qtde_q);
int busca_quarto(quarto *p_quarto, int qtde_q, char categoria);
int busca_hospede(hospede *p, int tam);
void imprime(hospede *p)

int main(){
    quarto *quartos = NULL;
    hospede *hospedes = NULL;
    int opcao, qtde_q = 15;
    
    printf("\n\nSEJA BEM VINDO AO SISTEMA DO HOTEL!");
    
    aloca_quarto(&quartos, qtde_q);
    
    cadastra_quarto(quartos, qtde_q);
    
    do{
        printf("\n\nOpcoes disponiveis:\n\n[1] Check-in;\n[2] Check-out;\n[3] Relatorio\n[4] Fim.\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        fflush(stdin);
        
        switch(opcao){
            case 1:
                printf("\nCHECK-IN\n");
                aux_hospede = busca_hospede(hospedes, qtde_h, -1);
                if(hospedes == NULL || aux_hospede==-1)
                {
                aloca_hospede(&hospedes, qtde_h+1);
                cadastra_hospede(hospedes + qtde_h, quartos, qtde_q);
                qtde_h++;
            	}
            	else{
            		cadastra_hospede(hospedes + aux_hospede, quartos, qtde_q);
				}
				              
                break;
            case 2:
                printf("\nCHECK-OUT\n");
                
                break;
            case 3:
                printf("\nRelatorio dos quartos:\n");
                
                break;
            case 4:
                printf("\nObrigada por utilizar o sistema!\n");
                printf("\n\nRelatorio atual:\n");
                
                break;
            default:
                printf("\nOpcao nao reconhecida!");
            }
    }while(opcao != 4);
    
    return 0;
}

void aloca_quarto(quartos **p, tam)
{
	if((*p=(quarto*)realloc(*p, tam*sizeof(quarto))=NULL)
	{
		printf("\nErro na alocaÁ„o de memÛria. O programa ser· encerrado"));
		exit (1);
	}
}

void aloca_hospede(hospede **p, int tam)
{
	if((*p=(hospede*)realloc(*p, tam*sizeof(hospede))=NULL)
	{
		printf("\nErro na alocaÁ„o de memÛria. O programa ser· encerrado"));
		exit (1);
	}
}

void cadastra_quarto(quartos *p, int tam)
{
	int i;
	for(i=0;i<tam;i++, p++)
	{
		(p+i)->num = i+1;
		(p+i)->status = 'L';
		if((p+i)->num <6)
			(p+i)->categoria = 'S';
			else
			(p+i)->categoria = 'F';
	}
}

void cadastra_hospede(hospede *p_hospede, quarto *p_quarto, int qtde_q)
{
	int aux_quarto;
	printf("\nNome do hÛspede: ");
	gets(p_hospede->nome);
	printf("\nQuantidade de acompanhantes: ");
	scanf("%d", &(p_hospede->acompanhante));
	if(p_hospede->acompanhante>0)
		p_hospede->categoria = 'F';
	else
		p_hospede->categoria = 'S';
	aux_quarto = busca_quarto(p_quarto, qtde_q, p_hospede->categoria)
	if(aux_quarto == -1)
	{
		printf("\nN„o h· quarto disponÌvel nesta categoria. \nO checkin n„o foi realizado");
		p_hospede->quarto = -1;
		return;
	}
	else
	{
		p_hospede->quarto +1;
		printf("\nDias de permanÍncia: ");
		scanf("%d", &(p_hospede->dias));
		fflush(stdin);
		printf("\nCheckin realizado!");
	}
}

int busca_quarto(quarto *p_quarto, int qtde_q, char categoria)
{
	int i;
	for(i=0;i<qtde_q;i++)
	{
		if(p_(quarto+i)->categoria == categoria || (p_quarto+i)>status == 'L')
		{
			return i;
		}
	}
	return -1;
}

int busca_hospede(hospede *p, int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(p->quarto == quarto)
			return i;
	}
	return -1;
}
