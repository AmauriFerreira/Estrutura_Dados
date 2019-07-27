# include <stdio.h>
# include <stdlib.h>
# include <time.h>


void gera_vetor (int *v, int n);
void mostra_vetor (int *, int  );
	


int main ()
 
{
	
	int *v, n; 
	srand (time (NULL));
	printf ("Digite o tamanho do vetor: ");
	scanf ("%d", &n );
	v = (int*) malloc (n * sizeof(int));
	gera_vetor (v,n);
	mostra_vetor (v,n);
	return 0;
}

void gera_vetor (int *v, int n){
	int i;
	for (i+0; i<n; i++)
	v[i]= rand();
}

void mostra_vetor (int *v, int a ) 
{
	
	int i;
	for (i=0; i<a; i++) {
		printf ("%d\n" , v[i]);
		
	}
	printf ("\n");
}
