#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Instruction:
//   Write a program to copy its input to its output, replacing each tab by \t,
//   each backspace by \b and each backslash by \\. This makes tabs and backspaces visibles

// Function to set terminal to raw mode
void set_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Function to restore terminal to original mode
void reset_terminal_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);  // Enable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int main() {
  char c;

  set_raw_mode();
  atexit(reset_terminal_mode);  // Ensure terminal is reset on exit

  for (int i = 0; (c = getchar()) != EOF; i++)
  {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\b' || c == 127) {
      putchar('\\');
      putchar('b');
    }
    else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    }

    else putchar(c);

  }
  return 0;
}
