# include <stdio.h>
# include <stdlib.h>
# include <time.h>


int main () {
	
	int m, n; 
	srand(time (NULL));
	m = rand();
	n = rand();
	printf ("\nm = %d\n n= %d ", m ,n);
	
	return 0;
}
