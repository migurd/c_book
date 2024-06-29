#include <stdio.h>

// Instructions:
//   Write a program to count blanks, tabs, and newlines

int main() {
  int bc, tc, nlc;
  char c;
  
  bc = tc = nlc = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ') ++bc;
    if (c == '\t') ++tc;
    if (c == '\n') ++nlc;
  }
  printf("%5s%5s%5s\n", "Bla", "Tab", "New");
  printf("%5d%5d%5d\n", bc, tc, nlc);
  return 0;
}
