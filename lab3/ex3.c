//lab 3 ex3
#include <stdio.h>

#define pin 1234
#define max_guesses 5

int main(){
    int pin_guess;
    int guess=1;

    while(guess != max_guesses){
        printf("\nEnter pin code: ");
        scanf("%d", &pin_guess);

        if(pin_guess == pin){
            printf("correct pin!");
            break;
        }else{
            printf("wrong guess, %d guesses left.", (max_guesses-guess));
            guess++;
        }
    }
    printf("guesses limit reached. locked out.\n");
}