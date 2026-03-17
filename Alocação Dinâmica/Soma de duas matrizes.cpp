#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    int **a = (int **)malloc(m * sizeof(int *));
    int **b = (int **)malloc(m * sizeof(int *));
    int **c = (int **)malloc(m * sizeof(int *));

    for (i = 0; i < m; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            scanf("%d", &b[i][j]);
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf("%d ", c[i][j]);
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        free(a[i]); free(b[i]); free(c[i]);
    }
    free(a); free(b); free(c);
    return 0;
}
