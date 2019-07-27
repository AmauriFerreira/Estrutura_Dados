#include <stdio.h>
#include <stdlib.h>

struct aluno {
	
	int idade;
	char *nome ;
};

int main () {
	struct aluno aluno1;
	aluno1.idade =21;
	aluno1.nome = "Bia";
	printf ("Nome = %s\nidade = %d",aluno1.nome,aluno1.idade);
	
	return 0;
}
