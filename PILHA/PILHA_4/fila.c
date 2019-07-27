#include "fila.h"

struct fila {
	
	int prim, ult, cont, capacidade;
	int * dados;
};

Fila * cria_fila (int i){
	
	Fila * f = (Fila *) malloc (sizeof(Fila)); 
	if(f != NULL) {
		f->prim = 0;
		f->ult = 0;
		f->cont = 0;
		f->capacidade = i;
		f->dados = (int *) malloc (sizeof(int) * i);
	}
	return f;
}

int fila_vazia (Fila * f){
	
	return !f->cont;
}

int fila_cheia (Fila * f){
	
	return (f->cont == f->capacidade);
}

int proxima (int posicao, Fila * f) {
	return (posicao + 1) % f->capacidade;
}

int insere (int i, Fila * f){
	
	if(fila_cheia(f)){
		return 0;
	}
	f->dados[f->ult] = i;
	f->ult = proxima(f->ult, f);
	f->cont++;
	return 1;
}

int remov (int * i, Fila * f){
	
	if(!fila_vazia(f)){
		
		*i = f->dados[f->prim];
		f->prim = proxima(f->prim, f);
		f->cont--;
		return 1;
	}
	return 0;
}

int tamanho (Fila * f){
	return f->cont;
}

void mostra_fila (Fila * f){
	int i;
	
	if(fila_vazia(f)){
		printf("\nFila vazia.\n");
	}
	else{
			i = f->prim;
			do{
				printf("%d ", f->dados[i]);
				i = proxima(i, f);
			}
			while (i!= f->ult);
		}
	printf("\n");
}

void mostra_vetor (Fila *f) {
	int i;
	if (fila_vazia(f)) {
		printf ("fila vazia");
	} 
	else {
		if (f->prim < f->ult) {
			for (i=0; i<f->prim; i++) {
				printf ("- ");
			}
			for (i=f->prim; i<f->ult; i++) {
				printf ("%d ", f->dados[i]);
			}
			for (i=f->ult; i<f->capacidade; i++) {
				printf ("- ");
			}
		}
		else if (f->ult < f->prim) {
			for (i=0; i<f->ult; i++) {
				printf ("%d ", f->dados[i]);
			}
			for (i=f->ult; i<f->prim; i++) {
				printf ("- ");
			}
			for (i=f->prim; i<f->capacidade; i++) {
				printf ("%d ", f->dados[i]);
			}
		}
		else {
			for (i=0; i<f->capacidade; i++) {
				printf ("%d ", f->dados[i]);
			}
		}
	}
	printf ("\n");
	system ("pause>>null");
}



