#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 50


    typedef struct {
        int dia, mes, ano;
    } Data;


    typedef struct {
        char nome[100];
        Data nascimento;
        int idade;
        char sexo;
    } Cliente;


    int calcular_idade(Data nascimento, Data atual) {
        int idade = atual.ano - nascimento.ano;
        if (atual.mes < nascimento.mes || (atual.mes == nascimento.mes && atual.dia < nascimento.dia)) {
            idade--;
        }
        return idade;
    }


    Data obter_data_atual() {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        Data data_atual;
        data_atual.dia = tm.tm_mday;
        data_atual.mes = tm.tm_mon + 1;
        data_atual.ano = tm.tm_year + 1900;
        return data_atual;
    }


    void cadastrar_cliente(Cliente clientes[], int *total, Data data_atual) {
        if (*total >= MAX_CLIENTES) {
            printf("Limite de clientes atingido!\n");
            return;
        }

        Cliente novo;
        printf("Nome: ");
        getchar();
        fgets(novo.nome, sizeof(novo.nome), stdin);
        novo.nome[strcspn(novo.nome, "\n")] = 0;
        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &novo.nascimento.dia, &novo.nascimento.mes, &novo.nascimento.ano);
        printf("Sexo (M/F): ");
        scanf(" %c", &novo.sexo);

        novo.idade = calcular_idade(novo.nascimento, data_atual);

        clientes[*total] = novo;
        (*total)++;
        printf("Cliente cadastrado com sucesso!\n");
    }


    void listar_clientes(Cliente clientes[], int total) {
        if (total == 0) {
            printf("Nenhum cliente cadastrado.\n");
            return;
        }
        for (int i = 0; i < total; i++) {
            printf("\nCliente %d:\n", i + 1);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Data de nascimento: %02d/%02d/%d\n", clientes[i].nascimento.dia, clientes[i].nascimento.mes, clientes[i].nascimento.ano);
            printf("Idade: %d\n", clientes[i].idade);
            printf("Sexo: %c\n", clientes[i].sexo);
        }
    }

    int main() {
        Cliente clientes[MAX_CLIENTES];
        int total_clientes = 0;
        Data data_atual = obter_data_atual();
        int opcao;

        do {
            printf("\nMenu:\n");
            printf("1 - Cadastrar cliente\n");
            printf("2 - Listar clientes\n");
            printf("0 - Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    cadastrar_cliente(clientes, &total_clientes, data_atual);
                    break;
                case 2:
                    listar_clientes(clientes, total_clientes);
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
