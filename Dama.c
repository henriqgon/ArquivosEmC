#include <stdio.h>

int main() {
    int X1, Y1, X2, Y2;

    while (1) {
        scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);

        if (X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0) {
            break;
        }

        // Caso 1: Dama já está na posição de destino
        if (X1 == X2 && Y1 == Y2) {
            printf("0\n");
        }
        // Caso 2: Se a Dama puder ir diretamente para a posição de destino
        else if (X1 == X2 || Y1 == Y2 || (X1 - Y1) == (X2 - Y2) || (X1 + Y1) == (X2 + Y2)) {
            printf("1\n");
        }
        // Caso 3: Se a Dama precisar de  2 movimentos
        else {
            printf("2\n");
        }
    }

    return 0;
}
