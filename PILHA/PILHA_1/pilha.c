#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha
{
	int v[MAX];
	int topo;
};

Pilha * cria_pilha()
{
	Pilha * p = (Pilha *) malloc (sizeof(Pilha));
	
	if (p != NULL)
	{
		p -> topo = 0;
		return p;
	}
	
	int pilha_vazia (const Pilha *p)
	{
	/*	if (p -> topo == 0)
			{
				return 1;
			}else
				{
					return 0;
				}*/
				return !p-> topo;
	}
	int pilha_cheia (const Pilha *p)
	{
		if(p-> topo == MAX)
			return 1;
		else
			return 0;
	//			return (p -> topo == MAX);
	}
	
	int push(int i, Pilha *p)
		{
			if (pilha_cheia(p))
				return 0;
			/*p-> v[p->topo] = i;
			p->topo++;*/
			p->v[p->topo++] = i;
		}
		
	int pop (int *i, Pilha *p)
		{
			if (pilha_vazia(p))
				return 0;
			/*p-> topo--;
			
			i* = p -> v[p->topo];*/
			
		 	*i = p->v[--p->topo];
			return 1;
		}

	int tamanho(const Pilha *p)
		{
			return p -> topo;
		}

	int consulta_topo(const Pilha *p)
		{
			if (!pilha_vazia(p))
				return p-> v[p->topo-1];
			return -1;
		}
		
	void mostra_pilha (const Pilha *p)
	{
		int i;
		if (pilha_vazia(p))
			printf("esta vazia");
			else
				for (i= p-> topo-1; i>=0; i--)
					printf("%d", p->v[i]);
				printf("\n");
	}
}
