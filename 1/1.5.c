#include <stdio.h>

// print Celsius-Farenheit table
// for fahr = 300, 280, ..., 0
// modified to swap the direction from high to low
// and to use #define and for loop

#define   LOWER   0
#define   UPPER   300
#define   STEP    20

int main()
{
  float celsius;

  printf("Celsius\tFarenheit\n");
  for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP)
    printf("%7.0f\t%9.2f\n", celsius, (9.0/5.0) * celsius + 32.0); 
}