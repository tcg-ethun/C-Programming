 
#include<stdio.h> 

   int main(){
   int num = 20;
   int *ptr =&num;
   int result = *ptr;

   printf("%u \n",&result);
   printf("%u \n",&num);
   printf("%u \n",*ptr);
   printf("%u \n",&ptr);
 
   return 0;
}