#include "lista.h"

struct lista * cria_lista(){
	struct lista * ap_lista = (struct lista *) malloc (sizeof(struct lista));//apontador de lista
	if(ap_lista != NULL){
		ap_lista->primeiro = NULL;
	}
	return ap_lista;
}

int lista_vazia(struct lista *l){
	if(l->primeiro == NULL){
		return 1;
	}
	return 0;
}

int insere_inicio (int i, struct lista *l){
	struct no * novo = cria_no(i);
	if(novo == NULL){
		return 0;
	}
	if(!lista_vazia(l)){
		novo->proximo = l->primeiro;
	}
	l->primeiro = novo;
	return 1;
}

void mostra_lista(struct lista *l){
	struct no * aux = l->primeiro;
	if(aux == NULL){
		printf("Lista vazia.\n");
	}else{
		printf("Elementos da lista: \n");
		
		while (aux != NULL){ //fim da lista
			printf("%d ", aux->info);
			aux = aux->proximo;
		}
	}
	
	printf("\n");
}
int insere_fim (int i, struct lista *l) {
	
	struct no * aux;
	struct no * novo = cria_no(i);
	
	if(novo == NULL) {
		return 0;
	}
	if (lista_vazia(l)) {
		l->primeiro = novo;
	}
	else{
		aux = l->primeiro;
		while (aux->proximo != NULL) {
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
	return 1;
}

int remove_inicio (int * i, struct lista * l){
	
	struct no * aux;
	if (lista_vazia(l)){
		return 0;
	}
	aux = l->primeiro;
	*i = l->primeiro->info;
	l->primeiro = l->primeiro->proximo;
	free(aux);
	return 1;
}

int remove_fim (int * i, struct lista * l) {
	
	struct no * aux;
	if(lista_vazia(l)){
		
		return 0;
	}
	
	if(l->primeiro->proximo == NULL) { //apenas 1
		
		*i = l->primeiro->info;
		free(l->primeiro);
		l->primeiro = NULL;
	}
	else {
		aux = l->primeiro;
		while(aux->proximo->proximo != NULL) {
			
			aux = aux->proximo;
		}
		*i = aux->proximo->info;
		free(aux->proximo);
		aux->proximo = NULL;
	}
	return 1;
}













