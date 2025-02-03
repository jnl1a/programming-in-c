//lab5 ex4
#include <stdio.h>

int sum(int *start, int *end) {
    int total = 0;
    while (start < end) {
        total += *(start++); // dereference, *start, and increment, start++, in same expression
    }
    return total;
}
