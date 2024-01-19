#include <stdio.h>
#include <stdlib.h>
//Escribe un programa en C que solicite al usuario ingresar la longitud de un array y luego inicialice un array dinámico de enteros con esa longitud. Llena el array con valores ingresados por el usuario y muestra los elementos en la pantalla.
int main()
{
    int longitud;
    printf("Ingrese la longitud del array\n");
    scanf("%d", &longitud);

    int* array_dinamico = (int *)malloc(longitud*sizeof(int));
    if (array_dinamico==NULL)
    {
        printf("No se guardó\n");
        exit(EXIT_FAILURE);
    }
    

    for (int i = 0; i < longitud; i++)
    {
        printf("Ingrese el valor %d del array\n",i+1);
        scanf("%d", &array_dinamico[i]);
        
    }

    printf("Este es el array:\n");
    for (int i = 0; i < longitud; i++)
    {
        printf("%d ",array_dinamico[i]);
    }
    
    free(array_dinamico);

    return 0;
}
