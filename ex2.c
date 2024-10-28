#include <stdio.h>

int main() {
  float weight;
  int value;
  printf("Enter your weight in pounds: \n");
  scanf("%f", &weight);
  // Platinum is $1770 / pound
  // 14.5 troy ounces in 1 pound
  value = 1770.0 * weight * 14.5;
  printf ("Your weight in platinum costs $%.4d. \n", value);

  printf("Your weight (as an integer) in octal is: %o\n", (int)weight); //octal format
  printf("Your weight (as an integer) in hexadecimal is: %x\n", (int)weight); //hexal format
}

// 1. result = $4234725.00
// 2. value in double doesnt change result
/* 4. when value is int, %d needs to be used in printf to match the variable type. 
   if it remains %f then it is trying to be interpreted as a floating point which might cause errors*/
/* 5. Printing a non-printable character using %c may produce no visible output, trigger special effects like a terminal bell, 
   or produce other unexpected behaviors. Printing the integer index itself using %d will simply display the number without issues.*/
   