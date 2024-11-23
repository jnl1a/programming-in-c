//lab4 ex7
#include <stdio.h>
#include <string.h>
#include <math.h>

void ex2();
void ex3();
void ex4();
void ex5();
void ex6();

void menu(){
    printf("\nMenu: \n");
    printf("1. Ex2 - Fibonacci (Iterative and Recursive)\n");
    printf("2. Ex3 - GCD (Iterative and Recursive)\n");
    printf("3. Ex4 - Decimal to Hexadecimal & Reverse String\n");
    printf("4. Ex5 - Analyse a String\n");
    printf("5. Ex6 - Ceil and Floor Calculations\n");
    printf("q. Exit\n");
}

int main(void){
    char choice;

    do{
        menu();
        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar();

        switch(choice){
            case '1': ex2();break;
            case '2': ex3();break;
            case '3': ex4();break;
            case '4': ex5();break;
            case '5': ex6();break;
            case 'q': printf("Quitting...\n");
                      return 0;break;
            default: printf("Invalid choice. Try again..\n");
        }
    }while( choice != 'q');
    return 0;
}

/*command to run: 
gcc programming-in-c/lab4/ex7.c programming-in-c/lab4/ex2.c programming-in-c/lab4/ex3.c programming-in-c/lab4/ex4.c programming-in-c/lab4/ex5.c programming-in-c/lab4/ex6.c -lm -o ex7
and 
./ex7
*/