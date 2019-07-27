#include "pilha.h"
#include "C:\Users\aluno.IPIRANGA\Desktop\Nova pasta\no.h"

struct pilha {
	struct no * topo;
};

Pilha * cria_pilha () {
	struct pilha * ap_pilha  = (struct pilha *) malloc (sizeof(struct pilha));
	if (ap_pilha != NULL) {
		ap_pilha->topo = NULL;
	}
	return ap_pilha;
}

int pilha_vazia (const Pilha *p){
	
	if(p->topo == NULL){
		return 1;
	}
	return 0;
}

int push (int i , Pilha * p){
	
	struct no * novo = cria_no(i);
	if(novo == NULL){
		return 0;
	}
	if(!pilha_vazia(p)){
		novo->proximo = p->topo;
	}
	p->topo = novo;
	return 1;
}
int pop (int * i, Pilha *p){
	
	struct no * aux;
	if (pilha_vazia(p)){
		return 0;
	}
	aux = p->topo;
	*i = p->topo->info;
	p->topo = p->topo->proximo;
	free(aux);
	return 1;
}

int tamanho (const Pilha *p){
	int cont = 0;
	struct no * aux = p->topo;
	while(aux != NULL){
		cont++;
		aux = aux->proximo;
	}
	return cont;
}

int consulta_topo (const Pilha *p){
	if(pilha_vazia(p)){
		return -1;
	}
	return p->topo->info;
	
}
void mostra_pilha (const Pilha *p){
	
	struct no * aux = p->topo;
	if(aux == NULL){
		printf("Pilha vazia.\n");
	}else{
		printf("Elementos da pilha: \n");
		
		while (aux != NULL){ //fim da pilha
			printf("%d ", aux->info);
			aux = aux->proximo;
		}
	}
	
	printf("\n");
}
