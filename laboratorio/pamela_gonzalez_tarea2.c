#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct estudiante
{
    int ID_estudiante;
    char nombre[100];
    int edad;
    char bandera_genero[7];
    char bandera_grado[11];
};

struct curso
{
    int ID_curso;
    char nombre_curso[35];
    int horas_credito;

};

struct matricula
{
    int ID_estudiante;
    int ID_curso_mat;
    int año;
    int semestre;
} ;

int main (int argc, char* argv[]) 
{
     if (argc!=2)
    {
        printf("Uso: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    } 


    FILE *archivo = fopen( argv[1], "rb");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    int numero_estudiantes = 0, numero_cursos = 0, numero_matriculas = 0;
    fseek(archivo, 2, SEEK_SET);
    fread(&numero_estudiantes, 4, 1, archivo);
    printf("%d\n", numero_estudiantes);

    struct estudiante estudiantes[numero_estudiantes];


    fseek(archivo, 6, SEEK_SET);
    fread(&numero_cursos, 4, 1, archivo);
    printf("%d\n", numero_cursos);

    struct curso cursos[numero_cursos];



    fseek(archivo, 10, SEEK_SET);
    fread(&numero_matriculas, 4, 1, archivo);
    printf("%d\n", numero_matriculas);

    struct matricula matriculas[numero_matriculas];
    

    fseek(archivo, 14, SEEK_SET);

    unsigned char bandera;
    for (int i = 0; i < numero_estudiantes; i++)
    {
        // sacar el id
        fread(&estudiantes[i].ID_estudiante, 4, 1, archivo);

        // sacar el género

        fread(&bandera, 1, 1, archivo);
        unsigned char bandera_2bites = (bandera >> 6);

        if (bandera_2bites == 0)
        {
            strcpy(estudiantes[i].bandera_genero, "Male");
            strcpy(estudiantes[i].bandera_grado, "No Graduado");
        }
        else if (bandera_2bites == 1)
        {
            strcpy(estudiantes[i].bandera_genero, "Male");
            strcpy(estudiantes[i].bandera_grado, "Graduado");
        }
        else if (bandera_2bites == 2)
        {
            strcpy(estudiantes[i].bandera_genero, "Female");
            strcpy(estudiantes[i].bandera_grado, "No graduado");
        }
        else if (bandera_2bites == 3)
        {
            strcpy(estudiantes[i].bandera_genero, "Female");
            strcpy(estudiantes[i].bandera_grado, "Graduado");
        }

        // sacar el nombre
        fread(&estudiantes[i].nombre, 23, 1, archivo);

        // sacar la edad

        fread(&estudiantes[i].edad, 4, 1, archivo);
    }

    // estructura cursos
    
    for (int i = 0; i < numero_cursos; i++)
    {
        // sacar id
        fread(&cursos[i].ID_curso, 4, 1, archivo);

        // sacar el nombre del curos
        fread(&cursos[i].nombre_curso, 32, 1, archivo);

        // sacar la edad

        fread(&cursos[i].horas_credito, 4, 1, archivo);
    }
    

    // estructura matriculas
    
    for (int i = 0; i < numero_matriculas; i++)
    {
        // sacar id_estudiantes
        fread(&matriculas[i].ID_estudiante, 4, 1, archivo);

        // sacar el idcuros_mat
        fread(&matriculas[i].ID_curso_mat, 4, 1, archivo);

        // sacar la año

        fread(&matriculas[i].año, 4, 1, archivo);

        // semestre

        fread(&matriculas[i].semestre, 4, 1, archivo);
    }


    printf("Nombre del curso                         Promedio\n");
    for (int i = 0; i < numero_cursos; i++)
    {
        float edad_acum = 0, n_est_curso = 0;
        float edad_prom = 0;
        for (int j = 0; j < numero_matriculas; j++)
        {
            if (cursos[i].ID_curso == matriculas[j].ID_curso_mat)
            {

                for (int k = 0; k < numero_estudiantes; k++)
                {
                    if (matriculas[j].ID_estudiante == estudiantes[k].ID_estudiante)
                    {
                        edad_acum += estudiantes[k].edad;
                        n_est_curso++;
                    }
                edad_prom = edad_acum / n_est_curso;
                }
            }
            
        }
        printf("%-40s %.1f\n", cursos[i].nombre_curso,edad_prom);
    }

    fclose(archivo);
    return 0;
}
