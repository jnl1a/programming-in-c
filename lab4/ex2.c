//lab4 ex2
#include <stdio.h>

long fib_iterative(int n){
    if(n<=1){
        return n; // n = 0 gives 0 and n = 1 gives 1
    }

    long firstNum=0, secondNum=1, fib;

    for(int i=2; i<=n; i++){ //i=2 since 0 and 1 already accounted for
        fib = firstNum + secondNum;
        firstNum = secondNum;
        secondNum = fib;
    }

    return secondNum;
}

/*
Readability of implementation is straightforward and clear as it directly 
uses a loop for calculation.
It uses one stack frame due to the for loop thus stack memory usage is consitant.
*/

long fib_recursive(int n){
    if(n<=1){
        return n;
    }

    return fib_recursive(n-1) + fib_recursive(n-2);
    // recursion occurs until the base case 
}

/*
Readability of implementation is more abstract thus not beginner friendly but it is more concise.
Stack frame usage is larger as a one is created per recursive call. this can lead to a stck overflow.
*/

/* commented for the use of ex7 
int main(void){
    int n=10;

    printf("Iterative fibonacci of %d: %ld\n", n, fib_iterative(n));
    printf("Recursive fibonacco of %d: %ld\n", n, fib_recursive(n));
    return 0;
}*/

void ex2(){
    int n=10;

    printf("Iterative fibonacci of %d: %ld\n", n, fib_iterative(n));
    printf("Recursive fibonacco of %d: %ld\n", n, fib_recursive(n));
}