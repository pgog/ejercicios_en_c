#include <stdio.h>


int main(){
    int number, potencia, resultado, digitos, modulo;
    number= potencia= resultado = digitos =modulo =0;
    printf("Ingrese el número\n");
    scanf("%d", &number);

    while (modulo !=0){
        modulo=number%10;
        printf("%d\n ", modulo);
        digitos++;
    }
    printf("%d\n", digitos);

    
}