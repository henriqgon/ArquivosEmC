#include<stdio.h>

int main() {
    float array[10];

   
    for (int i = 0; i < 10; i++) {
        array[i] = (i + 1) * 1.5f; 
    }

    float *pntr = array;

    for (int i = 0; i < 10; i++) {
        printf("Endereço de arr[%d] = %p\n", i, (void*)(pntr + i));
    }
    
    return 0;

}