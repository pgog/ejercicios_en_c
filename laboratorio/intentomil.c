#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct estudiantes {


   int ID_estudiante;
   char booleano;
   char flag[10];
   char grado[10];
   char nombre_estudiante[100];
   int edad;
};


struct cursos {


   int curso_id;
   char curso_name[30];
   int curso_horas;
   float edad_curso;
   float cant_estudiantes_curso;
   float prom_edad_curso;


};


struct matriculas {
   int ID_estudiante;
   int curso_id;
   int year;
   int semester;
} ;


int main() {


  
   // // Verifica si se proporcionan al menos tres argumentos
   // if (argc != 1) {
   //     fprintf(stderr, "Uso: %s <PrimerParametro> <SegundoParametro> <TercerParametro>\n", argv[0]);
   //     return 1;
   // }


   // Accede a los parámetros
   // char *primerParametro = argv[1];
   // char *segundoParametro = argv[2];
   // char *tercerParametro = argv[3];


  
   // //Aqui ingresaremos los rangos de edad de la variable
   // int edad_min = atoi(segundoParametro);
   // int edad_max = atoi(tercerParametro);


   // //char file[20];


   // FILE* datos = fopen(primerParametro,"rb"); //EL rb se supone que es para leer binarios, se supone que el ".bin" no importa.


   //Aqui ingresaremos los rangos de edad de la variable
   // int edad_min = 25;
   // int edad_max = 30;


   //char file[20];


   FILE* datos = fopen("/home/diegocub/Documentos/Laboratorio_stage_1/sample_data.bin", "rb"); //EL rb se supone que es para leer binarios, se supone que el ".bin" no importa.



   if(datos == NULL){
       printf("No pudo localizar el archivo \n");
       return 1;


   }

   char *encabezado;
   fread(&encabezado, 2, 1, datos);

 


   //Cantidad de estudiantes:
   int cant_estudiantes = 0;
   fseek(datos, 2, SEEK_SET);
   fread(&cant_estudiantes, 4, 1, datos);
   //printf("Cantidad de estudiantes: %d \n", cant_estudiantes);
   struct estudiantes estu[cant_estudiantes];


   //Cantidad de cursos:
   int cant_cursos = 0;
   fseek(datos, 6, SEEK_SET);
   fread(&cant_cursos, 4, 1, datos);
   //printf("Cantidad de cursos: %d \n", cant_cursos);
   struct cursos curso[cant_cursos];


   //Cantidad de matriculas:
   int cant_matriculas = 0;
   fseek(datos, 10, SEEK_SET);
   fread(&cant_matriculas, 4, 1, datos);
   //printf("Cantidad de matriculas: %d \n", cant_matriculas);
   struct matriculas matriculas[cant_matriculas];


   // _________________________________________
   // Ahora crearemos la estructura para la seccion estudiantes


   int pos = ftell(datos);
   // printf("El cursor esta en la %d \n",pos);
  
   //ESTRUCTURA ESTUDIANTES
   fseek(datos, 14, SEEK_SET);


   for(int i = 0; i < cant_estudiantes; i = i + 1){
       fread(&estu[i].ID_estudiante,4,1,datos);
       fread(&estu[i].booleano, 1, 1, datos);
           if((estu[i].booleano & 192) == 192){ //Se realiza mascara de bits para ver si da 11000000 (1: Femenino y 1: posgrado)
               strcpy(estu[i].flag, "Female");
               strcpy(estu[i].grado, "Posgrado");
           } else if ((estu[i].booleano & 192) == 128){ //Se realiza mascara de bit para ver si da 1000000 (1: Femenino y 0: pregrado)
               strcpy(estu[i].flag, "Female");
               strcpy(estu[i].grado, "Pregrado");
           } else if ((estu[i].booleano & 192) == 64){ //Se realiza mascara de bit para ver si da 0100000 (0: Masculino y 1: posgrado)
               strcpy(estu[i].flag, "Male");
               strcpy(estu[i].grado, "Posgrado");
           } else {                                    //Se realiza mascara de bit para ver si da 0100000 (0: Masculino y 0: pregrado)
               strcpy(estu[i].flag, "Male");
               strcpy(estu[i].grado, "Pregrado");
           }




       fread(&estu[i].nombre_estudiante, 23, 1, datos);
       fread(&estu[i].edad, 4, 1, datos);
       // fseek(datos, 4 , SEEK_CUR); //Toca tener en cuenta


       // if(edad_min <= estu[i].edad && estu[i].edad <= edad_max){
          
       // }
      
   }
   pos = ftell(datos);
   // aqui vemos en que posicion esta actualmente.ç


   // printf("El cursor esta en la %d \n",pos);


   // ESTRUCTURA CURSOS
   fseek(datos, 32014, SEEK_SET);


   for(int i = 0; i < cant_cursos; i = i + 1){
       fread(&curso[i].curso_id, 4, 1, datos);
       fread(&curso[i].curso_name, 32, 1, datos);
       fread(&curso[i].curso_horas, 4, 1, datos);
       //fseek(datos, 4 , SEEK_CUR); //Toca tener en cuenta


       // if(edad_min <= estu[i].edad && estu[i].edad <= edad_max){
          
       // }
      
   }


   pos = ftell(datos);


   // printf("El cursor despues de los cursos esta en: %d", pos);
  
   // ESTRUCTURA MATRICULAS
   fseek(datos, 34014, SEEK_SET); //A este no toco restarle 4


   for(int i = 0; i < cant_matriculas; i = i + 1){


       fread(&matriculas[i].ID_estudiante, 4, 1, datos);
       fread(&matriculas[i].curso_id, 4, 1, datos);
       fread(&matriculas[i].year, 4, 1, datos);
       fread(&matriculas[i].semester, 4, 1, datos);
      
   }


   //CONDICIONALES Y BUBLES PARA ENCONTRAR LA EDAD DE LOS ESTUDIANTES


   for(int i = 0; i < cant_cursos; i = i + 1) {


   for(int j = 0; j < cant_matriculas; j = j + 1){


       if(curso[i].curso_id == matriculas[j].curso_id){

           // printf("Encontrado: curso_id=%d, estudiante_id=%d, matricula id studiante: %d\n", curso[i].curso_id, estu[k].ID_estudiante, matriculas[j].ID_estudiante);

           for(int k = 0; k <cant_estudiantes ; k = k +1){
              
               if(estu[k].ID_estudiante == matriculas[j].ID_estudiante){ // Utilizar ID_estudiante en lugar de ID_student
               //Cantidad de estudiantes en ese curso
               curso[i].cant_estudiantes_curso = curso[i].cant_estudiantes_curso + 1;
               //Edad total de estudiantes en el curso
               curso[i].edad_curso = estu[k].edad + curso[i].edad_curso;


               // printf("Hola \n");


               //     printf("Encontrado: curso_id=%d, estudiante_id=%d, matricula id studiante: %d\n", curso[i].curso_id, estu[k].ID_estudiante, matriculas[j].ID_estudiante);
               }
           }
       }
   }
   }

   //Primero sacamos el año minimo y maximo
  
   int min_year = matriculas[0].year;
   int max_year = matriculas[0].year;


   for (int i = 1; i < cant_matriculas; i++) {
       if (matriculas[i].year < min_year) {
           min_year = matriculas[i].year;
       } else if (matriculas[i].year > max_year) {
       max_year = matriculas[i].year;
       }
   }


   int min_semester = matriculas[0].semester;
   int max_semester = matriculas[0].semester;


   for (int i = 1; i < cant_matriculas; i++) {
       if (matriculas[i].semester < min_semester) {
           min_semester = matriculas[i].semester;
       } else if (matriculas[i].semester > max_semester) {
       max_semester = matriculas[i].semester;
       }
   }


   int min_id_student = matriculas[0].ID_estudiante;
   int max_id_student = matriculas[0].ID_estudiante;


   for (int i = 1; i < cant_matriculas; i++) {
       if (matriculas[i].ID_estudiante < min_id_student) {
           min_id_student= matriculas[i].ID_estudiante;
       } else if (matriculas[i].ID_estudiante > max_id_student) {
       max_id_student = matriculas[i].ID_estudiante;
       }
   }

   //printf("%d %d %d %d %d %d \n",min_year, max_year, min_semester, max_semester, min_id_student, max_id_student);




    // Inicializar un conjunto de bits para mantener un registro de los ID de estudiantes únicos

    printf("Year     Semester    Male Undergrad   Female Undergrad  Male Grad Female Grad \n");

    for (int ano = min_year; ano <= max_year; ano++) {

        for (int semestre = min_semester; semestre <= max_semester; semestre++) {

            int estudiantes_contados[cant_estudiantes];

            memset(estudiantes_contados, 0, cant_estudiantes*sizeof(int));
                //int estudiantes_contados[cant_estudiantes];
            int contador = 0;
            int contador2 = 0;
            int contador3 = 0;
            int contador4 = 0;
            
            for (int i = 0; i < cant_matriculas; i++) {

                           
                
                
                if (matriculas[i].year == ano && matriculas[i].semester == semestre) {
                    
                    
                    
                    // Verificar si este ID de estudiante aún no ha sido contado

                    if (!estudiantes_contados[matriculas[i].ID_estudiante-1]) {

                        // Marcar este ID de estudiante como contado

                        estudiantes_contados[matriculas[i].ID_estudiante-1] = 1;

                        // Buscar al estudiante correspondiente en la estructura de estudiantes
                        for (int j = 0; j < cant_estudiantes; j++) {

                            if (estu[j].ID_estudiante == matriculas[i].ID_estudiante) {

                                // Verificar si el estudiante es "Male" y "Pregrado"

                                if ((strcmp(estu[j].flag, "Male") == 0) && (strcmp(estu[j].grado, "Pregrado") == 0)) {
                                    contador++;

                                    // No necesitamos continuar buscando más estudiantes para esta matrícula
                                    break;
                                }   else if ((strcmp(estu[j].flag, "Female") == 0) && (strcmp(estu[j].grado, "Pregrado") == 0))
                                {
                                    contador2++;
                                    break;
                                } else if ((strcmp(estu[j].flag, "Male") == 0) && (strcmp(estu[j].grado, "Posgrado") == 0))
                                {
                                    contador3++;
                                    break;
                                } else if ((strcmp(estu[j].flag, "Female") == 0) && (strcmp(estu[j].grado, "Posgrado") == 0))
                                {
                                    contador4++;
                                    break;
                                }
                                
                            }
                        }
                    }
                    
                }
                //printf("Año: %d, Semestre: %d, MP: %d FP %d MPos: %d FPos: %d \n", ano, semestre, contador, contador2, contador3, contador4);
            }

            printf("%-8d %-11d %-16d %-17d %-9d %d \n", ano, semestre, contador, contador2, contador3, contador4);
        }
    }




   fclose(datos);


   return 0;
}