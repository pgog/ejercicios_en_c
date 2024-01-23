#include <stdio.h>
/* copia la entrada a la salida; la . versión */
int main( )
    {
        int c;
        printf("EOF is %d", EOF);
        c = getchar();
        while (c != 3) {
            putchar(c);
            c = getchar();
        }
        
    }