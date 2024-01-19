#include "NumClass.h"

int isAmstrong(int n){
    int x = n;
    if (x<0){
        return 0;
    }
    if (x<10){//all 0to9 are Amstrong
        return 1;
    }
    int n_digits=0;
    //find the number of digits n_digits
    while(x>0){
        n_digits++;
        x=x/10;
    }
    x=n;
    int digit=0;
    int sum=0;
    int powered=0;
    for(int i=n;i>0;i=i/10){
        digit=i%10;
        powered=1;
        for(int j=0;j<n_digits;j++){
            powered=powered*digit;
        }
        sum=sum+powered;
    }
    if(n==sum){
        return 1;
    }
    return 0;
}
int isPalindrome(int n){
    int x=n;
    if (x<0){
        return 0;
    }
    int n_digits=0;
    //find the number of digits n_digits
    while(x>0){
        n_digits++;
        x=x/10;
    }
    //build array of digits
    int all_digits[n_digits];
    int index=0;
    int digit=0;
    for(int i=n;i>0;i=i/10){
        digit=i%10;
        all_digits[index]=digit;
        index++;
    }
    //check if palindrom
    index=0;
    while(index<n_digits-index-1){
        if(all_digits[index]!=all_digits[n_digits-1-index]){
            return 0;
        }
        index++;
    }
    return 1;
}