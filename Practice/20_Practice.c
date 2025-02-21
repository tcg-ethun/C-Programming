 
#include<stdio.h> 

int sum(int a , int b);
   int main(){
   int a,b,s;
   printf("Enter first num : ");
   scanf("%d",&a);
   printf("Enter second num : ");
   scanf("%d",&b);
 s = sum(a,b);
 printf("The sum value is : %d \n \n",s);
   return 0;
}



int sum(int a , int b){
 return a+b;
}
