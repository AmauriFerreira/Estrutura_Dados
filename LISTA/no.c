#include "no.h"

struct no * cria_no(int i){
	struct no * novo = (struct no *) malloc (sizeof(struct no));
	if(novo != NULL){
		novo->info = i;
		novo->proximo = NULL;
	}	
	return novo;
}
