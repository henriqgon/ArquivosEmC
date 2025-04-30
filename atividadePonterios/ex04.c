#include<stdio.h>

void areaEVolume(int *p, int *r){
    float a, v;

    a = (4 * *p) * (*r * *r);
    v = (4/3 * *p) * (*r * *r * *r);
    printf("%f\n", a);
    printf("%f", v);
}

int main() {
    int p, r;
    scanf("%d %d", &p, &r);

    areaEVolume(&p, &r);

    return 0;
}