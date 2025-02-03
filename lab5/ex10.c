//lab5 ex10
#include <stdio.h>
#include <stdlib.h>

//argc/argv are parameters of main function to handle command line arguements. allow to accept/process direct inputs when executed
//argc: integer representing the number of command-lines arguements (including program name)
//argv: array of pointers to char(strings)
//  argv[0] is program name, argv[1] to argv[argc-1] are more arguements from user

int main(int argc, char *argv[]) {
    // Check if exactly two arguments are provided
    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    // Convert arguments to numbers (strtod converts string to double)
    char *endptr1, *endptr2;
    double num1 = strtod(argv[1], &endptr1);
    double num2 = strtod(argv[2], &endptr2);

    // Check if the arguments are valid numbers
    if (*endptr1 != '\0' || *endptr2 != '\0') {
        printf("Error: Both arguments must be valid numbers.\n");
        return 1;
    }

    // Calculate the sum
    double sum = num1 + num2;

    // Print the result
    printf("The sum of %g and %g is %g.\n", num1, num2, sum);

    return 0;
}

//commands to run from terminal: ./ex10 num1 num2