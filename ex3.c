#include <stdio.h>
#include <string.h>

#define max_length 100

void reverse(char str[]){

    int length = strlen(str);

    for(int i = 0; i<length/2; i++){
        char temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }
}

int main(){
    char word1[max_length], word2[max_length], word3[max_length]; //arrays for string

    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);
    printf("Enter the third word: ");
    scanf("%s", word3);

    reverse(word1);
    reverse(word2);
    reverse(word3);

    printf("Reversed words:\n");
    printf("1: %s\n", word1);
    printf("2: %s\n", word2);
    printf("3: %s\n", word3);

    return 0;
}

