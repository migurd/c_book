#include <stdio.h>

/*
print Celsius-Fahrenheit table
  for cels = 0, 20, ..., 280, 300
*/
int main() {
  float fahr, cels;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  cels = lower;
  printf("%3s%6s\n", "C", "F");
  while (cels <= upper)
  {
    fahr = (9.0/5.0) * cels + 32;
    printf("%3.0f%6.1f\n", cels, fahr);
    cels += step;
  }
}
