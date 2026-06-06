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
    char continuar[10]; // Declarada aqui no início para ser usada no critério do do-while

    do {
        limparTela(); // CHAMADA AQUI: Limpa a tela toda vez que o menu reinicia

        printf("===============================\n");
        printf("   Calculadora Simples\n");
        printf("===============================\n");
        printf("Selecione uma operacao:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair\n");
        printf("Opcao: ");

        while (1) {
            if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 5) { // Ajustado para pegar números inválidos (ex: 8)
                printf("Entrada invalida. Por favor, digite um numero entre 1 e 5.\n");
                while (getchar() != '\n'); // Limpa o buffer de entrada
                printf("Opcao: ");
            } else {
                break;
            }
        }

        if (opcao == 5) {
            break; // Sai do do-while imediatamente e vai para a mensagem de despedida
        }

        int num1, num2;
        printf("Digite o primeiro numero: ");
        scanf("%d", &num1);
        printf("Digite o segundo numero: ");
        scanf("%d", &num2);

        float resultado;

        switch (opcao) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %d + %d = %d\n", num1, num2, (int)resultado);
                break;
            case 2:
                resultado = num1 - num2;
                printf("Resultado: %d - %d = %d\n", num1, num2, (int)resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("Resultado: %d * %d = %d\n", num1, num2, (int)resultado);
                break;
            case 4:
                if (num2 != 0) {
                    resultado = (float)num1 / num2; // Garante que a divisão não perca os decimais antes de truncar
                    printf("Resultado: %d / %d = %d\n", num1, num2, (int)resultado);
                } else {
                    printf("Erro: Divisao por zero nao e permitida.\n");
                }
                break;
        }

        printf("Deseja realizar outra operacao? (s/n): ");
        scanf("%s", continuar); 

    } while (continuar[0] == 's' || continuar[0] == 'S'); // CORRIGIDO: O bloco fecha aqui e repete o DO

    printf("Obrigado por usar a calculadora! Ate a proxima.\n");
    return 0;
}