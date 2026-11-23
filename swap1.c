# include <stdio.h>

int main(){
    int a, b;
    printf("enter the 1st no.");
    scanf("%d",&a);
    printf("enter the 2nd no.");
    scanf("%d",&b);
//using bitwise XOR 
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("after swapping a=%d and b=%d \n",a,b);
    return 0;
}