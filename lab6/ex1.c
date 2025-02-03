// lab6 ex1
#include <stdio.h> // stderr(standard error) <- predefined output stream used for error messages
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // isalnum <- to check if alpha numeric

#define MAX_FILE_SIZE 1000000  // Define a reasonable file size limit

// Function to check if a match is a whole word
int is_whole_word(const char *start, const char *word, int word_len) {
    if (start > word && isalnum(*(start - 1))) {
        return 0; // Not a whole word (preceding character is alphanumeric)
    }
    if (isalnum(start[word_len])) {
        return 0; // Not a whole word (following character is alphanumeric)
    }
    return 1;
}

// Function to replace words
char *replace_word(const char *text, const char *old_word, const char *new_word) {
    int old_len = strlen(old_word);
    int new_len = strlen(new_word);
    int count = 0;

    // Count occurrences of whole words
    const char *ptr = text;
    while ((ptr = strstr(ptr, old_word)) != NULL) {
        if (is_whole_word(ptr, old_word, old_len)) {
            count++;
        }
        ptr += old_len;
    }

    // Allocate memory for new text
    size_t new_size = strlen(text) + (new_len - old_len) * count + 1;
    char *new_text = malloc(new_size);
    if (!new_text) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Perform replacement
    char *dest = new_text;
    ptr = text;
    while (*ptr) {
        if (strncmp(ptr, old_word, old_len) == 0 && is_whole_word(ptr, old_word, old_len)) {
            strcpy(dest, new_word);
            dest += new_len;
            ptr += old_len;
        } else {
            *dest++ = *ptr++;
        }
    }
    *dest = '\0';

    return new_text;
}

int main() {
    char filename[256], old_word[100], new_word[100];
    printf("Enter filename: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file"); //prints a human-readable error message corresponding to the last error encountered during a system call or library function execution.
        return EXIT_FAILURE;
    }

    // Read file content into memory
    char *buffer = malloc(MAX_FILE_SIZE);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed!\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    size_t length = fread(buffer, 1, MAX_FILE_SIZE - 1, file);
    buffer[length] = '\0';
    fclose(file);

    printf("Enter the word to search: ");
    scanf("%99s", old_word);
    printf("Enter the replacement word: ");
    scanf("%99s", new_word);

    char *new_content = replace_word(buffer, old_word, new_word);
    free(buffer);

    // Write back to the file
    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        free(new_content);
        return EXIT_FAILURE;
    }
    fputs(new_content, file);
    fclose(file);

    printf("Replacement completed successfully.\n");
    free(new_content);

    return EXIT_SUCCESS;
}