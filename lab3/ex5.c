//lab3 ex5
#include <stdio.h>

#define MAX_NUMBERS 20   // Maximum number of numbers that can be entered
#define MIN_VALUE 1     // Minimum valid number
#define MAX_VALUE 100   // Maximum valid number

float mean(int num_count, int numbers[]){
    float sum = 0;
    for(int i =0; i<num_count; i++){
        sum += numbers[i];
    }
    float mean = sum/num_count;
    return mean;
}

void mode(int num_count, int numbers[]){ //assumed that the list of numbers is already sorted
    int mode = numbers[0]; //forst element starts as mode
    int mode_count = 1;
    int current_count = 1; //tracks the count of the current number being examined

    // Loop through the sorted list and count occurrences
    for (int i = 1; i < num_count; i++) {
        if (numbers[i] == numbers[i - 1]) {
            // Increment count for the current number
            current_count++;
        } else {
            // If the current number sequence ends, check if it had the highest count
            if (current_count > mode_count) {
                mode_count = current_count;
                mode = numbers[i - 1];
            }
            // Reset count for the new number
            current_count = 1;
        }
    }

    // Final check at the end of the list in case the most frequent number is the last one
    if (current_count > mode_count) {
        mode_count = current_count;
        mode = numbers[num_count - 1];
    }

    // Output the mode and its count
    printf("Mode: %d (appears %d times)\n", mode, mode_count);
}

float median(int num_count, int numbers[]){
    if (num_count % 2 == 1) {
        return numbers[num_count / 2];  // Odd count: median is the middle element
    } else {
        return (numbers[num_count / 2 - 1] + numbers[num_count / 2]) / 2.0;  // Even count: average of two middle elements
    }
}

int main() {
    int numbers[MAX_NUMBERS];  // Array to store up to 20 numbers
    int num_count = 0;         // To keep track of how many numbers have been entered
    int num;

    printf("Enter up to 20 numbers between %d and %d in ascending order:\n", MIN_VALUE, MAX_VALUE);

    while (num_count < MAX_NUMBERS) {
        printf("Enter number %d: ", num_count + 1);
        scanf("%d", &num);

        // Check if the number is within the valid range
        if (num < MIN_VALUE || num > MAX_VALUE) {
            printf("Invalid number. Please enter a number between %d and %d.\n", MIN_VALUE, MAX_VALUE);
            continue;  // Skip to the next iteration if the number is invalid
        }

        // If it's the first number or the current number is greater than or equal to the previous one, add it to the list
        if (num_count == 0 || num >= numbers[num_count - 1]) {
            numbers[num_count] = num;
            num_count++;
        } else {
            printf("The numbers must be in ascending order. Try again.\n");
        }

        // Ask the user if they want to continue entering numbers
        if (num_count >= MAX_NUMBERS) {
            break;  // Stop if the user has entered the maximum number of numbers
        }

        printf("Would you like to enter another number? (1 for yes, 0 for no): ");
        int continue_input;
        scanf("%d", &continue_input);
        
        if (continue_input == 0) {
            break;
        }
    }

    // Print the entered numbers
    printf("\nYou entered the following numbers in ascending order:\n");
    for (int i = 0; i < num_count; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    // Calculate and display mean, mode, and median
    float mean_value = mean(num_count, numbers);
    printf("Mean: %.2f\n", mean_value);

    mode(num_count, numbers);

    float median_value = median(num_count, numbers);
    printf("Median: %.2f\n", median_value);

    return 0;
}
