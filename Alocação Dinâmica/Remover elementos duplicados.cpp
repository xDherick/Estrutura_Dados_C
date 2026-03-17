#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, i, j, k = 0, repetido;
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    int *u = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        repetido = 0;
        for (j = 0; j < k; j++) {
            if (v[i] == u[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            u[k] = v[i];
            k++;
        }
    }

    for (i = 0; i < k; i++) printf("%d ", u[i]);

    free(v);
    free(u);
    return 0;
}
