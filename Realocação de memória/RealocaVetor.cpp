#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL,"Portuguese");
    int *vetor;
    int n, novo_n, i;

    // Solicita o tamanho inicial do vetor
    printf("Digite o número inicial de elementos do vetor: ");
    scanf("%d", &n);

    // Aloca memória para n inteiros
    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Preenchendo o vetor inicial
    printf("Digite %d números:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Exibindo o vetor antes da realocação
    printf("Vetor antes da realocação:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Solicita um novo tamanho
    printf("Digite o novo tamanho do vetor: ");
    scanf("%d", &novo_n);

    // Realoca o vetor
    vetor = (int *)realloc(vetor, novo_n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro na realocação de memória!\n");
        return 1;
    }

    // Se o novo tamanho for maior, preenche os novos elementos
    if (novo_n > n) {
        printf("Digite os novos %d elementos:\n", novo_n - n);
        for (i = n; i < novo_n; i++) {
            scanf("%d", &vetor[i]);
        }
    }

    // Exibindo o vetor após a realocação
    printf("Vetor após a realocação:\n");
    for (i = 0; i < novo_n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberando a memória alocada
    free(vetor);

    return 0;
}


