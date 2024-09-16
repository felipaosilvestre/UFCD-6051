#include <stdio.h>

int main() {
    char resposta;
    int opcao;

    do {
        // Exibir menu de opções
        printf("Escolha a operação desejada:\n");
        printf("1 - Soma\n");
        printf("2 - Subtração\n");
        printf("3 - Multiplicação\n");
        printf("4 - Divisão\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &opcao);

        // Introduza os números
        float x = 0.0f;
        float y = 0.0f;

        printf("Introduza o 1º número: ");
        scanf("%f", &x);

        printf("Introduza o 2º número: ");
        scanf("%f", &y);

        float resultado = 0.0f;

        // Executar a operação com base na opção escolhida
        switch (opcao) {
            case 1:
                resultado = x + y;
                printf("Soma: %f\n", resultado);
                break;
            case 2:
                resultado = x - y;
                printf("Subtração: %f\n", resultado);
                break;
            case 3:
                resultado = x * y;
                printf("Multiplicação: %f\n", resultado);
                break;
            case 4:
                if (y != 0.0f) {
                    resultado = x / y;
                    printf("Divisão: %f\n", resultado);
                } else {
                    printf("Divisão por zero não é permitida.\n");
                }
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

        // Perguntar se deseja utilizar a calculadora novamente
        printf("Deseja utilizar a calculadora novamente? (s/n): ");
        scanf(" %c", &resposta);  // Adiciona um espaço antes do %c para consumir o caractere de nova linha anterior
        getchar();  // Consumir o caractere de nova linha deixado pelo scanf

    } while (resposta == 's' || resposta == 'S');

    printf("Obrigado por usar a calculadora. Até a próxima!\n");
    return 0;
}
