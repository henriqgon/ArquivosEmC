#include <stdio.h>
#include <string.h>
#define MAX_LIVROS 10


    typedef struct {
        char titulo[100];
        char autor[100];
        int paginas;
    } Livro;


    typedef struct {
        Livro livros[MAX_LIVROS];
        int total_livros;
    } Biblioteca;

    void ler_livro(Livro *livro) {
        printf("Titulo: ");
        getchar();
        fgets(livro->titulo, sizeof(livro->titulo), stdin);
        livro->titulo[strcspn(livro->titulo, "\n")] = 0;

        printf("Autor: ");
        fgets(livro->autor, sizeof(livro->autor), stdin);
        livro->autor[strcspn(livro->autor, "\n")] = 0;

        printf("Numero de paginas: ");
        scanf("%d", &livro->paginas);
    }


    void imprimir_livro(Livro livro) {
        printf("Titulo: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Paginas: %d\n", livro.paginas);
    }


    void adicionar_livro(Biblioteca *biblioteca) {
        if (biblioteca->total_livros >= MAX_LIVROS) {
            printf("Biblioteca cheia!\n");
            return;
        }

        Livro novo;
        ler_livro(&novo);

        biblioteca->livros[biblioteca->total_livros] = novo;
        biblioteca->total_livros++;
        printf("Livro adicionado com sucesso!\n");
    }

    void imprimir_biblioteca(Biblioteca biblioteca) {
        if (biblioteca.total_livros == 0) {
            printf("Nenhum livro cadastrado.\n");
            return;
        }

        for (int i = 0; i < biblioteca.total_livros; i++) {
            printf("\nLivro %d:\n", i + 1);
            imprimir_livro(biblioteca.livros[i]);
        }
    }

    void livro_mais_paginas(Biblioteca biblioteca) {
        if (biblioteca.total_livros == 0) {
            printf("Nenhum livro cadastrado.\n");
            return;
        }

        int indice_maior = 0;
        for (int i = 1; i < biblioteca.total_livros; i++) {
            if (biblioteca.livros[i].paginas > biblioteca.livros[indice_maior].paginas) {
                indice_maior = i;
            }
        }

        printf("\nLivro com maior numero de paginas:\n");
        imprimir_livro(biblioteca.livros[indice_maior]);
    }

    int main() {
        Biblioteca biblioteca;
        biblioteca.total_livros = 0;
        int opcao;

        do {
            printf("\nMenu:\n");
            printf("1 - Adicionar livro\n");
            printf("2 - Listar livros\n");
            printf("3 - Exibir livro com mais paginas\n");
            printf("0 - Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    adicionar_livro(&biblioteca);
                    break;
                case 2:
                    imprimir_biblioteca(biblioteca);
                    break;
                case 3:
                    livro_mais_paginas(biblioteca);
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
