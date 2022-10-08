#include <stdio.h>

int hammingDistance(int a, int b)

{

int n=1000,i=0;

//array of size 1000 initialized to zero to store binary form of a

int arr1[1000] = {0};

i=0;

while (a > 0) {

arr1[i] = a % 2;

a = a / 2;

i++;

}

//array of size 1000 initialized to zero to store binary form of b

int arr2[1000] = {0};

i=0;

while (b > 0) {

arr2[i] = b % 2;

b = b / 2;

i++;

}

//counting the num of bits different in a and b i.e., the hamming distance

int count=0;

for(i=0;i<n;i++){

if((arr1[i]==1 && arr2[i]==0)||(arr1[i]==0 && arr2[i]==1)){

count++;

}

}

return count;

}

int main(){

int a=0,b=0;

while(a>=0 && b>=0)

{

printf("\nEnter two numbers to check hamming Distance\n");

scanf("%d %d", &a, &b);

if(a>=0 && b>=0){

int count= hammingDistance(a,b);
printf("%d",count);

}

}

return 0;

}