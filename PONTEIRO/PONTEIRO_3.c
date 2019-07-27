#include <stdio.h>
#include <stdlib.h>

void muda_int (int *a) {
	*a = *a * 100;
	
}

int main()
{

int a = 5 ; 
printf ("a antes da funcao = %d", a);
muda_int (&a);
printf ("\na depois da funcao = %d", a);
return 0;
}
