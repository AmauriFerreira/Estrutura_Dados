#include <stdio.h>
#include <stdlib.h>
typedef struct pilha Pilha;

Pilha * cria_pilha ();

int pilha_vazia (const Pilha *);

int push (int, Pilha *);
int pop (int *, Pilha *);

int tamanho (const Pilha *);
int consulta_topo (const Pilha *);

void mostra_pilha (const Pilha *);

