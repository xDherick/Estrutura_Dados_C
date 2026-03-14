#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserir(int lista[], int *tamanho, int valor, int posicao) {
    if (*tamanho >= 20) {
        printf("Lista cheia!\n");
        return;
    }
    if (posicao < 0 || posicao > *tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    
    for (int i = *tamanho; i > posicao; i--) {
        lista[i] = lista[i - 1];
    }
    lista[posicao] = valor;
    (*tamanho)++;
}

void remover(int lista[], int *tamanho, int posicao) {
    if (*tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }
    if (posicao < 0 || posicao >= *tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = posicao; i < *tamanho - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*tamanho)--;
}
void imprimirSequencial(int lista[], int tamanho) {
    printf("Lista: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("]\n");
}

No* inserirInicio(No *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) { 
        printf("Erro de alocação!\n");
        return lista;
    }
    novo->valor = valor;
    novo->prox = lista;
    
    return novo;
}

No* inserirFinal(No *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) { 
        printf("Erro de alocação!\n");
        return lista;
    }
    novo->valor = valor;
    novo->prox = NULL;
    
    if (lista == NULL) { 
        return novo;
    }
    
    No *aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    
    aux->prox = novo;
    return lista;
}

No* removerValor(No *lista, int valor) {
    if (lista == NULL) { 
        printf("Lista vazia!\n");
        return NULL;
    }
    No *aux = lista;
    No *anterior = NULL;
    
    while (aux != NULL && aux->valor != valor) { 
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == NULL) { 
        printf("Elemento não encontrado!\n");
        return lista;
    }
    if (anterior == NULL) { 
        lista = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }
    
    free(aux);
    
    return lista;
}

void imprimirEncadeada(No *lista) {
    printf("Lista: [ ");
    No *aux = lista;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("]\n");
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    
    printf("PARTE 1: LISTA SEQUENCIAL\n");
    int listaSeq[20];
    int tamanhoSeq = 0;
    
    inserir(listaSeq, &tamanhoSeq, 10, 0);
    inserir(listaSeq, &tamanhoSeq, 30, 1); 
    inserir(listaSeq, &tamanhoSeq, 20, 1); 
    imprimirSequencial(listaSeq, tamanhoSeq);
    
    printf("\nRemovendo o elemento da posicao 1 (o numero 20)\n");
    remover(listaSeq, &tamanhoSeq, 1);
    imprimirSequencial(listaSeq, tamanhoSeq);

    printf("PARTE 2: LISTA ENCADEADA\n");
    No *listaEnc = NULL; 
    
    listaEnc = inserirInicio(listaEnc, 50); 
    listaEnc = inserirInicio(listaEnc, 40); 
    listaEnc = inserirFinal(listaEnc, 60); 
    listaEnc = inserirFinal(listaEnc, 70); 
    imprimirEncadeada(listaEnc);
    
    printf("\nRemovendo o valor 60\n");
    listaEnc = removerValor(listaEnc, 60);
    imprimirEncadeada(listaEnc);
    
    printf("\nRemovendo o valor 40 (primeiro da lista)\n");
    listaEnc = removerValor(listaEnc, 40);
    imprimirEncadeada(listaEnc);
    
}
