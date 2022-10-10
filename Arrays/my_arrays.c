#include <stdio.h>
#define SIZE 10

void printArray(int arr[]) {
    printf("Index\tValue\n");
    for(int i=0; i<SIZE; i++) {
        printf("    %d\t    %d\n", i, arr[i]);
    }
}

void arrayHistogram(int arr[]) {
    int freq[3] = {0}; //frequency array
    
    for(int i=0; i<SIZE; i++) {
        freq[arr[i]-1]++;
    }
    
    printf("Value\tFrequency\tHistogram\n");
    for(int i=0; i<3; i++) {
        printf("%d\t%d\t\t", i+1, freq[i]);
        for(int j=0; j<freq[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void swapValues(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubbleSort(int arr[]) {
    for(int i=0; i<SIZE-1; i++) {
        for(int j=0; j<SIZE-1; j++) {
            if(arr[j] >= arr[j+1])
                swapValues(arr, j, j+1);
        }
    }
}

float median(int arr[]) {
    if(SIZE%2==0)
        return (arr[SIZE/2-1] + arr[SIZE/2])/2;
    else 
        return arr[(SIZE-1)/2];
}

int mode(int arr[]) {
    int freq[3] = {0};
    for(int i=0; i<SIZE; i++) {
        freq[arr[i]-1]++;
    }
    
    int mx = 0;
    for(int i=0; i<3; i++) {
        mx = (mx > freq[i])? mx:freq[i];
    }
    
    return mx;
}

int isSorted(int arr[], int n) {
    int ans = 1;
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1])
            ans = 0;
    }
    
    return ans;
}

int main() {
    int arr[SIZE] = {1,1,1,1,1,2,2,2,3,3};
    
    printArray(arr);
    
    arrayHistogram(arr);
    
    printf("before swap \n%d %d\n", arr[2], arr[5]);
    swapValues(arr, 2, 5);
    printf("after swap \n%d %d\n", arr[2], arr[5]);
    
    bubbleSort(arr);
    
    float MEDIAN = median(arr);
    printf("median of array - %.2f\n", MEDIAN);
    
    int MODE = mode(arr);
    printf("mode of the array - %d\n", MODE);
    
    int sorted = isSorted(arr, SIZE);
    if(sorted)
        printf("array is sorted\n");
    else
        printf("array is not sorted\n");
    
    return 0;
}