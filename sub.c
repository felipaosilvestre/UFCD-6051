#include <stdio.h>

int main() {
    int number1 = 0;
    int number2 = 0;

    // Solicita ao usuário que insira os dois números
    printf("Introduza o 1 numero: ");
    scanf("%d", &number1);

    printf("Introduza o 2 numero: ");
    scanf("%d", &number2);

    // Realiza a subtração
    int subtracao = number1 - number2;

    // Exibe o resultado da subtração
    printf("Subtracao: %d\n", subtracao);

    return 0;
}