#include <stdio.h>
#include <stdlib.h>

int devolve_a_modificado (int *a) {
	int b;
	b = *a * 5;
	return b;

	
}

int main(){

int a = 5 ; 
//printf ("a antes da 1a funcao = %d\n", a);
//muda_int(a);
//prprintf ("a depois da 1a funcao = %d\n", a);
a = devolve_a_modificado(&a);
printf("a depois da funcao = %d\n", a);

return 0;
}

