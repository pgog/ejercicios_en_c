#include <stdio.h>

int main()
{
    /*Fist hello word in C language*/
    printf("Hello Platzi");
    return 0;
}

Basic Types: 32,768
    Aritmeticos:
    (A) Valores enteros:
        int 2 o 4 Bytes permite tener numeros negativos y positivos
            2 Bytes -32,768 to 32,757
            4 bytes -2,147,483,648 to 2,147,483
        unsigned int 2 o 4 bytes no nos permite tener datos negativos
            2 Bytes 0 to 65.535
            4 bytes 0 to 4,294,967,295
        long 8 Bytes
            -9223372036854775808 to 9223372036854775807
        unsigned long 8 Bytes 
            0 to 18446744073709551615

    (B) De punto FLorante:

        float 4 Bytes 1.2E-38 to 3.4E+386 ( 6 decimal places)
        double 8 Bytes 2.3E-308 to1.7E+30815 (15 decimal places)
        long double 10 Bytes 3.4E-4932 to 1.1E+493219 (19 decimal places)

        void: No hay valor disponible, se usa en 3 casos:
        1. -Función retorna un tipo de datos void
            void funcion()
        2. -Funciòn tiene argumentos tipo void no acepta ningun parametro
            int danf(void)
        3. -Puntero o apuntador que va a la direcciòn en memoria de un objeto, pero no le importa el tipo de dato que tenga
        