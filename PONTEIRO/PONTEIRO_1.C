#include <stdio.h>
#include <stdlib.h>

int main()

{
	int i, *p;
	i=10;
	
#include <stdio.h>
#include <stdlib.h>

	p=(int*) malloc (sizeof(int));
	*p=15;
	printf("\nendereco de i=%p", &i);
		printf("\nconteudo de i=%d", i);
			printf("\nendereco de p=%p", &p);
				printf("\nconteudo de p=%p", p);
					printf("\nconteudo apontado por p=%d", *p);
	return 0;
}

