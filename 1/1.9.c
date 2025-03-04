#include <stdio.h>

// Copy input to output, replacing strings of multiple blanks with one blank
int main ()
{
  int c, blank = 0;
  
  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
      blank = 0;
    }
    if (c == ' ' && blank == 0) {
      putchar(c);
      blank = 1;
    } 
  }
}