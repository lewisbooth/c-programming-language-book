#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

// Print the longest line input line, and as much text as possible (MAXLINE)
int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)
    printf("Count: %d\n%s\n", max - 1, longest);

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
  // Continue incrementing counter until we reach the end of the line
  if (c != '\n' && c != EOF) {
    while ((c = getchar()) != EOF && c != '\n')
      i++;
    i++;
  }
  return i;
}

void copy(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    i++;
}