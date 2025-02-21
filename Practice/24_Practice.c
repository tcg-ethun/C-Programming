 
#include<stdio.h> 

void Calculate(float value);
     int main(){
      float value = 100.0;
      Calculate(value);
      printf(" \n Before Added Tax  : %f",value);
 
     return 0;
}

void Calculate(float valuec){
     valuec = valuec+(0.20*valuec);
     printf("After Added Tax : %f",valuec);
}
