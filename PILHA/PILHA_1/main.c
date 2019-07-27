#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Pilha * p1 = cria_pilha();
	int i;
	 
	
	if (p1)
		{
			printf("\nPilha criada com sucesso\n");			
		
			if (pilha_vazia(p1))
				printf("\nA pilha esta vazia\n");
			else
				printf("\nnue?");
		
		for(i=1; i<=6; i++)
			{
				push (i, p1);
				printf("\nempilhou %d\n", i);
				mostra_pilha(p1);
			}
			while (!pilha_vazia(p1))
				{
					pop(&i, p1);
					printf("%d foi desempilhado \n", i);
					mostra_pilha (p1);
				}
		}else
			{
				printf("\nfalha na alocacao\n");
			}
	
	return 0;
}
