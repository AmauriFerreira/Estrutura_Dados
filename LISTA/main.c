
#include "lista.h"



/*void teste_no(){


/*
	A LISTA:
	- SEMPRE ARMAZENAMOS O ENDEREÇO DO 1º ELEMENTO
	- EVENTUALMENTE ARMAZENAMOS:
		- O ENDEREÇO DO ULTIMO
		- O NUMERO DE ELEMENTOS
	- A LISTA EH INDENTIFICADA ENTAO PELO PRIMEIRO.
	
	POR QUESTOES DE CLAREZA E TAMBEM DE FACILIDADE EM
	ACRESCENTAR INFORMACOES, VAMOS CRIAR UMA ESTRUTURA
	QUE ARMAZENE UM ENDERECO:
	O ENDERECO DO PRIMEIRO ELEMENTO.
	
*/
/*int main() {
	
	struct no no1, no2;//no1 eh do tipo struct no
	struct no * ap_no;//ap_no eh um ponteiro de struct no
	printf("Valor armazenado em ap_no inicialmente: %p\n", ap_no);
	no1.info = 10;
	no1.proximo = NULL;
	
	/*nao eh assim:
	ap_no->info = 20;
	ap_no->proximo = NULL;
	EH ASSIM:
	*/
/*	ap_no = cria_no(20);
	if(ap_no != NULL){
		printf("no alocado com sucesso.\n");
		printf("Valor armazenado em ap_no depois da alocacao: %p\n\n", ap_no);
	}else{
		printf("no nao pode ser alocado.\n");
	}
	
	/*
	printf("Onde estah no1: %p\n", &no1);
	printf("Onde estah no2: %p\n", &no2);
	printf("Onde estah ap_no: %p\n", &ap_no);
	printf("Onde estah o espaco que ap_no aponta: %p\n", ap_no);		
	*/
	
/*	no2.info = 30;
	no2.proximo = &no1;
	
	no2.proximo->info = 50;//o campo info do no1 vai receber 50
	no2.proximo->proximo = ap_no;
	ap_no = &no2;
	
	printf("campo info da estrutura apontada por ap_no: %d\n", ap_no->info);
	printf("campo info da estrutura apontada pelo campo proximo da estrutura apontada por ap_no: %d\n", ap_no->proximo->info);
	
	return 0;
}

}*/

void teste_lista(){
	int n;
	struct lista *l = cria_lista();
		if(l != NULL){
			printf("Lista criada com sucesso!\n");
		}else{
			printf("Nao foi possivel criar a lista.\n");
	}
	insere_inicio (3,l);
	insere_inicio (12,l);
	insere_inicio (18,l);
	mostra_lista(l);
	insere_fim(4, l);
	insere_fim(14, l);
	insere_fim(24, l);
	mostra_lista(l);
	if(remove_inicio (&n, l)) {
		
		printf("\n%d foi removido do inicio\n", n);
		mostra_lista(l);
	}
	if(remove_fim (&n, l)) {
		
		printf("\n%d foi removido do fim\n", n);
		mostra_lista(l);
	}
	
}
	
int main(){
	teste_lista();
	
	return 0;
}
