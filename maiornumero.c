/*

1. Introduzir 2 números e imprimirem o maior.

*/

#include <stdio.h>

int main() {
    int num1, num2;

    // Solicita dois números ao usuário
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    // Verifica qual número é o maior e imprime o resultado
    if (num1 > num2) {
        printf("O maior numero e: %d\n", num1);
    } else if (num2 > num1) {
        printf("O maior numero e: %d\n", num2);
    } else {
        printf("Os dois numeros sao iguais.\n");
    }

    return 0;
}




