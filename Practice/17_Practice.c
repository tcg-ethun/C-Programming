 
#include<stdio.h> 

   int main(){
         int i, x;
         for(i=0; 1 ;i++){
          printf("Enter Number : ");
          scanf("%d",&x);
               if(x%2 !=0){
                break;
               }
         }
         printf("\n");
               printf("Loop Ended for %d \n \n",x);
   return 0;
}