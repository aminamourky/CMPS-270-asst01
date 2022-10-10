#include <stdio.h>
#include <string.h>
#include <stdlib.h>   
//declare function prototypes
void merge(char **, int, char **, int, char **);
int main(){
	//declare variables
	char **arr1=NULL, **arr2=NULL, **result=NULL;
	int num1, num2;
	//get size of arrays
	printf("Enter number of strings in array 1: ");
	scanf("%d", &num1);
	printf("Enter number of strings in array 2: ");
	scanf("%d", &num2);
	//allocate arrays
	arr1 = (char**)malloc(sizeof(char*)*num1);
	arr2 = (char**)malloc(sizeof(char*)*num2);
	result = (char**)malloc(sizeof(char*)*(num1+num2));
	//get input for arrays
	printf("Enter array 1: ");
	for(int i=0; i<num1; i++){
		arr1[i] = (char*)malloc(sizeof(char)*50);
		scanf("%s", arr1[i]);
	}
	printf("Enter array 2: ");
	for(int i=0; i<num2; i++){
		arr2[i] = (char*)malloc(sizeof(char)*50);
		scanf("%s", arr2[i]);
	}
	//call merge function
	merge(arr1, num1, arr2, num2, result);
	//display result
	printf("Result:\n");
	for(int i=0; i<num1+num2; i++){
		printf("%s\n", result[i]);
	}
	return 0;
}
//define merge function
void merge(char **arr1, int num1, char **arr2, int num2, char **result){
	//declare variables
	int i=0, j=0, k=0;
	//merge arrays
	while(i<num1 && j<num2){
		if(strcmp(arr1[i], arr2[j])<0){
			result[k] = arr1[i];
			i++;
		}
		else{
			result[k] = arr2[j];
			j++;
		}
		k++;
	}
	//add remaining elements
	while(i<num1){
		result[k] = arr1[i];
		i++;
		k++;
	}
	while(j<num2){
		result[k] = arr2[j];
		j++;
		k++;
	}
}

