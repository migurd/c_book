#include <stdio.h>

/*
print Fahrenheit-Celcsius table
  for fahr = 0, 20, ..., 280, 300
*/
int main() {
  float fahr, cels;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%3s%6s\n", "F", "C");
  while (fahr <= upper)
  {
    cels = (5.0/9.0) * (fahr - 32);
    printf("%3.0f%6.1f\n", fahr, cels);
    fahr += step;
  }
}
