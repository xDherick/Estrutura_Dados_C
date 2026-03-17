#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int m, n, i, j, busca, achou = 0;
    scanf("%d %d", &m, &n);

    int **mat = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) mat[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) scanf("%d", &mat[i][j]);

    scanf("%d", &busca);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] == busca) {
                printf("Posição: [%d][%d]\n", i, j);
                achou = 1;
            }
        }
    }
    if (!achou) printf("Não encontrado");

    return 0;
}
