// Instruction:
//   How would you test the word count program? What kinds of input are mos tlikely to uncover bugs if there are any?

// I can't think a potential bug. I imagine everything is straightforward
// It starts reading and counting every space of a file, once it finds a first non-blank, non-tab or not-newline it counts it as a word,
// then once it finds one of the characters found, it stops counting as a word, and then the two step previous step repeats until the file reaches EOF
#include <stdio.h>

// symbollic constants
#define IN  1
#define OUT 0

int main() {
  FILE *fin = fopen("exer_1_11.c", "r");
  if (fin == NULL) {
    perror("File couldn't be opened");
    return 1; // returned 1, which means something bad happened and notified app
  }
 
  // word counter, characters count and newline count
  int wc, cc, nlc, state;
  char c;

  state = OUT;
  wc = cc = nlc = 0;

  while(fscanf(fin, "%c", &c) != EOF) {
    ++cc;
    if ('\n' == c)
      ++nlc;
    if ('\n' == c || ' ' == c || '\t' == c)
      state = OUT;
    else if (OUT == state) {
      state = IN;
      wc++;
    }
  }
  printf("%10s%10s%10s\n", "Word Cou", "Char Cou", "New Line");
  printf("%10d%10d%10d\n", wc, cc, nlc);

  fclose(fin);
  return 0;
}
