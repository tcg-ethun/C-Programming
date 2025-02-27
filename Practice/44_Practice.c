 
#include<stdio.h> 

   int main(){
   int x;
   int *ptr;
   ptr = &x;
   *ptr = 30;
   printf("X is : %d \n",x);
   printf("*ptr is :%d \n",*ptr);
 
   return 0;
}