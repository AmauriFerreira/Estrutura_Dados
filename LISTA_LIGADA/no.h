#include <stdlib.h>

struct no {
	int info;
	struct no * proximo;
};

struct no * cria_no (int);

