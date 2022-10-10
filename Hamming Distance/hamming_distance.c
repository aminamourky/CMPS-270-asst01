#include <stdio.h>
#define SIZE 100        //size of the arrays to store the binary forms of the input integers

/**
 * Finds the Hamming distance between the bit representations of those two integers
 * @param a, requires that a is a positive integer 
 * @param b, requires that b is a positive integer
 * @return hamming distance between the bit presentations of a and b
 * 
 * Testing Partitions: 
 * Partition 1: The two integers are small positive integers
 * Partition 3: The two integers are large positive integers
 * Partition 5: One integer is 0 and the other is a large positive integer
 * Partition 6: One integer is 0 and the other is a small positive integer
*/

int hamming_distance(int a, int b);


int hamming_distance_test(int expected, int actual){
    int passed = 0; 
    if(expected == actual){
        passed = 1;
    }
}


int main(){
    int a=0;
    int b=0;

    while (a>=0 && b>=0){
        printf("Please enter two positive integers to calculate the hamming distance. Enter a negative integer to stop.\n");
        scanf("%d %d", &a, &b);

        if (a>=0 && b>=0){
            printf("%d\n", hamming_distance(a,b));
        }
    }
    return 0;

    //Testing 
    hamming_distance_test(1,hamming_distance(1,3));
    hamming_distance_test(17,hamming_distance(1234567,89101112));
    hamming_distance_test(12,hamming_distance(0,12345678));
    hamming_distance_test(1,hamming_distance(0,1));
}

int hamming_distance(int a, int b){

    int arr1[SIZE] = {0};
    int arr2[SIZE] = {0};

    int i=0;
    while (a>0){
        arr1[i] = a % 2;
        a /= 2;
        i++;
    }

    int j=0;
    while (b>0){
        arr2[j] = b % 2;
        b /= 2;
        j++;
    }

    int distance = 0;
    for (i=0; i<SIZE; i++){
        if ((arr1[i] == 1 && arr2[i] == 0) || (arr1[i] == 0 && arr2[i] == 1)) {distance++;}
    }
    return distance;
}