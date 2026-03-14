#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL,"Portuguese");
    int **matriz;
    int m, n, i, j;

    // Solicita as dimensões da matriz
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &n);

    // Alocando memória para as linhas (vetor de ponteiros)
    matriz = (int **)malloc(m * sizeof(int *));

    // Verifica se a alocação foi bem-sucedida
    if (matriz == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Alocando memória para as colunas de cada linha
    for (i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na alocação de memória!\n");
            return 1;
        }
    }

    // Preenchendo a matriz
    printf("Digite os elementos da matriz (%dx%d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibindo a matriz
    printf("Matriz armazenada:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    for (i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;

    return 0;
}

