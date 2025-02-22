 
#include<stdio.h> 

   int main(){
   int i,n;
   printf("Enter Number : ");
   scanf("%d",&n);

   i=0;
   do{
    printf("  %d ",i);
    i++;
   }while(i<=n);
   return 0;
}