#include <stdio.h>
#define SIZE 10

void printArray(int arr[]);
void arrayHistogram(int arr[]);
void swapValues(int arr[], int index1, int index2);
void bubbleSort(int arr[]);
float median(int arr[]);
int isSorted(int arr[], int n);

int main(){

    int arr[SIZE] = {1,1,3,2,1,2,1,2,3,3};
    
    //testing printArray function
    printArray(arr);

    //testing arrayHistogram function
    arrayHistogram(arr);

    //testing swapValues function
    swapValues(arr,1,3);
    printf("After swapping, the array becomes: \n");
    for(int i=0; i<SIZE-1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //testing bubbleSort function
    bubbleSort(arr);
    printf("After sorting, the array becomes: \n");
    for(int i=0; i<SIZE-1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //testing the median function 
    float _median = median(arr);
    printf("The median of the array is: %.2f\n",_median);

    //testing th isSorted function
    int sorted = isSorted(arr, SIZE);
    if (sorted == 1) {printf("The array is sorted.\n");}
    else {printf("The array is not sorted\n");}


    return 0;


}

void printArray(int arr[]){
    printf("Index\tValue\n");
    for(int i=0; i<SIZE; i++) {
        printf("    %d\t    %d\n", i, arr[i]);
    }
}

void arrayHistogram(int arr[]){
    //frequency array initialized with zeros
    int frequency[3] = {0};          

    //calculating the frequency of each element in the array
    for(int i=0; i<SIZE; i++) {
        frequency[arr[i]-1]++;
    }
    
    //printing the histogram of element frequency in the array
    printf("Value\tFrequency\tHistogram\n");
    for(int i=0; i<3; i++) {
        printf("%d\t%d\t\t", i+1, frequency[i]);
        for(int j=0; j<frequency[i]; j++) {
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
            if(arr[j] >= arr[j+1]){
                swapValues(arr, j, j+1);
            }
        }
    }
}

float median(int arr[]) {
    bubbleSort(arr);
    if(SIZE%2==0)
        return (arr[SIZE/2] + arr[SIZE/2-1])/2;
    else 
        return arr[(SIZE-1)/2];
}

int mode(int arr[]) {
    int maxValue = 0;
    int maxCount = 0; 
    
    for (int i=0; i<SIZE; i++){
        int frequency = 0; 

        for (int j=0; j<SIZE; ++j){
            if (arr[j] == arr[i]){++frequency;}
        }

        if (frequency > maxCount){
            maxCount = frequency;
            maxValue = arr[i];
        }
    }
    return maxValue;
}

//problem to be solved
int isSorted(int arr[], int n) {
    if (n == 1 || n == 0)
        return 1;
 
    // Unsorted pair found (Equal values allowed)
    if (arr[n - 1] > arr[n - 2])
        return 0;
 
    // Last pair was sorted
    // Keep on checking
    return isSorted(arr, n - 1);
}