#include <stdlib.h>
/* NÃO FAÇA ISSO !!!!!
int * cria_vetor (int n) {
	int v[n], i;
	for (i=0; i<n; i++) {
		v[i] = i;
	}
	return v;
}*/
int * cria_vetor (int n) {
	int *v, i;
	v = (int *) malloc (n * sizeof(int));
	for (i=0; i<n; i++) {
		v[i] = i;
	}
	return v;
}
int main () {
	int *v1, *v2;
	v1 = cria_vetor(5);
	v2 = cria_vetor(10);
	//processou tudo de v1 e tudo de v2
	free(v1);
	v1 = NULL;
	free(v2);
	v2 = NULL;
	return 0;
}
