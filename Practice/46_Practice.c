 
#include<stdio.h> 

   int main(){
   int x =20;
   int *ptr = &x;
   int **q = &ptr;
   int ***no= &q;
   int ****po = &no;
   printf("%d \n",****po);
   return 0;
}