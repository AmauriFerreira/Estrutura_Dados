#include "fila.h"
#include <time.h>

int concatena (Fila * f1, Fila * f2){
	int i, cont = 0;
	
	while (!fila_vazia(f2) && !fila_cheia(f1)) {
		remov(&i, f2);
		insere(i,f1);
		cont ++;
	
	}
	return cont;
}


void teste_fila () {
	
		Fila * f;
	int c;
	printf("Capacidade da fila: ");
	scanf("%d", &c);
	f= cria_fila(c);
	srand (time(0));
	
	do{
		if(rand() % 2){
			if(insere(rand()%10, f)){
				printf("\nInseriu: ");
				//mostra_fila(f);
				mostra_vetor(f);
			}
		}
		else{
			if(remov(&c, f)){
				printf("Removeu: ");
			//	mostra_fila(f);
				mostra_vetor(f);
			}
		}
	}while (!fila_vazia(f)); 
	
	return 0;	
}





int main(int argc, char *argv[]) {
	
//	teste_fila();
	int cont =0;
	Fila * f1 = cria_fila(8);
	Fila * f2 = cria_fila(4);
	insere(1, f1);
	insere(2, f1);
	insere(3, f1);
	insere(12, f1);
	insere(13, f1);
	insere(4, f2);
	insere(5, f2);
	insere(6, f2);
	insere(7, f2);
	
	cont = concatena(f1,f2);
	printf("\nForam transferidos %d valores \n", cont);
	
	mostra_fila(f1);
	mostra_fila(f2);
	
	
	return 0;
}
