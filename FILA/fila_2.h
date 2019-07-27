#include "no.h"
#include <stdlib.h>

typedef struct fila Fila;

Fila * cria_fila ();

int fila_vazia (Fila *);

int insere (int, Fila *);

int remov (int *, Fila *);

int tamanho (Fila *);

void mostra_fila (Fila *);



