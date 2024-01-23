#include <stdio.h>

// Escriba un program a p ara determ inar los rangos de variables char, short, int y lo n g , tanto sig n ed com o u n sig n e d , im prim iendo los valores apropia­ dos de los heciders estándar y por cálculo directo. Es más difícil si los calcula: de­ termine los rangos de los varios tipos de p unto flotante.

#include <limits.h>

int main()
{
    // Char
    printf("CHAR\n");
    printf("El valor de cada char es de %d bite\n", CHAR_BIT);
    printf("Unsigned char es %d\n", UCHAR_MAX);
    printf("Valor máx es %d, el minimo es %d\n", SCHAR_MAX, SCHAR_MIN);
    printf("\n");
    // int
    printf("INT\n");
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("signed int min: %d\n", INT_MIN);
    printf("signed int max: %d\n", INT_MAX);
    printf("\n");

    // Short
    printf("SHORT INT\n");
    printf("Unsigned short int es %d\n", USHRT_MAX);
    printf("Valor máx es %d, el minimo es %d\n", SHRT_MAX, SHRT_MIN);
    printf("\n");

    //LONG    
    printf(" LONG INT\n");
    printf("unsigned long int ES: %lu\n", ULONG_MAX);
    printf("Valor máx es %ld, el minimo es %ld\n", LONG_MAX, LONG_MIN);
    printf("\n");

    printf(" LONG LONG INT \n");
    printf("unsigned long long int max: %llu\n", ULLONG_MAX);
    printf("signed long long int min: %lld\n", LLONG_MIN);
    printf("signed long long int max: %lld\n", LLONG_MAX);
    printf("\n");

    return 0;


}