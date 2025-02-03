//lab5 ex6
#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 10  // Maximum number of strings
#define MAX_LENGTH 100  // Maximum length of each string

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];  // Array to store strings
    int num_strings = 0;  // To keep track of how many strings were entered
    char suffix[MAX_LENGTH];  // To store the suffix to append
    int index;  // To store the index of the string to append the suffix to
    
    // Request and store a sequence of input strings
    printf("Enter up to %d strings (enter an empty string to stop):\n", MAX_STRINGS);
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("String %d: ", i + 1);
        fgets(strings[i], MAX_LENGTH, stdin);
        
        // Remove the newline character if present
        strings[i][strcspn(strings[i], "\n")] = '\0';
        
        if (strlen(strings[i]) == 0) {  // Stop if the user enters an empty string
            break;
        }
        num_strings++;
    }

    // Check if any strings were entered
    if (num_strings == 0) {
        printf("No strings were entered. Exiting...\n");
        return 1;
    }

    // Prompt the user to enter a suffix to append
    printf("Enter the suffix to append: ");
    fgets(suffix, MAX_LENGTH, stdin);
    
    // Remove the newline character if present in suffix
    suffix[strcspn(suffix, "\n")] = '\0';

    // Ask the user which string to append the suffix to
    printf("Enter the index (1 to %d) of the string to append the suffix to: ", num_strings);
    scanf("%d", &index);

    // Validate the index
    if (index < 1 || index > num_strings) {
        printf("Invalid index! Exiting...\n");
        return 1;
    }

    // Append the suffix to the selected string
    // Ensure that the suffix doesn't exceed the maximum allowed length
    if (strlen(strings[index - 1]) + strlen(suffix) < MAX_LENGTH) {
        strcat(strings[index - 1], suffix);
        printf("Updated string: %s\n", strings[index - 1]);
    } else {
        printf("Suffix is too long to append to the selected string.\n");
    }

    return 0;
}
