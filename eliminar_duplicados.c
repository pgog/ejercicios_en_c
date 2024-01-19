#include <stdio.h>
#include <stdlib.h>
//Diseña un programa que inicialice un array dinámico de enteros con valores ingresados por el usuario. Luego, elimina los elementos duplicados, reduciendo la longitud del array si es necesario, y muestra el array resultante.
int main()
{
    int* entero= (int*) malloc (5*sizeof(int));
    if (entero==NULL)
    {
        printf("no se pudo guardar\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Introduce el valor %d\n", i+1);
        scanf("%d", &entero[i]);
    }
    
    int *nuevo = (int *)malloc(5 * sizeof(int));
    if (nuevo == NULL)
    {
        printf("no se pudo guardar\n");
        exit(EXIT_FAILURE);
    }
     
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (entero[i]==entero[j])
            {
                printf("%d está repetido\n",entero[i]);
                entero[i]=-1;
                int longitud_nueva=0;
                longitud_nueva+=1;
              
            }else{
                nuevo[i]= entero[i];
            }
            
        }
        
    }

    for (int i = 0; i < 5; i++)
    {
        if(entero[i] !=-1){
        printf("%d ", nuevo[i]);

        }
    }

    free(nuevo);
    free(entero);
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* entero = (int*) malloc(5 * sizeof(int));
    if (entero == NULL)
    {
        printf("no se pudo guardar\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Introduce el valor %d\n", i + 1);
        scanf("%d", &entero[i]);
    }

    int* nuevo = (int*) malloc(5 * sizeof(int));
    if (nuevo == NULL)
    {
        printf("no se pudo guardar\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the "nuevo" array with the same values as the "entero" array
    for (int i = 0; i < 5; i++)
    {
        nuevo[i] = entero[i];
    }

    // Check for duplicates in the "nuevo" array
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (nuevo[i] == nuevo[j])
            {
                printf("%d Está repetido\n", nuevo[i]);
                // Shift the remaining elements to the left and decrement the array length
                for (int k = j; k < 4; k++)
                {
                    nuevo[k] = nuevo[k + 1];
                }
                nuevo = (int*) realloc(nuevo, (5 - 1) * sizeof(int));
                i--; // To avoid skipping the next element after shifting
                break;
            }
        }
    }

    // Print the resultant array
    for (int i = 0; i < 5; i++)
    {
        printf("%d", nuevo[i]);
    }

    free(nuevo);
    free(entero);
    return 0;
}*/