 
#include<stdio.h> 

float FarenHeight(float celcius);

   int main(){

    float result = FarenHeight(0);
 printf("FahrenHeight value : %.2f",result);
   return 0;
}

float FarenHeight(float celcius){
   float far = celcius *( 9/5 ) + 32;
   return far ;
}
