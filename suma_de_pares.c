#include <stdio.h>
#include <stdlib.h>
//Crea un programa que inicialice un array dinámico de 10 elementos con números enteros ingresados por el usuario. Calcula la suma de los elementos que están en posiciones pares del array e imprime el resultado.
int main()
{
    int suma;
    int* array= (int*) malloc (10*sizeof(int));
    if (array==NULL)
    {
        printf("No se guardó\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese el dato %d\n", i+1);
        scanf("%d", &array[i]);
    }
    
    for (int i = 0; i < 10; i++)
    {
        if (i%2==0)
        {
            suma += array[i];
        }
        
    }
    printf("La suma de los valores ubicados en las posiciones pares es: %d\n", suma);
    

    free(array);
    return 0;
}
