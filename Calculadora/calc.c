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
    double num1, num2; // Alterado para double para aceitar decimais e inteiros
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

        // Loop de validação estrita da opção inicial (rejeita 1.5, letras, etc.)
        while (1) {
            scanf("%s", opcao_str);
            
            // Verifica se a string digitada tem exatamente 1 caractere e se é um número entre '1' e '5'
            if (strlen(opcao_str) == 1 && opcao_str[0] >= '1' && opcao_str[0] <= '5') {
                opcao = opcao_str[0] - '0'; // Converte o caractere para o número inteiro correspondente
                break;
            } else {
                printf("Entrada invalida. Por favor, digite um numero inteiro entre 1 e 5.\n");
                printf("Opcao: ");
            }
        }

        if (opcao == 5) {
            break; 
        }

        // Leitura dos números aceitando decimais (ex: 4.5 ou 7)
        printf("Digite o primeiro numero: ");
        while (scanf("%lf", &num1) != 1) {
            printf("Numero invalida. Digite novamente: ");
            while (getchar() != '\n'); // Limpa buffer em caso de letras
        }
        
        printf("Digite o segundo numero: ");
        while (scanf("%lf", &num2) != 1) {
            printf("Numero invalida. Digite novamente: ");
            while (getchar() != '\n');
        }

        switch (opcao) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %.2lf + %.2lf = %d\n", num1, num2, (int)resultado); // Resultado sempre inteiro
                break;
            case 2:
                resultado = num1 - num2;
                printf("Resultado: %.2lf - %.2lf = %d\n", num1, num2, (int)resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("Resultado: %.2lf * %.2lf = %d\n", num1, num2, (int)resultado);
                break;
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf / %.2lf = %d\n", num1, num2, (int)resultado);
                } else {
                    printf("Erro: Divisao por zero nao e permitida.\n");
                }
                break;
        }

        // Loop de validação estrita para a pergunta de continuar
        while (1) {
            printf("Deseja realizar outra operacao? (s/n): ");
            scanf("%s", continuar_str); 

            // Transforma em minúsculo para facilitar a comparação
            continuar_str[0] = tolower(continuar_str[0]);

            // Se for uma resposta válida de tamanho 1, sai do loop de validação
            if (strlen(continuar_str) == 1 && (continuar_str[0] == 's' || continuar_str[0] == 'n')) {
                break;
            }
            printf("Resposta invalida! Digite apenas 's' ou 'n'.\n");
        }

    } while (continuar_str[0] == 's'); 

    printf("Obrigado por usar a calculadora! Ate a proxima.\n");
    return 0;
}
