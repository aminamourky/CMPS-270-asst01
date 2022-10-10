#include <stdio.h>
#define MAX_SIZE 100 //define MAX_SIZE 

//function prototype
int Hamming_Pairs_Distance(int num1, int num2);

//main function
int main(void) {
    
    //declare and initialize variables num1 and num2 to zero
    int num1=0; 
    int num2=0; 
    
    while(num1 >= 0 && num2 >= 0){
       scanf("%d %d", &num1, &num2); //taking input from the user
       if(num1>=0 && num2>=0){ //both numbers must be greater than equal to 0.
          printf("%d",Hamming_Pairs_Distance(num1,num2)); //fucntion calling
     }//end if 
  }//end while

}//end main

//function definition for Hamming_Pairs_Distance which will return the distance
int Hamming_Pairs_Distance(int num1, int num2) { 
    
    int ham1[MAX_SIZE] = {0};  //declare and initialize the ham1 array to store binary form of num1
    int ham2[MAX_SIZE] = {0};  //declare and initialize the ham2 array to store binary form of num2
    
    int index1=0;//declare and initialize the variable index1.
    while (num1 > 0) { //iterate till num1 is greater than 0.
        ham1[index1] = num1 % 2; //assign num1%2 at index of  the ham1 array
        num1 /= 2; //divide the num1 by 2(binary)...This equivalent to num1= num1/2
        index1++;  //increase the count of index1 by 1
    }//end while 
   
    int index2 =0; //declare and initialize the variable index2
    
    while (num2 > 0){  //Iterate until num2 is greater than 0.
        ham2[index2] = num2 % 2; //assign num2 % 2 at index of  the ham2 array
        num2 /= 2;  //divide the num2 by 2(binary)...This equivalent to num2= num2/2
        index2++;  //increase the count of index2 by 1
    }//end while
    
    int Distance_Bit=0;//declare and initialize the Distance_Bit variable and initialize to 0.
     
    for(int i=0;i<MAX_SIZE;i++){//iterate through both arrays
    if((ham1[i]==1 && ham2[i]==0)||(ham1[i]==0 && ham2[i]==1)){ //if any one of the given condition is true
      Distance_Bit++; //increase the Distance by 1.
     }//end if 
  }//end for
  
   return Distance_Bit; //return the Distance_Bit to main function
}//end function 