#include <stdio.h>

#define conversion_rate 0.85 //usd to euros
#define max_inputs 10

int main(){
    float usd[max_inputs], euros;

    for(int i = 0; i<max_inputs; i++){
        //inputting dollars from user
        printf("Enter %d dollar amount to convert to eur: ", i+1);
        scanf("%f", &usd[i]);

        //outputting eur conversion
        euros = usd[i] * conversion_rate;
        printf("$%.2f = €%.2f\n", usd[i], euros);
    }

    return 0;
}