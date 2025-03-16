#include <stdio.h>

int main() {
 int arr[4];
    printf("Enter Bangla Number : ");
    scanf("%d",&arr[0]);
    printf("Enter Math Number : ");
    scanf("%d",&arr[1]);
    printf("Enter Chemistry Number : ");
    scanf("%d",&arr[2]);
    printf("Enter Physics Number : ");
    scanf("%d",&arr[3]);
    printf("Enter ICT Number : ");
    scanf("%d",&arr[4]);

    printf("Your Bangla number is : %d , Math is %d , Chemistry is %d , Physics is %d , ICT is %d",arr[0],arr[1],arr[2],arr[3],arr[4]);
    return 0;
}