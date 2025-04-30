#include <stdio.h>
#define MAX_ELEMENTOS 20


    typedef struct {
        int elementos[MAX_ELEMENTOS];
        int tamanho;
    } Conjunto;

    void criar_conjunto(Conjunto *c) {
        c->tamanho = 0;
    }

    void ler_conjunto(Conjunto *c) {
        int n, valor;
        printf("Quantos elementos deseja inserir (max %d)? ", MAX_ELEMENTOS);
        scanf("%d", &n);

        if (n > MAX_ELEMENTOS) {
            printf("Número excede o máximo permitido!\n");
            return;
        }

        c->tamanho = n;
        printf("Digite os %d elementos do conjunto:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &c->elementos[i]);
        }
    }

    void imprimir_conjunto(Conjunto c) {
        printf("{ ");
        for (int i = 0; i < c.tamanho; i++) {
            printf("%d ", c.elementos[i]);
        }
        printf("}\n");
    }

    Conjunto uniao(Conjunto c1, Conjunto c2) {
        Conjunto resultado;
        criar_conjunto(&resultado);

        for (int i = 0; i < c1.tamanho; i++) {
            resultado.elementos[resultado.tamanho++] = c1.elementos[i];
        }

        for (int i = 0; i < c2.tamanho; i++) {
            int ja_existe = 0;
            for (int j = 0; j < resultado.tamanho; j++) {
                if (c2.elementos[i] == resultado.elementos[j]) {
                    ja_existe = 1;
                    break;
                }
            }
            if (!ja_existe) {
                resultado.elementos[resultado.tamanho++] = c2.elementos[i];
            }
        }

        return resultado;
    }

    Conjunto interseccao(Conjunto c1, Conjunto c2) {
        Conjunto resultado;
        criar_conjunto(&resultado);

        for (int i = 0; i < c1.tamanho; i++) {
            for (int j = 0; j < c2.tamanho; j++) {
                if (c1.elementos[i] == c2.elementos[j]) {
                    resultado.elementos[resultado.tamanho++] = c1.elementos[i];
                    break;
                }
            }
        }

        return resultado;
    }

    int main() {
        Conjunto A, B, C;
        criar_conjunto(&A);
        criar_conjunto(&B);

        printf("Leitura do conjunto A:\n");
        ler_conjunto(&A);

        printf("Leitura do conjunto B:\n");
        ler_conjunto(&B);

        printf("Conjunto A: ");
        imprimir_conjunto(A);

        printf("Conjunto B: ");
        imprimir_conjunto(B);

        C = uniao(A, B);
        printf("União de A e B: ");
        imprimir_conjunto(C);

        C = interseccao(A, B);
        printf("Interseção de A e B: ");
        imprimir_conjunto(C);

        return 0;
    }
