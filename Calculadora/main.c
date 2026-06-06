#include <stdio.h>
#include <stdlib.h>

void limparTela() {
    #ifdef _WIN32
        system("cls"); // Limpa o terminal no Windows
    #else
        system("clear"); // Limpa o terminal no Linux e macOS
    #endif
}

int main () {
    int opcao;
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");

    while (1) {
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Por favor, digite um número entre 1 e 5.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            printf("Opção: ");
        } else {
            break;
        }
    }

    if (opcao >= 1 && opcao <= 4) {
        int num1, num2;
        printf("Digite o primeiro número: ");
        scanf("%d", &num1);
        printf("Digite o segundo número: ");
        scanf("%d", &num2);

        float resultado;

        switch (opcao) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %i + %i = %i\n", num1, num2, (int)resultado);
                break;
            case 2:
                resultado = num1 - num2;
                printf("Resultado: %i - %i = %i\n", num1, num2, (int)resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("Resultado: %i * %i= %i\n", num1, num2, (int)resultado);
                break;
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %d / %d = %.2f\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisão por zero não é permitida.\n");
                }
                break;
        }
    } else if (opcao == 5) {
        printf("Obrigado por usar a calculadora! Até a próxima.\n");
        return 0;
    }
    char continuar[10];
    printf("Deseja realizar outra operacao? (s/n): ");
        scanf("%s", continuar); 
    while (continuar[0] == 's' || continuar[0] == 'S'); 

    printf("Obrigado por usar a calculadora! Ate a proxima.\n");
    return 0;
}