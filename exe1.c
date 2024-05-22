/* Soma de Elementos em um Array: 
Crie um programa que solicita ao usuário inserir elementos em um array e
calcule a soma desses elementos.*/

#include <stdio.h>
#include <string.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int input[255];
    int soma = 0;
    char sair[2];
    int count = 0;  

    while (1) {
        if (count >= 255) {
            printf("O array está cheio.\n");
            break;
        }
        
        printf("Digite um numero: ");
        scanf("%d", &input[count]);
        clearBuffer();
        count++;

        printf("Deseja fechar o array? s/n ");
        fgets(sair, sizeof(sair), stdin);
        sair[strcspn(sair, "\n")] = '\0';

        if (strcmp(sair, "s") == 0) {
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        soma += input[i];
    }

    printf("A soma dos elementos é: %d\n", soma);

    return 0;
}
