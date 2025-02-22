 
#include<stdio.h> 

void print(int n);


   int main(){
   print(5);
   return 0;
}

//Recursive  //Recursion Function
void print(int n ){
 if(n==0){
  return;
 }
  printf("Hello Esan \n");
  print(n-1);
}