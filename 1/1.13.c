#include <stdio.h>
#include <string.h>

#define MAX_COUNT 10
#define HORIZONTAL_BLOCK "▇"
#define VERTICAL_BLOCK "█"

// Print a histogram of the lengths of words in the input
// Use -v arg to switch between horizontal and vertical
int main (int argc, char *argv[])
{
  int c;
  int counts[MAX_COUNT + 1] = {0};
  int letterCount = 0;
  int vertical = 0;

  // Detect vertical flag -v
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[1], "-v") == 0) {
      vertical = 1;
    }
  }
  
  // Split into words
  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\t' || c == '\n')) {
      // Bounds check
      if (letterCount >= MAX_COUNT) {
        letterCount = MAX_COUNT;
      }
      // Increment result and reset count
      counts[letterCount]++;
      letterCount = 0;
    }
    else {
      letterCount++;
    }
  }
  
  // Handle the EOF
  counts[letterCount]++;

  // Render vertical histogram
  if (vertical) {
    int highestCount = 0;
    for (int i = 1; i <= MAX_COUNT; i++) {
      if (counts[i] > highestCount)
        highestCount = counts[i];
    }
    // Loop down from highest count
    for (int i = highestCount; i >= 0; i--) {
      // Print rows with spacers either side of bars
      for (int j = 1; j <= MAX_COUNT; j++) {
        printf(" ");
        if (counts[j] >= i)
          printf(VERTICAL_BLOCK);
        else
          printf(" ");
        printf(" ");
      }
      printf("\n");
    }
    // Print labels at the bottom
    for (int i = 1; i <= MAX_COUNT; i++) {
      if (i < MAX_COUNT)
        printf("%2d ", i);
      else
        // Add a + to MAX_COUNT bar
        printf("%2d+", i);
    }
    printf("\n");
  }
  // Render horizontal histogram
  else
    for (int i = 1; i <= MAX_COUNT; i++) {
      if (i == MAX_COUNT)
        // Add a + to MAX_COUNT row
        printf("%2d+:",i);
      else
        printf("%3d:",i);
      // Print histogram bars of "="
      for (int j = 0; j < counts[i]; j++)
        printf(HORIZONTAL_BLOCK);
      printf("\n");
    }

}