//lab3 ex9
#include <stdio.h>
#include <stdlib.h> // functions for memory allocation and conversions
#include <ctype.h>

#define MIN_RANGE -10.0 
#define MAX_RANGE 10.0  
#define MAX_LINE 1024   // Maximum line length for error handling

void processNumbers(const char *outputFile);

int main() {
    const char *outputFileName = "output.txt";
    processNumbers(outputFileName);
    return 0;
}

void processNumbers(const char *outputFile) {
    FILE *outFile = fopen(outputFile, "w"); // opens for writing
    if (!outFile) {
        // error handling
        fprintf(stderr, "Error: Could not open output file '%s' for writing.\n", outputFile); 
        exit(EXIT_FAILURE);
    }

    printf("Enter real numbers separated by spaces (Ctrl+C to exit):\n");

    char inputLine[MAX_LINE];
    while (fgets(inputLine, sizeof(inputLine), stdin)) { // processing user input of string
        char *ptr = inputLine; // parsing, current position
        char *endPtr; // end position of parsing
        while (*ptr != '\0') {
            // Skip leading whitespace
            while (isspace(*ptr)) ptr++;

            // Attempt to parse a double
            double number = strtod(ptr, &endPtr);

            // If parsing failed
            if (ptr == endPtr) {
                if (*ptr != '\0') {
                    fprintf(stderr, "Error: Invalid input '%c' ignored.\n", *ptr);
                }
                ptr++;
                continue;
            }

            // validate number
            if (number >= MIN_RANGE && number <= MAX_RANGE) {
                fprintf(outFile, "%f\n", number);
            } else {
                fprintf(stderr, "Warning: Number '%f' is out of range.\n", number);
            }

            // updating pointer
            ptr = endPtr;
        }
    }

    fclose(outFile);
    printf("Processing complete. Valid numbers saved to '%s'.\n", outputFile);
}
