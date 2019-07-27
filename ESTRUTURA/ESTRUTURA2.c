#include <stdio.h>
#include <stdlib.h>
struct aluno {
	int idade;
	char *nome;
};
int main () {
	struct aluno aluno1, aluno2;
	struct aluno *ptr_aluno;
	aluno1.idade = 21;
	aluno1.nome = "Bia";
	printf ("Nome = %s\nidade = %d\n", aluno1.nome, aluno1.idade);
	
	aluno2 = aluno1;
	printf ("Nome = %s\nidade = %d\n", aluno2.nome, aluno2.idade);
	
	ptr_aluno = (struct aluno *) malloc (sizeof(struct aluno));
	ptr_aluno->nome = "Gil";
	ptr_aluno->idade = 17;
	printf ("Nome = %s\nidade = %d\n", ptr_aluno->nome, ptr_aluno->idade);
		
	return 0;
}

