#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void inverter(int *v, int n) {
    int i, temp;
    for (i = 0; i < n / 2; i++) {
        temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, i;
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &v[i]);

    inverter(v, n);

    for (i = 0; i < n; i++) printf("%d ", v[i]);
    free(v);
    return 0;
}
