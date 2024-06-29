#include <stdio.h>

// Instruction:
//   Veritfy that the expression getchar() != EOF is 0 or 1

int main(void) {
  printf("%d\n", getchar() != EOF); // ctrl+d unix and ctrl+z win
  // if input then 1, if ctrl+d then 0

  return 0; // when 0 returned then everything is aight, but when a different value is return, that means error. That's useful when u run C programs
}
