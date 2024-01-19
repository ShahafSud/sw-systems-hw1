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
int isPrime(int n){
    if (n <= 1) return 0;// if 1, 0 or negative return 0
    if (n <= 3) return 1;// if 2 or 3 return 1
    if (n % 2 == 0 || n % 3 == 0) return 0;
    // implamenting the euclidian method
    for (int i = 5; i * i <= n; i += 6) {//for a given interval, check all odd dividers
        if (n % i == 0 || n % (i + 2) == 0 || n % (i + 4) == 0){
            return 0;
        }
    }
    return 1;
}