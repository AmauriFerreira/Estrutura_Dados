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
void inverte (Pilha **p) {
	int i;
	Pilha *aux = cria_pilha();
	Pilha *p_aux = *p;
	while (!pilha_vazia(*p)) {
		pop (&i, *p);
		push (i, aux);
	}
	*p = aux;
	free (p_aux);
}
int maior_pilha (Pilha *p) {
	int maior, aux;
	Pilha *p_aux;
	if (pilha_vazia(p))
		return -1;
	pop(&aux, p);
	maior = aux;
	push(aux, p_aux);
	while (!pilha_vazia(p)) {
		pop(&aux, p);
		if (aux > maior) {
			maior = aux;
		}
		push(aux, p_aux);
	}
	while (!pilha_vazia(p_aux)){
		pop(&aux, p_aux);
		push(aux, p);
	}
	return maior;
}

int main(int argc, char *argv[]) {
	Pilha * p1 = cria_pilha();
	Pilha * aux_p;
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
		
		aux_p = p1;
		p1 = invertida (p1);
		//mostra_pilha (p1);
		free (aux_p);
		inverte(&p1);
		//mostra_pilha(p1);
	}
	else {
		printf ("\nfalha na alocacao\n");
	}
	return 0;
}

