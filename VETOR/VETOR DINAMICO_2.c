#include <stdio.h>
#include <stdlib.h>

//elementos = ponteiro de inteiro
typedef struct {
		int capacidade, ocupacao;
		int *elemento;
} vetor_dinamico;

typedef vetor_dinamico* ponteiro_vd;
// malloc devolve o genérico, quero o vetor dinamico*
vetor_dinamico *cria_vetor (int Pcapacidade) {
vetor_dinamico *v = (vetor_dinamico *) malloc (sizeof(vetor_dinamico));
	v->capacidade=Pcapacidade;
	v->ocupacao=0;
	v->elemento= (int*)malloc(sizeof(int)* Pcapacidade);
	return v; // está retornando o vetor_dinamico
}
	
	int esta_vazio(vetor_dinamico *v){
	//return !v->ocupacao
	if (v->ocupacao == 0){
		return 1;
	return 0;
	}
}
	
	int esta_cheio (vetor_dinamico *v){
		
			if (v->ocupacao== v->capacidade)
		return 1;	
	return 0;
	}
	void aumenta (vetor_dinamico *v) {
		int *aux = (int*) malloc(sizeof(int) * v->capacidade*2);
		int i;
		for (i=0; i<v->ocupacao; i++) {
			aux[i] = v->elemento[i];
		}
		free(v->elemento);
		v->elemento = aux;
		v->capacidade = v->capacidade*2;
	}
	void mostra (vetor_dinamico *v){
		int i;
		printf ("\ncapacidade = %d\nocupacao = %d\n", v->capacidade, v->ocupacao);
		for(i=0; i<v->ocupacao; i++){
			printf ("%d", v->elemento[i]);
		}	}

	void insere (int i, vetor_dinamico *v) {
	if (esta_cheio(v)){
		aumenta(v);
	}
	v->elemento[v->ocupacao] = i;
	v->ocupacao++;
}
	
int main (){
	

	vetor_dinamico * v = cria_vetor(5);
	int i;
	for (i=1; i<=50; i++){
		insere (i,v);
		mostra (v);
	}
	return 0;
}
