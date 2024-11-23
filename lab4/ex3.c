//lab4 ex3
#include <stdio.h>

long gcd_iterative(int x, int y){ // x > y
    //euclidean algorithm
    while(y!=0){
        int temp = y;
        y = x%y;
        x=temp;
    }
    // % the previous mod, x, with new mod, y, until y = 0
    return x;
}

/*
Readability of implementation is straightforward and clear using the while loop.
It uses one stack frame due to the loop thus stack memory usage is consitant.
It's safer for larger inputs.
*/

long gcd_recursive(int x, int y){
    if(y == 0){
        return x;
    }

    return gcd_recursive(y, x%y); 
}

/*
Readability of implementation is more abstract thus not beginner friendly but it is more concise.
There is no need for temporary variables.
Stack frame usage is larger as a one is created per recursive call. this can lead to a stck overflow.
Less ideal for larger inputs.
*/

/* commented for ex7
int main(void){
    int x,y;
    printf("Enter x (the larger number): ");
    scanf("%d", &x);

    printf("Enter y (the smaller number): ");
    scanf("%d", &y);

    printf("Iterative GCD of %d & %d: %ld\n", x, y, gcd_iterative(x, y));
    printf("Recursive GCD of %d & %d: %ld\n", x, y, gcd_recursive(x, y));
    return 0;
}*/

void ex3(){
    int x,y;
    printf("Enter x (the larger number): ");
    scanf("%d", &x);
    getchar();

    printf("Enter y (the smaller number): ");
    scanf("%d", &y);
    getchar();

    printf("Iterative GCD of %d & %d: %ld\n", x, y, gcd_iterative(x, y));
    printf("Recursive GCD of %d & %d: %ld\n", x, y, gcd_recursive(x, y));
}