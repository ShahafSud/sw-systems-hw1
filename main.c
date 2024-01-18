#include <stdio.h>
#include "NumClass.h"

int main(){
    int a=isStrong(145);
    int b=isStrong(146);
    int c=isStrong(1);

    printf("145 is strong: %d\n",a);
    printf("146 is strong: %d\n",b);
    printf("1 is strong: %d\n",c);

}