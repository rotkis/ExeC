/*Cálculo de Estatísticas em um Array:
Escreva um programa que recebe um array de números e calcula a média,
mediana e moda dos elementos.*/

#include <stdio.h>
#include <stdlib.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double calcularMedia(int* array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return (double)soma / tamanho;
}

double calcularMediana(int* array, int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);
    if (tamanho % 2 == 0) {
        return (array[tamanho/2 - 1] + array[tamanho/2]) / 2.0;
    } else {
        return array[tamanho/2];
    }
}

int calcularModa(int* array, int tamanho) {
    int moda = array[0];
    int maxCount = 0;
    int count = 1;
    
    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i-1]) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                moda = array[i-1];
            }
            count = 1;
        }
    }
    if (count > maxCount) {
        maxCount = count;
        moda = array[tamanho - 1];
    }
    return moda;
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

    int* array = (int*)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        array[i] = valores[i];
    }

    double media = calcularMedia(array, tamanho);
    double mediana = calcularMediana(array, tamanho);
    int moda = calcularModa(array, tamanho);

    printf("Média: %.2lf\n", media);
    printf("Mediana: %.2lf\n", mediana);
    printf("Moda: %d\n", moda);

    free(array);
    return 0;
}
