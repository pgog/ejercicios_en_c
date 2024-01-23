#include <stdio.h>
int main()
{
    long sb=0,salto=0,tab=0;
    int c;
    while ((c = getchar()) != EOF) {
        switch (c)
        {
        case '\t':
            ++tab;        
            break;
        case '\n':
            ++salto;        
            break;
        case ' ':
            ++sb;        
            break;
        default:
            break;
        }
    }
    printf("Espacios en blanco: %ld\n", sb);
    printf("Tabulaciones: %ld\n", tab);
    printf("Saltos de página: %ld\n", salto);


    return 0;
}
