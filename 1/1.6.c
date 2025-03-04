#include <stdio.h>

// Verify that the expression "getchar() != EOF is 0 or 1"
int main ()
{
  int c;

  while (c != EOF) {
    putchar(c);
    c = getchar();
    printf("%d\n", c != EOF);
  }
}