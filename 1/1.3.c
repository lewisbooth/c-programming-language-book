#include <stdio.h>

// print Farenheit-Celsius table
// for fahr = 0, 20, ..., 300
// modified to print a heading
int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Farenheit\tCelsius\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%9.0f\t%7.2f\n", fahr, celsius);
    fahr = fahr + step;
  }
}