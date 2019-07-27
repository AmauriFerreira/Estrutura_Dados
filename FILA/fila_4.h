#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;

Fila * cria_fila (int);

int fila_vazia (Fila *);
int fila_cheia (Fila *);

int insere (int, Fila *);

int remov (int *, Fila *);

int tamanho (Fila *);

void mostra_fila (Fila *);

void mostra_vetor (Fila *);

