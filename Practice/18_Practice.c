 
#include<stdio.h> 

   int main(){
   int i,n;
   printf("Enter Number :");
   scanf("%d",&n);
   for (i=0;i<=n;i++){
    if (i%6==0){
     continue;
    }
printf("%d \n",i);
   }

   return 0;
}