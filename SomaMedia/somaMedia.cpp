#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL,"Portuguese");
    int *vetor;
    int n, i,maior, soma = 0;
    float media;

    // Solicita o tamanho do vetor
    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &n);

    // Aloca memória para n inteiros
    vetor = (int *)malloc(n * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    // Preenchendo o vetor
    printf("Digite %d números:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
        
        if(i == 0)
          maior = vetor[i];
       
	    if(vetor[i] > maior)
          maior = vetor[i]; 			
    }
    media = soma/n;
    // Exibindo os valores armazenados
    printf("Elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("------------------------------------");
    // Exibindo a soma e a média
    printf("\nA Soma dos Valores no vetor é: %d ", soma);
    printf("\nA Média dos Valores no vetor é: %.2f ", media);
    printf("\nO Maior Valor inserido no vetor é: %d ", maior);
	// Liberando a memória alocada
    free(vetor);

    return 0;
}

