#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor (int *, int, int);
void mostra_vetor (int *, int, char *);
void bubble (int *, int);
void insertion (int *, int);
int partition(int*, int,int);
void quick(int*, int,int);


int main () {
	int *v, n, limite;
	srand(time(NULL));
	printf ("Digite o tamanho do vetor: ");
	scanf ("%d", &n);
	printf ("Digite o limite do rand: ");
	scanf ("%d", &limite);
	v = (int *) malloc (n * sizeof(int));
	gera_vetor (v, n, limite);
	//mostra_vetor (v, n, "Vetor Gerado");
	
	printf ("\nbubble...\n");
	bubble (v, n);
	//mostra_vetor (v, n, "Vetor Ordenado pelo bubble");
	
	gera_vetor (v, n, limite);
	//mostra_vetor (v, n, "Vetor Gerado");
	printf ("\ninsertion...\n");
	insertion (v, n);
	mostra_vetor (v, n, "Vetor Ordenado pelo insertion");
	
	gera_vetor (v, n, limite);
	//mostra_vetor (v, n, "Vetor Gerado");
	printf ("\nquick...\n");
	quick (v,0, n-1);
	//mostra_vetor (v, n, "Vetor Ordenado pelo quick");
	
	
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

int partition(int*v, int p ,int r){
	int i, j,x, aux;
	x = v[r];
	i = p-1;
	for(j=p; j <r; j++){
		if (v[j]<x){
			i++;
			aux = v[i];
			v[i]=v[j];
			v[j] = aux;
		}
		i++;
		aux = v[r];
		v[r] = v[i];
		v[i] = aux;
		return 1;
	}
}
void quick(int*v, int p ,int r){
	int q;
	if(p<r){
		q = partition(v, p, r);
		quick(v,p, q-1);
		quick(v, q+1, r);
	}
}







