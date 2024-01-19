#include <stdio.h>
#include <stdlib.h>

// Crea una función llamada concatenarCadenas que tome dos cadenas de caracteres como parámetros y devuelva una nueva cadena que sea la concatenación de ambas.

int main() {
 int i, n;
 char c;

 printf("Ingresa la primera cadena de texto\n");
 char* string = (char*)malloc((256*sizeof(char)));
 fgets(string,256,stdin);

 printf("Ingresa la segunda cadena de texto\n");
 char* texto2= (char*)malloc((256*sizeof(char)));
 fgets(texto2,256,stdin);

 // Concatenar las cadenas sin usar string.h
 for (i = 0; string[i] != '\0'; i++) {} // buscar el final de la primera cadena y guarda el total caracteres de la cadena en i
 for (n = 0; texto2[n] != '\0'; n++) {} // buscar el final de la segunda cadena

 // Reservar memoria para la nueva cadena
 char* concatenadas= (char*)malloc(((i+n+1)*sizeof(char)) );

 // Concatenar las cadenas
 for (i = 0; string[i] != '\0'; i++) {
    concatenadas[i] = string[i];
    printf("%c\n", concatenadas[i]);//Imprime la posición i
    printf("%s\n", concatenadas);//Imprime lo que lleva el arreglo hasta i
 }
 for (n = 0; texto2[n] != '\0'; n++) {
    concatenadas[i+n] = texto2[n];
    printf("%c\n", concatenadas[i+n]);//Imprime la posición i
 }
 concatenadas[i+n] = '\0'; // agregar el carácter nulo al final

 printf("%s \n", concatenadas);

 free(concatenadas);
 free(string);
 free(texto2);

 return 0;
}
   