//lab6 ex2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

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

int main() {
    char filename[256], temp_filename[] = "temp.txt";
    char old_word[MAX_WORD_SIZE], new_word[MAX_WORD_SIZE];

    printf("Enter filename: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    FILE *temp_file = fopen(temp_filename, "w");
    if (!temp_file) {
        perror("Error creating temporary file");
        fclose(file);
        return EXIT_FAILURE;
    }

    printf("Enter the word to search: ");
    scanf("%99s", old_word);
    printf("Enter the replacement word: ");
    scanf("%99s", new_word);

    int old_len = strlen(old_word);
    int new_len = strlen(new_word);
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        char *ptr = buffer;
        while ((ptr = strstr(ptr, old_word)) != NULL) {
            if (is_whole_word(ptr, old_word, old_len)) {
                fwrite(buffer, 1, ptr - buffer, temp_file);
                fwrite(new_word, 1, new_len, temp_file);
                ptr += old_len;
                memmove(buffer, ptr, strlen(ptr) + 1);
                ptr = buffer;
            } else {
                ptr += old_len;
            }
        }
        fputs(buffer, temp_file);
    }

    fclose(file);
    fclose(temp_file);

    // Replace original file with modified content
    remove(filename);
    rename(temp_filename, filename);

    printf("Replacement completed successfully.\n");
    return EXIT_SUCCESS;
}
