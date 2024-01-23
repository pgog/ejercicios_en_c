#include <stdio.h>
#include <string.h>

struct clientes{
    char nombre[20];
    char apellido[40];
    long celular;

};

void mostrar_datos(struct clientes *c){
    printf("El nombre es %s %s y el nùmero de celular es %ld", c->nombre,c->apellido,c->celular);
}

int main(){
    struct clientes c1;
    strcpy(c1.nombre, "Pamela");
    strcpy(c1.apellido,"Gonzalez Gomez");
    c1.celular=3113489513;
    mostrar_datos(&c1);

    return 0;
}

