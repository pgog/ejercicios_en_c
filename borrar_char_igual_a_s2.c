
// Escriba una versión alterna de sq u e e z e(sl,s2 ) que borre cada carácter de s i que coincida con cualquier carácter de la cadena s2.

#include <stdio.h>

#define MAXSTR 1000

void squeeze(char str1[], char str2[]);

int main(void)
{
  char str1[MAXSTR];
  printf("INGRESE FRASE 1\n");
  fgets(str1, MAXSTR, stdin); // Se utiliza fgets para leer la línea

  char str2[MAXSTR];
  printf("INGRESE FRASE 2\n");
  fgets(str2, MAXSTR, stdin); // Se utiliza fgets para leer la línea


  squeeze(str1, str2);

  printf("%s\n", str1);

  return 0;
}

void squeeze(char str1[], char str2[])
{
  int i, j, k;
  for (k = 0; str2[k] != '\0'; ++k)
  {
    for (i = j = 0; str1[i] != '\0'; ++i)
    {
      if (str1[i] != str2[k])
      {
        str1[j++] = str1[i];
      }
    }

    str1[j] = '\0';
  }
}