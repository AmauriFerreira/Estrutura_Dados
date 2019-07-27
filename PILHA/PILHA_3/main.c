#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha * invertida (Pilha *p) {
	int i;
	Pilha *aux = cria_pilha();
	while (!pilha_vazia(p)) {
		pop (&i, p);
		push (i, aux);
	}
	return aux;
}

int main(int argc, char *argv[]) {
	Pilha * p1 = cria_pilha();
	int i;
	if (p1) {
		printf ("\npilha criada com sucesso\n");
		if (pilha_vazia(p1))
			printf ("\na pilha esta vazia\n");
		else
			printf ("\nue?");
		for (i=1; i<=6; i++) {
			push (i, p1);
			printf ("empilhou %d\n", i);
			mostra_pilha (p1);
		}
		/*while (!pilha_vazia(p1)) {
			pop (&i, p1);
			printf ("%d foi desempilhado\n", i);
			mostra_pilha (p1);
		}*/
		p1 = invertida (p1);
		mostra_pilha (p1);
	}
	else {
		printf ("\nfalha na alocacao\n");
	}
	return 0;
}
