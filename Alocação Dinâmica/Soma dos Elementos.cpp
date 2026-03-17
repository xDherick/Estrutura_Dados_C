#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, i, soma = 0;
    printf("Tamanho: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        soma += v[i];
    }

    printf("Soma: %d", soma);
    free(v);
    return 0;
}
