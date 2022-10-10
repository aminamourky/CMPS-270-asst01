#include <stdio.h>
#include <string.h>

int decimal_to_binary(int a);
int msb(int a);
int lsb(int a);

int main(){
    int num;
    printf("Please enter a positive non-zero integer to get the distance between the first and last bits set to 1.\n");
    scanf("%d", &num);

    int binary = decimal_to_binary(num);
    int _msb = msb(binary);
    int _lsb = lsb(binary);
    printf("%d", (_msb - _lsb));
    return 0;
}

int decimal_to_binary(int a){
    if (a==0){return 0;}
    else{
        return (a%2 + 10*decimal_to_binary(a/2));
    }
}

int msb(int a){
    
    char s[100];
    sprintf(s, "%d", a);

    unsigned int position = strlen(s);

    for (unsigned int i=0; i<strlen(s); i++){
        if (s[i] == '1') {break;}
        position--;
    }


    return (position-1);
}


int lsb(int a){
    char s[100];
    sprintf(s, "%d", a);

    unsigned int position = 0;

    for (unsigned int i=strlen(s)-1; 0<=i; i--){
        if (s[i] == '1') {break;}

        position++;
    }
    return position;
}