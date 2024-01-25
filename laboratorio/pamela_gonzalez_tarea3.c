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
};

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("No ingreso los argumentos correctos");
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
    
    struct estudiante estudiantes[numero_estudiantes];

    fseek(archivo, 6, SEEK_SET);
    fread(&numero_cursos, 4, 1, archivo);
    
    struct curso cursos[numero_cursos];

    fseek(archivo, 10, SEEK_SET);
    fread(&numero_matriculas, 4, 1, archivo);
    
    struct matricula matriculas[numero_matriculas];

    //Estructura estudiantes

    unsigned char bandera;
    
    for (int i = 0; i < numero_estudiantes; i++)
    {
        // registrar el id
        fread(&estudiantes[i].ID_estudiante, 4, 1, archivo);

        // registrar el género

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

        // registrar el nombre
        fread(&estudiantes[i].nombre, 23, 1, archivo);

        // registrar la edad

        fread(&estudiantes[i].edad, 4, 1, archivo);
    }

    // Estructura cursos
    
    for (int i = 0; i < numero_cursos; i++)
    {
        // registrar id
        fread(&cursos[i].ID_curso, 4, 1, archivo);

        // registrar el nombre del curos
        fread(&cursos[i].nombre_curso, 32, 1, archivo);

        // registrar la edad

        fread(&cursos[i].horas_credito, 4, 1, archivo);
    }

    // Estructura matriculas
    
    for (int i = 0; i < numero_matriculas; i++)
    {
        // registrar id_estudiantes
        fread(&matriculas[i].ID_estudiante, 4, 1, archivo);

        // registrar el idcuros_mat
        fread(&matriculas[i].ID_curso_mat, 4, 1, archivo);

        // registrar la año

        fread(&matriculas[i].año, 4, 1, archivo);

        // registrar semestre

        fread(&matriculas[i].semestre, 4, 1, archivo);
    }

    // Numero de años
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

    // Numero semestres
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

    int registro_año = 0, semestre = 0;

    printf("Year    Semester  Male Undergrad  Female Undergrad  Male Grad  Female Grad\n");

    for (int i = año_min; i < (cantidad_años + año_min); i++)
    {
        registro_año = i;
        for (int j = semestre_min; j < (num_semestres + semestre_min); j++)
        {
            semestre = j;

            int e_comparados[numero_estudiantes ];
            memset(e_comparados, 0, numero_estudiantes * sizeof(int));
            int mg_acum = 0, mu_acum = 0, fg_acum = 0, fu_acum = 0;

            for (int a = 0; a < numero_matriculas; a++)
            {

                if (matriculas[a].año == registro_año && matriculas[a].semestre == semestre)
                {
                    int id_e_m = matriculas[a].ID_estudiante;
                    for (int k = 0; k < numero_estudiantes; k++)
                    {

                        if (id_e_m == estudiantes[k].ID_estudiante)
                        {

                            if (e_comparados[k] == estudiantes[k].ID_estudiante)
                            {
                            }
                            else
                            {
                                e_comparados[k] = estudiantes[k].ID_estudiante;
                                if (estudiantes[k].bandera2 == 0)
                                {
                                    mu_acum++;
                                    break;
                                }
                                else if (estudiantes[k].bandera2 == 1)
                                {
                                    mg_acum++;
                                    break;
                                }
                                else if (estudiantes[k].bandera2 == 2)
                                {
                                    fu_acum++;
                                    break;
                                }
                                else if (estudiantes[k].bandera2 == 3)
                                {
                                    fg_acum++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            printf("%-10d %-10d %-17d %-15d %-10d %d\n", registro_año, semestre, mu_acum, fu_acum, mg_acum, fg_acum);
        }
    }

    fclose(archivo);
    return 0;
}