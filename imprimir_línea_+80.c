#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int get_line(char line[], int maxline);

int main(void)
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    if (len>= LIMIT) 
    {
      printf("%s", line);
    }

    printf("line_length: %d\n", len);
  }

  return 0;
}

int get_line(char line[], int maxline)
{
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
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