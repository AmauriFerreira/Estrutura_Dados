#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int capacidade, ocupacao;
	int *elementos; 
} vetor_dinamico;

vetor_dinamico *cria_vetor (int capacidade) {
	vetor_dinamico *v = 
	(vetor_dinamico *) malloc (sizeof(vetor_dinamico));
	v->capacidade = capacidade;
	v->ocupacao = 0;
	v->elementos = (int *) malloc (sizeof(int) * capacidade);
	return v;
}
int esta_vazio (vetor_dinamico *v) {
	//return !v->ocupacao;
	//return (v->ocupacao == 0);
	if (v->ocupacao == 0) 
		return 1;
	return 0;
}
int esta_cheio (vetor_dinamico *v) {
	//return (v->ocupacao == v->capacidade);
	if (v->ocupacao == v->capacidade) 
		return 1;
	return 0;
}
int precisa_diminuir (vetor_dinamico *v) {
	if (v->ocupacao <= v->capacidade/4) 
		return 1;
	return 0;
}
/*NÃO É ASSIM QUE FAZ!!!
void aumenta (vetor_dinamico *v) {
	int * aux = (int *) malloc (sizeof(int) * v->capacidade*2);
	int i; 
	for (i=0; i<v->ocupacao; i++)
		aux[i] = v->elementos[i];
	free(v->elementos);
	v->elementos = aux;
	v->capacidade = v->capacidade * 2;
}
void diminui (vetor_dinamico *v) {
	int * aux = (int *) malloc (sizeof(int) * (v->capacidade/2));
	int i; 
	for (i=0; i<v->ocupacao; i++)
		aux[i] = v->elementos[i];
	free(v->elementos);
	v->elementos = aux;
	v->capacidade = v->capacidade / 2;
}*/
void redimensiona (vetor_dinamico *v, int nova_capacidade) {
	int * aux = (int *) malloc (sizeof(int) * nova_capacidade);
	int i; 
	for (i=0; i<v->ocupacao; i++)
		aux[i] = v->elementos[i];
	free(v->elementos);
	v->elementos = aux;
	v->capacidade = nova_capacidade;
}
void mostra (vetor_dinamico *v) {
	int i;
	printf ("\ncapacidade = %d\nocupacao = %d\n", 
	v->capacidade, v->ocupacao);
	for (i=0; i<v->ocupacao; i++) {
		printf ("%d ", v->elementos[i]);
	}
	printf ("\n");
}
void insere (int i, vetor_dinamico *v) {
	if (esta_cheio(v)) {
		redimensiona (v, v->capacidade*2);
	}
	v->elementos[v->ocupacao] = i;
	v->ocupacao++;
}
void remov (int *i, vetor_dinamico *v) {
	v->ocupacao--;
	*i = v->elementos[v->ocupacao];
	if (precisa_diminuir (v)) 
		redimensiona (v, v->capacidade/2);
}
int main () {
	vetor_dinamico * v = cria_vetor(10);
	int i;
	for (i=1; i<=35; i++) {
		insere (i, v);
		mostra (v);
	}
	while (!esta_vazio(v)) {
		remov (&i, v);
		mostra (v);
		printf ("%d foi removido\n", i);
	}
	return 0;
}






