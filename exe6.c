#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
    char nome[255];
    int idade;
    double salario;
} Registro;

void criarArquivo() {
    FILE *f = fopen("arquivo.bin", "ab");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Registro registro;
    printf("Digite o nome do funcionário: ");
    fgets(registro.nome, sizeof(registro.nome), stdin);
    registro.nome[strcspn(registro.nome, "\n")] = '\0';

    printf("Digite a idade do funcionário: ");
    scanf("%d", &registro.idade);
    clearBuffer();

    printf("Digite o salário do funcionário: ");
    scanf("%lf", &registro.salario);
    clearBuffer();

    fwrite(&registro, sizeof(Registro), 1, f);
    fclose(f);

    printf("Registro adicionado com sucesso!\n");
}

void listarArquivo() {
    FILE *f = fopen("arquivo.bin", "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Registro registro;
    while (fread(&registro, sizeof(Registro), 1, f) == 1) {
        printf("Nome: %s\n", registro.nome);
        printf("Idade: %d\n", registro.idade);
        printf("Salário: %.2lf\n", registro.salario);
        printf("--------------------------\n");
    }

    fclose(f);
}

void buscarRegistroPorNome() {
    char nome[255];
    printf("Digite o nome do funcionário para buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    FILE *f = fopen("arquivo.bin", "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Registro registro;
    int encontrado = 0;
    while (fread(&registro, sizeof(Registro), 1, f) == 1) {
        if (strcmp(registro.nome, nome) == 0) {
            printf("Nome: %s\n", registro.nome);
            printf("Idade: %d\n", registro.idade);
            printf("Salário: %.2lf\n", registro.salario);
            printf("--------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Registro não encontrado.\n");
    }

    fclose(f);
}

int main() {
    int opcao;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1 - Listar todos os registros\n");
        printf("2 - Adicionar novo registro\n");
        printf("3 - Buscar registro por nome\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        clearBuffer();

        switch (opcao) {
            case 1:
                listarArquivo();
                break;
            case 2:
                criarArquivo();
                break;
            case 3:
                buscarRegistroPorNome();
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
