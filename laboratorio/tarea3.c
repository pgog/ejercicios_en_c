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
    unsigned int bandera2;
} /* estudiantes[1000] */;

struct curso
{
    int ID_curso;
    char nombre_curso[35];
    int horas_credito;

} /* cursos[51] */;

struct matricula
{
    int ID_estudiante;
    int ID_curso_mat;
    int año;
    int semestre;
} /* matriculas[12061] */;

int main() /* (int argc, char* argv[]) */
{
    /* if (argc!=4)
    {
        printf("Uso: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    } */

    /*  int edad_min = atoi(argv[2]);
     int edad_max = atoi(argv[3]); */

    FILE *archivo = fopen("/home/pamela/C/laboratorio/sample_data.bin" /* argv[1] */, "rb");
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
        estudiantes[i].bandera2 = (bandera >> 6);

        if (estudiantes[i].bandera2 == 0)
        {
            strcpy(estudiantes[i].bandera_genero, "Male");
            strcpy(estudiantes[i].bandera_grado, "No Graduado");
        }
        else if (estudiantes[i].bandera2 == 1)
        {
            strcpy(estudiantes[i].bandera_genero, "Male");
            strcpy(estudiantes[i].bandera_grado, "Graduado");
        }
        else if (estudiantes[i].bandera2 == 2)
        {
            strcpy(estudiantes[i].bandera_genero, "Female");
            strcpy(estudiantes[i].bandera_grado, "No graduado");
        }
        else if (estudiantes[i].bandera2 == 3)
        {
            strcpy(estudiantes[i].bandera_genero, "Female");
            strcpy(estudiantes[i].bandera_grado, "Graduado");
        }

        // sacar el nombre
        fread(&estudiantes[i].nombre, 23, 1, archivo);

        // sacar la edad

        fread(&estudiantes[i].edad, 4, 1, archivo);
    }

    // imprmir estudiantes
    /* for (int i = 0; i < numero_estudiantes; i++)
   {
       printf("Nombre %-20s \tedad %d \t genero %s\n", estudiantes[i].nombre, estudiantes[i].edad,  estudiantes[i].bandera_genero);
   } */

    long posicion_actual = ftell(archivo);
    printf("Posición actual: %ld\n", posicion_actual);

    // estructura cursos
    // fseek(archivo, 32014, SEEK_SET);
    for (int i = 0; i < numero_cursos; i++)
    {
        // sacar id
        fread(&cursos[i].ID_curso, 4, 1, archivo);

        // sacar el nombre del curos
        fread(&cursos[i].nombre_curso, 32, 1, archivo);

        // sacar la edad

        fread(&cursos[i].horas_credito, 4, 1, archivo);
    }
    // imprmir cursos
    /*  for (int i = 0; i < numero_cursos; i++)
    {
        printf("ID curso %-5d \tnombre del curso %-30s \t horas de credito %d\n", cursos[i].ID_curso, cursos[i].nombre_curso, cursos[i].horas_credito);
    }

    posicion_actual = ftell(archivo);
    printf("Posición actual: %ld\n", posicion_actual); */

    // estructura matriculas
    //  fseek(archivo, 32010, SEEK_SET);
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

    // imprmir matriculas
    /* for (int i = 0; i < numero_matriculas; i++)
   {
       printf("ID estudiante %-8d ID curso %-8d Año %-8d Semestre %d\n", matriculas[i].ID_estudiante, matriculas[i].ID_curso_mat, matriculas[i].año, matriculas[i].semestre);
   } */

    // numero de años
    int año_min = 9999, año_max = 0;

    for (int i = 0; i < numero_matriculas; i++)
    {
        if (matriculas[i].año < año_min)
        {
            año_min = matriculas[i].año;
        }
        if (matriculas[i].año > año_max)
        {
            año_max = matriculas[i].año;
        }
    }

    int cantidad_años = (año_max - año_min) + 1;
    printf("min %d max %d %d\n ", año_min, año_max, cantidad_años);

    // numero semestres
    int semestre_min = 100, semestre_max = 0;

    for (int i = 0; i < numero_matriculas; i++)
    {
        if (matriculas[i].semestre < semestre_min)
        {
            semestre_min = matriculas[i].semestre;
        }
        if (matriculas[i].semestre > semestre_max)
        {
            semestre_max = matriculas[i].semestre;
        }
    }

    int num_semestres = (semestre_max - semestre_min) + 1;

    printf("min %d max %d num %d\n", semestre_min, semestre_max, num_semestres);

    int mg_acum = 0, mu_acum = 0, fg_acum = 0, fu_acum = 0;
    int registro_año = 0, semestre = 0;
    printf("%d\n", año_min);

    // printf("Year    Semester  Male Undergrad  Female Undergrad  Male Grad  Female Grad\n");

    int *e_comparados = (int *)malloc(numero_estudiantes * sizeof(int));
    if (e_comparados == NULL)
    {
        fprintf(stderr, "Error al asignar memoria dinámica\n");
        return 1;
    }

    for (int i = año_min; i < (cantidad_años + año_min); i++)
    {
        registro_año = i;

        for (int j = semestre_min; j < (num_semestres + semestre_min); j++)
        {
            semestre = j;

            for (int l = 0; l < numero_matriculas; l++)
            {
                for (int k = 0; k < numero_estudiantes; k++)
                {

                    if (matriculas[l].ID_estudiante == estudiantes[k].ID_estudiante)
                    {

                        for (int m = 0; m < numero_estudiantes; m++)
                        {
                            if (e_comparados[m] == estudiantes[k].ID_estudiante)
                            {
                            }
                            else
                            {
                                e_comparados[m] = estudiantes[k].ID_estudiante;
                                if (estudiantes[k].bandera2 == 0)
                                {
                                    mu_acum++;
                                    continue;
                                }
                                else if (estudiantes[k].bandera2 == 1)
                                {
                                    mg_acum++;
                                    continue;
                                }
                                else if (estudiantes[k].bandera2 == 2)
                                {
                                    fu_acum++;
                                    continue;
                                }
                                else if (estudiantes[k].bandera2 == 3)
                                {
                                    fg_acum++;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            printf("año %d semestre %d\n", registro_año, semestre);
        printf("%-10d %-15d %-15d %-15d %-15d %d\n", registro_año, semestre, mu_acum, fu_acum, mg_acum, fg_acum);
        }

    }

    free(e_comparados);
    fclose(archivo);
    return 0;
}
