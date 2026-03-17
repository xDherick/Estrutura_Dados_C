#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, i, maior, menor;
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (i == 0) {
            maior = menor = v[i];
        } else {
            if (v[i] > maior) maior = v[i];
            if (v[i] < menor) menor = v[i];
        }
    }

    printf("Maior: %d\nMenor: %d", maior, menor);
    free(v);
    return 0;
}
