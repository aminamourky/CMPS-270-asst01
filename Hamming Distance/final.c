#include <stdio.h>
#define SIZE 100        //size of the arrays to store the binary forms of the input integers

int hamming_distance(int a, int b);

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