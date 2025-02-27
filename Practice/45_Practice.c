 
#include<stdio.h> 

   int main(){
   int a =5 , b= 10;
   int *p = &a , *q= &b;
   *p=*q;
    printf(" Value of a is : %d \n ",a);
    printf("Value of b is : %d \n ",b);
   return 0;
}