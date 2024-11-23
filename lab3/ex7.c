//lab3 ex7
#include <stdio.h>
#include <ctype.h> // functions to test characters eg. isalpha()
#include <string.h> //str__() functions

void process_text(const char *input_text); //declaration of function

int main() {
    char input_text[1024];

    printf("Enter text to process: ");
    //fgets() <- used to read an entire line of input
    if (fgets(input_text, sizeof(input_text), stdin) != NULL) { //stdin <- file pointer pointing to input stream
        process_text(input_text); 
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}

void process_text(const char *input_text) {
    int errors = 0;
    const char *delimiters = " \t\n"; // Define word delimiters (spaces, tabs, newlines)
    char text_copy[1024];
    
    // Copy input text to avoid modifying the original
    strncpy(text_copy, input_text, sizeof(text_copy) - 1); // -1 to make sure there is space for the null terminator (no overflow)
    text_copy[sizeof(text_copy) - 1] = '\0'; // \0 <- sets last character to a null terminator
    //null terminator, \0 <- to mark the end of a string 
    
    // Tokenize the input text to process each word separately
    char *word = strtok(text_copy, delimiters);
    //strtok() = splits the text(sentence) into words based on delimiters ^(line24), it modifies the string it operates on
    // \0 insterted at the positions of the delimiters thus, cutting the string into words

    while (word != NULL) {
        
        // 1. Check for words longer than 10 characters and without a hyphen
        if (strlen(word) > 10 && strchr(word, '-') == NULL) {
            printf("Warning: '%s' is longer than 10 characters and does not contain a hyphen.\n", word);
            errors++;
        }
        
        // 2. Check for uppercase characters beyond the first one
        for (int i = 1; word[i] != '\0'; i++) { //starts checking from the second character
            if (isupper(word[i])) {
                printf("Warning: '%s' contains uppercase characters beyond the first one.\n", word);
                errors++;
                break;
            }
        }
        
        // 3. Check for words starting with a non-alphabetic character
        if (!isalpha(word[0])) { //first character of the word
            printf("Warning: '%s' starts with a non-alphabetic character.\n", word);
            errors++;
        }
        
        // Move to the next word
        word = strtok(NULL, delimiters);
    }
    
    // Display the total number of errors
    if (errors == 0) {
        printf("No errors found.\n");
    } else {
        printf("%d errors found.\n", errors);
    }
}

//command to run text file: ./ex7 < test_text_for_ex7.txt