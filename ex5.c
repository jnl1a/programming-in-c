#include <stdio.h>

#define NUMBER_OF_ENTRIES 10 // Number of days to be entered by the user

int main() {
    int days[NUMBER_OF_ENTRIES]; // Array to store user-supplied days
    int weeks, remaining_days;

    printf("Enter %d numbers of days:\n", NUMBER_OF_ENTRIES);
    for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
        printf("Days [%d]: ", i + 1);
        scanf("%d", &days[i]);
    }

    // Output: Convert days into weeks and remaining days
    printf("\nDays converted into weeks and days:\n");
    for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
        weeks = days[i] / 7; // Calculate full weeks
        remaining_days = days[i] % 7; // Calculate remaining days
        printf("%d days = %d weeks and %d days\n", days[i], weeks, remaining_days);
    }

    return 0;
}