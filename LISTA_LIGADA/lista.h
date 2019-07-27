#include <stdio.h>
#include "no.h"

struct lista {
	struct no * primeiro;
};

struct lista * cria_lista ();
int lista_vazia (struct lista *);
int insere_inicio (int, struct lista *);

void mostra_lista (struct lista *);

