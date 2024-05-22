/*Ordenação de Structs:
Crie um programa que ordena um array de structs com base em um dos campos 
(por exemplo, idade) usando qsort da biblioteca glibc.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[255];
    int idade;
    double salario;
} Funcionario;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int compararIdade(const void *a, const void *b) {
    Funcionario *func1 = (Funcionario *)a;
    Funcionario *func2 = (Funcionario *)b;
    return (func1->idade - func2->idade);
}

int main() {
    int n;

    printf("Digite o número de funcionários: ");
    scanf("%d", &n);
    clearBuffer();

    Funcionario *funcionarios = (Funcionario *)malloc(n * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o nome do funcionário %d: ", i + 1);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';

        printf("Digite a idade do funcionário %d: ", i + 1);
        scanf("%d", &funcionarios[i].idade);
        clearBuffer();

        printf("Digite o salário do funcionário %d: ", i + 1);
        scanf("%lf", &funcionarios[i].salario);
        clearBuffer();
    }

    qsort(funcionarios, n, sizeof(Funcionario), compararIdade);

    printf("\nFuncionários ordenados por idade:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n",
               funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }

    free(funcionarios);

    return 0;
}
