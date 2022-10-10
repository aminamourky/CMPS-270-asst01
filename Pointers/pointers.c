#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(char **arr1, int size1, char **arr2, int size2, char **merged);

//Driver function 
int main(){

    char **arr1=NULL, **arr2=NULL, **merged=NULL;
	int size1, size2;

    printf("Enter the number of strings in the first array: ");
    scanf("%d", &size1);
    arr1 = (char**)malloc(sizeof(char*)*size1);
    printf("Enter the elements of array 1: ");
	for(int i=0; i<size1; i++){
		arr1[i] = (char*)malloc(sizeof(char)*50);
		scanf("%s", arr1[i]);
	}

    printf("Enter the number of strings in the second array: ");
    scanf("%d", &size2);
    arr2 = (char**)malloc(sizeof(char*)*size2);
    printf("Enter the elements of array 1: ");
	for(int i=0; i<size2; i++){
		arr2[i] = (char*)malloc(sizeof(char)*50);
		scanf("%s", arr2[i]);
	}

    //allocating the merged array
    merged = (char**)malloc(sizeof(char*)*(size1+size2));

    merge(arr1, size1, arr2, size2, merged);
    printf("The new array:\n");
	for(int i=0; i<size1+size2; i++){
		printf("%s\n", merged[i]);
	}

	return 0;
}

void merge(char **arr1, int size1, char **arr2, int size2, char **merged){

    int i=0, j=0, k=0;
    //merge the two arrays (enough procedure if the arrays are of the same length)
    while(i<size1 && j<size2){
		if(arr1[i] < arr2[j]){
			merged[k] = arr1[i];
			i++;
		}
		else{
			merged[k] = arr2[j];
			j++;
		}
		k++;
	}

    //If the arrays have different lengths, we need to add the remaining elements
    while(i<size1){
		merged[k] = arr1[i];
		i++;
		k++;
	}
	while(j<size2){
		merged[k] = arr2[j];
		j++;
		k++;
	}
}