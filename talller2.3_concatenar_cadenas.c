#include <stdio.h>
#include <stdlib.h>

// Crea una función llamada concatenarCadenas que tome dos cadenas de caracteres como parámetros y devuelva una nueva cadena que sea la concatenación de ambas.

char *concatenarCadenas(const char *cadena1, const char *cadena2)
{
    char *cadenas = (char *)malloc((strlen(cadena1) + strlen(cadena2) + 1) * sizeof(char));
    if (cadenas == NULL)
    {
        printf("No se pudo guardar.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(cadenas, cadena1);
    strcat(cadenas, cadena2);
    //printf("%s\n", cadenas);
    return cadenas;
    
}

int main()
{
    /*char *texto1 = "Hola ";
    char *texto2 = "Todo gud"*/;
    
    printf("Ingresa la primera cadena de texto\n");
    char* texto1= (char*)malloc((256*sizeof(char)));
    fgets(texto1,256,stdin);


    printf("Ingresa la segunda cadena de texto\n");
    char* texto2= (char*)malloc((256*sizeof(char)));
    fgets(texto2,256,stdin); //stdin es para coger el texto de la consola

    char* concatenadas=concatenarCadenas(texto1, texto2);

    printf("%s \n", concatenadas);
     
    free(concatenadas);
    free(texto1);
    free(texto2);

    return 0;
}
