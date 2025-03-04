#include <stdio.h>

int fahr_to_celsius(int fahr);

// print Farenheit-Celsius table
// for fahr = 0, 20, ..., 300
// modified to call a function for conversion
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
    celsius = fahr_to_celsius(fahr);
    printf("%9.0f\t%7.2f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

int fahr_to_celsius(int fahr) {
  return (5.0/9.0) * (fahr-32.0);
}