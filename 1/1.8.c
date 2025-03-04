#include <stdio.h>

// Count the blanks, tabs and newlines in input
int main ()
{
  int c, blanks = 0, tabs = 0, newlines = 0;
  
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++blanks;    
    if (c == '\t')
      ++tabs;
    if (c == '\n')
      ++newlines;
  }
  
  printf("Blanks\t\t%d\n", blanks);
  printf("Tabs\t\t%d\n", tabs);
  printf("Newlines\t%d\n", newlines);
}