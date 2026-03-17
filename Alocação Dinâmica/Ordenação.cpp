#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, i, j, temp;
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &v[i]);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) printf("%d ", v[i]);
    free(v);
    return 0;
}
