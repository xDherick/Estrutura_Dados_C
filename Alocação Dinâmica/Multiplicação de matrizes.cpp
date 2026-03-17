#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int m1, n1, m2, n2, i, j, k;
    scanf("%d %d %d %d", &m1, &n1, &m2, &n2);

    if (n1 != m2) return 0;

    int **a = (int **)malloc(m1 * sizeof(int *));
    for (i = 0; i < m1; i++) a[i] = (int *)malloc(n1 * sizeof(int));

    int **b = (int **)malloc(m2 * sizeof(int *));
    for (i = 0; i < m2; i++) b[i] = (int *)malloc(n2 * sizeof(int));

    int **c = (int **)calloc(m1, sizeof(int *));
    for (i = 0; i < m1; i++) c[i] = (int *)calloc(n2, sizeof(int));

    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++) scanf("%d", &a[i][j]);

    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++) scanf("%d", &b[i][j]);

    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            for (k = 0; k < n1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
