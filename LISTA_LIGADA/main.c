#include "lista.h"

void teste_no() {
	struct no no1, no2;
	struct no * ap_no;
	printf ("valor armazenado em ap_no inicialmente: %p\n", ap_no);
	no1.info = 10;
	no1.proximo = NULL;
	/*não é assim
	  ap_no->info = 20;
	  ap_no->proximo = NULL;
	*/
	//é assim
	ap_no = cria_no(20);
	/*if (ap_no != NULL) {
		printf ("no alocado com sucesso\n");
		printf ("valor armazenado em ap_no depois da alocacao: %p\n", ap_no);
	}
	else {
		printf ("no nao pode ser alocado\n");
	}
	printf ("onde esta no1: %p\n", &no1);
	printf ("onde esta no2: %p\n", &no2);
	printf ("onde esta ap_no: %p\n", &ap_no);
	printf ("onde esta o espaco que ap_no aponta: %p\n", ap_no);*/
	
	no2.info = 30;
	no2.proximo = &no1;
	
	no2.proximo->info = 50;
	
	no2.proximo->proximo = ap_no;
	
	ap_no = &no2;
	
	printf ("campo info da estrutura apontada por ap_no: %d\n", ap_no->info);
	printf ("campo info da estrutura apontada pelo campo proximo da estrutura apontada por ap_no: %d\n", ap_no->proximo->info);
}
void teste_lista () {
	struct lista *l = cria_lista();
	if (l != NULL) {
		printf ("lista criada com sucessuu!!\n");
	}
	else {
		printf ("nao foi possivel criar a lista\n");
	}
	insere_inicio (3, l);
	insere_inicio (12, l);
	insere_inicio (18, l);
	mostra_lista (l);
}

int main(int argc, char *argv[]) {
	//teste_no();
	teste_lista();
	return 0;
}






