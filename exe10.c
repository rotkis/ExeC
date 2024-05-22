/*Manipulação de Tempo:
Utilize a biblioteca time.h para calcular o tempo que um determinado
trecho de código leva para ser executado.*/

#include <stdio.h>
#include <time.h>

void tarefaPesada() {
    // Exemplo de uma tarefa que consome tempo, como uma operação intensiva de cálculo
    for (long long i = 0; i < 1000000000; i++) {
        // Apenas um loop para simular trabalho pesado
    }
}

int main() {
    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();  // Captura o tempo inicial

    tarefaPesada();  // Trecho de código que você quer medir

    fim = clock();  // Captura o tempo final

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %f segundos\n", tempo_gasto);

    return 0;
}
