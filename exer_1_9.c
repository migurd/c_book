#include <stdio.h>

// Instructions:
//   Write a program to copy its input to its output replacing each string of one or more blanks by a single blank

int main() {
  char c[100];
  int i = 0;

  // write input
  printf("Input: ");
  while ((c[i] = getchar()) != EOF)
  {
    if (c[i] > 0 && c[i] == '\b') --i;
    else ++i;
  }
  printf("\n");

  // trim
  printf("Output: ");
  i = 0;
  int is_white_space = 0;
  while (c[i] != '\0')
  {
    if (c[i] == 0)
      for (; c[i] == ' '; i++)
        ;
    if (c[i] != ' ') {
      putchar(c[i]);
      is_white_space = 0;
    }
    if (c[i] == ' ') {
      if (!is_white_space) {
        is_white_space = 1;
        putchar(c[i]);
      }
    }
    i++;
  }
  printf("\n");
  return 0;
}
