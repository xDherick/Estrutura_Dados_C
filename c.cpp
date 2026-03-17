#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

	typedef struct No{
	int valor;
	struct No *prox;
	}No;

int main (){
	setlocale(LC_ALL, "Portuguese");
	printf("olá");
}
