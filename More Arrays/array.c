
#include<stdio.h>
#include<stdlib.h>


char* concat(char** arr, int num);

int main()
{
   char* arr[3] = {"I LOVE CODING", "THIS IS SPARTA"};
   char* new_array = concat(arr, 3);
   printf("%s", new_array);
   return 0;
}

char* concat(char** arr, int num)
{
   char* array;
   array = (char*)malloc(sizeof(char) * 1000);
   int index = 0;
   
   for(int i=0; i<num; i++)
   {
       for(int j=0; arr[i][j]!='\0'; j++)
       {
           array[index++] = arr[i][j];
       }
       array[index++] = ' ';
   }
   
   array[index-1] = '\0';
   return array;
}
