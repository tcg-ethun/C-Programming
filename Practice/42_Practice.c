 
#include<stdio.h> 

   int main(){
   int age = 20;
   int *ptr = &age;
   int result = *ptr;
   printf("%p \n",&age);
   printf("%u \n",&age);
   printf("\n");
   printf("%u \n",*ptr);
   printf("%u\n",&*ptr);
   printf("\n");
   printf("%u\n",&result);
   printf("%u\n",result);
   printf("\n");
   printf("%d \n",*(&age));
   printf("\n");

   return 0;
}