#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    int **mat = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) mat[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) scanf("%d", &mat[i][j]);
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }

    for (i = 0; i < m; i++) free(mat[i]);
    free(mat);
    return 0;
}
