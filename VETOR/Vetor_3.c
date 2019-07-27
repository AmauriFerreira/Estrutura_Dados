#include <stdio.h>

int main () {
	int v[5];
	printf ("posicao 0 = %p\n", v+0);
	printf ("posicao 1 = %p\n", v+1);
	printf ("posicao 2 = %p\n", v+2);
	printf ("posicao 3 = %p\n", v+3);
	printf ("posicao 4 = %p\n", v+4);
	return 0;
}
