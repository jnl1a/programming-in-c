#include <stdio.h>
#include <math.h>

// Using math.h functions to transform x
void applyCeil(double *x, int useMathFn) {
    if (useMathFn) {
        // Using math.h functions
        *x = ceil(*x);  
    } else {
        // Manually
        int integer = (int)(*x);  // Convert to integer (truncate)
        if (*x > integer) {
            *x = integer + 1;  // If there's a fractional part, increment by 1
        } else {
            *x = integer;  // assign the integer part
        }
    }
}

void applyFloor(double *x, int useMathFn) {
    if (useMathFn) {
        // Using math.h functions
        *x = floor(*x); 
    } else {
        // Manually
        int integer = (int)(*x);  // Convert to integer (truncate)
        if (*x < integer) {
            *x = integer - 1;  // If there's a negative fractional part, decrement by 1
        } else {
            *x = integer;  // assign the integer part
        }
    }
}

/* commented for ex7
int main() {
    double num;
    int useMathFn;

    // Ask user whether to use math.h or manual method
    printf("Enter 1 for math.h functions, 0 for manual methods: ");
    scanf("%d", &useMathFn);

    // Input prompt
    printf("Enter a number for ceil: ");
    scanf("%lf", &num);

    // Apply ceil
    applyCeil(&num, useMathFn);
    printf("Result after applying Ceil: %.2f\n", num);

    // Re-initialize num for the next test
    printf("Enter another number for floor: ");
    scanf("%lf", &num);

    // Apply floor
    applyFloor(&num, useMathFn);
    printf("Result after applying Floor: %.2f\n", num);

    return 0;
}*/

void ex6(){
    double num;
    int useMathFn;

    // Ask user whether to use math.h or manual method
    printf("Enter 1 for math.h functions, 0 for manual methods: ");
    scanf("%d", &useMathFn);

    // Input prompt
    printf("Enter a number for ceil: ");
    scanf("%lf", &num);

    // Apply ceil
    applyCeil(&num, useMathFn);
    printf("Result after applying Ceil: %.2f\n", num);

    // Re-initialize num for the next test
    printf("Enter another number for floor: ");
    scanf("%lf", &num);

    // Apply floor
    applyFloor(&num, useMathFn);
    printf("Result after applying Floor: %.2f\n", num);
}