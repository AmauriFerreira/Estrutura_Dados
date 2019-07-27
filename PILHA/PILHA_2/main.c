#include <stdio.h>
#include <stdlib.h>

double fat (int n){
	if (n==1 || n==0)
		return 1;
	return n* fat(n-1);
}

int fib (int n){
	if (n==1 || n==0)
		return 1;
	return fib(n-1)+ fib(n-2);
}

int main() {
	int i;
	for(i=0; i<=45; i++)
		printf("\nfatorial de %d = %d",i, fib(i));
	return 0;
}
