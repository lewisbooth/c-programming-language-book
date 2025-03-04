#include <stdio.h>
#define MAXLINE   1000

int reverse(char line[], char reversed[], int maxline);

// Reverse all input lines
int main()
{
  int length;
  char line[MAXLINE];
  char reversed[MAXLINE];

  while ((length = reverse(line, reversed, MAXLINE)) > 0)
    printf("%s", reversed);
    
  return 0;
}

int reverse(char line[], char reversed[], int limit)
{
  int c, i, j, length;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
    line[i] = c;
  length = i;
  if (c == '\n') {
    line[i] = '\n';
    // Skip empty lines but continue the program
    if (length == 0)
      length = 1;
  }
  for (j = 0; j < length; j++) {
    i--;
    reversed[j] = line[i];
  }
  reversed[j] = '\n';
  reversed[j+1] = '\0';
  return length;
}