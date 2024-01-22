#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Escribe un programa que cree un array dinámico de caracteres e ingrese una palabra desde el usuario. Luego, invierte la palabra (cambia el orden de las letras) utilizando memoria dinámica y muestra la palabra invertida.

int main() {
 int n=0;

 char* string = (char*)malloc((256*sizeof(char)));
  if (string==NULL)
    {
        printf("No se guardó\n");
        exit(EXIT_FAILURE);
    }
   

 printf("Ingresa la cadena de texto\n");
 fgets(string,256,stdin);

 /*for (int i = 0; string [i] != '\0' ; i++) { 
    n+=1;
 } //contar el valor de la cadena*/
 int caracteres= strlen(string);
 printf("Numero de caracteres: %d\n", caracteres);

 char* nuevo=(char*)malloc((n*sizeof(char)));
 if (nuevo==NULL)
    {
        printf("No se guardó\n");
        exit(EXIT_FAILURE);
    }

 for (int i = 0; i <=caracteres; i++)
 {
    nuevo[i]=string[caracteres-i-2];
    
 }
 
 printf("%s \n", nuevo);
 
 free(string);
 free(nuevo);

 return 0;
}