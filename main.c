#include <stdio.h>
#include "NumClass.h"
#define FALSE 0
#define TRUE 1
int main(){
    //initiolize all parameters
    int condition=FALSE;
    int num1=-1;
    int num2=-1;
    int max=0;
    int min=0;
    // take input numbers, if negative take again 
    while(num1<0){
        scanf("%d", &num1);
    }
    while(num2<0){
        scanf("%d", &num2);
    }
    //find max and min
    if(num1<=num2){
        max=num2;
        min=num1;
    }
    else{
        max=num1;
        min=num2; 
    }
    //print results
    printf("The Armstrong numbers are:" );
    for (int i =min;i<max+1;i++){
        condition=isAmstrong(i);
        if(condition==1){
            printf(" %d",i);
        }
    }
    printf("\n");
    printf("The Palindromes are:" );

    for (int i =min;i<max+1;i++){
        condition=isPalindrome(i);
        if(condition==1){
            printf(" %d",i);
        }
    }
    printf("\n");
    printf("The Prime numbers are:" );

    for (int i =min;i<max+1;i++){
        condition=isPrime(i);
        if(condition==1){
            printf(" %d",i);
        }
    }

    printf("\n");
    printf("The Strong numbers are:" );

    for (int i =min;i<max+1;i++){
        condition=isStrong(i);
        if(condition==1){
            printf(" %d",i);
        }
    }
        printf("\n");
}