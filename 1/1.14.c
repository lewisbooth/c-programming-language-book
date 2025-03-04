#include <stdio.h>
#include <ctype.h>

#define HORIZONTAL_BLOCK "▇"
#define ALPHABET_SIZE 26

// Print a histogram of the frequency of letters in the input
int main ()
{
  int c;
  int counts[ALPHABET_SIZE] = {0};

  while ((c = getchar()) != EOF) {
    c = tolower(c);
    if (c >= 'a' && c <= 'z') {
      counts[c - 'a']++;
    }
  }

  for (int i = 0; i < ALPHABET_SIZE; i++) {
    printf("%c: ", 'a' + i);
    for (int j = 0; j < counts[i]; j++) {
      printf(HORIZONTAL_BLOCK);
    }
    printf(" %d\n", counts[i]);
  }
}