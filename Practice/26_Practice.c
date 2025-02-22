 
#include<stdio.h> 

   int main(){
   int i,sum=0,n;
   printf("Enter the Number : ");
   scanf("%d",&n);
   i=3;
while(i<=n){
 sum += i;
 i+=3;
}
 printf(" Sum : %d",sum);
   return 0;
}