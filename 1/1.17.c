#include <stdio.h>
#define MINLENGTH 10
#define MAXLINE   1000

int get_line(char line[], int maxline);

// Print all input lines longer than MINLENGTH characters
int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > MINLENGTH) {
      printf("Count: %d\n%s\n", len - 1, line);
    }
  return 0;
}

int get_line(char s[], int limit)
{
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  // Null terminate the string
  s[i] = '\0';
  return i;
}