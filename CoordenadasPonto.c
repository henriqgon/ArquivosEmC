#include<stdio.h>;
 int main(){

    double x, y;

    scanf("%lf", &x);
    scanf("%lf", &y);

    //EIXO X

    if(y==0 && x!=0){
        printf("Eixo X\n");
    }

    // EIXO Y

    if(x==0 && y!=0){
        printf("Eixo Y\n");
    }

    // QUADRANTE 1
    if(x > 0 && y > 0){

        printf("Q1\n");
    }

    // QUADRANTE 2
    if(x < 0 && y > 0){

        printf("Q2\n");
    }

    // QUADRANTE 3
    if(x < 0 && y < 0){

        printf("Q3\n");
    }

    // QUADRANTE 4
    if(x > 0 && y < 0){

        printf("Q4\n");
    }


    if(x == 0 && y == 0){

        printf("Origem\n");
    }
    return 0;
 }
