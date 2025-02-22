 
#include<stdio.h> 

   int main(){
   int n,sum=0,x;
   printf("Enter the number : ");
   scanf("%d",&x);
   n=3;
   do{
        sum+=n;
        n+= 3;
   }while(n<=x);
 printf(" Sum is : %d",sum);
   return 0;
}