#include<stdio.h>

int main() {

    int i=0, f=0, mi=0, fi=0, min=0, hora=0;
    scanf("%d %d %d %d",&i,&mi, &f, &fi);

    hora=f-i;
    min=fi-mi;

    if(hora==0 && min==0){
        hora=24;
        min=0;
    }
    if(hora==0){
        if(min<0){
            hora=23;
            min+=60;
        }
    }
    if(hora<0){
        hora+=24;
        if(min<0){
            hora-=1;
            min+=60;
        }
    }
    if(hora>0){
        if(min<0){
            hora-=1;
            min+=60;
        }
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",hora,min);
    return 0;
}
