#include <stdio.h>

int main() {
int number [] = {10,30,40,30};
float avrg , sum=0;
int i;
int size = sizeof(number) / sizeof(number[0]);
for ( i = 0; i < size ; i++)
{
sum+=number[i];
}
avrg = sum/size;
printf("%.2f",avrg);
    return 0;
}