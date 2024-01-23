#include <stdio.h>

void imprimir_dia(int numero_de_dia){
    switch (numero_de_dia)
    {
    case 1:
        printf("Lunes");
        break;
    case 2:
        printf("Martes");
        break;
    case 3:
        printf("Miércoles");
        break;
    case 4:
        printf("Jueves");
        break;
    case 5:
        printf("Viernes");
        break;
    case 6:
        printf("Sàbado");
        break;
    case 7:
        printf("Domingo");
        break;

    default:
        break;
    }
}
int main()
{
    imprimir_dia(2);
    return 0;
}
