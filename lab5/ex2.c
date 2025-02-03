//lab5 ex2
#include <stdio.h>
#include <stdlib.h>

int* copyArray(const int* array, int size);

//test driver for the copyArray function
int main(){
    int originalArr[] = {1,2,3,4,5};
    int size = sizeof(originalArr)/sizeof(originalArr[0]); //to calculate size in bytes (size = total/one)

    //normal size copy:
    //calling copy array function
    int* copied = copyArray(originalArr, size);
    if (copied != NULL){
        printf("original array: ");
        for(int i=0; i<size; i++){
            printf("%d ", originalArr[i]);
        }
        printf("\n");

        printf("copied array: ");
        for(int i=0; i<size; i++){
            printf("%d ", copied[i]);
        }
        printf("\n");

        //free allocated memory
        free(copied);
        //used with malloc
        //if not freed then the allocated memory wont be returned to the system
    }else{
        printf("failed to copy array.\n");
    }

    //large size copy:
    int largeSize = 100; //any number thats larger than current array size
    int* largeCopy = copyArray(originalArr, largeSize);

    if(largeCopy != NULL){
        printf("copied large array: ");
        for(int i=0; i<largeSize; i++){
            printf("%d ", largeCopy[i]);
        }
        printf("\n");

        //free allocated memory
        free(largeCopy);
    }else{
        printf("failed to copy large array.\n");
    }

    return 0;
}

int* copyArray(const int* array, int size){
    if (size <= 0 || array == NULL){
        return NULL; //for invalid inputs
    }

    //allocating memory for new array
    int* newArr = (int*)malloc(size*sizeof(int));
    //dynamic memory allocation, declared at run time

    if (newArr == NULL){
        printf("failed to allocate memory.\n");
        return NULL;
    }

    //copying array
    for(int i=0; i<size; i++){
        newArr[i] = array[i];
    }
    
    return newArr;
}

/*
the ouput of oversized array returns the original 5 numbers
followed by multiple garbage values (random digits) to fill in
the remaining space left
*/