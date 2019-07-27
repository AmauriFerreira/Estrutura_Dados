#include <stdio.h>
#include <stdlib.h>

void mostra_vetor(int v [],int n, char *msg ) 
{
int i;
printf ("\n%s\n",msg);
for (i=0;i<n;i++){
	printf ("%d ",v[i]);
	
}
printf("\n");
}
	
int main(){

int v1[5], v2[10], i;
for(i=0;i<5; i++) {
	v1[i]=i+1;
}

mostra_vetor (v1, 5, " vetor 1");

for(i=0; i<10; i++) {
	v2[i]=i+3;
	
}
mostra_vetor (v2, 10, "vetor 2");

return 0;
}

