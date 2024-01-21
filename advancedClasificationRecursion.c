#include "NumClass.h"
#define FALSE 0
#define TRUE 1
int sum_powers(int n,int n_digits,int sum){
    if(n==0){
        return sum;
    }
    int x=n;
    //remove 0s
    while(x%10==0){
        x=x/10;
    }
    int digit=x%10;
    x=(x-digit)/10;
    int powered_digit=1;
    for (int i=0;i<n_digits;i++){
        powered_digit=powered_digit*digit;
    }
    sum=sum+powered_digit;
    return sum_powers(x,n_digits,sum);
}

int isAmstrong(int n){
    int n_digits=0;
    int x = n;
    //find the number of digits n_digits
    while(x>0){
        n_digits++;
        x=x/10;
    }
    int sumP=sum_powers(n,n_digits,0);
    if (n==sumP){
        return TRUE;
    }
    return FALSE;
}
int isPalindrome(int n){
    if(n/10==0){
        return TRUE;
    }
    int D1=n%10;//digit 1
    //find lase digit(L_D)
    int L_D=n;
    int LD_multiplayre=1;
    while(L_D/10!=0){
        L_D=L_D/10;
        LD_multiplayre=LD_multiplayre*10;
    }
    //check last and first digits
    if (L_D!=D1){
        return FALSE;
    }
    //get n without the last and first digits
    int n_no_firstAndLast=(n-(L_D*LD_multiplayre))/10;
    int isP=isPalindrome(n_no_firstAndLast);
    return isP;
}