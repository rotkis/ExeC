/*Cadastro de Produtos usando Struct:
Crie uma estrutura de dados chamada "Produto" que armazena nome, preço e quantidade em estoque.
Permita ao usuário cadastrar produtos, exibir as informações e
calcular o valor total em estoque (preço * quantidade).*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[255];
    double preco;
    double quantidade;
} Produto;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Produto produtos[255];
    int i = 0;
    char sair[2];
    double valor_total = 0;
    double valor = 0;

    while (1) {
        printf("Digite o nome do produto: ");
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
        
        printf("Digite o preço do produto: ");
        scanf("%lf", &produtos[i].preco);
        clearBuffer();
        
        printf("Digite a quantidade do produto: ");
        scanf("%lf", &produtos[i].quantidade);
        clearBuffer();
        
        i++;
        
        printf("Terminou o cadastro de produto? s/n ");
        fgets(sair, sizeof(sair), stdin);
        sair[strcspn(sair, "\n")] = '\0';
        clearBuffer();
        if (strcmp(sair, "s") == 0) {
            break;
        }
    }

    printf("Lista dos produtos cadastrados:\n");
    for (int j = 0; j < i; j++) {
        printf("Nome: %s\nPreço: %.2lf\nQuantidade: %.2lf\n", produtos[j].nome, produtos[j].preco, produtos[j].quantidade);
        valor = produtos[j].preco * produtos[j].quantidade;
        printf("Valor total desse produto: %.2lf\n", valor);
        valor_total += valor;
    }

    printf("Valor total de todos os produtos: %.2lf\n", valor_total);

    return 0;
}
