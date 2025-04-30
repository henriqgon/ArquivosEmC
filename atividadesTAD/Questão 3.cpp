#include <stdio.h>
#include <string.h>
#define MAX_FUNCIONARIOS 10


    typedef struct {
        char nome[100];
        char cargo[50];
        float salario_base;
        float beneficios;
        float descontos;
    } Funcionario;


    typedef struct {
        Funcionario funcionarios[MAX_FUNCIONARIOS];
        int total_funcionarios;
    } Loja;


    void cadastrar_funcionario(Loja *loja) {
        if (loja->total_funcionarios >= MAX_FUNCIONARIOS) {
            printf("Limite de funcionarios atingido!\n");
            return;
        }

        Funcionario novo;
        printf("Nome: ");
        getchar(); // Limpar buffer
        fgets(novo.nome, sizeof(novo.nome), stdin);
        novo.nome[strcspn(novo.nome, "\n")] = 0; // Remover \n do final

        printf("Cargo: ");
        fgets(novo.cargo, sizeof(novo.cargo), stdin);
        novo.cargo[strcspn(novo.cargo, "\n")] = 0;

        printf("Salario base: ");
        scanf("%f", &novo.salario_base);
        printf("Beneficios: ");
        scanf("%f", &novo.beneficios);
        printf("Descontos: ");
        scanf("%f", &novo.descontos);

        loja->funcionarios[loja->total_funcionarios] = novo;
        loja->total_funcionarios++;
        printf("Funcionario cadastrado com sucesso!\n");
    }


    float calcular_salario_liquido(Funcionario f) {
        return f.salario_base + f.beneficios - f.descontos;
    }


    void listar_funcionarios(Loja loja) {
        if (loja.total_funcionarios == 0) {
            printf("Nenhum funcionario cadastrado.\n");
            return;
        }

        for (int i = 0; i < loja.total_funcionarios; i++) {
            printf("\nFuncionario %d:\n", i + 1);
            printf("Nome: %s\n", loja.funcionarios[i].nome);
            printf("Cargo: %s\n", loja.funcionarios[i].cargo);
            printf("Salario Base: %.2f\n", loja.funcionarios[i].salario_base);
            printf("Beneficios: %.2f\n", loja.funcionarios[i].beneficios);
            printf("Descontos: %.2f\n", loja.funcionarios[i].descontos);
            printf("Salario Liquido: %.2f\n", calcular_salario_liquido(loja.funcionarios[i]));
        }
    }


    float calcular_media_salarial(Loja loja) {
        if (loja.total_funcionarios == 0) return 0;
        float soma = 0;
        for (int i = 0; i < loja.total_funcionarios; i++) {
            soma += calcular_salario_liquido(loja.funcionarios[i]);
        }
        return soma / loja.total_funcionarios;
    }


    void maior_salario(Loja loja) {
        if (loja.total_funcionarios == 0) {
            printf("Nenhum funcionario cadastrado.\n");
            return;
        }

        int indice_maior = 0;
        float maior = calcular_salario_liquido(loja.funcionarios[0]);

        for (int i = 1; i < loja.total_funcionarios; i++) {
            float salario = calcular_salario_liquido(loja.funcionarios[i]);
            if (salario > maior) {
                maior = salario;
                indice_maior = i;
            }
        }

        printf("\nFuncionario com maior salario:\n");
        printf("Nome: %s\n", loja.funcionarios[indice_maior].nome);
        printf("Cargo: %s\n", loja.funcionarios[indice_maior].cargo);
        printf("Salario Liquido: %.2f\n", maior);
    }

    int main() {
        Loja loja;
        loja.total_funcionarios = 0;
        int opcao;

        do {
            printf("\nMenu:\n");
            printf("1 - Cadastrar funcionario\n");
            printf("2 - Listar funcionarios\n");
            printf("3 - Exibir media salarial\n");
            printf("4 - Exibir funcionario com maior salario\n");
            printf("0 - Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    cadastrar_funcionario(&loja);
                    break;
                case 2:
                    listar_funcionarios(loja);
                    break;
                case 3:
                    printf("Media salarial da loja: %.2f\n", calcular_media_salarial(loja));
                    break;
                case 4:
                    maior_salario(loja);
                    break;
                case 0:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        } while (opcao != 0);

        return 0;
    }
