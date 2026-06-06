#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main () {
    char opcao_str[10];
    int opcao;
    double num1, num2; 
    double resultado;
    char continuar_str[10];

    do {
        limparTela();

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
            scanf("%s", opcao_str);
            if (strlen(opcao_str) == 1 && opcao_str[0] >= '1' && opcao_str[0] <= '5') {
                opcao = opcao_str[0] - '0'; 
                break;
            } else {
                printf("Entrada invalida. Por favor, digite um numero inteiro entre 1 e 5.\n");
                printf("Opcao: ");
            }
        }

        if (opcao == 5) {
            break; 
        }

        printf("Digite o primeiro numero: ");
        while (scanf("%lf", &num1) != 1) {
            printf("Numero invalido. Digite novamente: ");
            while (getchar() != '\n'); 
        }
        
        printf("Digite o segundo numero: ");
        while (scanf("%lf", &num2) != 1) {
            printf("Numero invalido. Digite novamente: ");
            while (getchar() != '\n');
        }

        // ALTERADO: Mudado para %.2lf para forcar a exibicao de numeros decimais (ex: 2.50)
        switch (opcao) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 2:
                resultado = num1 - num2;
                printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("Resultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2; // Como num1 e num2 sao double, a divisao obrigatoriamente gera decimais
                    printf("Resultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero nao e permitida.\n");
                }
                break;
        }

        while (1) {
            printf("Deseja realizar outra operacao? (s/n): ");
            scanf("%s", continuar_str); 

            continuar_str[0] = tolower(continuar_str[0]);

            if (strlen(continuar_str) == 1 && (continuar_str[0] == 's' || continuar_str[0] == 'n')) {
                break;
            }
            printf("Resposta invalida! Digite apenas 's' ou 'n'.\n");
        }

    } while (continuar_str[0] == 's'); 

    printf("Obrigado por usar a calculadora! Ate a proxima.\n");
    return 0;
}
