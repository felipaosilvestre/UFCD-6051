// imprimir um menu

#include <stdio.h>

int main()
{
    int opcao;

    do {
        // Exibe o menu de opções
        printf("\n--- Menu ---\n");
        printf("1 - Visualizar cronograma\n");
        printf("2 - Marcar ocupacoes\n");
        printf("3 - Atividade de manutencao\n");
        printf("4 - Mediacao\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) 
        {
            case 1:
                printf("Visualizando cronograma...\n");
                break;
            case 2:
                printf("Marcando ocupacoes...\n");
                break;
            case 3:
                printf("Atividade de manutencao em andamento...\n");
                break;
            case 4:
                printf("Mediacao iniciada...\n");
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while(opcao != 5); 

    int main()
    {

        exibirMenu();
        
    }

    return 0;
}