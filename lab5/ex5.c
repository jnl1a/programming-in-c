//lab5 ex5
#include <stdio.h>

#define SIZE 101 // 1-100 range (included)

float f(int x, int y, int z){
    return x+(6.0*y)+(7.2*z);
}

int main(){
    float array[SIZE][SIZE][SIZE];

    //calculating function for all possible values of x,y,z
    for(int x=0; x<SIZE; x++){
        for(int y=0; y<SIZE; y++){
            for(int z=0; z<SIZE; z++){
                array[x][y][z] = f(x,y,z);
            }
        }
    }

    //example for verification of size = 3
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3; z++){
                printf("f(%d, %d, %d) = %.2f\n", x, y, z, array[x][y][z]);
            }
        }
    }

    return 0;
}