 
#include<stdio.h> 

   int main(){
   int arr [] = {20,40,23,27};
   int size = sizeof(arr) / sizeof(arr[0]);
   printf("Array is : ");
   for(int i=0; i < size;i++){
      printf("%d ",arr[i]);
   }
   return 0;
}