//lab3 ex6
#include <stdio.h>
#include <stdbool.h>  // For bool, true, and false
#include <string.h>   // For comparing strings

float calculate_tax(float income, bool is_ict, bool is_green_disposal) {
    float tax = 0.0;

    // Adjust the first tax bracket if the user collects old equipment for green disposal
    float first_income_limit = is_green_disposal ? 15000.0 : 10000.0;
    //                         condition? value if true : value if false <- ternary operator
    float second_income_limit = 8000.0;
    
    // Calculate taxes based on the bracket limits
    if (income <= first_income_limit) {
        tax = income * 0.18;  // 18% on first bracket
    } else if (income <= first_income_limit + second_income_limit) {
        tax = first_income_limit * 0.18  // Tax on the first 
              + (income - first_income_limit) * 0.20;  // 20% on the next bracket
    } else {
        tax = first_income_limit * 0.18                    // Tax on the first
              + second_income_limit * 0.20                 // Tax on the second 
              + (income - first_income_limit - second_income_limit) * 0.25;  // 25% on the remaining
    }

    if (is_ict) {
        tax *= 0.95;  // Apply a 5% rebate on the total tax if in ICT industry
    }

    return tax;
}

//checks if "true" or "false" (no case sensitivity)
bool parse_boolean_input(const char* input) {
    
    if (strcasecmp(input, "true") == 0) {
        return true;
    }else if (strcasecmp(input, "false") == 0) {
        return false;
    }else {
        printf("Invalid input. Please enter 'true' or 'false'.\n");
        return false;  // Default to false in case of invalid input
    }
}

int main() {
    //initialisation
    float income;
    bool is_ict, is_green_disposal;
    char input[10];  // Buffer to store user input for true/false questions

    // user input income
    printf("Enter your annual income: €");
    scanf("%f", &income);

    // user input ICT industry status
    printf("Are you working in the ICT industry? (true or false): ");
    scanf("%s", input);
    is_ict = parse_boolean_input(input);

    // user input green disposal status
    printf("Do you collect old electronic equipment for green disposal? (true or false): ");
    scanf("%s", input);
    is_green_disposal = parse_boolean_input(input);

    // Calculate tax
    float tax = calculate_tax(income, is_ict, is_green_disposal);

    // Display the result
    printf("Your calculated tax is: €%.2f\n", tax);

    return 0;
}
