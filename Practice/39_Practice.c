 
#include<stdio.h> 

   int main(){
   int age =10;
 int *ptr = &age;
 int result = *ptr;
 printf("%d",result);
   return 0;
}