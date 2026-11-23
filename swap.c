# include <stdio.h>
void swap(int a,int b,  int temp)
{   
    temp = a;
    a =b;
    b =temp;
    printf("after swapping a=%d and b=%d \n",a,b);
}
int main(){
    int a , b, temp;
    printf("enter the 1st no.");
    scanf("%d",&a);
    printf("enter the 2nd no.");
    scanf("%d",&b);
    swap(a,b,temp);
    return 0;

}