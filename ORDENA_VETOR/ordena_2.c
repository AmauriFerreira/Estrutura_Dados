#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor (int *, int, int);
void mostra_vetor (int *, int, char *);
void bubble (int *, int);
void insertion (int *, int);
int busca_simples (int *, int, int, int *);
int busca_binaria (int *, int, int, int *);

int main () {
	int *v, n, limite, x, cont;
	srand(time(NULL));
	printf ("Digite o tamanho do vetor: ");
	scanf ("%d", &n);
	printf ("Digite o limite do rand: ");
	scanf ("%d", &limite);
	v = (int *) malloc (n * sizeof(int));
	gera_vetor (v, n, limite);
	mostra_vetor (v, n, "Vetor Gerado");
	printf ("Digite o valor da busca: ");
	scanf ("%d", &x);
	if (busca_simples(v, n, x, &cont)) {
		printf ("\nachei o x na busca simples com %d comparacoes\n", cont);
	}
	else {
		printf ("\nNao achei o x na busca simples com %d comparacoes\n", cont);
	}
	printf ("\nvou ordenar\n");
	bubble (v, n);
	
		mostra_vetor (v, n, "Vetor Ordenado");
	if (busca_binaria(v, n, x, &cont)) {
		printf ("\nachei o x na busca binaria com %d comparacoes\n", cont);
	}
	else {
		printf ("\nNao achei o x na busca binaria com %d comparacoes\n", cont);
	}
	
	printf ("\nvou ordenar\n");
	insertion (v, n);
	
	mostra_vetor (v, n, "Vetor Ordenado");
	if (busca_binaria(v, n, x, &cont)) {
		printf ("\nachei o x na busca binaria com %d comparacoes\n", cont);
	}
	else {
		printf ("\nNao achei o x na busca binaria com %d comparacoes\n", cont);
	}
	return 0;
}

void gera_vetor (int *v, int n, int limite) {
	int i;
	for (i=0; i<n; i++)
		v[i] = rand() % limite;
}
void mostra_vetor (int *v, int n, char *msg) {
	int i;
	printf ("\n%s\n", msg);
	for (i=0; i<n; i++)
		printf ("%d ", v[i]);
	printf ("\n");
}
void bubble (int *v, int n) {
	int i, j, aux;
	for (i=1; i<n; i++) {
		for (j=0; j<n-i; j++) {
			if (v[j] > v[j+1]) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}
void insertion (int *v, int n) {
	int i, j, x;
	for (i=1; i<n; i++) {
		x = v[i];
		for (j=i-1; j>=0 && v[j] > x; j--) {
			v[j+1] = v[j];
		}
		v[j+1] = x;
	}
}
int busca_simples (int *v, int n, int x, int *cont) {
	int i;
	*cont = 0;
	for (i=0; i<n; i++) {
		(*cont)++;
		if (v[i] == x)
			return 1;
	}
	return 0;
}
int busca_binaria (int *v, int n, int x, int *cont) {
	int ini=0, fim=n-1, meio;
	*cont = 0;
	while (ini <= fim) {
		(*cont)++;
		meio = (ini + fim) / 2;
		if (x == v[meio])
			return 1;
		if (x > v[meio])
			ini = meio + 1;
		else
			fim = meio - 1;
	}
	return 0;
}





