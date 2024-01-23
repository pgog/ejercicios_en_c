#include <stdio.h>

//Escriba un p rogram a que elimine los blancos y los tabuladores que estén al final de cada línea de en trad a, y que borre com pletam ente las líneas en blanco.

#define MAXLINE 1000

int get_line(char line[], int max_line_len);
void remove_trailing_blanks(char line[], int length);

int main(void)
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    remove_trailing_blanks(line, len);
    printf("%s", line);
  }

  return 0;
}

int get_line(char line[], int max_line_len)
{
  int c, i;

  for (i = 0; i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void remove_trailing_blanks(char line[], int length)
{
  int i;

  for (i = length - 2; i>=0 && (line[i] == ' ' || line[i] == '\t' || line[i]=='\n'); --i)
    ;

  line[i + 1] = '\n';
  line[i + 2] = '\0';
}