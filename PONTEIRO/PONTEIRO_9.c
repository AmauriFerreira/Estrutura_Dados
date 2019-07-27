#include <stdio.h>
#include <stdlib.h>


int * cria_vetor (int n) {
	int *v, i;
	v=(int*) malloc (n* sizeof(int));
	for(i=0; i<n; i++) {
		v[i] = i;
		}
		return v;
}

int main () 
{
	
	int *v1, v2;
	v1 = cria_vetor (5);
	v2 = cria_vetor (10);
	printf(" %d \n %d", v1, v2);
//.....................................
	free (v1);
	v1= NULL;
	free(v2);
	v2 = NULL;
		printf("\n %d \n %d", v1, v2);
//.......................................
	return 0;
}
