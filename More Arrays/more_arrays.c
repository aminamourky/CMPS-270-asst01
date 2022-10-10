#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Concatenates the elements of two arrays
 * @param arr, requires that is a 2D array of integers 
 * @return display each index with its corresponding value in the array
 * 
 * Testing Partitions: 
 * Case 1: the two elements within the 2D array are of the same length
 * Case 2: the first element within the 2D array is larger than the second element
 * Case 3: the first element within the 2D array is smaller than the second element
*/

char **concat(char *arr [][3], int num);

int concat_test(int expected, int actual){
    int passed = 0; 
    if(expected == actual){
        passed = 1;
    }
}


int main()
{
    char *arr [][3] = {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
    char **ans = concat (arr, 2);
    printf ("\"%s\",\"%s\"\n", ans [0], ans [1]);
    free (ans);                     
    return 0;
}

char **concat (char *arr [][3], int num) {
    char **new_arr = malloc (sizeof (char *) * num);   
    for (int i = 0; i < num; i++) {
        new_arr [i] = malloc (sizeof (char) * 100);        
        int position = 0;
        for (int j = 0; j < 3; j++) {
            strcpy (new_arr [i] + position, arr [i][j]);      
            position = strlen (new_arr [i]);
            strcpy (new_arr [i] + position, " ");                
            position++;
        }
        new_arr [i][position - 1] = '\0'; 
    }
    return new_arr;
}

