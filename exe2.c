/*Manipulação de Strings:
Desenvolva um programa que recebe uma string do usuário e conta o número de vogais nela.*/

#include <stdio.h>
#include <string.h>

int main(){
    char string[255];
    int cont =0;
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] == '\0';
    for (int i=0; i < sizeof(string); i++){
        if (string[i] == 'a' || string[i] == 'i' || string[i] == 'u'|| string[i] == 'e'|| string[i] == 'o' || string[i] == 'A' || string[i] == 'I' || string[i] == 'U'|| string[i] == 'E'|| string[i] == 'O'){
            printf("%c ", string[i]);
            cont++;
        }
    }
    printf("\nA soma das vogais é: %d\n", cont);
}