//lab3 ex10
#include <stdio.h>
#include <string.h> 

typedef struct {
    int code;
    char name[30];
    float price;
} Item; //structure of item array

void showMenu();
void addItems(Item items[], int item_count, float *total);
// *total to modify the variable directly instead of a local copy

int main(void){
    Item items[] = {
        {1, "Apple", 0.99},
        {2, "Banana", 1.29},
        {3, "Water", 1.49},
        {4, "Milk", 1.69},
        {5, "Bread", 2.49}
    }; //array of items available in store

    int item_count = sizeof(items)/sizeof(items[0]); //total size in bytes divided by the size of the first element in bytes = total elements

    char choice;
    float total = 0; //running total for shopping session

    while(1){ //loops until user chooses to quit
        showMenu();
        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar();

        switch(choice){
            case '1': //show available items and adding to cart
                    printf("\nAvailable items: \n");
                    for(int i = 0; i<item_count; i++){
                        printf("Code: %d, Name: %s, Price: %.2f\n", items[i].code, items[i].name, items[i].price);
                    }
                    addItems(items, item_count, &total);
                    break;
            case '2': //show current total
                    printf("Current total: %.2f\n", total);
                    break;
            case '3': //checkout
                    printf("Are you sure you want to check out? (y/n): ");
                    char confirmCheckOut;
                    scanf("%c", &confirmCheckOut);
                    if(confirmCheckOut == 'y' || confirmCheckOut == 'Y'){
                        printf("Total amount: %.2f\n", total);
                        printf("Thanks for your pruchase!\n");
                        total=0; //total is reset
                    }
                    break;
            case '4': //cancel
                    printf("Are you sure you want to cancel session? (y/n): ");
                    char confirmCancel;
                    scanf("%c", &confirmCancel);
                    if(confirmCancel == 'y' || confirmCancel == 'Y'){
                        printf("Session cancelled. Starting new session. \n"); 
                        total = 0; //reset - new session
                    }
                    break;
            case 'q': //quit
                    printf("Are you sure you want to quit? (y/n): ");
                    char confirmQuit;
                    scanf("%c", &confirmQuit);
                    getchar();
                    if(confirmQuit == 'y' || confirmQuit == 'Y'){
                        printf("Quitting... \n"); 
                        return 0; //exit program
                    }
                    break;
            default:
                    printf("Invalid choice, try again.\n");
            
        }
    }

    return 0;
}

void showMenu(){
    printf("\nWelcome!\n");
    printf("1. Add items to shopping cart\n");
    printf("2. Show current total\n");
    printf("3. Check out\n");
    printf("4. Cancel Session\n");
    printf("q. Quit\n");
}

void addItems(Item items[], int item_count, float *total){
    int item_code, quantity;
    printf("Enter code of the item to add: ");
    scanf("%d", &item_code);

    //looking for item in list
    int found = 0; //flag
    for(int i = 0; i<item_count; i++){
        if(items[i].code == item_code){
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            *total += items[i].price*quantity;
            printf("Added %d of %s to cart. Subtotal: %.2f\n", quantity, items[i].name, items[i].price*quantity);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Item not found.\n");
    }
}