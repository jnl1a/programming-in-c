//lab5 ex7
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h> //for inet_pton
// header file that provides functions to manipulate internet addresses


//union is a special data type in C that allows 
//you to store different types of data in the same memory location.

//union to hold IPv4 address
union IPaddress{
    uint8_t octets[4]; //array for 4 octets
    uint32_t hexValue; //32-bit address
};

int main(){
    union IPaddress ip;

    //input buffer for ipv4 address dotted dec format
    char ipStr[16];

    //user input
    printf("enter IPv4 address: ");
    scanf("%15s", ipStr); //limit input size for no overflow

    //inet_pton to convert string to binary form
    if(inet_pton(AF_INET, ipStr, &ip.hexValue) != 1){ //af_inet: address family(ipv4), ipStr: the string, ip.hexValue: the binary
        printf("invalid IPv4 address format.\n");
        return 1;
    }

    //print in octet form
    printf("IPv4 address in octet form: %u.%u.%u.%u\n", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);

    //print in 32-bit hex 
    printf("IPv4 address in hex form: 0x%o8X\n", ip.hexValue);
}