#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &v[i]);
    }

    printf("Elementos: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}
