#include <stdio.h>
#include <string.h>

/**
 * Converts the decimal integer into binary
 * @param a, requires that a is a positive integer 
 * @return the binary representation of a
*/
int decimal_to_binary(int a);

/**
 * Finds the position of the most significant bit
 * @param a, requires that a is a positive non-zero integer 
 * @return the position of the most significant bit that is set to 1
*/
int msb(int a);

/**
 * Finds the position of the least significant bit
 * @param a, requires that a is a positive non-zero integer 
 * @return the position of the least significant bit that is set to 1
*/
int lsb(int a);

/*Testing Partitions: 
 * Partition 1: The integer is a small positive non-zero integer
 * Partition 3: The integer is a large positive non-zero integer
 */

int msb_lsb_test(int expected, int actual){
    int passed = 0; 
    if(expected == actual){
        passed = 1;
    }
}

int main(){
    int num;
    printf("Please enter a positive non-zero integer to get the distance between the first and last bits set to 1.\n");
    scanf("%d", &num);

    int binary = decimal_to_binary(num);
    int _msb = msb(binary);
    int _lsb = lsb(binary);
    printf("%d", (_msb - _lsb));

    return 0;
}

//converts a decimal integer into binary
int decimal_to_binary(int a){
    if (a==0){return 0;}
    else{
        return (a%2 + 10*decimal_to_binary(a/2));
    }
}

//Finds the position of the most significant bit
int msb(int a){
    
    char s[100];
    sprintf(s, "%d", a);

    unsigned int position = strlen(s);

    for (unsigned int i=0; i<strlen(s); i++){
        if (s[i] == '1') {break;}
        position--;
    }

    return (position-1);
}

//Finds the position of the least significant bit
int lsb(int a){
    char s[100];
    sprintf(s, "%d", a);

    unsigned int position = 0;

    for (unsigned int i=strlen(s)-1; 0<=i; i--){
        if (s[i] == '1') {break;}
        position++;
    }
    return position;
}