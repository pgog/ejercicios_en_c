#include <stdio.h>

//scriba un p rogram a en ta b que reemplace cadenas de blancos por el m ínim o núm ero de tabuladores y blancos p ara obtener el mismo espaciado. Considere los paros de tabulación de igual m anera que para d e tab . C uando un tabulador o un simple espacio en blanco fuese suficiente p ara alcanzar un paro de tabulación, ¿a cuál se le debe d a r preferencia?

#define TAB_LENGTH 8

int main(){

    int c;
    unsigned nr_of_spaces =0;
    unsigned line_pos =0;

    while ((c=getchar())!=EOF)
    {
        ++line_pos;
        if (c==' ')
        {
            ++nr_of_spaces;

            if (line_pos % TAB_LENGTH==0 && nr_of_spaces >1)
            {
                putchar('\t');
                nr_of_spaces=0;
            }
            
        }else{
            while (nr_of_spaces>0)
            {
                putchar(' ');
                --nr_of_spaces;
            }
            if (c=='\n')
            {
                line_pos=0;
            }
            
        putchar(c);
        }
        
    }
    return 0;
}