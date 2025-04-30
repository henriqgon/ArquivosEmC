#include<stdio.h>
#include<math.h>

void parteInteiraEFracao(int *a, float *b){
    *a = (int) *b;
    *b = *b - *a;

    printf("%d\n", *a);
    printf("%f", *b);
}

int main() {
    int c;
    float d;

    scanf("%d", &c);
    scanf("%f", &d);

    parteInteiraEFracao(&c, &d);

    return 0;
}