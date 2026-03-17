#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int l, c, v;
} Elemento;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int m, n, i, j, valor, k = 0;
    scanf("%d %d", &m, &n);
    Elemento *e = NULL;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &valor);
            if (valor != 0) {
                e = (Elemento *)realloc(e, (k + 1) * sizeof(Elemento));
                e[k].l = i; e[k].c = j; e[k].v = valor;
                k++;
            }
        }
    }

    for (i = 0; i < k; i++) printf("[%d][%d] = %d\n", e[i].l, e[i].c, e[i].v);

    free(e);
    return 0;
}
