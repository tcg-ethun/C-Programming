 
#include<stdio.h> 

   int main(){
   int num = 20;
   int *ptr =&num;
   int result = *ptr;

   printf("%u \n",&result);
   printf("%d \n",*ptr);
   printf("%u \n",&ptr);
 
   return 0;
}