/*Punto 2: Funciones y Arrays
2.1. Crea una función llamada calcularPromedio que tome un arreglo de enteros y su tamaño como parámetros, y devuelva el promedio de los elementos.*/
#include <stdio.h>

float promedio(int* enteros, int tamaño){
    float acum=0;
    for(int i=0;i<tamaño;i++){
        acum+=enteros[i];        
    }
    float prom=acum/tamaño;
    return prom;

}

int main(){
    int tamaño;
    printf("Ingrese el tamaño del arreglo:\n");
    scanf("%d", &tamaño);
    int enteros[tamaño];
    for(int i=0;i<tamaño;i++){
        printf("Ingrese un número entero:\n");
        scanf("%d", &enteros[i]);
    }
    float resultado_prom = promedio(enteros,tamaño);
    printf("El promedio es %.2f\n", resultado_prom);
    return 0;
}
//2.2. En el main, declara un arreglo de números e inicialízalo con valores de tu elección. Llama a la función calcularPromedio pasándole el arreglo y su tamaño. Imprime el resultado en la consola.