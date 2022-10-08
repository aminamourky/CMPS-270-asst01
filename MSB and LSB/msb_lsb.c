#include <stdio.h>

// Decimal to binary conversion
int convert_to_Binary(int decimal_number){
    if (decimal_number == 0) {return 0;}
    else{
        return (decimal_number % 2 + 10 *convert_to_Binary(decimal_number / 2));//return recursion function it self here and then back to return main
}
}


int call_lsb(int s) {

    char str[50];//Declare String

    unsigned int i,j=0;//declare variable here

    sprintf(str, "%d", s); //convert integer to string

    for(i=strlen(str)-1;0<=i;i--)//Operation for find out lsb

{

if(str[i]=='1') {
    break;
    }

j++;

}

return j;

}

int call_msb(int s)

{

char str[50];//Declare String

unsigned int i,j;//declare variable here

sprintf(str, "%d", s); //convert integer to string

j=strlen(str);

for(i=0;i<strlen(str);i++)//Operation for find out lsb

{

if(str[i]=='1')

{

break;

}

j--;

}

return j-1;

}

int main()

{

int decimal_number,converted,lsb,msb;

printf("Enter the number ::");//Input your number here message

scanf("%d",&decimal_number);//store it in variable

converted= convert_to_Binary(decimal_number);//converting it with recursion function call here

printf("Binary of the following number is :%d \n",converted);//Print it

lsb=call_lsb(converted);//cal lsb function from here

msb=call_msb(converted);//call msb function from here

printf("LSB is : %d \n",lsb);//print lsb here

printf("MSB is : %d \n",msb);//print msb here

printf("The distance between lsb and msb is : %d",msb-lsb );//print distance here

return 0;

}