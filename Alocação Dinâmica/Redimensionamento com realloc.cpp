#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, m, i;
    printf("Tamanho inicial: ");
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) scanf("%d", &v[i]);

    printf("Novo tamanho: ");
    scanf("%d", &m);
    v = (int *)realloc(v, m * sizeof(int));

    if (m > n) {
        for (i = n; i < m; i++) scanf("%d", &v[i]);
    }

    for (i = 0; i < m; i++) printf("%d ", v[i]);

    free(v);
    return 0;
}
