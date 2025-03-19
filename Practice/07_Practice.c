 
#include<stdio.h> 

  //Uses of int , float and char data type

   int main(){
   int items = 50;
   float price = 9.99, total;
   char doller = '$';
   total = items*price;
   printf(" Number of items: %d \n",items);
   printf("Cost per items : %.2f %c\n" ,price,doller);
printf("Total Price : %.2f %c \n \n" , total,doller);

   return 0;
}