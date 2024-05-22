/*Manipulação de Ponteiros:
Implemente uma função que recebe um array e seu tamanho como argumentos
e retorna um novo array invertido, utilizando ponteiros.*/

#include <stdio.h>
#include <stdlib.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int* inverterArray(int* array, int tamanho) {
    int* invertido = (int*)malloc(tamanho * sizeof(int));
    if (invertido == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    for (int i = 0; i < tamanho; i++) {
        invertido[i] = array[tamanho - 1 - i];
    }
    return invertido;
}

int main() {
    int valores[255];
    int tamanho = 0;

    printf("Insira valores no array (digite -1 para terminar):\n");
    while (1) {
        int valor;
        printf("Valor %d: ", tamanho + 1);
        scanf("%d", &valor);
        if (valor == -1) {
            break;
        }
        valores[tamanho] = valor;
        tamanho++;
    }

    int* invertido = inverterArray(valores, tamanho);

    printf("Array invertido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", invertido[i]);
    }
    printf("\n");

    free(invertido);

    return 0;
}
