/*Manipulação de Ponteiros em String:
Implemente uma função que recebe uma string como entrada e retorna a mesma string,
mas com todas as letras convertidas para maiúsculas.
Use ponteiros para percorrer a string.*/

#include <stdio.h>
#include <string.h>

void letramaiscula(char *mudar) {
    while (*mudar) {
        if (*mudar >= 'a' && *mudar <= 'z') {
            *mudar = *mudar - 32;
        }
        mudar++;
    }
}

int main(){
    char string[255];
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    letramaiscula(string);
    printf("String em maiúsculas: %s\n", string);

    return 0;
}