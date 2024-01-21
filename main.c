#include <stdio.h>
#include "NumClass.h"

int main(){
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    for (int i =400;i<450;i++){
        a=isStrong(i);
        b=isPrime(i);
        c=isAmstrong(i);
        d=isPalindrome(i);
        printf("%d is strong: %d\n",i,a);
        printf("%d is prime: %d\n",i,b);
        printf("%d is Amstrong: %d\n",i,c);
        printf("%d is Palindrome: %d\n",i,d);
        printf("\n");
    }
}