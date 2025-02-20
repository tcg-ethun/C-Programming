 
#include<stdio.h> 

   int main(){
   int doorcode = 2025,input;
   printf("Enter Door Code :");
   scanf("%d",&input);
   if(doorcode == input){
      printf("Opened !");
   }
   else{
      printf("Locked !");
   }
 
   return 0;
}