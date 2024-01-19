#include <stdio.h>


#define PIZZACOST 1.5
const NEWLINE= '\n';

int main()
{
    float costoPizzas;
    float numberOfSlices =3;

    costoPizzas= PIZZACOST*numberOfSlices;

    printf("Total bill:%c %f", NEWLINE, costoPizzas);
}
