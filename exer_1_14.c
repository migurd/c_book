// Instruction:
//   Write a program to print a histogram of the frequencies of different characters in its input

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char c;
  int amount;
} Character;

int main() {
  char c;
  int counter = 0;
  Character *ch_obj = (Character *) malloc(0 * sizeof(Character));
  if (ch_obj == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  // delete character wasn't taken into consideration
  while ((c = getchar()) != EOF) {
    int found = 0;
    
    // if element already exists
    for (int i = 0; i < counter; i++) {
      if (c == ch_obj[i].c) {
        ++ch_obj[i].amount;
        found = 1;
        break;
      }
    }
    
    // if character not found, then it's added to the obj list
    if (!found) {
      ++counter;
      Character *new_obj = (Character *) realloc(ch_obj, counter * sizeof(Character));
      if (new_obj == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
      }
      ch_obj = new_obj;
      ch_obj[counter-1].c = c;
      ch_obj[counter-1].amount = 1;
    }
  }

  // histogram
  // find highest value
  int highest = 0;
  for (size_t i = 0; i < counter; i++)
    if (ch_obj[i].amount > highest)
      highest = ch_obj[i].amount;
  // printf("%d\n", highest);
  // printf * of each in vertical
  for (size_t i = 0; i < highest; i++) {
    for (size_t j = 0; j < counter; j++) {
      char v = ' ';
      if (ch_obj[j].amount >= highest-i)
        v = '*';
      printf("%-3c", v);
    }
    printf("\n");
  }
  // print field names
  for (size_t i = 0; i < counter; i++)
    printf("%-3c", ch_obj[i].c);
  return 0;
}
