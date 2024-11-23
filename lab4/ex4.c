//lab4 ex4
#include <stdio.h>
#include <string.h>

//dex to hex conversion
void decToHex(int n);
void reverseStr(char str[], int left, int right);

/* commented for ex7
int main(void){
    int decimal;
    char str[25];

    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    // Consume the newline character left by scanf
    getchar();

    printf("Hexadecimal rep of %d: ", decimal);
    decToHex(decimal);

    printf("\nEnter text: ");
    fgets(str, sizeof(str), stdin); //read string input

    // Remove the trailing newline character if present
    str[strcspn(str, "\n")] = '\0';

    reverseStr(str, 0, strlen(str)-1);
    printf("Reversed String: %s\n", str);

    return 0;
}*/

void ex4(){
    int decimal;
    char str[25];

    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    // Consume the newline character left by scanf
    getchar();

    printf("Hexadecimal rep of %d: ", decimal);
    decToHex(decimal);

    printf("\nEnter text: ");
    fgets(str, sizeof(str), stdin); //read string input

    // Remove the trailing newline character if present
    str[strcspn(str, "\n")] = '\0';

    reverseStr(str, 0, strlen(str)-1);
    printf("Reversed String: %s\n", str);
}

void decToHex(int n){
    if(n==0){
        return;
    } //base case -> stop recursion

    //recursion - most significant to least significant digits
    decToHex(n/16);
    //dividing by 16 to process most signuficant digit first(left)

    int remainder = n%16;
    if (remainder < 10){
        printf("%d", remainder); // digits 0-9
    }else{
        printf("%c", 'A' + (remainder - 10)); // letters A-F (10-15)
        // (remainder-10) will return a number that when added to A, the respectful letter is obtained
    }
}

void reverseStr(char str[], int left, int right){
    //base case -> stop when pointers meet/cross
    if (left>=right){
        return;
    }

    //swap characters from left & right
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    //recursion
    reverseStr(str, left+1, right-1);
}