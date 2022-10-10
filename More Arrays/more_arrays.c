#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note second dimension of array must be fixed in C; we assume every inner array has 3 strings 
// and there are nStrings arrays of these 
char **concat (char *input [][3], int nStrings) {
    char **answer = malloc (sizeof (char *) * nStrings);   // allocate space for the string array 
    for (int i = 0; i < nStrings; i++) {
        answer [i] = malloc (sizeof (char) * 100);        // allocate space for the concatenated string 
        int pos = 0;
        for (int j = 0; j < 3; j++) {
            strcpy (answer [i] + pos, input [i][j]);      // copy string to correct position in array 
            pos = strlen (answer [i]);
            strcpy (answer [i] + pos, " ");               // add a space at the end 
            pos++;
        }
        answer [i][pos - 1] = '\0'; // at the end of concatenated string, there will be a space, put \0 there 
    }
    return answer;
}
int main()
{
    // Test code 
    char *arr [][3] = {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
    char **ans = concat (arr, 2);
    printf ("\"%s\",\"%s\"\n", ans [0], ans [1]);
    free (ans [0]);                 // Free up allocated space for strings 
    free (ans [1]);
    free (ans);                     // Free up the array itself 
    return 0;
}

