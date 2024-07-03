// Instruction:
//   Write a program to print a histogram of the lengths of words in its input.
//   It's easy to draw the histogram with the bars horizontal, a vertical orientation is more challenging

#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
  int arr[10] = {0}; // limit 10 characters
  char op;
  char c;
  int counter = 0;
  int state = OUT;

  printf("Vertical (V) or Horiziontal (H): ");
  op = getchar();

  printf("Input: ");
  while ((c = getchar()) != EOF) {
    if (' ' == c || '\n' == c || '\t' == c) {
      if (IN == state) 
        ++arr[counter-1]; // we save one position behind so it matches the starting point of 0
      counter = 0;
      state = OUT;
    }
    else {
      state = IN;
      counter++;
    }
  }

  int biggest = 0;
  switch (op) {
    case 'V':
      for (int i = 0; i < 10; i++)
        if (arr[i] > biggest) biggest = arr[i];
      for (int i = biggest; i > 0; i--) {
        for (int j = 0; j < 10; j++) {
          if (arr[j] >= i)
            printf("%3s", "*");
          else
            printf("%3s", " ");
        }
        printf("\n");
      }
      for (int i = 0; i < 10; i++)
        printf("%3d", i+1);
      printf("\n");
      break;
    case 'H':
      for (int i = 0; i < 10; i++) {
        printf("%-5i", i+1);
        for (int j = 0; j < arr[i]; j++)
          printf("*");
        printf("\n");
      }
      break;
  }
  return 0;
}
