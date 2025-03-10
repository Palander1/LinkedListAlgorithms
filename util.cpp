#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, double *Key) {
    scanf("%s", Word);

    // Instructions that do not require a key
    if (strcmp(Word, "Stop") == 0 ||
        strcmp(Word, "Print") == 0 ||
        strcmp(Word, "Max") == 0 ||
        strcmp(Word, "Min") == 0 ||
        strcmp(Word, "Sum") == 0 ||
        strcmp(Word, "Length") == 0 ||
        strcmp(Word, "Read") == 0 ||
        strcmp(Word, "Write") == 0 ||
        strcmp(Word, "Release") == 0) {
        return 1;
    }

    // Instructions that require a numeric key
    if (strcmp(Word, "Search") == 0 ||
        strcmp(Word, "Insert") == 0 ||
        strcmp(Word, "Append") == 0 ||
        strcmp(Word, "Delete") == 0) {
        return scanf("%lf", Key) == 1;
    }

    return 0; // Invalid instruction
}
