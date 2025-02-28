#include <stdio.h>

int main() {
    int arr[2][2] = {{1,4}, {3,7}};
    int *p = &arr[2][2];

    printf("%d\n", *(p+2)); 
    return 0;
}