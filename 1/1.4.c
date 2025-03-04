#include <stdio.h>

// print Celsius-Farenheit table
// for fahr = 0, 20, ..., 300
// modified to swap Celsius and Farenheit
int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("Celsius\tFarenheit\n");
  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%7.0f\t%9.2f\n", celsius, fahr);
    celsius = celsius + step;
  }
}