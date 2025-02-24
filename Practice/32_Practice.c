 
#include<stdio.h> 

 int celcius(int  fahrenheit);

   int main(){
   float result = celcius(64);
   printf("Celcius is : %.2f",result);
 
   return 0;
}
int  celcius(int  fahrenheit){
  float cel = (fahrenheit -32)*5/9;
 return cel;
}
