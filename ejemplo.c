#include <stdio.h>
#include <string.h>
 int main()
 {
    int c=3;
    int *p = &c;
    printf("& de %d\n",&c);

    printf("* de %d",*p);
    return 0;
 }