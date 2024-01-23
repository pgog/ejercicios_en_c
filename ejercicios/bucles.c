#include <stdio.h>

int main(){
    int k=10;
    while (k<20)
    {
        printf("K vale %d \n", k);
        k++;
    }
    do
    {
        printf("k vale %d\n",k);
        k--;
    } while (k>15);
    
    for (int i=0; i<5;i++){
        printf("Estoy en la iteraciòn %d.\n", i);
    }
}