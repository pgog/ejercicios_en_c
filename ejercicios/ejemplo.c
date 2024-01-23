#include <stdio.h>
#include <string.h>
 int main()
{
//     int c=3;
//     int *p = &c;
//     printf("& de %d\n",&c);

//     printf("* de %d",*p);
//     return 0;

//     char array[5];
//     for (int i; i<5;)
 
 int x=5;
 int * p = &x;
 printf("%d\n", *p);
 *p=6;
 printf("%d\n", *p);
 printf("%d\n",x);
 }
