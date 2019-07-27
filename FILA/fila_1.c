#include "fila.h"

struct fila {
	
	struct no * primeiro;
	struct no * ultimo;
	int cont;
};

Fila * cria_fila() {
	Fila * f = (Fila *) malloc (sizeof(Fila));
	if (f != NULL) {
		
		f->primeiro = NULL;
		f->ultimo = NULL;
		f->cont = 0;
	}
	return f;
}

int fila_vazia (Fila * f)  {
	return !f->cont;
}


int insere (int i , Fila * f){
	struct no * novo = cria_no(i);
	if (novo != NULL) {
		if(fila_vazia(f)){
			f->primeiro = novo;
		}
		else{
			f->ultimo->proximo = novo;
		}
		f->ultimo = novo;
		f->cont++;
		
		return 1;
	}
	return 0;
}

int remov (int * i, Fila * f){
	
	struct no * aux;
	if(fila_vazia(f)){
		return 0;
	}
	aux = f->primeiro;
	*i = f->primeiro->info;
	f->primeiro = f->primeiro->proximo;
	f->cont--;
	if(f->primeiro == NULL){
		f->ultimo = NULL;
	}
	free(aux);
	return 1;
	
}

int tamanho (Fila * f) {
	return f->cont;
}

void mostra_fila (Fila *f){
	struct no * aux;
	if(fila_vazia(f)){
		printf("\nFila vazia\n");
	}
	else{
		aux = f->primeiro;
		while(aux != NULL) {
			printf("%d ", aux->info);
			aux = aux->proximo;
		}
		printf("\n");
	}	
}




