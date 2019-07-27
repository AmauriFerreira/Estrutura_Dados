#include "no.h"
#include <stdio.h>

struct lista{
	struct no * primeiro;
};

struct lista * cria_lista();

int lista_vazia(struct lista *);

int insere_inicio (int, struct lista *);

void mostra_lista(struct lista *);

int insere_fim (int, struct lista *);

int remove_inicio (int *, struct lista *);

int remove_fim (int *, struct lista *);
return 0;
