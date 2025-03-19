 
#include<stdio.h> 


void countdown(int n);

    int main(){
  countdown(5);
    return 0;
}

void countdown(int n){
   if(n==10){
     return;
   }
   printf("%d \n",n);
   countdown(n+1);
}
