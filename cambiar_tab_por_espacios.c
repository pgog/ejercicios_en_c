#include <stdio.h>

//Escriba un p rogram a d etab que reemplace tabuladores de la en­trada con el núm ero apropiado de blancos p ara espaciar hasta el siguiente paro de tabulación. Considere un co n ju n to fijo de paros de tabulación, digam os cada n colum nas. ¿Debe ser n una variable o un parám etro simbólico?

#define TAB_LENGTH 6

int main(void)
{
    int c;
    unsigned int nr_of_spaces;
    while ((c=getchar())!=EOF)
    {
        if (c=='\t')
        {
            nr_of_spaces =TAB_LENGTH;

            while (nr_of_spaces>0)
            {
                putchar(' ');
                --nr_of_spaces;
            }
            
        }else{
            putchar(c);//putchar imprime un solo caracter en la consola (salida estándar). La función putchar toma un argumento de tipo int que representa el carácter a imprimir.
        }
        
    }
    

    return 0;
}
