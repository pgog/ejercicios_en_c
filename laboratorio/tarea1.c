#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct estudiante
{
    char nombre[100];
    int edad;
    char bandera_genero[7];
    char bandera_grado[11];
};

int main(){/* int argc, char* argv[])
{
    if (argc!=4)
    {
        printf("Uso: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    }
    

    int edad_min = atoi(argv[2]); 
    int edad_max = atoi(argv[3]); */
    
    FILE *archivo = fopen("/home/pamela/C/laboratorio/sample_data.bin"/* argv[1] */, "rb");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }


    int numero_estudiantes = 0;
    fseek(archivo, 2, SEEK_SET);
    fread(&numero_estudiantes, 4, 1, archivo);
    printf("%d\n", numero_estudiantes);
    struct estudiante estudiantes[numero_estudiantes];

    /* long posicion_actual = ftell(archivo);
    printf("Posición actual: %ld\n", posicion_actual); */

    fseek(archivo, 18, SEEK_SET);

    
    unsigned char bandera;
    for (int i = 0; i < numero_estudiantes; i++)
    {
        // sacar el género

        fread(&bandera, 1, 1, archivo);
        unsigned char  bandera_2bites= (bandera >> 6);

        if (bandera_2bites==0)
        {
            strcpy(estudiantes[i].bandera_genero, "Male");
            strcpy(estudiantes[i].bandera_grado, "No Graduado");
        } else if (bandera_2bites==1)
        {
            strcpy(estudiantes[i].bandera_genero, "Male");
            strcpy(estudiantes[i].bandera_grado, "Graduado");
        } else if (bandera_2bites==2)
        {
            strcpy(estudiantes[i].bandera_genero, "Female");
            strcpy(estudiantes[i].bandera_grado, "No graduado");
        }else if (bandera_2bites==3)
        {
            strcpy(estudiantes[i].bandera_genero, "Female");
            strcpy(estudiantes[i].bandera_grado, "Graduado");
        }
        

        // sacar el nombre
        fread(&estudiantes[i].nombre, 23, 1, archivo);

        // sacar la edad

        fread(&estudiantes[i].edad, 4, 1, archivo);
        fseek(archivo, 4, SEEK_CUR);
    }

    // imprmir estudiantes
    for (int i = 0; i < numero_estudiantes; i++)
    {
        printf("Nombre %-20s \tedad %d \t genero %-20s stado %s\n", estudiantes[i].nombre, estudiantes[i].edad,  estudiantes[i].bandera_genero, estudiantes[i].bandera_grado);
    }
 
 
    
    /* printf("Name                     Age       Gender\n");

    for (int i = 0; i < 1000; i++)
    {
        if (estudiantes[i].edad >=edad_min && estudiantes[i].edad <= edad_max)
        {
            printf("%-20s \t %d \t  %s\n", estudiantes[i].nombre, estudiantes[i].edad,  estudiantes[i].bandera_genero);
        }
        
    } */
    

    fclose(archivo);
    return 0;
}
