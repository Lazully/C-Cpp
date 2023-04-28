#include<stdio.h>
#include<conio.h>

int main()
{
	
void recebe(float *p, int q);
void calculaMedia (float *p1, float *p2, float *p3, int q);
void mostraStatus (float *p, int q);
float n1[100], n2[100], med[100];
int al;

do
{
	printf("por favor, digite a quantidade de alunos: ");
	scanf("%i", %al);
}while(al<0 || al>100);

recebe(n1,al);
printf("\n");
recebe(n2,qtd,2);
calculaMedia(n1,n2,med,al);
mostraStatus(med,al);

getch();
return 0;
}

void recebe(float *p, int q, int tipo)
{
	int i;
	for(i=0;i<q;i++,p++)
	{
		do
		{
			printf("Aluno %i - Digite a nota %i: ", i+1,tipo);
			scanf("%f", p);
		}while(*p<0 || *p>10);
	}
}
void calculaMedia (float *p1, float *p2, float *p3, int q)
{
	int i;
	for(i=0;i<q;i++,p1++;p2++;p3++)
	{
		*p3 = ((*p1)+(*p2))/2;
	}
}

void mostraStatus (float *p, int q)
{
	int i;
	for(i=0;i<q;i++)
	{
		if(*p>=7)
		{
			printf("\nAluno %i - Media = %2.f - Aprovado!", i+1,*p);
		}
		else if (*p>=4)
		{
			printf("\nAluno %i - Media = %.2f - Exame!",i+1,*p);
		}
		else
		{
			printf("\nAluno %i - Media = %2.f - reprovado!",i+1,*p);
		}
	}
}



