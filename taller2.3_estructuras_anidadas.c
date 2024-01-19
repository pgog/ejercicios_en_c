//Punto 3: Estructuras Anidadas
//3.1. Crea una nueva estructura llamada Direccion que tenga campos para la calle y la ciudad (cadenas de caracteres).
#include <stdio.h>
#include <string.h>

struct Direccion{
    char calle [20];
    char ciudad[20];
};

//3.2. Agrega un campo direccion a la estructura Persona que sea del tipo Direccion.


struct Persona{
	char nombre[30];
	int edad;
    struct Direccion direccion; //hay un campo llamado direccion que es del tipo Direccion. Esto significa que cada instancia de la estructura Persona tiene asociada consigo misma una instancia de la estructura Direccion.
    
};

//3.3. Declara e inicializa una variable de tipo Persona con valores de tu elección, incluyendo la dirección. Imprime todos los detalles de la persona, incluida su dirección.
int main(){
	struct Persona p1;
	strcpy(p1.nombre, "Pamela GG");
	p1.edad= 27;
	strcpy(p1.direccion.calle, "Calle 45");
	strcpy(p1.direccion.ciudad, "Medellín");

	printf("Los valores del Struct son nombre %s, edad %d, calle %s y ciudad %s\n", p1.nombre, p1.edad, p1.direccion.calle, p1.direccion.ciudad);

	
return 0;

}