#include "NumClass.h"
int isStrong(int n){
    int x = n;
    if (x<=0){
        return 0;
    }
    int sum=0;
    int result=0;
    int digit=0;
    while(x>0){
        result=1;
        digit = x%10;
        for (int i = 2; i <= digit; ++i) {
            result = result*i;
        }
        sum = sum+result;
        x=x/10;
    }
    if(n==sum){
        return 1;
    }
    return 0;
}