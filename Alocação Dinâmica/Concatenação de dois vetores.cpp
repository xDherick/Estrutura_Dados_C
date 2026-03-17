#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n1, n2, i;
    scanf("%d %d", &n1, &n2);
    int *v1 = (int *)malloc(n1 * sizeof(int));
    int *v2 = (int *)malloc(n2 * sizeof(int));
    int *v3 = (int *)malloc((n1 + n2) * sizeof(int));

    for (i = 0; i < n1; i++) {
        scanf("%d", &v1[i]);
        v3[i] = v1[i];
    }
    for (i = 0; i < n2; i++) {
        scanf("%d", &v2[i]);
        v3[n1 + i] = v2[i];
    }

    for (i = 0; i < n1 + n2; i++) printf("%d ", v3[i]);

    free(v1); free(v2); free(v3);
    return 0;
}
