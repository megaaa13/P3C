#include <stdio.h>

void format_str(char *buffer, unsigned int d, char *name, char initial) {
    sprintf(buffer, "Mister %s %c. has %d eggs", name, initial, d);
}

void print_digit(int number) {
    printf("The magic number is %d.\n", number);
}

// Floating away : 3.1416 (pi avec 4 décimale (.4f))

void print_foo() {
    printf("foo\n");
}

void format_str(char *buffer, unsigned int d, char *name, char initial) {
    sprintf(buffer, "Mister %s %c. has %d eggs", name, initial, d);
}