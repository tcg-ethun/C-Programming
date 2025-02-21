 
#include<stdio.h> 

// int sum(int a ,int b);
void PrintTable(int n);

   int main(){
      int n;
      printf("Enter The Number : ");
      scanf("%d",&n);
PrintTable(n);
   return 0;
}

// int sum(int a ,int b){
void PrintTable( int n){
  int i;
  for(i=0;i<=10;i++){
   printf("%d \n",i*n);
  }
}
