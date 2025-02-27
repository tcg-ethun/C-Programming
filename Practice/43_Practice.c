 
#include<stdio.h> 

int main(){
int age = 20;
int *ptr = &age;
int result = *ptr;

printf(" %d \n",*(&age));

return 0;
}