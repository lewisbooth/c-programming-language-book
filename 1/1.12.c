#include <stdio.h>

#define WORD  0
#define GAP   1

// Print input with one word on each line
int main ()
{
  int c = 0;
  int prev = GAP;
  
  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\t' || c == '\n')) {
      if (prev == WORD) {
        putchar('\n');
        prev = GAP;
      }
    }
    else {
      putchar(c);
      prev = WORD;
    }
  }
}