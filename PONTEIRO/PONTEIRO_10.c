#include <stdio.h>
#include <stdlib.h>

void muda_int (int a) {
	a = a * 10;
	
}	

void muda_mesmo (int *a) {
	*a = *a * 100;
	
}

int devolve_a_modificado (int *a) {
	*a = *a * 2;

}


int main(){

int a = 5 ; 
printf ("a antes da 1a funcao = %d\n", a);
muda_int(a);
printf ("a depois da 1a funcao = %d\n", a);
muda_mesmo (&a);
printf ("a depois da 1a funcao = %d\n", a);
a = devolve_a_modificado(&a);
printf("a depois da funcao = %d\n", a);

return 0;
}


