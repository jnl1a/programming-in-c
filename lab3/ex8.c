//lab3 ex8
#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

void process_text(const char *input_text); 

int main() {
    char input_text[1024];

    printf("Enter text to process: ");
    if (fgets(input_text, sizeof(input_text), stdin) != NULL) { 
        process_text(input_text); 
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}

void process_text(const char *input_text) {
    int errors = 0;
    const char *delimiters = " \t\n"; 
    char text_copy[1024];
    
    strncpy(text_copy, input_text, sizeof(text_copy) - 1);
    text_copy[sizeof(text_copy) - 1] = '\0'; 

    // flag variable to check for repeated spaces
    int prev_space = 0; //updated to 1 when there's a repeated space

    // Scan through the input text to check for repeated spaces and process words
    for (int i = 0; input_text[i] != '\0'; i++) { //loop until it reaches \0
        char current_char = input_text[i];
        // Check for repeated spaces -> compare current found space with previous character
        if (isspace(current_char)) {
            if (prev_space) {
                printf("Warning: Repeated spaces detected.\n");
                errors++;
            }
            prev_space = 1; // Mark that we've seen a space
        } else {
            prev_space = 0; // Reset when we encounter a non-space character
        }
        // Process each word from the text copy
        if (current_char == ' ' || current_char == '\n') { //when found a space or newline, word is processed using strtok()

            // We check for words between spaces
            char *word = strtok(text_copy, delimiters);
            while (word != NULL) {
                
                // Check for words longer than 10 characters and without a hyphen
                if (strlen(word) > 10 && strchr(word, '-') == NULL) {
                    printf("Warning: '%s' is longer than 10 characters and does not contain a hyphen.\n", word);
                    errors++;
                }
                
                // Check for uppercase characters beyond the first one
                for (int i = 1; word[i] != '\0'; i++) { 
                    if (isupper(word[i])) {
                        printf("Warning: '%s' contains uppercase characters beyond the first one.\n", word);
                        errors++;
                        break;
                    }
                }
                
                // Check for words starting with a non-alphabetic character
                if (!isalpha(word[0])) { 
                    printf("Warning: '%s' starts with a non-alphabetic character.\n", word);
                    errors++;
                }
                
                //MODIFICATION
                // Check for punctuation preceded by a space
                for (int i = 0; word[i] != '\0'; i++) {
                    if (isspace(word[i]) && ispunct(word[i + 1])) {
                        printf("Warning: '%s' has punctuation preceded by a space.\n", word);
                        errors++;
                        break;
                    }
                }
                // Move to the next word
                word = strtok(NULL, delimiters);
            }//while
        }//if
    }//for
    
    // Display the total number of errors
    if (errors == 0) {
        printf("No errors found.\n");
    } else {
        printf("%d errors found.\n", errors);
    }
}