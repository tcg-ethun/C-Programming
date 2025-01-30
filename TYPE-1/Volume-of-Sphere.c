#include<stdio.h>
#include<math.h>
#define pi 3.1416
float main(){
 float r,V;
 scanf("%f",&r);
V = 4*pi*pow(r,3)/3;
printf(" The result of Volume of Sphere is : %.2f",V);
}