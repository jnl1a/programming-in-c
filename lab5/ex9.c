//lab5 ex9

//check typedef defns in notes

#include <stdio.h>
#include <string.h>

#define NLEN 30

// Define new types using typedef
typedef char string_t[NLEN];  // string_t is a character array of size NLEN
typedef struct {
    string_t fname;
    string_t lname;
    int letters;
} name_t;  // name_t represents the struct

// Function to update name information
name_t update_info(name_t info) {
    info.letters = strlen(info.fname) + strlen(info.lname);
    return info;
}

int main(void) {
    name_t person = {"Neville", "Grech", 0};  // Use name_t for the person variable
    person = update_info(person);

    printf("%s %s, your name contains %d letters.\n",
           person.fname, person.lname, person.letters);

    return 0;
}
