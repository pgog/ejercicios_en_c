#include <stdio.h>

int main()
{
    /*/ciclo while
    float farh, celsius, lower, upper, step;

    lower=0;
    upper=300;
    step=20;

    farh=lower;
    printf("Tabla temperaturas\nCelcius Farengeith\n");

    while (farh<=upper) {
        celsius=(5.0/9.0)*(farh-32.0);
        printf("%3.0f \t %6.1f\n", farh, celsius);
        farh +=step;
    }*/
    //ciclo for
    int farh;
    for (farh= 300; farh  >=0; farh-=20)
    {
        printf("%3d\t %6.1f\n", farh,(5.0/9.0)*(farh-32.0));
    }
    
    
    return 0;
}
