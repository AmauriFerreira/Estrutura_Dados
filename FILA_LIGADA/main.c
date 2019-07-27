#include "fila.h"
#include <time.h>

int intercala_filas (Fila * f1, Fila * f2) {
	
	int i;
	Fila * f3 = cria_fila();
	while (!fila_vazia(f1) && !fila_vazia(f2)){
		remov(&i, f1);
		insere(i, f3);
		remov(&i, f2);
		insere(i, f3);
	}
	while (!fila_vazia(f1)){
		remov(&i, f1);
		insere(i, f3);
	}
	while (!fila_vazia(f2)){
		remov(&i, f2);
		insere(i, f3);
	}	
	
	return f3;
}


void split_filas (Fila * f1, Fila * f2, Fila * f3){
	
	int i;
	while (!fila_vazia(f1)){
		remov (&i, f1);
		if(i%2 == 1){
			insere(i, f2);
		}
		else{
			insere(i, f3);
		}
	}
}
/*		if(fila_vazia(f)){
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
	
	if (f->)
	
	return 1;
}
	*/


void concatena (Fila * f1, Fila * f2) {
	int i;
	while (!fila_vazia(f2)) {
		remov(&i, f2);
		insere(i, f1);
	}
}

void teste_fila () {
	Fila *f;
	int c;
	f = cria_fila();
	srand (time(0));
	do {
		if (rand() % 2) {
			if (insere(rand()%10, f)) {
				printf ("inseriu: ");
				mostra_fila(f);
			}
		}
		else {
			if (remov(&c, f)) {
				printf ("removeu: ");
				mostra_fila(f);
			}
		}
	} while (!fila_vazia(f));
}

int main(int argc, char *argv[]) {
	//teste_fila();
	Fila * f1 = cria_fila (8);
	Fila * f2 = cria_fila (4);
	
	insere (1, f1);
	insere (2, f1);
	insere (3, f1);
	insere (10, f1);
	insere (12, f1);
	insere (4, f2);
	insere (5, f2);
	insere (6, f2);
	insere (7, f2);
	

	mostra_fila(f1);
	mostra_fila(f2);
	
//	concatena (f1, f2);
//	mostra_fila(f1);
///	mostra_fila(f2); 
	
	intercala_filas(f1,f2);
	
	return 0;
}

