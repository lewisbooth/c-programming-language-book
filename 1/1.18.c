#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

// Remove leading and trailing blanks from each line of input
// Delete entirely blank lines
int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > 1)
      printf("%s", line);
  
  
  return 0;
}

int get_line(char s[], int limit)
{
  int c, i, j, leading, trailing;

  leading = 1; 
  trailing = j = 0;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    if (leading) {
      // Skip leading blanks
      if (c != ' ' && c != '\t') {
        s[j] = c;
        j++;
        leading = 0;
      }
    } else if (c == ' ' || c == '\t') {
      // Store the last index of a blank character
      if (!trailing)
        trailing = j;
      s[j] = c;
      j++;
    } else {
      // Otherwise copy to string
      trailing = 0;
      s[j] = c;
      j++;
    }
  }
  if (c == '\n') {
    s[j] = '\n';
    j++;
  }  
  // Null terminate the string
  if (trailing) {
    j = trailing;
    s[j] = '\n';
    j++;
    s[j] = '\0';
  } else {
    s[j] = '\0';
  }
  return j;
}