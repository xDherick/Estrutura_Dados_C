#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL,"Portuguese");
    int **matriz;
    int m, n, novo_m, novo_n, i, j;

    // Solicita as dimensões iniciais da matriz
    printf("Digite o número inicial de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite o número inicial de colunas da matriz: ");
    scanf("%d", &n);

    // Aloca memória para as linhas
    matriz = (int **)malloc(m * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Aloca memória para as colunas de cada linha
    for (i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na alocação de memória!\n");
            return 1;
        }
    }

    // Preenchendo a matriz inicial
    printf("Digite os elementos da matriz (%dx%d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibindo a matriz antes da realocação
    printf("Matriz antes da realocação:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Solicita novas dimensões para a matriz
    printf("Digite o novo número de linhas: ");
    scanf("%d", &novo_m);
    printf("Digite o novo número de colunas: ");
    scanf("%d", &novo_n);

    // Realoca memória para as novas linhas
    matriz = (int **)realloc(matriz, novo_m * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na realocação de memória!\n");
        return 1;
    }

    // Realoca memória para cada linha existente e adiciona novas linhas, se necessário
    for (i = 0; i < novo_m; i++) {
        matriz[i] = (int *)realloc(matriz[i], novo_n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na realocação de memória!\n");
            return 1;
        }
    }

    // Preenchendo os novos elementos caso a matriz tenha crescido
    if (novo_m > m || novo_n > n ) {
        printf("Digite os novos elementos:\n");
        for (i = m; i < novo_m; i++) {
            for (j = 0; j < novo_n; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        for (i = 0; i < m; i++) {
            for (j = n; j < novo_n; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
    }

    // Exibindo a matriz após a realocação
    printf("Matriz após a realocação:\n");
    for (i = 0; i < novo_m; i++) {
        for (j = 0; j < novo_n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    for (i = 0; i < novo_m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

