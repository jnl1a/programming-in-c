#include <stdio.h>

//functions
int add();
int subtract();
int multiply();

int main(void){

    int num1, num2;

    printf("Enter first number: \n");
    scanf("%d", &num1);

    printf("Enter second number: \n");
    scanf("%d", &num2);

    add(num1, num2);
    subtract(num1, num2);
    multiply(num1, num2);

    return 0;

}

int add(int num1, int num2){
    int ans = num1+num2;
    printf("addition: %d \n",ans);
    
    return 0;
}

int subtract(int num1, int num2){
    int ans = num1-num2;
    printf("subtract: %d \n", ans);
    return 0;
}

int multiply(int num1, int num2){
    int ans = num1*num2;
    printf("multpiplication: %d \n", ans);
    return 0;
}