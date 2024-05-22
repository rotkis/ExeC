/*Operações Matriciais:
Implemente funções para multiplicação de matrizes e transposição.
Utilize ponteiros para alocar dinamicamente o espaço de memória.*/

#include <stdio.h>
#include <stdlib.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
    int rows;
    int cols;
    int **data;
} Matriz;

Matriz* alocarMatriz(int rows, int cols) {
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
    matriz->rows = rows;
    matriz->cols = cols;
    matriz->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matriz->data[i] = (int*)malloc(cols * sizeof(int));
    }
    return matriz;
}

Matriz* multiplicarMatrizes(Matriz* A, Matriz* B) {
    if (A->cols != B->rows) {
        printf("As matrizes não podem ser multiplicadas.\n");
        return NULL;
    }

    Matriz* resultado = alocarMatriz(A->rows, B->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            resultado->data[i][j] = 0;
            for (int k = 0; k < A->cols; k++) {
                resultado->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
    return resultado;
}

Matriz* transporMatriz(Matriz* matriz) {
    Matriz* transposta = alocarMatriz(matriz->cols, matriz->rows);
    for (int i = 0; i < matriz->rows; i++) {
        for (int j = 0; j < matriz->cols; j++) {
            transposta->data[j][i] = matriz->data[i][j];
        }
    }
    return transposta;
}

void liberarMatriz(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        free(matriz->data[i]);
    }
    free(matriz->data);
    free(matriz);
}

void imprimirMatriz(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        for (int j = 0; j < matriz->cols; j++) {
            printf("%d ", matriz->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linha_a, coluna_a, linha_b, coluna_b;
    printf("Digite o número de linhas e colunas da matriz A: ");
    scanf("%d %d", &linha_a, &coluna_a);
    printf("Digite o número de linhas e colunas da matriz B: ");
    scanf("%d %d", &linha_b, &coluna_b);

    Matriz* A = alocarMatriz(linha_a, coluna_a);
    Matriz* B = alocarMatriz(linha_b, coluna_b);

    if (coluna_a == linha_b) {
        printf("Digite os valores da matriz A:\n");
        for (int i = 0; i < linha_a; i++) {
            for (int j = 0; j < coluna_a; j++) {
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &A->data[i][j]);
            }
        }

        printf("Digite os valores da matriz B:\n");
        for (int i = 0; i < linha_b; i++) {
            for (int j = 0; j < coluna_b; j++) {
                printf("B[%d][%d]: ", i, j);
                scanf("%d", &B->data[i][j]);
            }
        }

        printf("Matriz A:\n");
        imprimirMatriz(A);
        printf("Matriz B:\n");
        imprimirMatriz(B);

        Matriz* C = multiplicarMatrizes(A, B);
        if (C != NULL) {
            printf("Produto de A e B:\n");
            imprimirMatriz(C);
            Matriz* Ct = transporMatriz(C);
        printf("Transposta de C:\n");
        imprimirMatriz(Ct);
        liberarMatriz(Ct);
        liberarMatriz(C);
        }

        Matriz* At = transporMatriz(A);
        printf("Transposta de A:\n");
        imprimirMatriz(At);
        liberarMatriz(At);
        Matriz* Bt = transporMatriz(B);
        printf("Transposta de B:\n");
        imprimirMatriz(At);
        liberarMatriz(At);
    } else {
        printf("Não é possível fazer a multiplicação das matrizes.\n");
    }

    liberarMatriz(A);
    liberarMatriz(B);

    return 0;
}
