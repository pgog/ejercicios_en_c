#include <stdio.h>

float promedio(int niveles[], int n){
    int j;
    float acum=0;
    for ( j = 0; j < n; j++){
        acum += niveles[j];
    }
    return acum/n;
}

int main(int argc, char const *argv[])
{
    int n, i;
    printf("¿cuántos niveles son?");
    scanf("%d", &n);
    int niveles[n];
    for (i=0;i<n;i++){
        printf("Agrege calificaciòn para la posiciòn %d\n", i+1);
        scanf("%d", &niveles[i]);
    }
    printf("Las calificaciones fueron:\n");
    for ( i = 0; i < n; i++)
    {
        printf("Para el nivel %d: %d\n", i+1, niveles[i]);
    }

    printf("El promedio de la calificación es: %f", promedio(niveles, n));
    

    return 0;
}
