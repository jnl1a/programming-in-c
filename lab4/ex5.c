//lab4 ex5
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void analyizingStr(char str[]){
    int length = strlen(str);

    //check validity
    int valid = 1; //assume valid
    for(int i=0; i<=length; i++){
        if(isdigit(str[i])){
            valid = 0;
            break; // exit if theres a digit
        }
    }

    //output validity
    if(valid){
        printf("Input is valid.\n");
    }else{
        printf("Input invalid, contains numerical digits.\n");
    }

    //output length
    printf("Input length: %d\n", length);

    //output first char
    if(length > 0){
        printf("first character: %c\n", str[0]);
    }else{
        printf("No string characters.\n");
    }

    //finding most frequent char
    int frequentChar[256] = {0}; //array for frequency of all ascii characters
    int maxFreq = 0;
    char mostFreq = '\0';

    for(int i=0; i<length; i++){
        frequentChar[(unsigned char)str[i]]++;
        // inc frequency of current character
    }

    for(int i=0; i<256; i++){
        if(frequentChar[i] > maxFreq){
            maxFreq = frequentChar[i];
            mostFreq = (char)i;
        }
    }

    //output most freq char
    if(maxFreq > 0){
        printf("Most frequent character: %c\n", mostFreq);
    }else{
        printf("No string characters.\n");
    }
}

/* commented for ex7
int main(void){
    char str[100]; //array for input string

    printf("Enter a string: ");
    while(fgets(str, sizeof(str), stdin)){
        // Remove trailing newline character if present
        str[strcspn(str, "\n")] = '\0';

        analyizingStr(str);

        printf("\nEnter another string (Ctrl+C to exit): ");
    }

    return 0;
}*/

void ex5(){
    char str[100]; //array for input string

    printf("Enter a string: ");
    while(fgets(str, sizeof(str), stdin)){
        // Remove trailing newline character if present
        str[strcspn(str, "\n")] = '\0';

        analyizingStr(str);

        printf("\nEnter another string (Ctrl+C to exit): ");
    }
}