#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
	char nome[50];
	int matricula;
	float nota;
	struct Aluno *proximo;
}Aluno;

Aluno* inserir(Aluno *lista){
	Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
	if (novo = NULL) 
	return lista;
	
	printf("Matrícula: ");
	scanf("%d", &novo->matricula);
	printf("Nome: ");
	scanf(" %[^\n]", &novo->nome);
	printf("Nota: ");
	scanf("%float", &novo->nota);
	
	novo->proximo = lista;
	return novo;
}

void listar(Aluno *lista){
	Aluno *atual = lista;
	printf("\n Lista de Alunos \n");
	while (atual != NULL){
		printf("Matrícula: %d / Nome: %s /Nota: %.2f\n", atual->matricula, atual->nome, atual->nota);
		atual = atual->proximo;
	}
}

void buscar(Aluno *lista, int matricula){
	Aluno *atual = lista;
	while (atual != NULL){
		if (atual->matricula == matricula){
			printf("Encontrado: %s (Nota: %.2f)\n", atual->nome, atual->nota);
			return;
		}
		atual = atual->proximo;
	}
	printf("Aluno com a matrícula %d não encontrado.\n", matricula);
}

Aluno* remover(Aluno *lista, int matricula){
	Aluno *atual = lista;
	Aluno *anterior = NULL;
	
	while (atual != NULL &&atual->matricula != matricula){
		anterior = atual;
		atual = atual->proximo;
	}
	
	if (atual == NULL){
		printf("Matrícula não encontrada para remoção.\n");
		return lista;
	}
	if (anterior == NULL){
		lista = atual->proximo;
	}else{
		anterior->proximo = atual->proximo;
	}
	
	free(atual);
	printf("Aluno removido com sucesso!\n");
	return lista;
}

void mostrarMedia(Aluno *lista){
	if (lista == NULL){
		printf("Lista vazia. Media: 0\n");
		return;
	}
	float soma = 0;
	int cont = 0;
	Aluno *atual = lista;
	while (atual != NULL){
		soma += atual->nota;
		cont++;
		atual = atual->proximo;
	}
	printf("Média Geral: %.2f\n", soma / cont);
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	Aluno *lista = NULL;
	int opcao, matricula;
	
	do{
		printf("\n1. Inserir\n2. Remover\n3. Buscar\n4. Listar\n5. Média\n6. Sair\nEscolha: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: lista = inserir(lista); break;
			case 2:
				printf("Matrícula para remover: ");
				scanf("%d", &matricula);
				lista = remover(lista, matricula);
				break;
			case 3:
				printf("Matrícula para buscar: ");
				scanf("%d", &matricula);
				buscar(lista, matricula);
				break;
			case 4: listar(lista); 
				break;
			case 5: mostrarMedia(lista);
				break;
		}
	} while (opcao != 0);
	return 0;
}
