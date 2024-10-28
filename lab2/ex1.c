#include <stdio.h>

int main(){
    int input;

    printf("enter integer number: ");
    scanf("%d", &input);

    if(input >= 0 && input <= 127){
        printf("the corresponding character is: %c", (char)input);
    }else{
        printf("error, integer invalid.\n");
    }
    return 0;
}