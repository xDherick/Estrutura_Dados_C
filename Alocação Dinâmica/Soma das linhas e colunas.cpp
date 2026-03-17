#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    int **mat = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) mat[i] = (int *)malloc(n * sizeof(int));

    int *sl = (int *)calloc(m, sizeof(int));
    int *sc = (int *)calloc(n, sizeof(int));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            sl[i] += mat[i][j];
            sc[j] += mat[i][j];
        }
    }

    for (i = 0; i < m; i++) printf("Linha %d: %d\n", i, sl[i]);
    for (j = 0; j < n; j++) printf("Coluna %d: %d\n", j, sc[j]);

    return 0;
}
