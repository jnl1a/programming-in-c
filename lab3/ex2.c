//lab 3 ex2
#include <stdio.h>

int main(){
    int n;
    float factorial = 1;

    printf("Enter a +ve integer: ");
    scanf("%d", &n);

    if(n<1){
        printf("cannot calculate factorial for -ve numbers.");
    }else{
        for(int i = 1; i <= n; i++){
            factorial = factorial * i;
        }

        printf("%d factorial = %f\n", n, factorial);
    }

    return 0;
}
//the same as lab2 ex7