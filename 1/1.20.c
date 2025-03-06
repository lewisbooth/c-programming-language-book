#include <stdio.h>
#define TABWIDTH 4
#define MAXLINE  1000

int detab(char line[], int maxline);

// Replace all tabs with blanks to next tab stop
// Blanks are represented by '.' for visibility
int main()
{
  int len;
  char line[MAXLINE];

  while ((len = detab(line, MAXLINE)) > 0)
    printf("%s", line);
  printf("%s", "\n");
  return 0;
}

int detab(char s[], int limit)
{
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    if (c == '\t') {
      int spaces = TABWIDTH - (i % TABWIDTH);
      for (int j = 0; j < spaces; j++) {
        s[i] = '.';
        i++;
      }
      i--;
    } else {
      s[i] = c;
    }
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  // Null terminate the string
  s[i] = '\0';
  return i;
}