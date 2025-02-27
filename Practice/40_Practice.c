 
#include<stdio.h> 

   int main(){
   float roll =50.3394;
   float *ptr = &roll;
   float reSult = *ptr;
   char naMe = 'X';
   char *pro = &naMe;
   char result = *pro;
   printf(" The %c value is : %.4f \n",result,reSult);
   return 0;
}