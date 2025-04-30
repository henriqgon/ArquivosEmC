#include<stdio.h>

void funcao(int vet[], int t, int* min, int* max){
    *min = vet[0];
    *max = vet[0];
    for (int i = 0; i < t; i++){
        if (vet[i] < *min) *min = vet[i];
        if (vet[i] < *max) *max = vet[i];
    }
}

int main(){
    int vet[] = { 5, 3, 1, 4, 2, 6};
    int min, max;

    funcao(vet, 6, &min, &max);
    printf("%d %d\n", min, max);
    return 0;
}