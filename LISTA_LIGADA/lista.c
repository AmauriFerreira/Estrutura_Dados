#include "lista.h"

struct lista * cria_lista () {
	struct lista * ap_lista  = (struct lista *) malloc (sizeof(struct lista));
	if (ap_lista != NULL) {
		ap_lista->primeiro = NULL;
	}
	return ap_lista;
}
int lista_vazia (struct lista * l) {
	if (l->primeiro == NULL) {
		return 1;
	}
	return 0;
}
int insere_inicio (int i, struct lista *l) {
	struct no * novo = cria_no(i);
	if (novo == NULL) {
		return 0;
	}
	if (!lista_vazia(l)) {
		novo->proximo = l->primeiro;
	}
	l->primeiro = novo;
	return 1;
}
void mostra_lista (struct lista *l) {
	struct no * aux = l->primeiro;
	if (aux == NULL) {
		printf ("lista vazia\n");
	}
	else {
		printf ("elementos da lista: ");
		while (aux != NULL) {
			printf ("%d ", aux->info);
			aux = aux->proximo;
		}
	}
}







